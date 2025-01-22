// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "Vkianv_harris_pipelined_edition___024root.h"

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_static(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_initial(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_final(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__stl(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vkianv_harris_pipelined_edition___024root___eval_phase__stl(Vkianv_harris_pipelined_edition___024root* vlSelf);

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_settle(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vkianv_harris_pipelined_edition___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("src/kianv_harris_pipelined_edition.sv", 16, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vkianv_harris_pipelined_edition___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__stl(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___stl_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf);
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root____Vm_traceActivitySetAll(Vkianv_harris_pipelined_edition___024root* vlSelf);

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_stl(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vkianv_harris_pipelined_edition___024root___stl_sequent__TOP__0(vlSelf);
        Vkianv_harris_pipelined_edition___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 1024> Vkianv_harris_pipelined_edition__ConstPool__TABLE_he196a955_0;

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___stl_sequent__TOP__0(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h7d159660__0 = 0;
    CData/*1:0*/ kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0;
    kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT____Vconcswap_1_h43a4b6d3__0 = 0;
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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
    vlSelfRef.WriteMaskM = ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask) 
                            & (- (IData)(((~ (IData)(vlSelfRef.halt)) 
                                          & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM)))));
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
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW 
        = ((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q))
            ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W
            : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q))
                ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW
                : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW));
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
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE 
        = (((0U != vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE) 
            & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE)) 
           | (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE));
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
    vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn 
        = ((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE)) 
           & (IData)(vlSelfRef.resetn));
}

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_triggers__stl(Vkianv_harris_pipelined_edition___024root* vlSelf);

VL_ATTR_COLD bool Vkianv_harris_pipelined_edition___024root___eval_phase__stl(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vkianv_harris_pipelined_edition___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vkianv_harris_pipelined_edition___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__ico(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__act(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__nba(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root____Vm_traceActivitySetAll(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___ctor_var_reset(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->resetn = VL_RAND_RESET_I(1);
    vlSelf->halt = VL_RAND_RESET_I(1);
    vlSelf->Instr = VL_RAND_RESET_I(32);
    vlSelf->ReadDataM = VL_RAND_RESET_I(32);
    vlSelf->PCF = VL_RAND_RESET_I(32);
    vlSelf->WriteMaskM = VL_RAND_RESET_I(4);
    vlSelf->ReadMemM = VL_RAND_RESET_I(1);
    vlSelf->AluResultM = VL_RAND_RESET_I(32);
    vlSelf->WriteDataM = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__ResultSrcD = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__AluControlD = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__AluSrcAD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__AluSrcBD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__ImmSrcD = VL_RAND_RESET_I(3);
    vlSelf->kianv_harris_pipelined_edition__DOT__PCTargetSrcD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__RegWriteD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__PCWrite = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__MemWriteD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__JumpD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__BranchD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__CsrInstrIncD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__InstrD = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp = VL_RAND_RESET_I(3);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2M = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask = VL_RAND_RESET_I(4);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCF_ = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultSrcE0 = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q = VL_RAND_RESET_I(3);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q = VL_RAND_RESET_I(5);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q = VL_RAND_RESET_I(1);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q = VL_RAND_RESET_I(3);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q = VL_RAND_RESET_I(2);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q = VL_RAND_RESET_I(3);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum = VL_RAND_RESET_I(32);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter = VL_RAND_RESET_Q(64);
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
