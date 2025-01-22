/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  copyright (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  the software is provided "as is" and the author disclaims all warranties
 *  with regard to this software including all implied warranties of
 *  merchantability and fitness. in no event shall the author be liable for
 *  any special, direct, indirect, or consequential damages or any damages
 *  whatsoever resulting from loss of use, data or profits, whether in an
 *  action of contract, negligence or other tortious action, arising out of
 *  or in connection with the use or performance of this software.
 *
 */
`default_nettype none 
`timescale 1 ns / 100 ps
// verilog_lint: waive-start explicit-parameter-storage-type
/* verilator lint_off WIDTH */
`include "riscv_defines.svh"

module execute_stage (
    input wire logic clk,                 // 時脈訊號
    input wire logic resetn,              // 同步重設訊號，低電位有效
    input wire logic Stall,               // 管線暫停訊號
    input wire logic RegWriteE,           // 註冊寫入控制訊號 (執行階段)
    input wire ResultSrc_t ResultSrcE,    // 結果來源控制訊號 (執行階段)
    input wire LoadOp_t LoadOpE,          // 加載操作類型 (執行階段)
    input wire StoreOp_t StoreOpE,        // 存儲操作類型 (執行階段)
    input wire logic [31:0] Rd1E,         // 第一操作數 (執行階段)
    input wire logic [31:0] Rd2E,         // 第二操作數 (執行階段)
    input wire logic [4:0] RdE,           // 目標暫存器索引 (執行階段)
    input wire logic [31:0] PCPlus4E,     // 程式計數器加4的結果 (執行階段)
    input wire logic [31:0] PCE,          // 程式計數器值 (執行階段)
    input wire logic [31:0] ImmExtE,      // 立即數擴展結果 (執行階段)
    input wire logic [31:0] ResultW,      // 寫回階段的結果數據
    input wire logic [31:0] AluResultE,   // ALU 計算結果 (執行階段)
    input wire logic MemWriteE,           // 存儲控制訊號 (執行階段)
    input wire PCTargetSrc_t PCTargetSrcE,// PC 更新來源選擇訊號 (執行階段)
    input wire AluSrcA_t AluSrcAE,        // ALU 第一操作數來源控制 (執行階段)
    input wire AluSrcB_t AluSrcBE,        // ALU 第二操作數來源控制 (執行階段)
    input wire ForwardAE_t ForwardAE,     // 操作數 A 轉發控制訊號
    input wire ForwardBE_t ForwardBE,     // 操作數 B 轉發控制訊號
    input wire logic [31:0] CsrDataE,     // CSR 數據 (執行階段)
    output wire logic [31:0] AluResultM,  // ALU 計算結果 (存取階段)
    output wire logic RegWriteM,          // 註冊寫入控制訊號 (存取階段)
    output wire ResultSrc_t ResultSrcM,   // 結果來源控制訊號 (存取階段)
    output wire logic MemWriteM,          // 存儲控制訊號 (存取階段)
    output wire LoadOp_t LoadOpM,         // 加載操作類型 (存取階段)
    output wire StoreOp_t StoreOpM,       // 存儲操作類型 (存取階段)
    output wire logic [31:0] Rd2M,        // 第二操作數 (存取階段)
    output wire logic [4:0] RdM,          // 目標暫存器索引 (存取階段)
    output wire logic [31:0] PCPlus4M,    // 程式計數器加4的結果 (存取階段)
    output wire logic [31:0] PCTargetE,   // PC 更新目標地址 (執行階段)
    output wire logic [31:0] SrcAE,       // ALU 第一操作數
    output wire logic [31:0] SrcBE,       // ALU 第二操作數
    output wire ResultSrc_t ResultSrcE_, // 更新後的結果來源控制訊號
`ifndef SIM
    output wire logic [31:0] WriteDataUnAlignedM // 未對齊的存儲數據
`else
    input wire logic [31:0] InstrE,       // 指令碼 (執行階段)
    output wire logic [31:0] WriteDataUnAlignedM, // 未對齊的存儲數據
    output wire logic [31:0] InstrM      // 指令碼 (存取階段)
`endif
);

  // RegWriteM_i：將執行階段的註冊寫入信號 RegWriteE 傳遞到存取階段 RegWriteM
  dflop #(1, 0) RegWriteM_i (
      .resetn(resetn), // 同步重設訊號，低電位有效
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號，當管線未暫停時啟用
      .d(RegWriteE),   // 輸入：執行階段的註冊寫入控制信號
      .q(RegWriteM)    // 輸出：存取階段的註冊寫入控制信號
  );

  // 判斷是否為 CSR 操作
  logic isCsrOperation; 
  assign isCsrOperation = ResultSrcE == ResultSrc_t'(RESULT_SRC_CSRDATA); // 判斷結果來源是否為 CSR 數據
  assign ResultSrcE_ = isCsrOperation ? RESULT_SRC_ALURESULT : ResultSrcE; // 若是 CSR 操作，結果來源改為 ALU 結果

  // ResultSrcM_i：將更新後的結果來源控制訊號 ResultSrcE_ 傳遞到存取階段 ResultSrcM
  dflop #($bits(ResultSrcM), 0) ResultSrcM_i (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(ResultSrcE_), // 輸入：更新後的結果來源控制訊號
