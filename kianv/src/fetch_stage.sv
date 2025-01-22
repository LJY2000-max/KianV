/*
 *  kianv 五階段流水線 RISC-V - 取指階段模組 (Fetch Stage)
 *
 *  版權所有 (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  授權條款允許任何用途的使用、複製、修改和/或分發此軟體，無論是否收費，前提是上述版權聲明和此授權條款需出現在所有副本中。
 *
 *  本軟體按「原樣」提供，作者對此軟體不提供任何形式的保證，包括適銷性和特定用途的隱含保證。
 *  在任何情況下，作者不對因使用本軟體或其效能引起的任何特別的、直接的、間接的或後果性損害或任何損害（包括使用、數據或利潤的損失）負責。
 */

`default_nettype none
`timescale 1 ns / 100 ps
// 禁用某些 lint 警告
// verilog_lint: waive-start explicit-parameter-storage-type
/* verilator lint_off WIDTH */

`include "riscv_defines.svh" // 包含 RISC-V 定義文件

module fetch_stage (
    input wire logic clk,             // 時鐘信號
    input wire logic resetn,          // 重置信號 (低有效)
    input wire logic [31:0] Instr,    // 當前指令
    input wire logic FlushD,          // 清除解碼階段信號
    input wire logic Stall,           // 暫停信號
    input wire logic [31:0] PCF,      // 當前程式計數器 (PC)
    output wire logic [31:0] InstrD,  // 解碼階段的指令
    output wire logic [31:0] PCPlus4F,// 當前階段的 PC + 4
    output wire logic [31:0] PCPlus4D,// 解碼階段的 PC + 4
    output wire logic [31:0] PCD      // 解碼階段的 PC 值
);

  // 用於處理重置與清除信號的結合邏輯
  logic FlushD_resetn;
  assign FlushD_resetn = resetn & !FlushD; // 當清除信號有效時，強制模組進行重置

  // 解碼階段指令暫存器
  dflop #(32, `NOP_INSTR) InstrD_i (
      .resetn(FlushD_resetn), // 使用清除邏輯處理重置
      .clk(clk),              // 時鐘信號
      .en(!Stall),            // 當未暫停時更新
      .d(Instr),              // 當前指令輸入
      .q(InstrD)              // 解碼階段的指令輸出
  );

  // 計算 PC + 4 的加法器
  adder #(
      .WIDTH(32) // 加法器的數據寬度為 32 位
  ) pc_plus4f_i (
      .a(PCF),       // 當前程式計數器值
      .b(32'd4),     // 加 4
      .y(PCPlus4F)   // 輸出 PC + 4
  );

  // 解碼階段的 PC + 4 暫存器
  dflop #(32, 0) PCPlus4D_i (
      .resetn(FlushD_resetn), // 使用清除邏輯處理重置
      .clk(clk),              // 時鐘信號
      .en(!Stall),            // 當未暫停時更新
      .d(PCPlus4F),           // 當前階段的 PC + 4
      .q(PCPlus4D)            // 解碼階段的 PC + 4 輸出
  );

  // 解碼階段的 PC 值暫存器
  dflop #(32, 0) PCD_i (
      .resetn(FlushD_resetn), // 使用清除邏輯處理重置
      .clk(clk),              // 時鐘信號
      .en(!Stall),            // 當未暫停時更新
      .d(PCF),                // 當前程式計數器值
      .q(PCD)                 // 解碼階段的 PC 值輸出
  );

endmodule
/* verilator lint_on WIDTH */
// verilog_lint: waive-stop explicit-parameter-storage-type
