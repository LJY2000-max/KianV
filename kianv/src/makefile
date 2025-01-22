# 編譯測試平台的Makefile
CXX = g++
VERILATOR = verilator
VERILATOR_ROOT = $(shell verilator --getenv VERILATOR_ROOT)
VINC = $(VERILATOR_ROOT)/include

# Verilator和編譯器標誌
VFLAGS = -Wall --trace -cc --exe
CXXFLAGS = -std=c++17 -Wall -I$(VINC) -I obj_dir -pthread
VERILATED_OBJS = $(VINC)/verilated.cpp $(VINC)/verilated_vcd_c.cpp $(VINC)/verilated_threads.cpp

# 源文件
VSRC = kianv_harris_pipelined_edition.sv
CSRC = tb_kianv.cpp

# 目標文件
TARGET = kianv_sim

all: $(TARGET)

# 先用 verilator 生成所需文件
obj_dir/V$(VSRC:.sv=.mk): $(VSRC) $(CSRC)
	$(VERILATOR) $(VFLAGS) $(VSRC) $(CSRC)

# 編譯 verilator 生成的文件
obj_dir/V$(VSRC:.sv=__ALL.a): obj_dir/V$(VSRC:.sv=.mk)
	$(MAKE) -C obj_dir -f V$(VSRC:.sv=.mk)

# 修改最後的鏈接命令 - 直接編譯 verilated 源文件
$(TARGET): obj_dir/V$(VSRC:.sv=__ALL.a)
	$(CXX) $(CXXFLAGS) \
	    obj_dir/V$(VSRC:.sv=__ALL.a) \
	    $(VERILATED_OBJS) \
	    $(CSRC) \
	    -I$(VINC) \
	    -lpthread -o ./$(TARGET)

clean:
	rm -rf obj_dir $(TARGET)