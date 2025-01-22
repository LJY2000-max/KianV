# 工具鏈和編譯器設定
CXX = g++
VERILATOR = verilator
VERILATOR_ROOT = $(shell verilator --getenv VERILATOR_ROOT)
VINC = $(VERILATOR_ROOT)/include

# 目錄設定
SRC_DIR = src
TB_DIR = tb
BUILD_DIR = obj_dir

# 源檔案
VSRC = $(SRC_DIR)/kianv_harris_pipelined_edition.sv
CSRC = $(TB_DIR)/tb_kianv.cpp

# 自動找出所有的 SystemVerilog 源檔案
SV_SRCS = $(wildcard $(SRC_DIR)/*.sv)

# 目標檔案
TARGET = kianv_sim

# Verilator 和編譯器標誌
VFLAGS = -Wall --trace -cc --exe -I$(SRC_DIR)
CXXFLAGS = -std=c++17 -Wall -I$(VINC) -I$(BUILD_DIR) -pthread
VERILATED_OBJS = $(VINC)/verilated.cpp $(VINC)/verilated_vcd_c.cpp $(VINC)/verilated_threads.cpp

# 默認目標
all: $(TARGET)

# 創建構建目錄
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Verilator 編譯
$(BUILD_DIR)/Vkianv_harris_pipelined_edition.mk: $(SV_SRCS) $(CSRC) | $(BUILD_DIR)
	$(VERILATOR) $(VFLAGS) $(VSRC) $(CSRC) --Mdir $(BUILD_DIR)

# 編譯 Verilator 生成的檔案
$(BUILD_DIR)/Vkianv_harris_pipelined_edition__ALL.a: $(BUILD_DIR)/Vkianv_harris_pipelined_edition.mk
	$(MAKE) -C $(BUILD_DIR) -f Vkianv_harris_pipelined_edition.mk

# 最終連結
$(TARGET): $(BUILD_DIR)/Vkianv_harris_pipelined_edition__ALL.a
	$(CXX) $(CXXFLAGS) \
		$(BUILD_DIR)/Vkianv_harris_pipelined_edition__ALL.a \
		$(VERILATED_OBJS) \
		$(CSRC) \
		-I$(VINC) \
		-lpthread -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean