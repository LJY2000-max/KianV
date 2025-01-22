// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "Vkianv_harris_pipelined_edition__Syms.h"
#include "Vkianv_harris_pipelined_edition___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___dump_triggers__stl(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root___eval_triggers__stl(Vkianv_harris_pipelined_edition___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkianv_harris_pipelined_edition___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
