/*
 *  kianv 五階段流水線 RISC-V 處理器定義文件
 *
 *  版權所有 (c) 2022 hirosh dabui <hirosh@dabui.de>
 *
 *  授權條款允許任何用途的使用、複製、修改和/或分發此軟體，無論是否收費，前提是上述版權聲明和此授權條款需出現在所有副本中。
 *
 *  本軟體按「原樣」提供，作者對此軟體不提供任何形式的保證，包括適銷性和特定用途的隱含保證。
 *  在任何情況下，作者不對因使用本軟體或其效能引起的任何特別的、直接的、間接的或後果性損害或任何損害（包括使用、數據或利潤的損失）負責。
 *
 */

`ifndef KIANV_RISCV_HARRIS // 避免重複定義的防護巨集
`define KIANV_RISCV_HARRIS

`define NOP_INSTR 32'h00000013 // 定義空操作 (NOP) 指令的值

// ALU 操作數來源選擇
typedef enum logic [0:0] {
  ALU_SRCA_RD1, // 來自 Rs1 的值
  ALU_SRCA_PC   // 來自程式計數器 (PC)
} AluSrcA_t;

typedef enum logic [0:0] {
  ALU_SRCB_RD2,     // 來自 Rs2 的值
  ALU_SRCB_IMM_EXT  // 來自立即數擴展值
} AluSrcB_t;

// 寄存器寫回數據來源
typedef enum logic [1:0] {
  RESULT_SRC_ALURESULT, // 寄存器值來自 ALU 計算結果
  RESULT_SRC_READDATA,  // 寄存器值來自記憶體讀取
  RESULT_SRC_PCPLUS4,   // 寄存器值為 PC + 4
  RESULT_SRC_CSRDATA    // 寄存器值來自 CSR 資料
} ResultSrc_t;

// 程式計數器目標來源
typedef enum logic [0:0] {
  PCSRC_TARGET_SRCA_SRC, // 程式計數器目標來源 Rs1 + 立即數
  PCSRC_TARGET_PC_SRC    // 程式計數器目標來源 PC + 立即數
} PCTargetSrc_t;

// 程式計數器下一值來源
typedef enum logic [0:0] {
  PCSRC_PCPLUS4,  // 下一值為 PC + 4
  PCSRC_PCTARGET  // 下一值為計算後的目標地址
} PCSrc_t;

// 立即數類型定義
typedef enum logic [2:0] {
  IMMSRC_R_TYPE = 3'bXXX, // R 型指令 (無立即數)
  IMMSRC_I_TYPE = 3'b000, // I 型指令
  IMMSRC_S_TYPE = 3'b001, // S 型指令
  IMMSRC_B_TYPE = 3'b010, // B 型指令
  IMMSRC_U_TYPE = 3'b100, // U 型指令
  IMMSRC_J_TYPE = 3'b011  // J 型指令
} ImmSrc_t;

// ALU 操作類型
typedef enum logic [2:0] {
  ALU_OP_ADD,         // 加法
  ALU_OP_SUB,         // 減法
  ALU_OP_ARITH_LOGIC, // 算術邏輯操作
  ALU_OP_LUI,         // 加載高立即數
  ALU_OP_AUIPC,       // 加立即數至 PC
  ALU_OP_BRANCH       // 分支運算
} AluOp_t;

// 乘法操作類型
typedef enum logic [1:0] {
  MULOP_MUL,   // 無符號乘法
  MULOP_MULH,  // 高位乘法
  MULOP_MULSU, // 符號無符號混合乘法
  MULOP_MULU   // 無符號高位乘法
} MulOp_t;

// 除法操作類型
typedef enum {
  DIVOP_DIV,  // 有符號除法
  DIVOP_DIVU, // 無符號除法
  DIVOP_REM,  // 有符號取餘
  DIVOP_REMU  // 無符號取餘
} DivOp_t;

// CSR 操作類型
typedef enum logic [0:0] {
  CSR_OP_CSRRS, // CSRRS 指令
  CSR_OP_NA     // 無操作
} CsrOp_t;

// CSR 寄存器定義
typedef enum logic [11:0] {
  CSR_REG_CYCLE = 'hC00,   // 周期計數器低位
  CSR_REG_CYCLEH = 'hC80,  // 周期計數器高位
  CSR_REG_INSTRET = 'hC02, // 指令計數器低位
  CSR_REG_INSTRETH = 'hC82, // 指令計數器高位
  CSR_REG_TIME = 'hC01,    // 時間寄存器低位
  CSR_REG_TIMEH = 'hC81    // 時間寄存器高位
} CsrRegs_t;

// 存儲操作類型
typedef enum logic [1:0] {
  STORE_OP_SB, // 存儲字節
  STORE_OP_SH, // 存儲半字
  STORE_OP_SW  // 存儲字
} StoreOp_t;

// 加載操作類型
typedef enum logic [2:0] {
  LOAD_OP_LB,  // 加載字節
  LOAD_OP_LBU, // 加載無符號字節
  LOAD_OP_LH,  // 加載半字
  LOAD_OP_LHU, // 加載無符號半字
  LOAD_OP_LW   // 加載字
} LoadOp_t;

// ALU 控制信號
typedef enum logic [4:0] {
  ALU_CTRL_ADD_ADDI, // 加法或加立即數
  ALU_CTRL_SUB,      // 減法
  ALU_CTRL_XOR_XORI, // XOR 或 XORI
  ALU_CTRL_OR_ORI,   // OR 或 ORI
  ALU_CTRL_AND_ANDI, // AND 或 ANDI
  ALU_CTRL_SLL_SLLI, // 左移或左移立即數
  ALU_CTRL_SRL_SRLI, // 右移或右移立即數
  ALU_CTRL_SRA_SRAI, // 算術右移或右移立即數
  ALU_CTRL_SLT_SLTI, // 小於比較或立即數
  ALU_CTRL_AUIPC,    // 加立即數至 PC
  ALU_CTRL_LUI,      // 加載高立即數
  ALU_CTRL_SLTU_SLTIU, // 無符號小於比較或立即數
  ALU_CTRL_BEQ,      // 分支等於
  ALU_CTRL_BNE,      // 分支不等
  ALU_CTRL_BLT,      // 分支小於
  ALU_CTRL_BGE,      // 分支大於等於
  ALU_CTRL_BLTU,     // 無符號分支小於
  ALU_CTRL_BGEU      // 無符號分支大於等於
} AluControl_t;

// 前推多工器 (ForwardAE)
typedef enum logic [1:0] {
  FORWARD_SRCAE_RD1E,        // 從 Rs1E
  FORWARD_SRCAE_RESULTW,     // 從結果回寫
  FORWARD_SRCAE_ALURESULTM   // 從 ALU 結果
} ForwardAE_t;

// 前推多工器 (ForwardBE)
typedef enum logic [1:0] {
  FORWARD_SRCBE_RD2E,        // 從 Rs2E
  FORWARD_SRCBE_RESULTW,     // 從結果回寫
  FORWARD_SRCBE_ALURESULTM   // 從 ALU 結果
} ForwardBE_t;

// 前推多工器 (ForwardAD)
typedef enum logic [0:0] {
  FORWARD_SRCAD_RD1D,        // 從 Rs1D
  FORWARD_SRCAD_RESULTW      // 從結果回寫
} ForwardAD_t;

// 前推多工器 (ForwardBD)
typedef enum logic [0:0] {
  FORWARD_SRCBD_RD2D,        // 從 Rs2D
  FORWARD_SRCBD_RESULTW      // 從結果回寫
} ForwardBD_t;

`endif  // KIANV_RISCV_HARRIS
