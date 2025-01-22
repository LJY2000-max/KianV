/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  記憶體階段 (Memory Stage) 模組
 *  負責處理存取記憶體的操作，例如加載和存儲數據，並準備數據給下一階段 (寫回階段)。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
// verilog_lint: waive-start explicit-parameter-storage-type
/* verilator lint_off WIDTH */
`include "riscv_defines.svh"

module memory_stage (
    input wire logic clk,                  // 時脈訊號
    input wire logic resetn,              // 同步重設訊號，低電位有效
    input wire logic Stall,               // 管線暫停訊號
    input wire logic RegWriteM,           // 註冊寫入控制訊號 (存取階段)
    input wire ResultSrc_t ResultSrcM,    // 結果來源控制訊號 (存取階段)
    input wire LoadOp_t LoadOpM,          // 加載操作類型 (存取階段)
    input wire StoreOp_t StoreOpM,        // 存儲操作類型 (存取階段)
    input wire logic [4:0] RdM,           // 目標暫存器索引 (存取階段)
    input wire logic [31:0] AluResultM,   // ALU 計算結果 (存取階段)
    input wire logic [31:0] WriteDataUnAlignedM, // 未對齊的寫入數據
    input wire logic [31:0] PCPlus4M,     // 程式計數器加4的結果 (存取階段)
    input wire logic [31:0] ReadDataM,    // 從記憶體讀取的數據
    output wire logic [31:0] WriteDataM,  // 對齊後的寫入數據
    output wire logic RegWriteW,          // 註冊寫入控制訊號 (寫回階段)
    output wire ResultSrc_t ResultSrcW,   // 結果來源控制訊號 (寫回階段)
    output wire LoadOp_t LoadOpW,         // 加載操作類型 (寫回階段)
    output wire logic [4:0] RdW,          // 目標暫存器索引 (寫回階段)
    output wire logic [31:0] AluResultW,  // ALU 計算結果 (寫回階段)
    output wire logic [3:0] wmask,        // 記憶體寫入掩碼
    output wire logic [31:0] PCPlus4W,    // 程式計數器加4的結果 (寫回階段)
`ifndef SIM
    output wire logic [31:0] ReadDataW    // 從記憶體讀取的數據 (寫回階段)
`else
    output wire logic [31:0] ReadDataW,   // 從記憶體讀取的數據 (寫回階段)
    input wire logic [31:0] InstrM,       // 指令碼 (存取階段)
    output wire logic [31:0] InstrW       // 指令碼 (寫回階段)
`endif
);

  // 將存取階段的註冊寫入控制訊號傳遞到寫回階段
  dflop #(1, 0) RegWriteW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(RegWriteM),
      .q(RegWriteW)
  );

  // 將存取階段的結果來源控制訊號傳遞到寫回階段
  dflop #($bits(ResultSrcW), 0) ResultSrcW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(ResultSrcM),
`ifdef ICARUS
      .q(ResultSrcW)         // 適用 ICARUS 模擬器
`else
      .q({>>{ResultSrcW}})   // 其他模擬器的位寬處理
`endif
  );

  // 將存取階段的加載操作類型傳遞到寫回階段
  dflop #($bits(LoadOpW), 0) LoadOpW_t (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(LoadOpM),
`ifdef ICARUS
      .q(LoadOpW)            // 適用 ICARUS 模擬器
`else
      .q({>>{LoadOpW}})      // 其他模擬器的位寬處理
`endif
  );

  // 將存取階段的目標暫存器索引傳遞到寫回階段
  dflop #(5, 0) RdW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(RdM),
      .q(RdW)
  );

  // 將存取階段的 ALU 計算結果傳遞到寫回階段
  dflop #(32, 0) AluResultW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(AluResultM),
      .q(AluResultW)
  );

  // 存儲數據對齊處理模組
  store_alignment store_alignment_i (
      .addr(AluResultM[1:0]),            // 地址的低兩位，用於對齊處理
      .StoreOp(StoreOpM),                // 存儲操作類型
      .data(WriteDataUnAlignedM),        // 未對齊的存儲數據
      .result(WriteDataM),               // 對齊後的存儲數據
      .wmask(wmask)                      // 寫入掩碼
  );

  // 將存取階段的程式計數器加4結果傳遞到寫回階段
  dflop #(32, 0) PCPlus4W_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(PCPlus4M),
      .q(PCPlus4W)
  );

  // 將從記憶體讀取的數據傳遞到寫回階段
  dflop #(32, 0) ReadDataW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(ReadDataM),
      .q(ReadDataW)
  );

`ifdef SIM
  // 模擬環境下，將指令從存取階段傳遞到寫回階段
  dflop #(32, `NOP_INSTR) InstrW_i (
      .resetn(resetn),
      .clk(clk),
      .en(!Stall),
      .d(InstrM),
      .q(InstrW)
  );
`endif

  /* verilator lint_on WIDTH */
  // verilog_lint: waive-stop explicit-parameter-storage-type
endmodule
