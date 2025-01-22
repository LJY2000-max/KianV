/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  暫存器檔案模組 (Register File Module)
 *  實現 32 個 32 位元的暫存器檔案，支援兩個讀取埠和一個寫入埠。
 */
`default_nettype none 
`timescale 1 ns / 100 ps

module register_file32 #(
    parameter REGISTER_DEPTH = 32,  // 暫存器深度：rv32e = 16, rv32i = 32
    parameter CLEAR_REGISTER_FILE = 0 // 是否初始化清除暫存器
) (
    input  wire logic        clk,   // 時脈訊號
    input  wire logic        we,    // 寫入使能訊號
    input  wire logic [ 4:0] A1,    // 第一讀取埠地址
    input  wire logic [ 4:0] A2,    // 第二讀取埠地址
    input  wire logic [ 4:0] A3,    // 寫入埠地址
    input  wire logic [31:0] wd,    // 寫入數據
    output wire logic [31:0] Rd1,   // 第一讀取埠數據
    output wire logic [31:0] Rd2    // 第二讀取埠數據
);

  // 定義暫存器檔案：REGISTER_DEPTH 個 32 位元暫存器
  logic [31:0] bank[0:REGISTER_DEPTH -1];

  // 初始化階段，根據參數選擇是否清除暫存器檔案
  initial begin
    if (CLEAR_REGISTER_FILE) begin
      for (int i = 0; i < $size(bank); i = i + 1) begin
        bank[i] = 32'd0; // 將所有暫存器初始化為 0
        $display("cleared register file\n"); // 打印訊息，用於模擬檢查
      end
    end
  end

  // 寫入操作：在正緣時寫入資料到指定暫存器
  always_ff @(posedge clk) begin
    if (we && A3 != 0) begin // 寫入使能且目標暫存器非零 (x0 永遠為零)
      bank[A3] <= wd;        // 將數據 wd 寫入地址 A3 指定的暫存器
    end
  end

  // 讀取操作：非同步讀取指定地址的暫存器數據
  assign Rd1 = A1 != 0 ? bank[A1] : 32'b0; // 第一讀取埠，x0 永遠返回 0
  assign Rd2 = A2 != 0 ? bank[A2] : 32'b0; // 第二讀取埠，x0 永遠返回 0

endmodule
