// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#ifndef VERILATED_VKIANV_HARRIS_PIPELINED_EDITION___024ROOT_H_
#define VERILATED_VKIANV_HARRIS_PIPELINED_EDITION___024ROOT_H_  // guard

#include "verilated.h"


class Vkianv_harris_pipelined_edition__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkianv_harris_pipelined_edition___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(resetn,0,0);
        VL_IN8(halt,0,0);
        VL_OUT8(WriteMaskM,3,0);
        VL_OUT8(ReadMemM,0,0);
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__ResultSrcD;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__AluControlD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__AluSrcAD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__AluSrcBD;
        CData/*2:0*/ kianv_harris_pipelined_edition__DOT__ImmSrcD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__PCTargetSrcD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__RegWriteD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__PCWrite;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__MemWriteD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__JumpD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__BranchD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__CsrInstrIncD;
        CData/*2:0*/ kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW;
        CData/*3:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultSrcE0;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q;
        CData/*2:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q;
        CData/*4:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q;
        CData/*2:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q;
        CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q;
        CData/*2:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q;
        CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_IN(Instr,31,0);
        VL_IN(ReadDataM,31,0);
        VL_OUT(PCF,31,0);
        VL_OUT(AluResultM,31,0);
        VL_OUT(WriteDataM,31,0);
    };
    struct {
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__InstrD;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2M;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCF_;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt;
        IData/*31:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter;
        QData/*63:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter;
        VlUnpacked<IData/*31:0*/, 32> kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vkianv_harris_pipelined_edition__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vkianv_harris_pipelined_edition___024root(Vkianv_harris_pipelined_edition__Syms* symsp, const char* v__name);
    ~Vkianv_harris_pipelined_edition___024root();
    VL_UNCOPYABLE(Vkianv_harris_pipelined_edition___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
