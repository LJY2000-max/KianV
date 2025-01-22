/*
 *  kianv 五階段流水線 RISC-V 加載解碼器 (Load Decoder)
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

module load_decoder (
    input wire [2:0] funct3D,       // 指令的 funct3 欄位，用於表示加載類型
    output LoadOp_t LoadOpD         // 加載操作類型的輸出信號
);

  // 定義加載指令類型的邏輯信號
  logic is_lb;   // 負責加載符號位元組 (LB)
  logic is_lh;   // 負責加載符號半字 (LH)
  logic is_lw;   // 負責加載符號字 (LW)
  logic is_lbu;  // 負責加載無符號位元組 (LBU)
  logic is_lhu;  // 負責加載無符號半字 (LHU)

  // 比對 funct3 欄位，判斷當前是何種加載類型
  assign is_lb  = funct3D == 3'b000; // 位元組 (有符號)
  assign is_lh  = funct3D == 3'b001; // 半字 (有符號)
  assign is_lw  = funct3D == 3'b010; // 字 (有符號)
  assign is_lbu = funct3D == 3'b100; // 位元組 (無符號)
  assign is_lhu = funct3D == 3'b101; // 半字 (無符號)

  // 根據指令類型設定加載操作類型信號
  always_comb begin
    case (1'b1)
      is_lb:  LoadOpD = LOAD_OP_LB;   // 加載符號位元組
      is_lh:  LoadOpD = LOAD_OP_LH;   // 加載符號半字
      is_lw:  LoadOpD = LOAD_OP_LW;   // 加載符號字
      is_lbu: LoadOpD = LOAD_OP_LBU;  // 加載無符號位元組
      is_lhu: LoadOpD = LOAD_OP_LHU;  // 加載無符號半字
      default: begin
        /* verilator lint_off WIDTH */ // 禁用與位寬相關的 lint 警告
        LoadOpD = LOAD_OP_LB;          // 預設為加載符號位元組
        /* verilator lint_on WIDTH */  // 重新啟用位寬相關的 lint 警告
      end
    endcase
  end

endmodule
