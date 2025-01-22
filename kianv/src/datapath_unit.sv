/*
 *  kianv 五階段流水線 RISC-V 數據通路模組 (Datapath Unit)
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
`include "riscv_defines.svh"

module datapath_unit #(
    parameter RESET_ADDR = 0 // 程式計數器初始值
) (
    // 信號說明
    input wire logic clk,                  // 時鐘信號，用於驅動整個流水線
    input wire logic resetn,               // 重置信號 (低有效)，重置所有寄存器和狀態
    input wire logic halt,                 // 暫停信號，用於暫停流水線操作

    input wire logic [31:0] Instr,         // 當前取指階段的指令
    output wire logic [31:0] InstrD,       // 解碼階段的指令輸出

    // 控制信號
    input wire PCTargetSrc_t PCTargetSrcD, // 指定程式計數器 (PC) 的目標來源
                                           // (例如，PC + 立即數，或來自寄存器加立即數)
    input wire ResultSrc_t ResultSrcD,     // 指定結果來源 (ALU 結果、記憶體數據、PC + 4 或 CSR)
    input wire AluControl_t AluControlD,   // 指定 ALU 的控制操作 (如加法、減法、與、或等)
    input wire AluSrcA_t AluSrcAD,         // ALU 第一操作數的來源選擇信號
                                           // (例如，來源於 Rs1 或 PC)
    input wire AluSrcB_t AluSrcBD,         // ALU 第二操作數的來源選擇信號
                                           // (例如，來源於 Rs2 或立即數)
    input wire ImmSrc_t ImmSrcD,           // 指定立即數的來源類型 (如 I 型, S 型, B 型)
    input wire logic RegWriteD,            // 解碼階段的寄存器寫入使能信號
    input wire StoreOp_t StoreOpD,         // 解碼階段的存儲操作類型信號 (SB, SH, SW)
    input wire LoadOp_t LoadOpD,           // 解碼階段的加載操作類型信號 (LB, LH, LW, LBU, LHU)
    input wire CsrOp_t CsrOpD,             // 解碼階段的 CSR 操作信號 (如 CSRRS, CSRRW, 無操作)

    // 解碼階段信號
    output wire logic Immb10D,             // 指示立即數的第 10 位，用於某些特定操作的判斷
    input wire logic CsrInstrIncD,         // CSR 指令增量信號，用於指示是否需要更新指令計數器

    // 記憶體操作信號 (dmem)
    input wire logic MemWriteD,            // 解碼階段的記憶體寫使能信號，用於啟用寫入操作
    input wire logic JumpD,                // 解碼階段的跳躍信號，用於指示是否執行跳躍操作
    input wire logic BranchD,              // 解碼階段的分支信號，用於指示是否執行分支操作

    // 記憶體操作輸出信號
    output wire logic [31:0] AluResultM,   // 記憶體階段的 ALU 結果，用於地址計算或其他用途
    output wire logic [31:0] WriteDataM,   // 記憶體階段的寫入數據，用於寫入記憶體
    input wire logic [31:0] ReadDataM,     // 從記憶體讀取的數據，用於加載指令
    output wire logic [3:0] WriteMaskM,    // 記憶體寫入掩碼，用於控制哪幾個位有效寫入
    output wire logic ReadMemM,            // 記憶體讀取信號，用於啟用讀取操作

    // 分支邏輯信號
    output wire logic [31:0] PCF           // 當前階段的程式計數器 (PC)，指向當前指令的地址
);

  ///////////////////////////////////////////////////////////////////////////////////////
  // 流水線內部信號定義

  // 程式計數器 (PC) 相關信號
  logic [31:0] PCPlus4F;            // 取指階段的 PC + 4
  logic [31:0] PCPlus4D;            // 解碼階段的 PC + 4
  logic [31:0] PCD;                 // 解碼階段的程式計數器值

  // 寄存器檔案相關信號
  logic [4:0] Rs1E;                 // 執行階段的第一來源寄存器地址
  logic [4:0] Rs2E;                 // 執行階段的第二來源寄存器地址
  /* verilator lint_off UNUSEDSIGNAL */ //我新增
  logic [31:0] Rd1D;                // 解碼階段的第一來源寄存器數據
  logic [31:0] Rd2D;                // 解碼階段的第二來源寄存器數據
  /* verilator lint_on UNUSEDSIGNAL */ //我新增
  logic RegWriteE;                  // 執行階段的寄存器寫使能信號

  // 控制信號
  ResultSrc_t ResultSrcE;           // 執行階段的結果來源選擇信號
  PCTargetSrc_t PCTargetSrcE;       // 執行階段 PC 目標來源選擇信號
  LoadOp_t LoadOpE;                 // 執行階段加載操作類型信號
  StoreOp_t StoreOpE;               // 執行階段存儲操作類型信號
  logic MemWriteE;                  // 執行階段記憶體寫使能信號
  logic JumpE;                      // 執行階段跳躍信號
  logic BranchE;                    // 執行階段分支信號
  logic CsrInstrIncE;               // 執行階段 CSR 指令增量信號

  // 寄存器相關信號
  logic [4:0] Rs1D;                 // 解碼階段的第一來源寄存器地址
  logic [4:0] Rs2D;                 // 解碼階段的第二來源寄存器地址
  logic [4:0] RdE;                  // 執行階段的目標寄存器地址
  logic [31:0] Rd1E;                // 執行階段的第一來源寄存器數據
  logic [31:0] Rd2E;                // 執行階段的第二來源寄存器數據

  // ALU 相關信號
  AluControl_t AluControlE;         // 執行階段 ALU 控制信號
  AluSrcA_t AluSrcAE;               // ALU 第一操作數來源信號
  AluSrcB_t AluSrcBE;               // ALU 第二操作數來源信號
  logic [31:0] PCPlus4E;            // 執行階段的 PC + 4
  logic [31:0] ImmExtE;             // 執行階段的立即數擴展值
  logic [31:0] PCE;                 // 執行階段程式計數器值

  // CSR 操作信號
  CsrOp_t CsrOpE;                   // 執行階段 CSR 操作信號

  // 模擬用信號
