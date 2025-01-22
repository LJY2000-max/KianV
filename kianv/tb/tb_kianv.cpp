// tb_kianv.cpp - KianV處理器的Verilator測試平台
#include <verilated.h>        // Verilator的基本頭文件
#include "Vkianv_harris_pipelined_edition.h"  // 由Verilator生成的處理器模型頭文件
#include <verilated_vcd_c.h>  // 用於生成波形文件
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

double sc_time_stamp() {
    return 0;
}

// 測試平台類
class TestBench {
private:
    // 核心組件
    Vkianv_harris_pipelined_edition* dut;  // 設計單元（我們的處理器）
    VerilatedVcdC* trace;                  // 波形追蹤器
    unsigned long tick;                     // 時鐘計數器
    
    // 記憶體模擬
    std::vector<uint32_t> instruction_memory;  // 指令記憶體
    std::vector<uint32_t> data_memory;         // 數據記憶體

public:
    // 構造函數
    TestBench() {
        // 創建處理器實例
        dut = new Vkianv_harris_pipelined_edition;
        trace = nullptr;
        tick = 0;
        
        // 初始化記憶體
        instruction_memory.resize(1024, 0);  // 4KB指令記憶體
        data_memory.resize(1024, 0);         // 4KB數據記憶體
    }

    // 析構函數
    ~TestBench() {
        delete dut;
        if (trace) delete trace;
    }

    // 開啟波形追蹤
    void openTrace(const char* filename) {
        if (!trace) {
            trace = new VerilatedVcdC;
            dut->trace(trace, 99);  // 追蹤99層層級的信號
            trace->open(filename);
        }
    }

    // 時鐘控制
    void tick_clock() {
        tick++;
        
        // 時鐘下降沿
        dut->clk = 0;
        dut->eval();
        // 明確使用 uint64_t 型別
        if (trace) trace->dump(static_cast<uint64_t>(10*tick - 2));

        // 時鐘上升沿
        dut->clk = 1;
        dut->eval();
        // 明確使用 uint64_t 型別
        if (trace) trace->dump(static_cast<uint64_t>(10*tick));

        // 更新記憶體訪問
        handleMemoryAccess();
    }

    // 處理記憶體訪問
    void handleMemoryAccess() {
        // 處理指令讀取
        uint32_t pc = dut->PCF;
        if (pc < instruction_memory.size() * 4) {
            dut->Instr = instruction_memory[pc/4];
        }

        // 處理數據訪問
        if (dut->ReadMemM) {
            // 處理讀取請求
            uint32_t addr = dut->AluResultM;
            if (addr < data_memory.size() * 4) {
                dut->ReadDataM = data_memory[addr/4];
            }
        }
        
        if (dut->WriteMaskM != 0) {
            // 處理寫入請求
            uint32_t addr = dut->AluResultM;
            uint32_t data = dut->WriteDataM;
            uint8_t mask = dut->WriteMaskM;
            
            if (addr < data_memory.size() * 4) {
                // 根據寫入遮罩更新記憶體
                for (int i = 0; i < 4; i++) {
                    if (mask & (1 << i)) {
                        uint8_t* byte_ptr = (uint8_t*)&data_memory[addr/4];
                        byte_ptr[i] = (data >> (8*i)) & 0xFF;
                    }
                }
            }
        }
    }

    // 加載程序
    bool loadProgram(const char* filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "無法打開程序文件: " << filename << std::endl;
            return false;
        }

        // 讀取ELF或二進制文件內容到指令記憶體
        // 這裡需要根據具體的文件格式實現加載邏輯
        // ...

        return true;
    }

    // 執行程序並收集結果
    void runAndCollectSignature(const char* signature_file) {
        std::ofstream sig_file(signature_file);
        if (!sig_file.is_open()) {
            std::cerr << "無法創建簽名文件: " << signature_file << std::endl;
            return;
        }

        // 重置處理器
        dut->resetn = 0;
        tick_clock();
        dut->resetn = 1;

        // 運行直到遇到halt信號或達到最大週期
        unsigned long max_cycles = 10000;
        while (!dut->halt && tick < max_cycles) {
            tick_clock();
        }

        // 寫入執行結果到簽名文件
        // 需要根據RISCOF的要求格式輸出結果
        // ...

        sig_file.close();
    }
};

// 主函數
int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "用法: " << argv[0] << " <程序文件> <簽名文件>" << std::endl;
        return 1;
    }

    // 初始化Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // 創建測試平台
    TestBench* tb = new TestBench();
    
    // 可選：開啟波形追蹤
    tb->openTrace("trace.vcd");

    // 加載並運行程序
    if (!tb->loadProgram(argv[1])) {
        return 1;
    }
    
    // 執行並生成簽名
    tb->runAndCollectSignature(argv[2]);

    delete tb;
    return 0;
}