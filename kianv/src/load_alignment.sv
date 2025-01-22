/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  加載數據對齊模組 (Load Alignment Module)
 *  根據加載操作類型 (LoadOp) 和地址 (addr) 的低位，將從記憶體讀取的數據進行對齊處理，並返回對齊後的數據。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
`include "riscv_defines.svh"

module load_alignment (
    input  wire logic    [ 1:0] addr,    // 地址的低兩位，用於確定數據對齊方式
    input  wire LoadOp_t        LoadOp, // 加載操作類型，例如字節、半字或字
    input  wire logic    [31:0] data,   // 從記憶體讀取的原始數據
    output logic         [31:0] result  // 對齊後的數據
);

  // 加載操作類型的判斷信號
  logic is_lb;   // 負號擴展的字節加載
  logic is_lbu;  // 無符號字節加載
  logic is_lh;   // 負號擴展的半字加載
  logic is_lhu;  // 無符號半字加載
  logic is_lw;   // 字加載

  // 判斷 LoadOp 是否對應特定的加載操作
  assign is_lb  = LOAD_OP_LB == LoadOp;   // 判斷是否為 LB 操作
  assign is_lbu = LOAD_OP_LBU == LoadOp;  // 判斷是否為 LBU 操作
  assign is_lh  = LOAD_OP_LH == LoadOp;   // 判斷是否為 LH 操作
  assign is_lhu = LOAD_OP_LHU == LoadOp;  // 判斷是否為 LHU 操作
  assign is_lw  = LOAD_OP_LW == LoadOp;   // 判斷是否為 LW 操作

  // 數據對齊處理邏輯
  always_comb begin
    result = 'hx; // 預設為未定義值，避免合成警告

    // 字節加載處理 (LB 或 LBU)
    if (is_lb | is_lbu) begin
      result[7:0] = 
                  addr[1:0] == 2'b00 ? data[7  :0]  : // 地址低兩位為 00，取低字節
                  addr[1:0] == 2'b01 ? data[15 :8]  : // 地址低兩位為 01，取次低字節
                  addr[1:0] == 2'b10 ? data[23:16] : // 地址低兩位為 10，取次高字節
                  addr[1:0] == 2'b11 ? data[31:24] : // 地址低兩位為 11，取高字節
                  8'hx;                             // 無效地址
      result = {is_lbu ? 24'b0 : {24{result[7]}}, result[7:0]}; // 無符號加載補零，符號加載進行符號擴展
    end

    // 半字加載處理 (LH 或 LHU)
    if (is_lh | is_lhu) begin
      result[15:0] = 
                  ~addr[1] ? data[15:0]  : // 地址第 1 位為 0，取低半字
                  addr[1]  ? data[31:16] : // 地址第 1 位為 1，取高半字
                  16'hx;                  // 無效地址
      result = {is_lhu ? 16'b0 : {16{result[15]}}, result[15:0]}; // 無符號加載補零，符號加載進行符號擴展
    end

    // 字加載處理 (LW)
    if (is_lw) result = data; // 直接將整個字返回
  end

endmodule