`ifdef ICARUS
      .q(ResultSrcM)   // 輸出：存取階段的結果來源控制訊號 (ICARUS 模式)
`else
      .q({>>{ResultSrcM}}) // 輸出：存取階段的結果來源控制訊號 (其他模擬器)
`endif
  );

  // MemWriteM_i：將執行階段的存儲控制信號 MemWriteE 傳遞到存取階段 MemWriteM
  dflop #(1, 0) MemWriteM_i (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(MemWriteE),   // 輸入：執行階段的存儲控制信號
      .q(MemWriteM)    // 輸出：存取階段的存儲控制信號
  );

  // LoadOpM_t：將執行階段的加載操作類型 LoadOpE 傳遞到存取階段 LoadOpM
  dflop #($bits(LoadOpM), 0) LoadOpM_t (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(LoadOpE),     // 輸入：執行階段的加載操作類型
`ifdef ICARUS
      .q(LoadOpM)      // 輸出：存取階段的加載操作類型 (ICARUS 模式)
`else
      .q({>>{LoadOpM}}) // 輸出：存取階段的加載操作類型 (其他模擬器)
`endif
  );

  // StoreOpM_i：將執行階段的存儲操作類型 StoreOpE 傳遞到存取階段 StoreOpM
  dflop #($bits(StoreOpM), 0) StoreOpM_i (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(StoreOpE),    // 輸入：執行階段的存儲操作類型
`ifdef ICARUS
      .q(StoreOpM)     // 輸出：存取階段的存儲操作類型 (ICARUS 模式)
`else
      .q({>>{StoreOpM}}) // 輸出：存取階段的存儲操作類型 (其他模擬器)
