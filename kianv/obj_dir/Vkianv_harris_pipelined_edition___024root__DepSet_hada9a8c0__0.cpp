// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "Vkianv_harris_pipelined_edition__Syms.h"
#include "Vkianv_harris_pipelined_edition___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__ico(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG

void Vkianv_harris_pipelined_edition___024root___eval_triggers__ico(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkianv_harris_pipelined_edition___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__act(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG

void Vkianv_harris_pipelined_edition___024root___eval_triggers__act(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkianv_harris_pipelined_edition___024root___dump_triggers__act(vlSelf);
    }
#endif
}
