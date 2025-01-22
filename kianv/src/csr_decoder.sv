/*
 *  kianv 五階段流水線 RISC-V CSR 解碼器 (CSR Decoder)
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

module csr_decoder (
    input wire logic [2:0] funct3D, // 指令的 funct3 欄位，用於識別 CSR 指令類型
    output CsrOp_t CsrOpD           // CSR 操作類型的輸出信號
);

  // 定義 CSRRS 操作的邏輯信號
  logic is_csrrs;

  // 判斷 funct3 是否為 3'b010，對應 CSRRS 操作
  assign is_csrrs = funct3D == 3'b010;

  // 根據指令類型設定 CSR 操作信號
  always_comb begin
    case (1'b1)
      is_csrrs: CsrOpD = CSR_OP_CSRRS; // CSRRS 操作
      default:  CsrOpD = CSR_OP_NA;   // 預設為無操作 (NA)
    endcase
  end

endmodule
