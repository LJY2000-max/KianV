/*
 *  kianv 5-staged pipelined RISC-V
 *
 *  存儲數據對齊模組 (Store Alignment Unit)
 *  根據存儲操作類型 (StoreOp) 和地址低兩位 (addr)，生成對齊後的數據和對應的寫入掩碼 (wmask)。
 */
`default_nettype none 
`timescale 1 ns / 100 ps

`include "riscv_defines.svh"

module store_alignment (
    input  wire logic     [ 1:0] addr,     // 地址的低兩位，用於確定數據對齊方式
    input  wire StoreOp_t        StoreOp,  // 存儲操作類型 (SB, SH, SW)
    input  wire logic     [31:0] data,     // 原始數據
    output logic          [31:0] result,   // 對齊後的數據
    output logic          [ 3:0] wmask     // 寫入掩碼，用於選擇字節/半字/字
);

  always_comb begin
    // 預設值
    wmask  = 4'b0000; // 初始掩碼全為 0
    result = 'hx;     // 未定義值，用於檢查錯誤情況

    // 根據存儲操作類型處理
    case (StoreOp)
      // 存儲字節 (SB)
      STORE_OP_SB: begin
        // 根據地址低兩位選擇對應字節並生成掩碼
        result[7:0]   = addr[1:0] == 2'b00 ? data[7:0] : 8'hx;
        result[15:8]  = addr[1:0] == 2'b01 ? data[7:0] : 8'hx;
        result[23:16] = addr[1:0] == 2'b10 ? data[7:0] : 8'hx;
        result[31:24] = addr[1:0] == 2'b11 ? data[7:0] : 8'hx;

        // 根據地址低兩位生成對應的寫入掩碼
        wmask = addr[1:0] == 2'b00 ? 4'b0001 : // 只寫入最低字節
                addr[1:0] == 2'b01 ? 4'b0010 : // 只寫入次低字節
                addr[1:0] == 2'b10 ? 4'b0100 : // 只寫入次高字節
                                     4'b1000;  // 只寫入最高字節
      end

      // 存儲半字 (SH)
      (STORE_OP_SH): begin
        // 根據地址第 1 位選擇低半字或高半字，並生成掩碼
        result[15:0]  = ~addr[1] ? data[15:0] : 16'hx; // 低半字
        result[31:16] = addr[1]  ? data[15:0] : 16'hx; // 高半字

        // 根據地址第 1 位生成對應的寫入掩碼
        wmask = addr[1] ? 4'b1100 : // 寫入高半字
                         4'b0011;  // 寫入低半字
      end

      // 存儲字 (SW)
      (STORE_OP_SW): begin
        // 全字存儲，直接取整個數據
        result = data;

        // 寫入掩碼全為 1
        wmask  = 4'b1111; // 寫入所有字節
      end

      // 預設情況：無效存儲操作
      default: begin
        result = 'hx;     // 設為未定義值
        wmask  = 4'b0000; // 寫入掩碼全為 0
      end
    endcase
  end
endmodule