`ifdef SIM
  logic [31:0] InstrE;              // 執行階段的指令 (僅模擬用)
`endif 
  ///////////////////////////////////////////////////////////////////////////////////////
  // 記憶體階段信號
  logic RegWriteM;                  // 記憶體階段的寄存器寫使能信號
  ResultSrc_t ResultSrcM;           // 記憶體階段的結果來源信號
  logic MemWriteM;                  // 記憶體階段的記憶體寫使能信號
  LoadOp_t LoadOpM;                 // 記憶體階段的加載操作類型信號
  StoreOp_t StoreOpM;               // 記憶體階段的存儲操作類型信號
  /* verilator lint_off UNUSEDSIGNAL */ //我新增
  logic [31:0] Rd2M;                // 記憶體階段第二來源寄存器的數據，用於存儲操作
  /* verilator lint_on UNUSEDSIGNAL */ //我新增
  logic [4:0] RdM;                  // 記憶體階段目標寄存器地址
  logic [31:0] PCPlus4M;            // 記憶體階段的 PC + 4 值
  logic [31:0] PCTargetE;           // 執行階段的目標 PC 值，用於分支或跳躍指令
  logic [31:0] SrcAE;               // 執行階段的第一操作數來源數據
  logic [31:0] SrcBE;               // 執行階段的第二操作數來源數據
  /* verilator lint_off UNUSEDSIGNAL */ //我新增
  ResultSrc_t ResultSrcE_;          // 執行階段的結果來源信號（內部處理）
  /* verilator lint_on UNUSEDSIGNAL */ //我新增
  logic [31:0] WriteDataUnAlignedM; // 未對齊的寫入數據，用於存儲操作
`ifdef SIM
  logic [31:0] InstrM;              // 記憶體階段的指令（僅模擬用）
`endif

  // 寫回階段信號
  logic RegWriteW;                  // 寫回階段的寄存器寫使能信號
  ResultSrc_t ResultSrcW;           // 寫回階段的結果來源信號
  LoadOp_t LoadOpW;                 // 寫回階段的加載操作類型信號
  logic [4:0] RdW;                  // 寫回階段目標寄存器地址
  logic [31:0] AluResultW;          // 寫回階段的 ALU 結果
  logic [3:0] wmask;                // 記憶體寫入掩碼信號，用於指定有效寫入位
  logic [31:0] PCPlus4W;            // 寫回階段的 PC + 4 值
`ifndef SIM
  logic [31:0] ReadDataW;           // 記憶體讀取的數據，用於寫回
`else
  logic [31:0] ReadDataW;           // 記憶體讀取的數據（僅模擬用）
  logic [31:0] InstrW;              // 寫回階段的指令（僅模擬用）
