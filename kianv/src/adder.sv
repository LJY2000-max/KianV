/*
 *  kianv 五階段流水線 RISC-V - 加法器模組 (Adder)
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

module adder #(
    parameter WIDTH = 32 // 加法器數據寬度參數，默認為 32 位
) (
    input  wire logic [WIDTH-1:0] a, // 第一輸入操作數
    input  wire logic [WIDTH-1:0] b, // 第二輸入操作數
    output wire logic [WIDTH-1:0] y  // 加法結果輸出
);
  // 加法運算，將兩個輸入相加並輸出
  assign y = a + b;
endmodule

// 禁用某些 lint 警告
// verilog_lint: waive-stop explicit-parameter-storage-type
