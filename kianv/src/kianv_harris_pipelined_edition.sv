/*
 *  kianv 五階段流水線 RISC-V 處理器
 *
 *  版權所有 (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  授權條款允許任何用途的使用、複製、修改和/或分發此軟體，無論是否收費，前提是上述版權聲明和此授權條款需出現在所有副本中。
 *
 *  本軟體按「原樣」提供，作者對此軟體不提供任何形式的保證，包括適銷性和特定用途的隱含保證。
 *  在任何情況下，作者不對因使用本軟體或其效能引起的任何特別的、直接的、間接的或後果性損害或任何損害（包括使用、數據或利潤的損失）負責。
 *
 */
`default_nettype none `timescale 1 ns / 100 ps
`include "riscv_defines.svh"
// 禁用 Verilog 的某些 lint 檢查
// verilog_lint: waive-start explicit-parameter-storage-type
module kianv_harris_pipelined_edition #(
    parameter RESET_ADDR = 0 // 設定初始程式計數器的地址
) (
    input wire logic clk,                // 時鐘信號
    input wire logic resetn,             // 重置信號 (低有效)
    input wire logic halt,               // 停止信號
    input wire logic [31:0] Instr,       // 輸入的指令
    input wire logic [31:0] ReadDataM,   // 從記憶體讀取的數據
    output wire logic [31:0] PCF,        // 程式計數器輸出
    output wire logic [3:0] WriteMaskM,  // 記憶體寫入掩碼
    output wire logic ReadMemM,          // 記憶體讀取信號
    output wire logic [31:0] AluResultM, // ALU 計算結果
    output wire logic [31:0] WriteDataM // 寫入記憶體的數據
    
);

  // 定義控制信號和暫存器
  logic [6:0] opD;         // 操作碼
  logic [2:0] funct3D;     // funct3 欄位
  logic [0:0] funct7b5D;   // funct7 第 5 位 (R 型指令)
  logic [0:0] funct7b1D;   // funct7 第 1 位 (R 型指令)
  logic [0:0] immb10D;     // 立即數 (第 10 位)

  // 定義管線控制訊號
  ResultSrc_t ResultSrcD;        // 結果來源
  AluControl_t AluControlD;      // ALU 控制信號
  AluSrcA_t AluSrcAD;            // ALU 第一個操作數來源
  AluSrcB_t AluSrcBD;            // ALU 第二個操作數來源
  ImmSrc_t ImmSrcD;              // 立即數來源
  PCTargetSrc_t PCTargetSrcD;    // 程式計數器目標來源
  StoreOp_t StoreOpD;            // 存儲操作類型
  LoadOp_t LoadOpD;              // 加載操作類型
  CsrOp_t CsrOpD;                // CSR 操作類型

  logic RegWriteD;    // 寄存器寫入信號
  /* verilator lint_off UNUSEDSIGNAL*/ //我新增
  logic PCWrite;      // 程式計數器寫入信號
  /* verilator lint_on UNUSEDSIGNAL*/ //我新增
  logic MemWriteD;    // 記憶體寫入信號
  logic JumpD;        // 跳躍信號
  logic BranchD;      // 分支信號

  logic CsrInstrIncD; // CSR 指令增量信號
  /* verilator lint_off UNUSEDSIGNAL*/ //我新增
  logic [31:0] InstrD; // 暫存的指令
  /* verilator lint_on UNUSEDSIGNAL*/ //我新增
  assign opD       = InstrD[6:0];   // 提取操作碼
  assign funct3D   = InstrD[14:12]; // 提取 funct3 欄位
  assign funct7b5D = InstrD[30];    // 提取 funct7 第 5 位
  assign funct7b1D = InstrD[25];    // 提取 funct7 第 1 位

// 模擬環境下的初始輸出訊息
`ifdef SIM
  initial begin
    $display("=========================");
    $display("Module:\t%m");
    $display("=========================");
  end
`endif

  // 控制單元模組實例化
  control_unit control_unit_i (
      .opD         (opD),
      .funct3D     (funct3D),
      .funct7b5D   (funct7b5D),
      .funct7b1D   (funct7b1D),
      .immb10D     (immb10D),
      .PCTargetSrcD(PCTargetSrcD),
      .ResultSrcD  (ResultSrcD),
      .MemWriteD   (MemWriteD),
      .JumpD       (JumpD),
      .BranchD     (BranchD),
      .AluControlD (AluControlD),
      .AluSrcAD    (AluSrcAD),
      .AluSrcBD    (AluSrcBD),
      .ImmSrcD     (ImmSrcD),
      .RegWriteD   (RegWriteD),
      .StoreOpD    (StoreOpD),
      .LoadOpD     (LoadOpD),
      .CsrOpD      (CsrOpD),
      .CsrInstrIncD(CsrInstrIncD)
  );

  // 數據通路模組實例化
  datapath_unit #(
      .RESET_ADDR(RESET_ADDR) // 初始化程式計數器地址
  ) datapath_unit_i (
      .clk         (clk),
      .resetn      (resetn),
      .halt        (halt),
      .Instr       (Instr),
      .InstrD      (InstrD),
      .PCTargetSrcD(PCTargetSrcD),
      .ResultSrcD  (ResultSrcD),
      .AluControlD (AluControlD),
      .AluSrcAD    (AluSrcAD),
      .AluSrcBD    (AluSrcBD),
      .ImmSrcD     (ImmSrcD),
      .RegWriteD   (RegWriteD),
      .StoreOpD    (StoreOpD),
      .LoadOpD     (LoadOpD),
      .CsrOpD      (CsrOpD),
      .Immb10D     (immb10D),
      .CsrInstrIncD(CsrInstrIncD),
      .MemWriteD   (MemWriteD),
      .JumpD       (JumpD),
      .BranchD     (BranchD),
      .AluResultM  (AluResultM),
      .WriteDataM  (WriteDataM),
      .ReadDataM   (ReadDataM),
      .WriteMaskM  (WriteMaskM),
      .ReadMemM    (ReadMemM),
      .PCF         (PCF)
  );

  /* 重新啟用寬度警告 */
  /* verilator lint_on WIDTH */
endmodule
// 禁用 Verilog 的某些 lint 檢查
// verilog_lint: waive-stop explicit-parameter-storage-type