`endif
  ///////////////////////////////////////////////////////////////////////////////////////
  // 寫回階段的對齊數據
  logic [31:0] ReadDataAlignedW;  // 從記憶體讀取的數據，已對齊到適當位置

  // 執行階段的程式計數器來源選擇
  PCSrc_t PCSrcE;                // 執行階段的 PC 來源選擇信號 (PC+4 或分支目標)

  // 程式計數器暫存信號
  logic [31:0] PCF_;             // 執行階段的下一個 PC 值，用於更新 PC

  // 解碼階段的立即數擴展
  logic [31:0] ImmExtD;          // 解碼階段擴展的立即數

  // 執行階段的 ALU 運算結果
  logic [31:0] AluResultE;       // ALU 計算的結果輸出

  // 執行階段的分支條件信號
  logic ZeroE;                   // ALU 計算結果是否為零的標誌 (分支判斷用)
  logic taken_branch;            // 指示是否採取分支 (基於條件分支判斷)

  // 執行階段的結果來源信號
  /* verilator lint_off UNUSEDSIGNAL */ //我新增
  logic ResultSrcE0;             // 執行階段的結果來源信號，部分用於內部處理
   /* verilator lint_on UNUSEDSIGNAL */ //我新增

  // 前遞 (Forwarding) 信號，用於解決資料冒險
  ForwardAE_t ForwardAE;         // ALU 第一操作數的前遞控制信號
  ForwardBE_t ForwardBE;         // ALU 第二操作數的前遞控制信號

  ForwardAD_t ForwardAD;         // 第一來源寄存器數據的前遞控制信號
  ForwardBD_t ForwardBD;         // 第二來源寄存器數據的前遞控制信號

  // 流水線控制信號
  logic StallF;                  // 停止取指階段的信號
  logic StallD;                  // 停止解碼階段的信號
  logic FlushD;                  // 清除解碼階段的信號
  logic FlushE;                  // 清除執行階段的信號

  // CSR (控制與狀態暫存器) 相關信號
  logic [31:0] CsrDataE;         // 執行階段從 CSR 讀取的數據

  // 寫回階段的最終結果
  logic [31:0] ResultW;          // 寫回階段的數據結果，用於寫入寄存器
  ///////////////////////////////////////////////////////////////////////////////////////
  // 階段模組實例化

  // 取指階段模組
  fetch_stage fetch_stage_i (
      .clk     (clk),
      .resetn  (resetn),
      .Instr   (Instr),
      .FlushD  (FlushD),
      .Stall   (StallD),
      .PCF     (PCF),
      .InstrD  (InstrD),
      .PCPlus4F(PCPlus4F),
      .PCPlus4D(PCPlus4D),
      .PCD     (PCD)
  );

  // 解碼階段模組
  decode_stage decode_stage_i (
      .clk         (clk),
      .resetn      (resetn),
      .Stall       (halt),
      .FlushE      (FlushE),
      .InstrD      (InstrD),
      .Rs1D        (Rs1D),
      .Rs2D        (Rs2D),
      .Rd1D        (Rd1D),
      .Rd2D        (Rd2D),
      .PCD         (PCD),
      .RegWriteD   (RegWriteD),
      .ResultSrcD  (ResultSrcD),
      .PCTargetSrcD(PCTargetSrcD),
      .LoadOpD     (LoadOpD),
      .StoreOpD    (StoreOpD),
      .MemWriteD   (MemWriteD),
      .JumpD       (JumpD),
      .BranchD     (BranchD),
      .CsrInstrIncD(CsrInstrIncD),
      .ResultW     (ResultW),
      .ForwardAD   (ForwardAD),
      .ForwardBD   (ForwardBD),
      .AluControlD (AluControlD),
      .AluSrcAD    (AluSrcAD),
      .AluSrcBD    (AluSrcBD),
      .PCPlus4D    (PCPlus4D),
      .ImmExtD     (ImmExtD),
      .CsrOpD      (CsrOpD),
      .Rs1E        (Rs1E),
      .Rs2E        (Rs2E),
      .Immb10D     (Immb10D),
      .RegWriteE   (RegWriteE),
      .ResultSrcE  (ResultSrcE),
      .PCTargetSrcE(PCTargetSrcE),
      .LoadOpE     (LoadOpE),
      .StoreOpE    (StoreOpE),
      .MemWriteE   (MemWriteE),
      .JumpE       (JumpE),
      .BranchE     (BranchE),
      .CsrInstrIncE(CsrInstrIncE),
      .RdE         (RdE),
      .Rd1E        (Rd1E),
      .Rd2E        (Rd2E),
      .AluControlE (AluControlE),
      .AluSrcAE    (AluSrcAE),
      .AluSrcBE    (AluSrcBE),
      .PCPlus4E    (PCPlus4E),
      .ImmExtE     (ImmExtE),
      .PCE         (PCE),
      .CsrOpE      (CsrOpE)
`ifdef SIM,
      .InstrE      (InstrE)
