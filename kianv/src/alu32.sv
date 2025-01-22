/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  32位元算術邏輯單元 (ALU) 模組
 *  提供 RISC-V 指令集中所需的算術與邏輯運算。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
`include "riscv_defines.svh"

module alu32 (
    input  wire logic        [31:0] a,           // ALU 第一操作數
    input  wire logic        [31:0] b,           // ALU 第二操作數
    input  wire AluControl_t        AluControl,  // ALU 控制訊號，決定運算類型
    output logic             [31:0] result,      // ALU 運算結果
    output wire logic               zero         // 結果為零的訊號
);

  // 中間信號宣告
  logic [31:0] sltx_sltux_rslt; // SLT/SLTU 比較結果
  logic [63:0] sext_rs1;        // 用於 SRA/SRAI 的符號擴展結果
  /* verilator lint_off UNUSEDSIGNAL */ //我新增
  logic [63:0] sra_srai_rslt;   // SRA/SRAI 運算結果
  /* verilator lint_on UNUSEDSIGNAL */ //我新增
  logic        is_sub;          // SUB 指令的判斷信號
  logic [31:0] condinv;         // 取反條件操作數
  logic [31:0] sum;             // 加減法結果

  // 比較運算：SLT/SLTU 的結果 (無符號比較)
  assign sltx_sltux_rslt = {31'b0, a < b};

  // 符號擴展：將操作數 `a` 擴展至 64 位元，用於 SRA/SRAI
  assign sext_rs1 = {{32{a[31]}}, a};

  // 算術右移 (SRA/SRAI)
  assign sra_srai_rslt = sext_rs1 >> b[4:0];

  // 判斷是否為減法操作
  assign is_sub = AluControl == ALU_CTRL_SUB;

  // 根據是否為減法操作選擇是否對 `b` 取反
  assign condinv = is_sub ? ~b : b;

  // 加法運算：根據條件進行加法或減法
  assign sum = a + (condinv + {30'b0, is_sub});

  // 運算邏輯：根據 AluControl 決定 ALU 運算類型
  always_comb begin
    case (AluControl)
      ALU_CTRL_ADD_ADDI:   result = sum;                   // 加法
      ALU_CTRL_SUB:        result = sum;                   // 減法
      ALU_CTRL_XOR_XORI:   result = a ^ b;                 // XOR
      ALU_CTRL_OR_ORI:     result = a | b;                 // OR
      ALU_CTRL_AND_ANDI:   result = a & b;                 // AND
      ALU_CTRL_SLL_SLLI:   result = a << b[4:0];           // 左移
      ALU_CTRL_SRL_SRLI:   result = a >> b[4:0];           // 邏輯右移
      ALU_CTRL_SRA_SRAI:   result = sra_srai_rslt[31:0];   // 算術右移
      ALU_CTRL_SLT_SLTI:   result = (a[31] == b[31]) ? sltx_sltux_rslt : {31'b0, a[31]}; // SLT
      ALU_CTRL_SLTU_SLTIU: result = sltx_sltux_rslt;       // SLTU
      ALU_CTRL_LUI:        result = b;                     // LUI
      ALU_CTRL_AUIPC:      result = sum;                   // AUIPC
      ALU_CTRL_BEQ:        result = {31'b0, a == b};       // BEQ
      ALU_CTRL_BNE:        result = {31'b0, a != b};       // BNE
      ALU_CTRL_BLT:        result = {31'b0, (a < b) ^ (a[31] != b[31])}; // BLT
      ALU_CTRL_BGE:        result = {31'b0, (a >= b) ^ (a[31] != b[31])}; // BGE
      ALU_CTRL_BLTU:       result = {31'b0, a < b};        // BLTU
      ALU_CTRL_BGEU:       result = {31'b0, a >= b};       // BGEU
      default:             result = 32'b0;                 // 預設值
    endcase
  end

  // 判斷結果是否為零
  assign zero = result == 32'b0;

endmodule
