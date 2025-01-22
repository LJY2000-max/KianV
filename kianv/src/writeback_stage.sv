/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  寫回階段 (Writeback Stage) 模組
 *  負責處理從記憶體讀取的數據對齊，並將對齊結果提供給寫回階段。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
// verilog_lint: waive-start explicit-parameter-storage-type
/* verilator lint_off WIDTH */
`include "riscv_defines.svh"

module writeback_stage (
    /* verilator lint_off UNUSEDSIGNAL */ //我新增
    input wire logic [31:0] AluResultW,     // ALU 計算結果的低兩位，用於尋址和數據對齊
    /* verilator lint_on UNUSEDSIGNAL */ //我新增
    input wire LoadOp_t LoadOpW,          // 加載操作類型 (寫回階段)
    input wire logic [31:0] ReadDataW,    // 從記憶體讀取的原始數據
    output wire logic [31:0] ReadDataAlignedW // 對齊後的數據 (寫回階段)
);

  // 加載數據對齊處理模組
  load_alignment load_alignment_i (
      .addr  (AluResultW[1:0]),          // 地址的低兩位，用於確定數據對齊方式
      .LoadOp(LoadOpW),                 // 加載操作類型，用於選擇對齊策略
      .data  (ReadDataW),               // 輸入：從記憶體讀取的原始數據
      .result(ReadDataAlignedW)         // 輸出：對齊後的數據
  );

endmodule
/* verilator lint_on WIDTH */
// verilog_lint: waive-stop explicit-parameter-storage-type
