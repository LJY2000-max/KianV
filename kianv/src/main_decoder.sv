/*
 *  kianv 五階段流水線 RISC-V 主解碼器
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
// 禁用 Verilog 的某些 lint 檢查
// verilog_lint: waive-start explicit-parameter-storage-type

module main_decoder (
    input wire logic [6:0] opD,          // 操作碼
    input wire logic [0:0] funct7b1D,    // funct7 第 1 位
    output AluSrcA_t AluSrcAD,           // ALU 第一操作數來源
    output AluSrcB_t AluSrcBD,           // ALU 第二操作數來源
    output AluOp_t AluOp,                // ALU 操作類型
    output ResultSrc_t ResultSrcD,       // 結果來源
    output ImmSrc_t ImmSrcD,             // 立即數來源
    output PCTargetSrc_t PCTargetSrcD,   // 程式計數器目標來源
    output logic JumpD,                  // 跳躍信號
    output logic BranchD,                // 分支信號
    output logic RegWriteD,              // 寄存器寫入信號
    output logic MemWriteD,              // 記憶體寫入信號
    output logic CsrInstrIncD            // CSR 指令增量信號
);

  /* verilator lint_off WIDTH */ // 關閉與位寬相關的 lint 警告

  // 指令操作碼的局部參數定義
  localparam load = 'b000_0011;       // 加載指令
  localparam store = 'b010_0011;      // 存儲指令
  localparam rtype = 'b011_0011;      // R 型指令
  localparam itype = 'b001_0011;      // I 型指令
  localparam jal = 'b110_1111;        // JAL (跳躍並連結)
  localparam jalr = 'b110_0111;       // JALR (跳躍並連結寄存器)
  localparam branch = 'b110_0011;     // 分支指令
  localparam lui = 'b011_0111;        // LUI (加載高立即數)
  localparam aupic = 'b001_0111;      // AUIPC (加立即數至程式計數器)
  localparam system = 'b111_0011;     // 系統指令 (特權/CSR)

  // 定義每種指令類型的標誌信號
  logic is_load, is_store, is_rtype, is_itype, is_jal, is_jalr;
  logic is_branch, is_lui, is_aupic, is_system;

  // 判斷指令類型
  assign is_load = opD == load;
  assign is_store = opD == store;
  assign is_rtype = opD == rtype;
  assign is_itype = opD == itype;
  assign is_jal = opD == jal;
  assign is_jalr = opD == jalr;
  assign is_branch = opD == branch;
  assign is_lui = opD == lui;
  assign is_aupic = opD == aupic;
  assign is_system = opD == system;

  // 根據指令類型選擇立即數來源
  always_comb begin : ImmSrcComb
    case (1'b1)
      is_rtype:                                 ImmSrcD = IMMSRC_R_TYPE;
      is_itype | is_jalr | is_load | is_system: ImmSrcD = IMMSRC_I_TYPE;
      is_store:                                 ImmSrcD = IMMSRC_S_TYPE;
      is_branch:                                ImmSrcD = IMMSRC_B_TYPE;
      is_lui | is_aupic:                        ImmSrcD = IMMSRC_U_TYPE;
      is_jal:                                   ImmSrcD = IMMSRC_J_TYPE;
      default:                                  ImmSrcD = IMMSRC_R_TYPE;
    endcase
  end

  // 根據指令類型選擇 ALU 操作類型
  always_comb begin : AluOpComb
    AluOp = ALU_OP_ADD; // 預設為加法操作
    case (1'b1)
      (is_load | is_store):    AluOp = ALU_OP_ADD;         // 加法 (記憶體地址計算)
      (is_rtype & !funct7b1D): AluOp = ALU_OP_ARITH_LOGIC; // 算術/邏輯操作
      (is_itype):              AluOp = ALU_OP_ARITH_LOGIC;
      (is_jal):                AluOp = ALU_OP_ADD;         // 計算目標地址
      (is_jalr):               AluOp = ALU_OP_ADD;         // 計算目標地址
      (is_branch):             AluOp = ALU_OP_BRANCH;      // 分支操作
      (is_lui):                AluOp = ALU_OP_LUI;         // 加載高立即數
      (is_aupic):              AluOp = ALU_OP_AUIPC;       // PC 加立即數
      default:                 AluOp = ALU_OP_ADD;
    endcase
  end

  // 根據指令類型生成控制信號
  always_comb begin : CtrlSignalComb
    BranchD = 1'b0;                       // 預設無分支
    JumpD = 1'b0;                         // 預設無跳躍
    AluSrcAD = ALU_SRCA_RD1;              // ALU 第一操作數來自 Rs1
    AluSrcBD = ALU_SRCB_RD2;              // ALU 第二操作數來自 Rs2
    ResultSrcD = RESULT_SRC_ALURESULT;    // 結果來自 ALU 計算
    RegWriteD = 1'b0;                     // 預設無寄存器寫入
    MemWriteD = 1'b0;                     // 預設無記憶體寫入
    PCTargetSrcD = PCSRC_TARGET_SRCA_SRC; // 預設 PC 目標為 Rs1 + 立即數
    CsrInstrIncD = 1'b1;                  // 預設允許 CSR 指令計數增量

    // 根據指令類型設定控制信號
    case (1'b1)
      is_load: begin
        AluSrcAD   = ALU_SRCA_RD1;
        AluSrcBD   = ALU_SRCB_IMM_EXT;
        ResultSrcD = RESULT_SRC_READDATA;
        RegWriteD  = 1'b1;
      end
      is_store: begin
        AluSrcBD  = ALU_SRCB_IMM_EXT;
        MemWriteD = 1'b1;
      end
      is_rtype: begin
        RegWriteD = 1'b1;
      end
      is_itype: begin
        AluSrcBD  = ALU_SRCB_IMM_EXT;
        RegWriteD = 1'b1;
      end
      is_jal: begin
        JumpD = 1'b1;
        AluSrcBD = ALU_SRCB_IMM_EXT;
        ResultSrcD = RESULT_SRC_PCPLUS4;       // 寄存器值為 PC + 4
        PCTargetSrcD = PCSRC_TARGET_PC_SRC;   // PC += 立即數
        RegWriteD = 1'b1;
      end
      is_jalr: begin
        JumpD = 1'b1;
        AluSrcBD = ALU_SRCB_IMM_EXT;
        ResultSrcD = RESULT_SRC_PCPLUS4;       // 寄存器值為 PC + 4
        PCTargetSrcD = PCSRC_TARGET_SRCA_SRC; // PC = Rs1 + 立即數
        RegWriteD = 1'b1;
      end
      is_branch: begin
        PCTargetSrcD = PCSRC_TARGET_PC_SRC;   // PC += 立即數
        BranchD = 1'b1;
      end
      is_lui: begin
        AluSrcBD   = ALU_SRCB_IMM_EXT;
        ResultSrcD = RESULT_SRC_ALURESULT;    // 寄存器值為立即數 << 12
        RegWriteD  = 1'b1;
      end
      is_aupic: begin
        AluSrcAD   = ALU_SRCA_PC;
        AluSrcBD   = ALU_SRCB_IMM_EXT;
        ResultSrcD = RESULT_SRC_ALURESULT;    // 寄存器值為 PC + (立即數 << 12)
        RegWriteD  = 1'b1;
      end
      is_system: begin
        ResultSrcD = RESULT_SRC_CSRDATA;
        RegWriteD  = 1'b1;
      end
      default: CsrInstrIncD = 1'b0;           // 禁止 CSR 指令計數增量
    endcase
  end

  /* verilator lint_on WIDTH */ // 重新啟用與位寬相關的 lint 警告
endmodule
// verilog_lint: waive-stop explicit-parameter-storage-type