`endif
  );

  // 執行階段模組
  execute_stage execute_stage_i (
      .clk                (clk),
      .resetn             (resetn),
      .Stall              (halt),
      .RegWriteE          (RegWriteE),
      .ResultSrcE         (ResultSrcE),
      .LoadOpE            (LoadOpE),
      .StoreOpE           (StoreOpE),
      .Rd1E               (Rd1E),
      .Rd2E               (Rd2E),
      .RdE                (RdE),
      .PCPlus4E           (PCPlus4E),
      .PCE                (PCE),
      .ImmExtE            (ImmExtE),
      .ResultW            (ResultW),
      .AluResultE         (AluResultE),
      .MemWriteE          (MemWriteE),
      .PCTargetSrcE       (PCTargetSrcE),
      .AluSrcAE           (AluSrcAE),
      .AluSrcBE           (AluSrcBE),
      .ForwardAE          (ForwardAE),
      .ForwardBE          (ForwardBE),
      .CsrDataE           (CsrDataE),
      .AluResultM         (AluResultM),
      .RegWriteM          (RegWriteM),
      .ResultSrcM         (ResultSrcM),
      .MemWriteM          (MemWriteM),
      .LoadOpM            (LoadOpM),
      .StoreOpM           (StoreOpM),
      .Rd2M               (Rd2M),
      .RdM                (RdM),
      .PCPlus4M           (PCPlus4M),
      .PCTargetE          (PCTargetE),
      .SrcAE              (SrcAE),
      .SrcBE              (SrcBE),
      .ResultSrcE_        (ResultSrcE_),
`ifndef SIM
      .WriteDataUnAlignedM(WriteDataUnAlignedM)
