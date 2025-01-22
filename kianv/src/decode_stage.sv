/*
 *  kianv 五階段流水線 RISC-V - 解碼階段模組 (Decode Stage)
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
/* verilator lint_off WIDTH */

module decode_stage (
    input wire logic clk,                  // 時鐘信號
    input wire logic resetn,               // 重置信號 (低有效)
    input wire logic Stall,                // 暫停信號，解決資料冒險
    input wire logic FlushE,               // 清除執行階段的信號
    /* verilator lint_off UNUSEDSIGNAL */ //我新增
    input wire logic [31:0] InstrD,        // 解碼階段的指令
    /* verilator lint_on UNUSEDSIGNAL */ //我新增
    input wire logic [31:0] PCD,           // 解碼階段的程式計數器 (PC)
    input wire logic RegWriteD,            // 解碼階段的寄存器寫入信號
    input wire ResultSrc_t ResultSrcD,     // 解碼階段的結果來源信號
    input wire PCTargetSrc_t PCTargetSrcD, // 解碼階段的 PC 目標來源信號
    input wire LoadOp_t LoadOpD,           // 解碼階段的加載操作信號
    input wire StoreOp_t StoreOpD,         // 解碼階段的存儲操作信號
    input wire logic MemWriteD,            // 解碼階段的記憶體寫使能信號
    input wire logic JumpD,                // 解碼階段的跳躍信號
    input wire logic BranchD,              // 解碼階段的分支信號
    input wire logic CsrInstrIncD,         // 解碼階段的 CSR 增量信號
    input wire logic [31:0] ResultW,       // 寫回階段的結果數據
    input wire ForwardAD_t ForwardAD,      // 第一來源寄存器的前遞信號
    input wire ForwardBD_t ForwardBD,      // 第二來源寄存器的前遞信號
    input wire AluControl_t AluControlD,   // 解碼階段的 ALU 控制信號
    input wire AluSrcA_t AluSrcAD,         // 解碼階段 ALU 第一操作數的來源
    input wire AluSrcB_t AluSrcBD,         // 解碼階段 ALU 第二操作數的來源
    input wire logic [31:0] PCPlus4D,      // 解碼階段的 PC + 4
    input wire logic [31:0] ImmExtD,       // 解碼階段的立即數擴展
    input wire CsrOp_t CsrOpD,             // 解碼階段的 CSR 操作信號
    output wire logic [4:0] Rs1E,          // 執行階段的第一來源寄存器地址
    output wire logic [4:0] Rs2E,          // 執行階段的第二來源寄存器地址
    output wire logic [4:0] Rs1D,          // 解碼階段的第一來源寄存器地址
    output wire logic [4:0] Rs2D,          // 解碼階段的第二來源寄存器地址
    output wire logic Immb10D,             // 解碼階段的立即數第 10 位
    output wire logic RegWriteE,           // 執行階段的寄存器寫使能信號
    output wire ResultSrc_t ResultSrcE,    // 執行階段的結果來源信號
    output wire PCTargetSrc_t PCTargetSrcE,// 執行階段的 PC 目標來源信號
    output wire LoadOp_t LoadOpE,          // 執行階段的加載操作信號
    output wire StoreOp_t StoreOpE,        // 執行階段的存儲操作信號
    output wire logic MemWriteE,           // 執行階段的記憶體寫使能信號
    output wire logic JumpE,               // 執行階段的跳躍信號
    output wire logic BranchE,             // 執行階段的分支信號
    output wire logic CsrInstrIncE,        // 執行階段的 CSR 增量信號
    /*
    output wire logic [31:0] Rd1D,         // 解碼階段第一來源寄存器的數據
    output wire logic [31:0] Rd2D,         // 解碼階段第二來源寄存器的數據
    這裡的訊號接收來自register_file32模組，所以應該為input。
    */
    input wire logic [31:0] Rd1D,         // 解碼階段第一來源寄存器的數據
    input wire logic [31:0] Rd2D,         // 解碼階段第二來源寄存器的數據
    output wire logic [4:0] RdE,           // 執行階段的目標寄存器地址
    output wire logic [31:0] Rd1E,         // 執行階段第一來源寄存器的數據
    output wire logic [31:0] Rd2E,         // 執行階段第二來源寄存器的數據
    output wire AluControl_t AluControlE,  // 執行階段的 ALU 控制信號
    output wire AluSrcA_t AluSrcAE,        // 執行階段 ALU 第一操作數的來源
    output wire AluSrcB_t AluSrcBE,        // 執行階段 ALU 第二操作數的來源
    output wire logic [31:0] PCPlus4E,     // 執行階段的 PC + 4
    output wire logic [31:0] ImmExtE,      // 執行階段的立即數擴展
    output wire logic [31:0] PCE,          // 執行階段的程式計數器
`ifndef SIM
    output wire CsrOp_t CsrOpE             // 執行階段的 CSR 操作信號
`else
    output wire CsrOp_t CsrOpE,            // 執行階段的 CSR 操作信號
    output wire logic [31:0] InstrE        // 執行階段的指令 (模擬用)
`endif
);

    // 解碼階段邏輯實現 (decode stage)

    // 信號定義
    logic FlushE_resetn;        // 執行階段清除信號的有效重置
    logic [4:0] RdD;            // 解碼階段的目標寄存器地址 (Rd)

    // 信號分配與控制邏輯
    assign FlushE_resetn = resetn & ~FlushE;  // 當 `FlushE` 有效時，強制進行清除

    // 從指令中提取來源與目標寄存器地址
    assign Rs1D = InstrD[19:15];             // 第一來源寄存器地址 (Rs1)
    assign Rs2D = InstrD[24:20];             // 第二來源寄存器地址 (Rs2)
    assign RdD = InstrD[11:7];               // 目標寄存器地址 (Rd)

    // 從立即數擴展中提取第 10 位數據
    assign Immb10D = ImmExtD[10];            // 用於某些指令操作的立即數第 10 位

    // 寄存器寫入控制信號傳遞到執行階段
    dflop #(1, 0) RegWriteE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(RegWriteD),          // 解碼階段的寄存器寫使能信號
        .q(RegWriteE)           // 傳遞到執行階段的寄存器寫使能信號
    );

    // 結果來源信號傳遞到執行階段
    dflop #($bits(ResultSrcE), 0) ResultSrcE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(ResultSrcD),         // 解碼階段的結果來源信號
    `ifdef ICARUS
        .q(ResultSrcE)          // 傳遞到執行階段的結果來源信號 (ICARUS 模擬器使用)
    `else
        .q({>>{ResultSrcE}})    // 非 ICARUS 模擬器下的結果來源信號處理
    `endif
    );

    // PC 目標來源信號傳遞到執行階段
    dflop #($bits(PCTargetSrcE), 0) PCTargetSrcE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(PCTargetSrcD),       // 解碼階段的 PC 目標來源信號
    `ifdef ICARUS
        .q(PCTargetSrcE)        // 傳遞到執行階段的 PC 目標來源信號 (ICARUS 模擬器使用)
    `else
        .q({>>{PCTargetSrcE}})  // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // 加載操作信號傳遞到執行階段
    dflop #($bits(LoadOpE), 0) LoadOpE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(LoadOpD),            // 解碼階段的加載操作信號
    `ifdef ICARUS
        .q(LoadOpE)             // 傳遞到執行階段的加載操作信號 (ICARUS 模擬器使用)
    `else
        .q({>>{LoadOpE}})       // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // 存儲操作信號傳遞到執行階段
    dflop #($bits(StoreOpE), 0) StoreOpE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(StoreOpD),           // 解碼階段的存儲操作信號
    `ifdef ICARUS
        .q(StoreOpE)            // 傳遞到執行階段的存儲操作信號 (ICARUS 模擬器使用)
    `else
        .q({>>{StoreOpE}})      // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // 記憶體寫使能信號傳遞到執行階段
    dflop #(1, 0) MemWriteE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(MemWriteD),          // 解碼階段的記憶體寫使能信號
        .q(MemWriteE)           // 傳遞到執行階段的記憶體寫使能信號
    );

    // 跳躍信號傳遞到執行階段
    dflop #(1, 0) JumpE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(JumpD),              // 解碼階段的跳躍信號
        .q(JumpE)               // 傳遞到執行階段的跳躍信號
    );

    // 分支信號傳遞到執行階段
    dflop #(1, 0) BranchE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(BranchD),            // 解碼階段的分支信號
        .q(BranchE)             // 傳遞到執行階段的分支信號
    );

    // CSR 指令增量信號傳遞到執行階段
    dflop #(1, 0) CsrInstrIncD_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(CsrInstrIncD),       // 解碼階段的 CSR 指令增量信號
        .q(CsrInstrIncE)        // 傳遞到執行階段的 CSR 指令增量信號
    );

    //////
    // 將目標寄存器地址傳遞到執行階段
    dflop #(5, 0) RdE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(RdD),                // 解碼階段的目標寄存器地址
        .q(RdE)                 // 傳遞到執行階段的目標寄存器地址
    );

    // 前遞邏輯：第一來源寄存器數據選擇
    logic [31:0] SrcFWD_AD;
    mux2 #(32) ForwardAD_mux_i (
        .d0(Rd1D),              // 來源寄存器數據
        .d1(ResultW),           // 寫回階段結果數據 (前遞數據)
        .s (ForwardAD),         // 前遞選擇信號
        .y (SrcFWD_AD)          // 最終選擇的數據
    );

    // 將第一來源寄存器數據傳遞到執行階段
    dflop #(32, 0) Rd1E_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(SrcFWD_AD),          // 解碼階段經前遞選擇後的第一來源數據
        .q(Rd1E)                // 傳遞到執行階段的第一來源數據
    );

    // 前遞邏輯：第二來源寄存器數據選擇
    logic [31:0] SrcFWD_BD;
    mux2 #(32) ForwardBD_mux_i (
        .d0(Rd2D),              // 來源寄存器數據
        .d1(ResultW),           // 寫回階段結果數據 (前遞數據)
        .s (ForwardBD),         // 前遞選擇信號
        .y (SrcFWD_BD)          // 最終選擇的數據
    );

    // 將第二來源寄存器數據傳遞到執行階段
    dflop #(32, 0) Rd2E_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(SrcFWD_BD),          // 解碼階段經前遞選擇後的第二來源數據
        .q(Rd2E)                // 傳遞到執行階段的第二來源數據
    );

    // 將第一來源寄存器地址傳遞到執行階段
    dflop #(5, 0) Rs1E_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(Rs1D),               // 解碼階段的第一來源寄存器地址
        .q(Rs1E)                // 傳遞到執行階段的第一來源寄存器地址
    );

    // 將第二來源寄存器地址傳遞到執行階段
    dflop #(5, 0) Rs2E_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(Rs2D),               // 解碼階段的第二來源寄存器地址
        .q(Rs2E)                // 傳遞到執行階段的第二來源寄存器地址
    );

    // 將 ALU 控制信號傳遞到執行階段
    dflop #($bits(AluControlE), 0) AluControlE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(AluControlD),        // 解碼階段的 ALU 控制信號
    `ifdef ICARUS
        .q(AluControlE)         // 傳遞到執行階段的 ALU 控制信號 (ICARUS 模擬器使用)
    `else
        .q({>>{AluControlE}})   // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // ALU 第一操作數來源信號傳遞到執行階段
    dflop #($bits(AluSrcAE), 0) AluSrcAE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(AluSrcAD),           // 解碼階段的 ALU 第一操作數來源信號
    `ifdef ICARUS
        .q(AluSrcAE)            // 傳遞到執行階段的 ALU 第一操作數來源信號 (ICARUS 模擬器使用)
    `else
        .q({>>{AluSrcAE}})      // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // ALU 第二操作數來源信號傳遞到執行階段
    dflop #($bits(AluSrcBE), 0) AluSrcBE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(AluSrcBD),           // 解碼階段的 ALU 第二操作數來源信號
    `ifdef ICARUS
        .q(AluSrcBE)            // 傳遞到執行階段的 ALU 第二操作數來源信號 (ICARUS 模擬器使用)
    `else
        .q({>>{AluSrcBE}})      // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    // 傳遞 PC + 4 信號到執行階段
    dflop #(32, 0) PCPlus4E_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(PCPlus4D),           // 解碼階段的 PC + 4
        .q(PCPlus4E)            // 傳遞到執行階段的 PC + 4
    );

    // 傳遞立即數擴展信號到執行階段
    dflop #(32, 0) ImmExtE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(ImmExtD),            // 解碼階段的立即數擴展
        .q(ImmExtE)             // 傳遞到執行階段的立即數擴展
    );

    // 傳遞 PC 信號到執行階段
    dflop #(32, 0) PCE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(PCD),                // 解碼階段的程式計數器 (PC)
        .q(PCE)                 // 傳遞到執行階段的程式計數器 (PC)
    );

    // 傳遞 CSR 操作信號到執行階段
    dflop #($bits(CsrOpE), 0) CsrOpE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(CsrOpD),             // 解碼階段的 CSR 操作信號
    `ifdef ICARUS
        .q(CsrOpE)              // 傳遞到執行階段的 CSR 操作信號 (ICARUS 模擬器使用)
    `else
        .q({>>{CsrOpE}})        // 非 ICARUS 模擬器下的信號處理
    `endif
    );

    `ifdef SIM
    // 傳遞指令信號到執行階段 (僅在模擬環境中啟用)
    dflop #(32, `NOP_INSTR) InstrE_i (
        .resetn(FlushE_resetn), // 當清除信號有效時，重置為初始值
        .clk(clk),              // 時鐘信號
        .en(!Stall),            // 暫停時不更新信號
        .d(InstrD),             // 解碼階段的指令
        .q(InstrE)              // 傳遞到執行階段的指令
    );
    `endif

endmodule
/* verilator lint_on WIDTH */
// verilog_lint: waive-stop explicit-parameter-storage-type