`endif
  );

//////
  // Rd2M_i：將執行階段的第二操作數 Rd2E 傳遞到存取階段 Rd2M
  dflop #(32, 0) Rd2M_i (
      .resetn(resetn), // 同步重設訊號，低電位有效
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號，當管線未暫停時啟用
      .d(Rd2E),        // 輸入：執行階段的第二操作數
      .q(Rd2M)         // 輸出：存取階段的第二操作數
  );

  // RdM_i：將執行階段的目標暫存器索引 RdE 傳遞到存取階段 RdM
  dflop #(5, 0) RdM_i (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(RdE),         // 輸入：執行階段的目標暫存器索引
      .q(RdM)          // 輸出：存取階段的目標暫存器索引
  );

  // PCPlus4M_i：將執行階段的程式計數器加4的結果 PCPlus4E 傳遞到存取階段 PCPlus4M
  dflop #(32, 0) PCPlus4M_i (
      .resetn(resetn), // 同步重設訊號
      .clk(clk),       // 時脈訊號
      .en(!Stall),     // 使能訊號
      .d(PCPlus4E),    // 輸入：執行階段的 PC + 4
      .q(PCPlus4M)     // 輸出：存取階段的 PC + 4
  );

  //PC += imm
  //PC = rs1 + imm
  // 計算新的程式計數器值
  logic [31:0] SrcAE_PCE;
  mux2 #(32) SrcAE_PCE_i (
      .d0(SrcAE),        // 輸入0：SrcAE (rs1 + imm)
      .d1(PCE),          // 輸入1：PCE (PC + imm)
      .s(PCTargetSrcE),  // 選擇訊號：PC 更新來源
      .y(SrcAE_PCE)      // 輸出：選擇的值
  );

  // PC 更新目標地址計算 (SrcAE_PCE + ImmExtE)
  adder #(.WIDTH(32)) pc_target_add_i (
      .a(SrcAE_PCE),     // 輸入：SrcAE_PCE
      .b(ImmExtE),       // 輸入：立即數擴展值
      .y(PCTargetE)      // 輸出：PC 更新目標地址
  );

  // 根據 CSR 操作判斷，選擇 ALU 結果或 CSR 數據
  logic [31:0] AluResultOrCsrDataE;
  mux2 #(32) AluResultOrCsrDataE_i (
      .d0(AluResultE),   // 輸入0：ALU 結果
      .d1(CsrDataE),     // 輸入1：CSR 數據
      .s(isCsrOperation),// 選擇訊號：是否為 CSR 操作
      .y(AluResultOrCsrDataE) // 輸出：選擇的結果
  );

  // 將選擇的 ALU 或 CSR 結果傳遞到存取階段
  dflop #(32, 0) AluResultM_i (
      .resetn(resetn),   // 同步重設訊號
      .clk(clk),         // 時脈訊號
      .en(!Stall),       // 使能訊號
      .d(AluResultOrCsrDataE), // 輸入：ALU 或 CSR 結果
      .q(AluResultM)     // 輸出：存取階段結果
  );

  // 轉發邏輯：ForwardAE_mux_i
  logic [31:0] SrcFWD_AE;
  mux3 #(32) ForwardAE_mux_i (
      .d0(Rd1E),         // 輸入0：Rd1E (操作數 1)
      .d1(ResultW),      // 輸入1：ResultW (寫回結果)
      .d2(AluResultM),   // 輸入2：AluResultM (存取階段結果)
      .s(ForwardAE),     // 選擇訊號：ForwardAE
      .y(SrcFWD_AE)      // 輸出：轉發的操作數 A
  );

  // ALU 第一操作數選擇
  mux2 #(32) srca_mux (
      .d0(SrcFWD_AE),    // 輸入0：轉發操作數 A
      .d1(PCE),          // 輸入1：程式計數器值
      .s(AluSrcAE),      // 選擇訊號：ALU 第一操作數來源
      .y(SrcAE)          // 輸出：ALU 第一操作數
  );

  // 轉發邏輯：ForwardBE_mux_i
  logic [31:0] SrcFWD_BE;
  mux3 #(32) ForwardBE_mux_i (
      .d0(Rd2E),         // 輸入0：Rd2E (操作數 2)
      .d1(ResultW),      // 輸入1：ResultW (寫回結果)
      .d2(AluResultM),   // 輸入2：AluResultM (存取階段結果)
      .s(ForwardBE),     // 選擇訊號：ForwardBE
      .y(SrcFWD_BE)      // 輸出：轉發的操作數 B
  );

  // ALU 第二操作數選擇
  mux2 #(32) srcb_mux (
      .d0(SrcFWD_BE),    // 輸入0：轉發操作數 B
      .d1(ImmExtE),      // 輸入1：立即數擴展值
      .s(AluSrcBE),      // 選擇訊號：ALU 第二操作數來源
      .y(SrcBE)          // 輸出：ALU 第二操作數
  );

  // WriteDataUnAlignedM：處理未對齊的寫入數據
  logic [31:0] WriteDataE;
  
  assign WriteDataE = SrcFWD_BE; // 取自轉發的操作數 B
  dflop #(32, 0) WriteDataUnAlignedM_i (
      .resetn(resetn),   // 同步重設訊號
      .clk(clk),         // 時脈訊號
      .en(!Stall),       // 使能訊號
      .d(WriteDataE),    // 輸入：未對齊的寫入數據
      .q(WriteDataUnAlignedM) // 輸出：存取階段的未對齊數據
  );

`ifdef SIM
  // 模擬環境下，將指令從執行階段傳遞到存取階段
  dflop #(32, `NOP_INSTR) InstrM_i (
      .resetn(resetn),   // 同步重設訊號
      .clk(clk),         // 時脈訊號
      .en(!Stall),       // 使能訊號
      .d(InstrE),        // 輸入：執行階段的指令
      .q(InstrM)         // 輸出：存取階段的指令
  );
`endif

endmodule
