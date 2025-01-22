/*
 *  kianv 五階段流水線 RISC-V 存儲解碼器 (Store Decoder)
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

module store_decoder (
    /* verilator lint_off UNUSEDSIGNAL */ //我新增
    input wire logic [2:0] funct3D, // 指令的 funct3 欄位，用於表示存儲類型
    /* verilator lint_on UNUSEDSIGNAL */ //我新增
    output StoreOp_t StoreOpD       // 存儲操作類型的輸出信號
);

  // 定義存儲指令類型的邏輯信號
  logic is_sb; // 負責存儲位元組 (SB)
  logic is_sh; // 負責存儲半字 (SH)
  logic is_sw; // 負責存儲字 (SW)

  // 根據 funct3 的低兩位判斷存儲類型
  assign is_sb = funct3D[1:0] == 2'b00; // SB: 存儲位元組
  assign is_sh = funct3D[1:0] == 2'b01; // SH: 存儲半字
  assign is_sw = funct3D[1:0] == 2'b10; // SW: 存儲字

  // 根據判斷的類型設置存儲操作信號
  always_comb begin
    case (1'b1)
      is_sb: StoreOpD = STORE_OP_SB; // 存儲位元組操作
      is_sh: StoreOpD = STORE_OP_SH; // 存儲半字操作
      is_sw: StoreOpD = STORE_OP_SW; // 存儲字操作
      default: begin
        /* verilator lint_off WIDTH */ // 禁用與位寬相關的 lint 警告
        StoreOpD = STORE_OP_SB;        // 預設為存儲位元組操作
        /* verilator lint_on WIDTH */  // 重新啟用位寬相關的 lint 警告
      end
    endcase
  end

endmodule