`else
      .WriteDataUnAlignedM(WriteDataUnAlignedM),
      .InstrE             (InstrE),
      .InstrM             (InstrM)
`endif
  );

  // 記憶體階段模組
  memory_stage memory_stage_i (
      .clk                (clk),
      .resetn             (resetn),
      .Stall              (halt),
      .RegWriteM          (RegWriteM),
      .ResultSrcM         (ResultSrcM),
      .LoadOpM            (LoadOpM),
      .StoreOpM           (StoreOpM),
      .RdM                (RdM),
      .AluResultM         (AluResultM),
      .WriteDataUnAlignedM(WriteDataUnAlignedM),
      .PCPlus4M           (PCPlus4M),
      .ReadDataM          (ReadDataM),
      .WriteDataM         (WriteDataM),
      .RegWriteW          (RegWriteW),
      .ResultSrcW         (ResultSrcW),
      .LoadOpW            (LoadOpW),
      .RdW                (RdW),
      .AluResultW         (AluResultW),
      .wmask              (wmask),
      .PCPlus4W           (PCPlus4W),
`ifndef SIM
      .ReadDataW          (ReadDataW)
`else
      .ReadDataW          (ReadDataW),
      .InstrM             (InstrM),
      .InstrW             (InstrW)
`endif
  );

  // 寫回階段模組
  writeback_stage writeback_stage_i (
      .AluResultW      (AluResultW),
      .LoadOpW         (LoadOpW),
      .ReadDataW       (ReadDataW),
      .ReadDataAlignedW(ReadDataAlignedW)
  );

  // 立即數擴展模組
  extend extend_i (
      .Instr (InstrD[31:7]), // 從指令中提取需要進行擴展的部分 (31:7 位)
      .ImmSrc(ImmSrcD),      // 指定立即數來源類型 (如 I 型, S 型, 等)
      .ImmExt(ImmExtD)       // 輸出擴展後的立即數
  );

  // 32 位元算術邏輯單元 (ALU)
  alu32 alu32_i (
      .a         (SrcAE),        // ALU 的第一操作數來源
      .b         (SrcBE),        // ALU 的第二操作數來源
      .AluControl(AluControlE),  // 控制 ALU 執行的操作 (如加法、減法、位移等)
      .result    (AluResultE),   // ALU 運算結果輸出
      .zero      (ZeroE)         // ALU 結果是否為零的標誌位輸出
  );

  // 控制與狀態暫存器 (CSR) 單元
  csr_unit csr_unit_i (
      .clk   (clk),                       // 時鐘信號
      .resetn(resetn),                    // 重置信號 (低有效)
      .IncInstructionCycle(CsrInstrIncE & !halt), // 是否增加指令計數器，當 CSR 指令執行且未暫停時
      .ImmExt(ImmExtE[11:0]),             // 從立即數擴展模組輸入的 CSR 操作地址 (12 位)
      .CsrOp (CsrOpE),                    // 指定執行的 CSR 操作類型 (如讀取/寫入)
      .rdata (CsrDataE)                   // 從 CSR 讀取的數據輸出
  );

  // 程式計數器更新邏輯
  assign taken_branch = (!ZeroE & BranchE); // 分支條件
  assign PCSrcE = PCSrc_t'(((taken_branch) || JumpE) ? PCSRC_PCTARGET : PCSRC_PCPLUS4); // PC 來源

  // PC 選擇器 - 兩輸入多路選擇器
  mux2 #(32) pcf__mux_i (
      .d0(PCPlus4F),   // 當前階段 PC + 4
      .d1(PCTargetE),  // 執行階段的目標 PC
      .s (PCSrcE),     // 選擇信號 (PC 來源)
      .y (PCF_)        // 輸出選擇的 PC
  );

  // 程式計數器寄存器
  dflop #(32, RESET_ADDR) PCF_i (
      .resetn(resetn), // 重置信號 (低有效)
      .clk(clk),       // 時鐘信號
      .en(!StallF),    // 當無暫停信號時使能更新
      .d(PCF_),        // 來自多路選擇器的輸入
      .q(PCF)          // 輸出的當前 PC 值
  );

  // 結果多路選擇器 - 三輸入多路選擇器
  mux3 #(32) result_mux_i (
      .d0(AluResultW),      // 來自 ALU 的結果
      .d1(ReadDataAlignedW),// 來自記憶體的對齊讀取數據
      .d2(PCPlus4W),        // 來自 PC + 4 的結果
      .s (ResultSrcW),      // 選擇信號 (結果來源)
      .y (ResultW)          // 輸出選擇的結果
  );

  // 寄存器檔案模組
  register_file32 #(
      .REGISTER_DEPTH     (32),  // 寄存器檔案深度
      .CLEAR_REGISTER_FILE(1'b0) // 是否清除寄存器檔案 (預設為 0)
  ) register_file32_i (
      .clk(clk),         // 時鐘信號
      .we (RegWriteW),   // 寄存器寫使能信號
      .A1 (Rs1D),        // 第一來源寄存器地址
      .A2 (Rs2D),        // 第二來源寄存器地址
      .A3 (RdW),         // 目標寄存器地址
      .wd (ResultW),     // 要寫入寄存器的數據
      .Rd1(Rd1D),        // 讀取的第一來源寄存器數據
      .Rd2(Rd2D)         // 讀取的第二來源寄存器數據
  );

  // 判斷是否進行記憶體讀取
  logic isReadMemE;
  assign isReadMemE = ResultSrcE_[0];  // 判斷執行階段結果來源是否為記憶體

  // 冒險處理單元
  hazard_unit hazard_unit_i (
      .clk(clk),              // 時鐘信號
      .resetn(resetn),        // 重置信號 (低有效)
      .halt(halt),            // 停止信號
      .Rs1D(Rs1D),            // 解碼階段的第一來源寄存器地址
      .Rs2D(Rs2D),            // 解碼階段的第二來源寄存器地址
      .Rs1E(Rs1E),            // 執行階段的第一來源寄存器地址
      .Rs2E(Rs2E),            // 執行階段的第二來源寄存器地址
      .RdE(RdE),              // 執行階段的目標寄存器地址
      .RdM(RdM),              // 記憶體階段的目標寄存器地址
      .RdW(RdW),              // 寫回階段的目標寄存器地址
      .RegWriteM(RegWriteM),  // 記憶體階段的寄存器寫使能信號
      .RegWriteW(RegWriteW),  // 寫回階段的寄存器寫使能信號
      .ReadMemE(isReadMemE),  // 執行階段是否需要記憶體讀取
      .PCSrcE(PCSrcE),        // 執行階段的 PC 來源選擇信號
      .ForwardAE(ForwardAE),  // 前遞選擇信號 (第一操作數)
      .ForwardBE(ForwardBE),  // 前遞選擇信號 (第二操作數)
      .ForwardAD(ForwardAD),  // 前遞選擇信號 (第一來源數據)
      .ForwardBD(ForwardBD),  // 前遞選擇信號 (第二來源數據)
      .StallF(StallF),        // 暫停取指階段
      .StallD(StallD),        // 暫停解碼階段
      .FlushD(FlushD),        // 清除解碼階段
      .FlushE(FlushE)         // 清除執行階段
  );

  // 記憶體寫入掩碼生成
  assign WriteMaskM = wmask & {4{MemWriteM & !halt}}; // 當寫入使能有效且未暫停時生效
  assign ReadMemM   = ResultSrcM[0]; // 記憶體讀取信號，由結果來源控制
  

endmodule
/* verilator lint_on WIDTH */
// verilog_lint: waive-stop explicit-parameter-storage-type
