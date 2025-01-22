/*
 *  kianv 五階段流水線 RISC-V ALU 解碼器
 *
 *  版權所有 (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  授權條款允許任何用途的使用、複製、修改和/或分發此軟體，無論是否收費，前提是上述版權聲明和此授權條款需出現在所有副本中。
 *
 *  本軟體按「原樣」提供，作者對此軟體不提供任何形式的保證，包括適銷性和特定用途的隱含保證。
 *  在任何情況下，作者不對因使用本軟體或其效能引起的任何特別的、直接的、間接的或後果性損害或任何損害（包括使用、數據或利潤的損失）負責。
 *
 */

`default_nettype none
`timescale 1 ns / 100 ps

`include "riscv_defines.svh" // 包含 RISC-V 定義文件

module alu_decoder (
    input  wire logic         imm_bit10,      // 立即數的第 10 位
    input  wire               op_bit5,        // 操作碼的第 5 位
    input  wire logic   [2:0] funct3D,        // funct3 欄位
    input  wire logic         funct7bit5D,    // funct7 的第 5 位
    input  wire AluOp_t       AluOp,          // ALU 操作碼
    output AluControl_t       AluControlD     // ALU 控制信號
);

  // 判斷 R 型指令是否為減法
  logic is_rtype_sub;
  // 判斷是否為右移 (SRL/SRLI) 指令
  logic is_srl_srli;

  assign is_rtype_sub = op_bit5 & funct7bit5D; // 當操作碼的第 5 位與 funct7 的第 5 位皆為 1 時為減法
  assign is_srl_srli  = (op_bit5 && !funct7bit5D) || (!op_bit5 && !imm_bit10); // 根據操作碼和立即數判斷右移類型

  // ALU 控制信號生成邏輯
  always_comb begin
    case (AluOp)
      // 加法操作
      ALU_OP_ADD:   AluControlD = ALU_CTRL_ADD_ADDI;
      // 減法操作
      ALU_OP_SUB:   AluControlD = ALU_CTRL_SUB;
      // 加立即數至程式計數器 (AUIPC)
      ALU_OP_AUIPC: AluControlD = ALU_CTRL_AUIPC;
      // 加載高立即數 (LUI)
      ALU_OP_LUI:   AluControlD = ALU_CTRL_LUI;
      // 分支操作
      ALU_OP_BRANCH: begin
        case (funct3D)
          3'b000: AluControlD = ALU_CTRL_BEQ;    // BEQ: 分支等於
          3'b001: AluControlD = ALU_CTRL_BNE;    // BNE: 分支不等
          3'b100: AluControlD = ALU_CTRL_BLT;    // BLT: 分支小於
          3'b101: AluControlD = ALU_CTRL_BGE;    // BGE: 分支大於等於
          3'b110: AluControlD = ALU_CTRL_BLTU;   // BLTU: 無符號分支小於
          3'b111: AluControlD = ALU_CTRL_BGEU;   // BGEU: 無符號分支大於等於
          default: begin
            /* verilator lint_off WIDTH */
            AluControlD = ALU_CTRL_ADD_ADDI; // 預設為加法
            /* verilator lint_on WIDTH */
          end
        endcase
      end
      // 算術與邏輯操作
      ALU_OP_ARITH_LOGIC: begin
        case (funct3D)
          3'b000: AluControlD = AluControl_t'(is_rtype_sub ? ALU_CTRL_SUB : ALU_CTRL_ADD_ADDI); // 加法或減法
          3'b100: AluControlD = ALU_CTRL_XOR_XORI;  // XOR 或 XORI
          3'b110: AluControlD = ALU_CTRL_OR_ORI;    // OR 或 ORI
          3'b111: AluControlD = ALU_CTRL_AND_ANDI;  // AND 或 ANDI
          3'b010: AluControlD = ALU_CTRL_SLT_SLTI;  // 小於比較
          3'b001: AluControlD = ALU_CTRL_SLL_SLLI;  // 左移
          3'b011: AluControlD = ALU_CTRL_SLTU_SLTIU; // 無符號小於比較
          3'b101: AluControlD = AluControl_t'(is_srl_srli ? ALU_CTRL_SRL_SRLI : ALU_CTRL_SRA_SRAI); // 右移類型判斷 (SRL 或 SRA)
          default: begin
            /* verilator lint_off WIDTH */
            AluControlD = ALU_CTRL_ADD_ADDI; // 預設為加法
            /* verilator lint_on WIDTH */
          end
        endcase
      end
      default: begin
        /* verilator lint_off WIDTH */
        AluControlD = ALU_CTRL_ADD_ADDI; // 預設為加法
        /* verilator lint_on WIDTH */
      end
    endcase
  end

endmodule
