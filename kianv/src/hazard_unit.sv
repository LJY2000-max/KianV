/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  冒險處理單元 (Hazard Unit)
 *  負責檢測並解決數據冒險與控制冒險問題，以確保管線運行的正確性。
 */
`default_nettype none 
`timescale 1 ns / 100 ps
// verilog_lint: waive-start explicit-parameter-storage-type
/* verilator lint_off WIDTH */
`include "riscv_defines.svh"

module hazard_unit (
    /* verilator lint_off UNUSEDSIGNAL */ //我新增
    input  wire logic         clk,             // 時脈訊號
    input  wire logic         resetn,          // 同步重設訊號，低電位有效
    /* verilator lint_on UNUSEDSIGNAL */ //我新增
    input  wire logic         halt,            // 停止訊號，用於停止管線運行
    input  wire logic   [4:0] Rs1D,            // 解碼階段的第一來源暫存器
    input  wire logic   [4:0] Rs2D,            // 解碼階段的第二來源暫存器
    input  wire logic   [4:0] Rs1E,            // 執行階段的第一來源暫存器
    input  wire logic   [4:0] Rs2E,            // 執行階段的第二來源暫存器
    input  wire logic   [4:0] RdE,             // 執行階段的目標暫存器
    input  wire logic   [4:0] RdM,             // 存取階段的目標暫存器
    input  wire logic   [4:0] RdW,             // 寫回階段的目標暫存器
    input  wire logic         RegWriteM,       // 存取階段的寫入控制訊號
    input  wire logic         RegWriteW,       // 寫回階段的寫入控制訊號
    input  wire logic         ReadMemE,        // 執行階段的記憶體讀取訊號
    input  wire PCSrc_t       PCSrcE,          // 執行階段的 PC 更新控制訊號
    output ForwardAE_t        ForwardAE,       // 第一來源操作數的轉發選擇 (執行階段)
    output ForwardBE_t        ForwardBE,       // 第二來源操作數的轉發選擇 (執行階段)
    output ForwardAD_t        ForwardAD,       // 第一來源操作數的轉發選擇 (解碼階段)
    output ForwardBD_t        ForwardBD,       // 第二來源操作數的轉發選擇 (解碼階段)
    output logic              StallF,          // 停止取指階段訊號
    output logic              StallD,          // 停止解碼階段訊號
    output logic              FlushD,          // 清空解碼階段訊號
    output logic              FlushE           // 清空執行階段訊號
);

  // 第一來源操作數轉發邏輯 (執行階段)
  always_comb begin
    if (((Rs1E == RdM) && RegWriteM) && (Rs1E != 0)) begin
      // 來源：存取階段的 ALU 結果
      ForwardAE = ForwardAE_t'(FORWARD_SRCAE_ALURESULTM);
    end else if (((Rs1E == RdW) && RegWriteW) && (Rs1E != 0)) begin
      // 來源：寫回階段的結果
      ForwardAE = ForwardAE_t'(FORWARD_SRCAE_RESULTW);
    end else begin
      // 來源：執行階段的操作數
      ForwardAE = ForwardAE_t'(FORWARD_SRCAE_RD1E);
    end
  end

  // 第二來源操作數轉發邏輯 (執行階段)
  always_comb begin
    if (((Rs2E == RdM) && RegWriteM) && (Rs2E != 0)) begin
      // 來源：存取階段的 ALU 結果
      ForwardBE = ForwardBE_t'(FORWARD_SRCBE_ALURESULTM);
    end else if (((Rs2E == RdW) && RegWriteW) && (Rs2E != 0)) begin
      // 來源：寫回階段的結果
      ForwardBE = ForwardBE_t'(FORWARD_SRCBE_RESULTW);
    end else begin
      // 來源：執行階段的操作數
      ForwardBE = ForwardBE_t'(FORWARD_SRCBE_RD2E);
    end
  end

  // 第一來源操作數轉發邏輯 (解碼階段)
  always_comb begin
    if (((Rs1D == RdW) && RegWriteW) && (Rs1D != 0)) begin
      // 來源：寫回階段的結果
      ForwardAD = ForwardAD_t'(FORWARD_SRCAD_RESULTW);
    end else begin
      // 來源：解碼階段的操作數
      ForwardAD = ForwardAD_t'(FORWARD_SRCAD_RD1D);
    end
  end

  // 第二來源操作數轉發邏輯 (解碼階段)
  always_comb begin
    if (((Rs2D == RdW) && RegWriteW) && (Rs2D != 0)) begin
      // 來源：寫回階段的結果
      ForwardBD = ForwardBD_t'(FORWARD_SRCAD_RESULTW);
    end else begin
      // 來源：解碼階段的操作數
      ForwardBD = ForwardBD_t'(FORWARD_SRCAD_RD1D);
    end
  end

  // 控制冒險與數據冒險處理邏輯
  logic is_pc_target;               // 表示 PC 是否需要更新
  logic lwStall;                    // 負載指令導致的停止訊號
  logic is_load_data_dependency;    // 負載指令的數據依賴性

  // 檢測控制冒險
  assign is_pc_target = logic'(PCSrcE);

  // 檢測數據冒險：負載指令依賴
  assign is_load_data_dependency = ((Rs1D == RdE) || (Rs2D == RdE)) && ReadMemE;

  always_comb begin
    // 停止與清空訊號
    lwStall = is_load_data_dependency;
    {StallF, StallD, FlushE} = {lwStall, lwStall, lwStall};
    {StallF, StallD, FlushE} |= {halt, halt, halt};

    // 控制冒險處理：清空解碼階段與執行階段
    FlushD = is_pc_target & !halt;
    FlushE |= is_pc_target;
    FlushE &= !halt;
  end

endmodule

/* verilator lint_on WIDTH */
// verilog_lint: waive-stop explicit-parameter-storage-type
