# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vkianv_harris_pipelined_edition.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vkianv_harris_pipelined_edition \
	Vkianv_harris_pipelined_edition___024root__DepSet_hada9a8c0__0 \
	Vkianv_harris_pipelined_edition___024root__DepSet_h031d8ae9__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vkianv_harris_pipelined_edition__ConstPool_0 \
	Vkianv_harris_pipelined_edition___024root__Slow \
	Vkianv_harris_pipelined_edition___024root__DepSet_hada9a8c0__0__Slow \
	Vkianv_harris_pipelined_edition___024root__DepSet_h031d8ae9__0__Slow \
	Vkianv_harris_pipelined_edition___024unit__Slow \
	Vkianv_harris_pipelined_edition___024unit__DepSet_h2a9797dc__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vkianv_harris_pipelined_edition__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vkianv_harris_pipelined_edition__Syms \
	Vkianv_harris_pipelined_edition__Trace__0__Slow \
	Vkianv_harris_pipelined_edition__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
