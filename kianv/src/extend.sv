/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  立即數擴展模組 (Immediate Extension Unit)
 *  根據 RISC-V 指令格式，對立即數進行符號擴展或位移處理，生成 32 位元的立即數。
 */
`default_nettype none 
`timescale 1 ns / 100 ps

`include "riscv_defines.svh"
module extend (
    input wire logic [31:7] Instr,     // 指令中的高 25 位元，包含立即數部分
    input wire ImmSrc_t ImmSrc,        // 立即數來源類型，決定擴展方式
    output logic [31:0] ImmExt         // 擴展後的 32 位元立即數
);

  // 根據立即數類型 (ImmSrc) 進行擴展
  always_comb begin
    case (ImmSrc)
      // I 型指令立即數 (e.g., 加法立即數運算 ADDI)
      IMMSRC_I_TYPE: 
        ImmExt = {{20{Instr[31]}}, Instr[31:20]};
        // 符號擴展：取 Instr[31] 作為高 20 位的符號位，擴展至 32 位元
      
      // S 型指令立即數 (e.g., 存儲指令 SW)
      IMMSRC_S_TYPE: 
        ImmExt = {{20{Instr[31]}}, Instr[31:25], Instr[11:7]};
        // S 型立即數由 Instr[31:25] 和 Instr[11:7] 拼接，並符號擴展

      // B 型指令立即數 (e.g., 分支指令 BEQ)
      IMMSRC_B_TYPE: 
        ImmExt = {{20{Instr[31]}}, Instr[7], Instr[30:25], Instr[11:8], 1'b0};
        // B 型立即數拼接順序：
        // Instr[31] 作為符號位，Instr[7] 作為最低位，Instr[30:25] 和 Instr[11:8] 依序拼接，最後補 1 個低位 0

      // J 型指令立即數 (e.g., 跳躍指令 JAL)
      IMMSRC_J_TYPE: 
        ImmExt = {{12{Instr[31]}}, Instr[19:12], Instr[20], Instr[30:21], 1'b0};
        // J 型立即數拼接順序：
        // Instr[31] 作為符號位，Instr[19:12]、Instr[20]、Instr[30:21] 依序拼接，最後補 1 個低位 0

      // U 型指令立即數 (e.g., LUI 和 AUIPC)
      IMMSRC_U_TYPE: 
        ImmExt = {Instr[31:12], 12'b0};
        // U 型立即數直接取 Instr[31:12]，高 20 位與指令對應，低 12 位補零

      // 預設值：無效類型
      default: 
        ImmExt = 32'bx; // 未定義值，用於指示錯誤情況
    endcase
  end
endmodule
