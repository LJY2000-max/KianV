/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  CSR 單元 (Control and Status Registers Unit)
 *  負責處理 CSR 寄存器的讀取操作，包括指令計數、週期計數和時間寄存器等。
 */
`default_nettype none 
`timescale 1 ns / 100 ps

`include "riscv_defines.svh"
`include "design_elements.sv"
module csr_unit (
    input  wire logic          clk,                 // 時脈訊號
    input  wire logic          resetn,              // 同步重設訊號，低電位有效
    input  wire logic          IncInstructionCycle, // 指令計數器增量信號
    input  wire logic   [11:0] ImmExt,              // CSR 指令的立即數 (CSR 地址)
    input  wire CsrOp_t        CsrOp,               // CSR 操作類型
    output logic        [31:0] rdata                // CSR 讀取數據
);

  // 定義 CSR 寄存器：週期計數器和指令計數器
  logic [63:0] cycle_counter; // 週期計數器
  logic [63:0] instr_counter; // 指令計數器

  // 指令計數器模組
  counter #(64) instr_cnt_i (
      .resetn(resetn),                  // 同步重設訊號
      .clk(clk),                        // 時脈訊號
      .inc(IncInstructionCycle),        // 指令計數器增量信號
      .q(instr_counter)                 // 輸出：指令計數器值
  );

  // 週期計數器模組
  counter #(64) cycle_cnt_i (
      .resetn(resetn),                  // 同步重設訊號
      .clk(clk),                        // 時脈訊號
      .inc(1'b1),                       // 每個時脈週期增量 1
      .q(cycle_counter)                 // 輸出：週期計數器值
  );

  // CSR 解碼相關信號
  CsrRegs_t csr_register;               // CSR 寄存器選擇
  logic     decode_csrs;                // CSR 解碼啟用信號
  logic     is_rdcycle;                 // 是否讀取 rdcycle
  logic     is_rdcycleh;                // 是否讀取 rdcycleh
  logic     is_instret;                 // 是否讀取 instret
  logic     is_instreth;                // 是否讀取 instreth
  logic     is_time;                    // 是否讀取 time
  logic     is_timeh;                   // 是否讀取 timeh

  // 將立即數解碼為 CSR 寄存器地址
  assign csr_register = CsrRegs_t'(ImmExt);

  // CSR 操作解碼
  assign decode_csrs = CsrOp == CSR_OP_CSRRS; // 判斷是否為 CSR 讀取操作
  assign is_rdcycle = decode_csrs & (csr_register == CSR_REG_CYCLE);   // 判斷是否讀取 rdcycle
  assign is_rdcycleh = decode_csrs & (csr_register == CSR_REG_CYCLEH); // 判斷是否讀取 rdcycleh

  assign is_instret = decode_csrs & (csr_register == CSR_REG_INSTRET);   // 判斷是否讀取 instret
  assign is_instreth = decode_csrs & (csr_register == CSR_REG_INSTRETH); // 判斷是否讀取 instreth

  assign is_time = decode_csrs & (csr_register == CSR_REG_TIME);   // 判斷是否讀取 time
  assign is_timeh = decode_csrs & (csr_register == CSR_REG_TIMEH); // 判斷是否讀取 timeh

  // 根據 CSR 地址選擇返回數據
  always_comb begin
    case (1'b1)
      is_instret:  rdata = instr_counter[31:0];   // 低 32 位指令計數
      is_instreth: rdata = instr_counter[63:32];  // 高 32 位指令計數
      is_rdcycle:  rdata = cycle_counter[31:0];   // 低 32 位週期計數
      is_rdcycleh: rdata = cycle_counter[63:32];  // 高 32 位週期計數
      is_time:     rdata = cycle_counter[31:0];   // 低 32 位時間計數 (暫用週期計數替代)
      is_timeh:    rdata = cycle_counter[63:32];  // 高 32 位時間計數 (暫用週期計數替代)
      default:     rdata = 32'hx;                 // 預設為未定義值
    endcase
  end

endmodule
