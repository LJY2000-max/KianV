// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "Vkianv_harris_pipelined_edition___024root.h"

void Vkianv_harris_pipelined_edition___024root___ico_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf);

void Vkianv_harris_pipelined_edition___024root___eval_ico(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vkianv_harris_pipelined_edition___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vkianv_harris_pipelined_edition___024root___ico_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0 = 0;
    CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0 = 0;
    // Body
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn 
        = ((~ ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE) 
               & (~ (IData)(vlSelfRef.halt)))) & (IData)(vlSelfRef.resetn));
    vlSelfRef.WriteMaskM = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask) 
                            & (- (IData)(((~ (IData)(vlSelfRef.halt)) 
                                          & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM)))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall 
        = ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
             == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                          >> 0xfU))) | ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
                                        == (0x1fU & 
                                            (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                             >> 0x14U)))) 
           & ((3U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)) 
              & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF) 
           | (IData)(vlSelfRef.halt));
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0 
        = (3U & ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD) 
                   << 1U) | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE)) 
                 | (7U & (- (IData)((IData)(vlSelfRef.halt))))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF 
        = kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD 
        = (1U & ((IData)(kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0) 
                 >> 1U));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = (1U & (IData)(kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE) 
           | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE) 
           & (~ (IData)(vlSelfRef.halt)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn 
        = ((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE)) 
           & (IData)(vlSelfRef.resetn));
}

void Vkianv_harris_pipelined_edition___024root___eval_triggers__ico(Vkianv_harris_pipelined_edition___024root* vlSelf);

