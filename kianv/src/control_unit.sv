/*
 *  kianv 五階段流水線 RISC-V 處理器控制單元
 *
 *  版權所有 (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  授權條款允許任何用途的使用、複製、修改和/或分發此軟體，無論是否收費，前提是上述版權聲明和此授權條款需出現在所有副本中。
 *
 *  本軟體按「原樣」提供，作者對此軟體不提供任何形式的保證，包括適銷性和特定用途的隱含保證。
 *  在任何情況下，作者不對因使用本軟體或其效能引起的任何特別的、直接的、間接的或後果性損害或任何損害（包括使用、數據或利潤的損失）負責。
 *
 */
`include "riscv_defines.svh" // 包含 RISC-V 定義文件
`default_nettype none        // 禁止自動推導 net 型別
`timescale 1 ns / 100 ps     // 設定時間單位與精度
// 禁用某些 Verilog lint 檢查
// verilog_lint: waive-start explicit-parameter-storage-type
module control_unit (
    input wire logic [6:0] opD,          // 操作碼
    input wire logic [2:0] funct3D,      // funct3 欄位
    input wire logic [0:0] funct7b5D,    // funct7 第 5 位
    input wire logic [0:0] funct7b1D,    // funct7 第 1 位
    input wire logic [0:0] immb10D,      // 立即數 (第 10 位)

    output wire PCTargetSrc_t PCTargetSrcD, // 程式計數器目標來源
    output wire ResultSrc_t ResultSrcD,    // 結果來源
    output wire logic MemWriteD,           // 記憶體寫入信號
    output wire logic JumpD,               // 跳躍信號
    output wire logic BranchD,             // 分支信號
    output wire AluControl_t AluControlD,  // ALU 控制信號
    output wire AluSrcA_t AluSrcAD,        // ALU 第一操作數來源
    output wire AluSrcB_t AluSrcBD,        // ALU 第二操作數來源
    output wire ImmSrc_t ImmSrcD,          // 立即數來源
    output wire logic RegWriteD,           // 寄存器寫入信號

    output wire StoreOp_t StoreOpD,        // 存儲操作類型
    output wire LoadOp_t LoadOpD,          // 加載操作類型
    output wire CsrOp_t CsrOpD,            // CSR 操作類型
    output wire logic CsrInstrIncD         // CSR 指令增量信號
);
  /* verilator lint_off WIDTH */ // 關閉與位寬相關的 lint 警告

  // 主解碼器模組
  main_decoder main_decoder_i (
      .opD         (opD),           // 傳遞操作碼
      .funct7b1D   (funct7b1D),     // funct7 第 1 位
      .AluSrcAD    (AluSrcAD),      // ALU 第一操作數來源
      .AluSrcBD    (AluSrcBD),      // ALU 第二操作數來源
      .AluOp       (AluOp),         // ALU 操作信號
      .ResultSrcD  (ResultSrcD),    // 結果來源
      .ImmSrcD     (ImmSrcD),       // 立即數來源
      .PCTargetSrcD(PCTargetSrcD),  // 程式計數器目標來源
      .JumpD       (JumpD),         // 跳躍信號
      .BranchD     (BranchD),       // 分支信號
      .RegWriteD   (RegWriteD),     // 寄存器寫入信號
      .MemWriteD   (MemWriteD),     // 記憶體寫入信號
      .CsrInstrIncD(CsrInstrIncD)   // CSR 指令增量信號
  );

  wire AluOp_t AluOp; // 定義 ALU 操作信號

  // ALU 解碼器模組
  alu_decoder alu_decoder_i (
      .imm_bit10  (immb10D),        // 立即數第 10 位
      .op_bit5    (opD[5]),         // 操作碼第 5 位
      .funct3D    (funct3D),        // funct3 欄位
      .funct7bit5D(funct7b5D),      // funct7 第 5 位
      .AluOp      (AluOp),          // ALU 操作信號
      .AluControlD(AluControlD)     // ALU 控制信號
  );

  // 加載解碼器模組
  load_decoder load_decoder_i (
      .funct3D(funct3D),            // funct3 欄位
      .LoadOpD(LoadOpD)             // 加載操作類型
  );

  // 存儲解碼器模組
  store_decoder store_decoder_i (
      .funct3D (funct3D),           // funct3 欄位
      .StoreOpD(StoreOpD)           // 存儲操作類型
  );

  // CSR 解碼器模組
  csr_decoder csr_decoder_i (
      funct3D,                      // funct3 欄位
      CsrOpD                        // CSR 操作類型
  );

  /* verilator lint_on WIDTH */ // 重新啟用與位寬相關的 lint 警告
endmodule
// verilog_lint: waive-stop explicit-parameter-storage-type
