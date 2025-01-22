/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  通用多工器與基礎元件模組
 *  提供靈活的數據選擇 (mux) 和同步邏輯單元 (dflop, counter)。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
/* verilator lint_off MULTITOP */
// verilog_lint: waive-start explicit-parameter-storage-type
// verilog_lint: waive-start module-filename
/* verilator lint_off DECLFILENAME */

module mux2 #(
    parameter WIDTH = 32 // 資料寬度
) (
    input  wire logic [WIDTH -1:0] d0,  // 輸入數據 0
    input  wire logic [WIDTH -1:0] d1,  // 輸入數據 1
    input  wire logic              s,   // 選擇訊號
    output wire logic [WIDTH -1:0] y    // 輸出數據
);
  // 根據選擇訊號 s 選擇 d0 或 d1
  assign y = s ? d1 : d0;
endmodule

module mux3 #(
    parameter WIDTH = 32 // 資料寬度
) (
    input  wire logic [WIDTH -1:0] d0,  // 輸入數據 0
    input  wire logic [WIDTH -1:0] d1,  // 輸入數據 1
    input  wire logic [WIDTH -1:0] d2,  // 輸入數據 2
    input  wire logic [       1:0] s,   // 2 位選擇訊號
    output wire logic [WIDTH -1:0] y    // 輸出數據
);
  // 根據選擇訊號 s 選擇 d0, d1 或 d2
  assign y = s[1] ? d2 : (s[0] ? d1 : d0);
endmodule

module mux4 #(
    parameter WIDTH = 32 // 資料寬度
) (
    input  wire logic [WIDTH -1:0] d0,  // 輸入數據 0
    input  wire logic [WIDTH -1:0] d1,  // 輸入數據 1
    input  wire logic [WIDTH -1:0] d2,  // 輸入數據 2
    input  wire logic [WIDTH -1:0] d3,  // 輸入數據 3
    input  wire logic [       1:0] s,   // 2 位選擇訊號
    output wire logic [WIDTH -1:0] y    // 輸出數據
);
  // 使用兩級 mux2 模組組合成 mux4
  logic [WIDTH -1:0] low, high;

  mux2 #(.WIDTH(WIDTH)) lowmux (
      .d0(d0),
      .d1(d1),
      .s (s[0]),
      .y (low)
  );

  mux2 #(.WIDTH(WIDTH)) highmux (
      .d0(d2),
      .d1(d3),
      .s (s[0]),
      .y (high)
  );

  mux2 #(.WIDTH(WIDTH)) finalmux (
      .d0(low),
      .d1(high),
      .s (s[1]),
      .y (y)
  );
endmodule

module mux5 #(
    parameter WIDTH = 32 // 資料寬度
) (
    input  wire logic [WIDTH -1:0] d0,  // 輸入數據 0
    input  wire logic [WIDTH -1:0] d1,  // 輸入數據 1
    input  wire logic [WIDTH -1:0] d2,  // 輸入數據 2
    input  wire logic [WIDTH -1:0] d3,  // 輸入數據 3
    input  wire logic [WIDTH -1:0] d4,  // 輸入數據 4
    input  wire logic [       2:0] s,   // 3 位選擇訊號
    output wire logic [WIDTH -1:0] y    // 輸出數據
);
  // 根據選擇訊號 s 選擇 d0 至 d4
  assign y = (s == 0) ? d0 : 
             (s == 1) ? d1 : 
             (s == 2) ? d2 : 
             (s == 3) ? d3 : d4;
endmodule

module dflop #(
    parameter WIDTH  = 32, // 資料寬度
    parameter PRESET = 0   // 預設值
) (
    input wire logic resetn,              // 同步重設訊號
    input wire logic clk,                 // 時脈訊號
    input wire logic en,                  // 使能訊號
    input wire logic [WIDTH -1:0] d,      // 輸入數據
    output logic [WIDTH -1:0] q           // 輸出數據
);
  // 正緣觸發的同步觸發器
  always_ff @(posedge clk)
    if (!resetn) q <= PRESET;             // 重設時將輸出設為預設值
    else if (en) q <= d;                  // 啟用時更新數據
endmodule

module counter #(
    parameter WIDTH = 32 // 計數器寬度
) (
    input wire logic resetn,              // 同步重設訊號
    input wire logic clk,                 // 時脈訊號
    input wire logic inc,                 // 計數增量信號
    output logic [WIDTH -1:0] q           // 計數器值
);
  // 正緣觸發的計數器
  always_ff @(posedge clk)
    if (!resetn) q <= 0;                  // 重設時歸零
    else if (inc) q <= q + 1;             // 增量操作
endmodule

/* verilator lint_on MULTITOP */
/* verilator lint_on DECLFILENAME */
// verilog_lint: waive-stop explicit-parameter-storage-type
// verilog_lint: waive-stop module-filename