bool Vkianv_harris_pipelined_edition___024root___eval_phase__ico(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vkianv_harris_pipelined_edition___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vkianv_harris_pipelined_edition___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vkianv_harris_pipelined_edition___024root___eval_act(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vkianv_harris_pipelined_edition___024root___nba_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf);

void Vkianv_harris_pipelined_edition___024root___eval_nba(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vkianv_harris_pipelined_edition___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

extern const VlUnpacked<CData/*2:0*/, 1024> Vkianv_harris_pipelined_edition__ConstPool__TABLE_he196a955_0;

VL_INLINE_OPT void Vkianv_harris_pipelined_edition___024root___nba_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0 = 0;
    CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0 = 0;
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    QData/*63:0*/ __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter;
    __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter = 0;
    QData/*63:0*/ __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter;
    __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter = 0;
    IData/*31:0*/ __VdlyVal__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0;
    __VdlyVal__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 = 0;
    CData/*4:0*/ __VdlyDim0__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0;
    __VdlyDim0__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 = 0;
    CData/*0:0*/ __VdlySet__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0;
    __VdlySet__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 = 0;
    // Body
    __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter;
    __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter;
    __VdlySet__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 = 0U;
    if (((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
         & (0U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW)))) {
        __VdlyVal__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 
            = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW;
        __VdlyDim0__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 
            = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW;
        __VdlySet__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0 = 1U;
    }
    if (vlSelfRef.resetn) {
        __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
            = (1ULL + vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter);
        if (((~ (IData)(vlSelfRef.halt)) & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE))) {
            __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter 
                = (1ULL + vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter);
        }
        if ((1U & (~ (IData)(vlSelfRef.halt)))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW 
                = vlSelfRef.ReadDataM;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW 
                = vlSelfRef.AluResultM;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2M 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E;
            if ((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))) {
                vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q = 0U;
                vlSelfRef.AluResultM = (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                         & (0xc02U 
                                            == (0xfffU 
                                                & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                         ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter)
                                         : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                             & (0xc82U 
                                                == 
                                                (0xfffU 
                                                 & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                             ? (IData)(
                                                       (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter 
                                                        >> 0x20U))
                                             : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                                 & (0xc00U 
                                                    == 
                                                    (0xfffU 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                                 ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter)
                                                 : 
                                                (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                                  & (0xc80U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                                  ? (IData)(
                                                            (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
                                                             >> 0x20U))
                                                  : 
                                                 (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                                   & (0xc01U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                                   ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter)
                                                   : 
                                                  (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                                    & (0xc81U 
                                                       == 
                                                       (0xfffU 
                                                        & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                                    ? (IData)(
                                                              (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
                                                               >> 0x20U))
                                                    : 0U))))));
            } else {
                vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q 
                    = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q;
                vlSelfRef.AluResultM = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE;
            }
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q;
        }
    } else {
        __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter = 0ULL;
        __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter = 0ULL;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2M = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q = 0U;
        vlSelfRef.AluResultM = 0U;
    }
    if (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn) {
        if ((1U & (~ (IData)(vlSelfRef.halt)))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__JumpD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__BranchD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__AluControlD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcAD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E 
                = (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                            >> 0x14U));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E 
                = (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                            >> 0xfU));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E 
                = ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                     == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0xfU))) & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                                & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                       >> 0xfU)))))
                    ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                    : ((0U == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                        >> 0xfU))) ? 0U
                        : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                       [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0xfU))]));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__CsrInstrIncD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__MemWriteD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q 
                = ((0U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                 >> 0xcU))) ? 0U : 
                   ((1U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0xcU))) ? 1U : 
                    ((2U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                   >> 0xcU))) ? 2U : 0U)));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E 
                = ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                     == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0x14U))) & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                                 & (0U 
                                                    != 
                                                    (0x1fU 
                                                     & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                        >> 0x14U)))))
                    ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                    : ((0U == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                        >> 0x14U)))
                        ? 0U : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                       [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0x14U))]));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D;
        }
    } else {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E = 0U;
    }
    if (vlSelfRef.resetn) {
        if ((1U & (~ (IData)(vlSelfRef.halt)))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE;
        }
    } else {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM = 0U;
    }
    if (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn) {
        if ((1U & (~ (IData)(vlSelfRef.halt)))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q 
                = ((0U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                 >> 0xcU))) ? 0U : 
                   ((1U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 0xcU))) ? 2U : 
                    ((2U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                   >> 0xcU))) ? 4U : 
                     ((4U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                    >> 0xcU))) ? 1U
                       : ((5U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                        >> 0xcU))) ? 3U
                           : 0U)))));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q 
                = (2U != (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                >> 0xcU)));
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE 
                = vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE 
                = (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                            >> 7U));
        }
    } else {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE = 0U;
    }
    if (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn) {
        if ((1U & (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD)))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD 
                = vlSelfRef.PCF;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D 
                = ((IData)(4U) + vlSelfRef.PCF);
            vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                = vlSelfRef.Instr;
        }
    } else {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD = 0x13U;
    }
    if (vlSelfRef.resetn) {
        if ((1U & (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF)))) {
            vlSelfRef.PCF = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCF_;
        }
    } else {
        vlSelfRef.PCF = 0U;
    }
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW = 0U;
    if (((0U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q)) 
         | (1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q)))) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
            = ((0xffffff00U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW) 
               | (0xffU & ((0U == (3U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW))
                            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW
                            : ((1U == (3U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW))
                                ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW 
                                   >> 8U) : ((2U == 
                                              (3U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW))
                                              ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW 
                                                 >> 0x10U)
                                              : ((3U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW))
                                                  ? 
                                                 (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW 
                                                  >> 0x18U)
                                                  : 0U))))));
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
            = ((((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))
                  ? 0U : (0xffffffU & (- (IData)((1U 
                                                  & (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
                                                     >> 7U)))))) 
                << 8U) | (0xffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW));
    }
    if (((2U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q)) 
         | (3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q)))) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
            = ((0xffff0000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW) 
               | (0xffffU & ((2U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW)
                              ? ((2U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW)
                                  ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW 
                                     >> 0x10U) : 0U)
                              : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW)));
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
            = ((((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))
                  ? 0U : (0xffffU & (- (IData)((1U 
                                                & (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
                                                   >> 0xfU)))))) 
                << 0x10U) | (0xffffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW));
    }
    if ((4U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW 
            = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW;
    }
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter 
        = __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
        = __Vdly__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter;
    if (__VdlySet__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[__VdlyDim0__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0] 
            = __VdlyVal__kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank__v0;
    }
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW 
        = ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q))
            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W
            : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q))
                ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW
                : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW));
    vlSelfRef.ReadMemM = (1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q));
    vlSelfRef.WriteDataM = 0U;
    if ((0U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q))) {
        vlSelfRef.WriteDataM = ((0xffff0000U & vlSelfRef.WriteDataM) 
                                | ((((1U == (3U & vlSelfRef.AluResultM))
                                      ? (0xffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)
                                      : 0U) << 8U) 
                                   | ((0U == (3U & vlSelfRef.AluResultM))
                                       ? (0xffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)
                                       : 0U)));
        vlSelfRef.WriteDataM = ((0xffffU & vlSelfRef.WriteDataM) 
                                | ((((3U == (3U & vlSelfRef.AluResultM))
                                      ? (0xffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)
                                      : 0U) << 0x18U) 
                                   | (((2U == (3U & vlSelfRef.AluResultM))
                                        ? (0xffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)
                                        : 0U) << 0x10U)));
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask 
            = ((0U == (3U & vlSelfRef.AluResultM)) ? 1U
                : ((1U == (3U & vlSelfRef.AluResultM))
                    ? 2U : ((2U == (3U & vlSelfRef.AluResultM))
                             ? 4U : 8U)));
    } else if ((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q))) {
        vlSelfRef.WriteDataM = ((((2U & vlSelfRef.AluResultM)
                                   ? (0xffffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)
                                   : 0U) << 0x10U) 
                                | ((2U & vlSelfRef.AluResultM)
                                    ? 0U : (0xffffU 
                                            & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM)));
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask 
            = ((2U & vlSelfRef.AluResultM) ? 0xcU : 3U);
    } else if ((2U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q))) {
        vlSelfRef.WriteDataM = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask = 0xfU;
    } else {
        vlSelfRef.WriteDataM = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask = 0U;
    }
    vlSelfRef.WriteMaskM = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask) 
                            & (- (IData)(((~ (IData)(vlSelfRef.halt)) 
                                          & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM)))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE 
        = (((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E) 
              == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM)) 
             & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM)) 
            & (0U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E)))
            ? 2U : (((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E) 
                       == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW)) 
                      & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW)) 
                     & (0U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E)))
                     ? 1U : 0U));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE 
        = (((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E) 
              == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM)) 
             & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM)) 
            & (0U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E)))
            ? 2U : (((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E) 
                       == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW)) 
                      & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW)) 
                     & (0U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E)))
                     ? 1U : 0U));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE 
        = ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE))
            ? vlSelfRef.AluResultM : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE))
                                       ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                                       : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q)
            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE
            : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE))
                ? vlSelfRef.AluResultM : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE))
                                           ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                                           : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q)
            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE
            : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE);
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt 
        = (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
           < vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE);
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum 
        = (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
           + (((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                ? (~ vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE) 
              + (1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE 
        = ((0x10U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
            ? ((8U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                ? 0U : ((4U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                         ? 0U : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                                  ? 0U : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                                           ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                              >= vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                                           : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                              < vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)))))
            : ((8U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                ? ((4U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                    ? ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                        ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                            ? ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                >= vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE) 
                               ^ ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                   >> 0x1fU) != (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE 
                                                 >> 0x1fU)))
                            : ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                < vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE) 
                               ^ ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                   >> 0x1fU) != (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE 
                                                 >> 0x1fU))))
                        : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                            ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                               != vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                            : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                               == vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)))
                    : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                        ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt
                            : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                        : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum
                            : (((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                 >> 0x1fU) == (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE 
                                               >> 0x1fU))
                                ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt
                                : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                   >> 0x1fU))))) : 
               ((4U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                 ? ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                     ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                         ? (IData)(((((QData)((IData)(
                                                      (- (IData)(
                                                                 (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                                                  >> 0x1fU))))) 
                                      << 0x20U) | (QData)((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE))) 
                                    >> (0x1fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)))
                         : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                            >> (0x1fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)))
                     : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                         ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                            << (0x1fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE))
                         : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                            & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)))
                 : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                     ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                         ? (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                            | vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                         : (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                            ^ vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE))
                     : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__BranchD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__JumpD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__MemWriteD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD = 0U;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__CsrInstrIncD = 1U;
    if ((1U & (~ ((((((((3U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                        | (0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                       | (0x33U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                      | (0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                     | (0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                    | (0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                   | (0x63U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                  | (0x37U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))))) {
        if ((0x17U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
            if ((0x73U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                vlSelfRef.kianv_harris_pipelined_edition__DOT__CsrInstrIncD = 0U;
            }
        }
    }
    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcAD = 0U;
    if (((((((((3U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
               | (0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
              | (0x33U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
             | (0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
            | (0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
           | (0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
          | (0x63U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
         | (0x37U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))) {
        if ((3U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
            if ((0x23U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                if ((0x33U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    if ((0x13U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                        if ((0x6fU != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            if ((0x67U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                                if ((0x63U == (0x7fU 
                                               & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                                    vlSelfRef.kianv_harris_pipelined_edition__DOT__BranchD = 1U;
                                }
                            }
                        }
                        if ((0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__JumpD = 1U;
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD = 1U;
                        } else if ((0x67U == (0x7fU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__JumpD = 1U;
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD = 0U;
                        } else if ((0x63U == (0x7fU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD = 1U;
                        }
                    }
                }
            }
            if ((0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                vlSelfRef.kianv_harris_pipelined_edition__DOT__MemWriteD = 1U;
            }
        }
        if ((3U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
            vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 1U;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
            vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcAD = 0U;
        } else {
            if ((0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
            } else if ((0x33U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                if ((0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
                } else if ((0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
                } else if ((0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
                } else if ((0x63U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
                }
            }
            if ((0x23U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                if ((0x33U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    if ((0x13U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                        if ((0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 2U;
                        } else if ((0x67U == (0x7fU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 2U;
                        } else if ((0x63U != (0x7fU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                            vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 0U;
                        }
                    }
                }
                if ((0x33U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
                } else if ((0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
                } else if ((0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
                } else if ((0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
                } else if ((0x63U != (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
                    vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
                }
            }
        }
    } else if ((0x17U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD = 1U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 0U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcAD = 1U;
    } else if ((0x73U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) {
        vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD = 3U;
        vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD = 1U;
    }
    __Vtableidx1 = (((((0x17U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                       << 9U) | (((0x37U == (0x7fU 
                                             & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                  << 8U) | ((0x63U 
                                             == (0x7fU 
                                                 & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                            << 7U))) 
                     | (((0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                         << 6U) | ((0x6fU == (0x7fU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                   << 5U))) | ((((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                                 << 4U) 
                                                | ((8U 
                                                    & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                       >> 0x16U)) 
                                                   | ((0x33U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                                      << 2U))) 
                                               | (((0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                                   << 1U) 
                                                  | (3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp 
        = Vkianv_harris_pipelined_edition__ConstPool__TABLE_he196a955_0
        [__Vtableidx1];
    vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD 
        = ((0x33U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))
            ? 0U : (((((0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                       | (0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                      | (3U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))) 
                     | (0x73U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))
                     ? 0U : ((0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))
                              ? 1U : ((0x63U == (0x7fU 
                                                 & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))
                                       ? 2U : (((0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))
                                                ? 4U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))
                                                    ? 3U
                                                    : 0U))))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE 
        = (((0U != vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE) 
            & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE)) 
           | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD 
        = ((4U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
            ? ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
                ? 0U : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
                         ? 0U : (0xfffff000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))
            : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
                ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
                    ? (((- (IData)((vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                    >> 0x1fU))) << 0x14U) 
                       | (((0xff000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD) 
                           | (0x800U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                        >> 9U))) | 
                          (0x7feU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                     >> 0x14U)))) : 
                   (((- (IData)((vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                 >> 0x1fU))) << 0xcU) 
                    | ((0x800U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  << 4U)) | ((0x7e0U 
                                              & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0x14U)) 
                                             | (0x1eU 
                                                & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                   >> 7U))))))
                : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD))
                    ? (((- (IData)((vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                      >> 7U))))
                    : (((- (IData)((vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                          >> 0x14U)))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn 
        = ((~ ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE) 
               & (~ (IData)(vlSelfRef.halt)))) & (IData)(vlSelfRef.resetn));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCF_ 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE)
            ? (((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q)
                 ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE
                 : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE) 
               + vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)
            : ((IData)(4U) + vlSelfRef.PCF));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall 
        = ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
             == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                          >> 0xfU))) | ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
                                        == (0x1fU & 
                                            (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                             >> 0x14U)))) 
           & ((3U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)) 
              & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF) 
           | (IData)(vlSelfRef.halt));
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0 
        = (3U & ((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD) 
                   << 1U) | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE)) 
                 | (7U & (- (IData)((IData)(vlSelfRef.halt))))));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF 
        = kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0;
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD 
        = (1U & ((IData)(kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0) 
                 >> 1U));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = (1U & (IData)(kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE) 
           | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE 
        = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE) 
           & (~ (IData)(vlSelfRef.halt)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__AluControlD 
        = ((4U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
            ? ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
                ? 0U : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
                         ? ((0x4000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                             ? ((0x2000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                 ? ((0x1000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                     ? 0x11U : 0x10U)
                                 : ((0x1000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                     ? 0xfU : 0xeU))
                             : ((0x2000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                 ? 0U : ((0x1000U & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                          ? 0xdU : 0xcU)))
                         : 9U)) : ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
                                    ? ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
                                        ? 0xaU : ((0x4000U 
                                                   & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                     ? 
                                                    ((1U 
                                                      & ((~ 
                                                          ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD 
                                                            >> 0xaU) 
                                                           | (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                              >> 5U))) 
                                                         | (IData)(
                                                                   (0x20U 
                                                                    == 
                                                                    (0x40000020U 
                                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))))
                                                      ? 6U
                                                      : 7U)
                                                     : 2U))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                     ? 0xbU
                                                     : 8U)
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)
                                                     ? 5U
                                                     : 
                                                    ((IData)(
                                                             (0x40000020U 
                                                              == 
                                                              (0x40000020U 
                                                               & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))
                                                      ? 1U
                                                      : 0U)))))
                                    : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp))
                                        ? 1U : 0U)));
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn 
        = ((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE)) 
           & (IData)(vlSelfRef.resetn));
}

void Vkianv_harris_pipelined_edition___024root___eval_triggers__act(Vkianv_harris_pipelined_edition___024root* vlSelf);

bool Vkianv_harris_pipelined_edition___024root___eval_phase__act(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vkianv_harris_pipelined_edition___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vkianv_harris_pipelined_edition___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vkianv_harris_pipelined_edition___024root___eval_phase__nba(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vkianv_harris_pipelined_edition___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__ico(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__nba(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__act(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG

void Vkianv_harris_pipelined_edition___024root___eval(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vkianv_harris_pipelined_edition___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("kianv_harris_pipelined_edition.sv", 16, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vkianv_harris_pipelined_edition___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vkianv_harris_pipelined_edition___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("kianv_harris_pipelined_edition.sv", 16, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vkianv_harris_pipelined_edition___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("kianv_harris_pipelined_edition.sv", 16, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vkianv_harris_pipelined_edition___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vkianv_harris_pipelined_edition___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vkianv_harris_pipelined_edition___024root___eval_debug_assertions(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.resetn & 0xfeU))) {
        Verilated::overWidthError("resetn");}
    if (VL_UNLIKELY((vlSelfRef.halt & 0xfeU))) {
        Verilated::overWidthError("halt");}
}
#endif  // VL_DEBUG
