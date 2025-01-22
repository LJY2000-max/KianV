// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vkianv_harris_pipelined_edition__Syms.h"


void Vkianv_harris_pipelined_edition___024root__trace_chg_0_sub_0(Vkianv_harris_pipelined_edition___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vkianv_harris_pipelined_edition___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root__trace_chg_0\n"); );
    // Init
    Vkianv_harris_pipelined_edition___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkianv_harris_pipelined_edition___024root*>(voidSelf);
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vkianv_harris_pipelined_edition___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vkianv_harris_pipelined_edition___024root__trace_chg_0_sub_0(Vkianv_harris_pipelined_edition___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF));
        bufp->chgBit(oldp+1,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD));
        bufp->chgBit(oldp+2,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__FlushE));
        bufp->chgBit(oldp+3,((1U & (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallF)))));
        bufp->chgBit(oldp+4,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT__FlushE_resetn));
        bufp->chgBit(oldp+5,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__fetch_stage_i__DOT__FlushD_resetn));
        bufp->chgBit(oldp+6,((1U & (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__StallD)))));
        bufp->chgBit(oldp+7,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__hazard_unit_i__DOT__lwStall));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+8,((0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)),7);
        bufp->chgCData(oldp+9,((7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                      >> 0xcU))),3);
        bufp->chgBit(oldp+10,((1U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+11,((1U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                     >> 0x19U))));
        bufp->chgBit(oldp+12,((1U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD 
                                     >> 0xaU))));
        bufp->chgCData(oldp+13,(vlSelfRef.kianv_harris_pipelined_edition__DOT__ResultSrcD),2);
        bufp->chgCData(oldp+14,(vlSelfRef.kianv_harris_pipelined_edition__DOT__AluControlD),5);
        bufp->chgBit(oldp+15,(vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcAD));
        bufp->chgBit(oldp+16,(vlSelfRef.kianv_harris_pipelined_edition__DOT__AluSrcBD));
        bufp->chgCData(oldp+17,(vlSelfRef.kianv_harris_pipelined_edition__DOT__ImmSrcD),3);
        bufp->chgBit(oldp+18,(vlSelfRef.kianv_harris_pipelined_edition__DOT__PCTargetSrcD));
        bufp->chgCData(oldp+19,(((0U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                               >> 0xcU)))
                                  ? 0U : ((1U == (3U 
                                                  & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                     >> 0xcU)))
                                           ? 1U : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                        >> 0xcU)))
                                                    ? 2U
                                                    : 0U)))),2);
        bufp->chgCData(oldp+20,(((0U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                               >> 0xcU)))
                                  ? 0U : ((1U == (7U 
                                                  & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                     >> 0xcU)))
                                           ? 2U : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                        >> 0xcU)))
                                                    ? 4U
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                         >> 0xcU)))
                                                     ? 1U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                          >> 0xcU)))
                                                      ? 3U
                                                      : 0U)))))),3);
        bufp->chgBit(oldp+21,((2U != (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+22,(vlSelfRef.kianv_harris_pipelined_edition__DOT__RegWriteD));
        bufp->chgBit(oldp+23,(vlSelfRef.kianv_harris_pipelined_edition__DOT__MemWriteD));
        bufp->chgBit(oldp+24,(vlSelfRef.kianv_harris_pipelined_edition__DOT__JumpD));
        bufp->chgBit(oldp+25,(vlSelfRef.kianv_harris_pipelined_edition__DOT__BranchD));
        bufp->chgBit(oldp+26,(vlSelfRef.kianv_harris_pipelined_edition__DOT__CsrInstrIncD));
        bufp->chgIData(oldp+27,(vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD),32);
        bufp->chgCData(oldp+28,(vlSelfRef.kianv_harris_pipelined_edition__DOT__control_unit_i__DOT__AluOp),3);
        bufp->chgBit(oldp+29,((1U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                     >> 5U))));
        bufp->chgBit(oldp+30,((IData)((0x40000020U 
                                       == (0x40000020U 
                                           & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))));
        bufp->chgBit(oldp+31,((1U & ((~ ((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD 
                                          >> 0xaU) 
                                         | (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 5U))) 
                                     | (IData)((0x20U 
                                                == 
                                                (0x40000020U 
                                                 & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD)))))));
        bufp->chgBit(oldp+32,((2U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+33,((0U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+34,((1U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+35,((4U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+36,((5U == (7U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+37,((3U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+38,((0x23U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+39,((0x33U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+40,((0x13U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+41,((0x6fU == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+42,((0x67U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+43,((0x63U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+44,((0x37U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+45,((0x17U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+46,((0x73U == (0x7fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD))));
        bufp->chgBit(oldp+47,((0U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+48,((1U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgBit(oldp+49,((2U == (3U & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xcU)))));
        bufp->chgIData(oldp+50,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+51,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCD),32);
        bufp->chgCData(oldp+52,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs1E),5);
        bufp->chgCData(oldp+53,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rs2E),5);
        bufp->chgIData(oldp+54,(((0U == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                  >> 0xfU)))
                                  ? 0U : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                                 [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0xfU))])),32);
        bufp->chgIData(oldp+55,(((0U == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                  >> 0x14U)))
                                  ? 0U : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                                 [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                            >> 0x14U))])),32);
        bufp->chgBit(oldp+56,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteE));
        bufp->chgCData(oldp+57,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q),2);
        bufp->chgBit(oldp+58,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q));
        bufp->chgCData(oldp+59,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__LoadOpE_i__q),3);
        bufp->chgCData(oldp+60,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__StoreOpE_i__q),2);
        bufp->chgBit(oldp+61,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteE));
        bufp->chgBit(oldp+62,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__JumpE));
        bufp->chgBit(oldp+63,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE));
        bufp->chgBit(oldp+64,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE));
        bufp->chgCData(oldp+65,((0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+66,((0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+67,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE),5);
        bufp->chgIData(oldp+68,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E),32);
        bufp->chgIData(oldp+69,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2E),32);
        bufp->chgCData(oldp+70,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q),5);
        bufp->chgBit(oldp+71,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q));
        bufp->chgBit(oldp+72,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q));
        bufp->chgIData(oldp+73,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4E),32);
        bufp->chgIData(oldp+74,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE),32);
        bufp->chgIData(oldp+75,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE),32);
        bufp->chgBit(oldp+76,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q));
        bufp->chgBit(oldp+77,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteM));
        bufp->chgCData(oldp+78,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__ResultSrcM_i__q),2);
        bufp->chgBit(oldp+79,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__MemWriteM));
        bufp->chgCData(oldp+80,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__LoadOpM_t__q),3);
        bufp->chgCData(oldp+81,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT____Vcellout__StoreOpM_i__q),2);
        bufp->chgIData(oldp+82,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd2M),32);
        bufp->chgCData(oldp+83,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdM),5);
        bufp->chgIData(oldp+84,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4M),32);
        bufp->chgIData(oldp+85,((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q)
                                   ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE
                                   : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE) 
                                 + vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)),32);
        bufp->chgIData(oldp+86,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE),32);
        bufp->chgIData(oldp+87,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE),32);
        bufp->chgCData(oldp+88,(((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))
                                  ? 0U : (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))),2);
        bufp->chgIData(oldp+89,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__WriteDataUnAlignedM),32);
        bufp->chgBit(oldp+90,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW));
        bufp->chgCData(oldp+91,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__ResultSrcW_i__q),2);
        bufp->chgCData(oldp+92,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q),3);
        bufp->chgCData(oldp+93,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW),5);
        bufp->chgIData(oldp+94,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW),32);
        bufp->chgCData(oldp+95,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__wmask),4);
        bufp->chgIData(oldp+96,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+97,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataW),32);
        bufp->chgIData(oldp+98,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ReadDataAlignedW),32);
        bufp->chgBit(oldp+99,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE));
        bufp->chgIData(oldp+100,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtD),32);
        bufp->chgIData(oldp+101,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE),32);
        bufp->chgBit(oldp+102,((0U == vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE)));
        bufp->chgBit(oldp+103,(((0U != vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE) 
                                & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__BranchE))));
        bufp->chgCData(oldp+104,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE),2);
        bufp->chgCData(oldp+105,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardBE),2);
        bufp->chgBit(oldp+106,((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                                 == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                              >> 0xfU))) 
                                & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                   & (0U != (0x1fU 
                                             & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                >> 0xfU)))))));
        bufp->chgBit(oldp+107,((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                                 == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                              >> 0x14U))) 
                                & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                   & (0U != (0x1fU 
                                             & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                >> 0x14U)))))));
        bufp->chgIData(oldp+108,((((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                   & (0xc02U == (0xfffU 
                                                 & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                   ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter)
                                   : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                       & (0xc82U == 
                                          (0xfffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                       ? (IData)((vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter 
                                                  >> 0x20U))
                                       : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                           & (0xc00U 
                                              == (0xfffU 
                                                  & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                           ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter)
                                           : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                               & (0xc80U 
                                                  == 
                                                  (0xfffU 
                                                   & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                               ? (IData)(
                                                         (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter 
                                                          >> 0x20U))
                                               : ((
                                                   (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
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
                                                    : 0U))))))),32);
        bufp->chgIData(oldp+109,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW),32);
        bufp->chgBit(oldp+110,(((3U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)) 
                                & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))));
        bufp->chgIData(oldp+111,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sltx_sltux_rslt),32);
        bufp->chgQData(oldp+112,((((QData)((IData)(
                                                   (- (IData)(
                                                              (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                                               >> 0x1fU))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE)))),64);
        bufp->chgQData(oldp+114,(((((QData)((IData)(
                                                    (- (IData)(
                                                               (vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE))) 
                                  >> (0x1fU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE))),64);
        bufp->chgBit(oldp+116,((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))));
        bufp->chgIData(oldp+117,(((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluControlE_i__q))
                                   ? (~ vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)
                                   : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcBE)),32);
        bufp->chgIData(oldp+118,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__alu32_i__DOT__sum),32);
        bufp->chgSData(oldp+119,((0xfffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)),12);
        bufp->chgQData(oldp+120,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__cycle_counter),64);
        bufp->chgQData(oldp+122,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter),64);
        bufp->chgBit(oldp+124,((1U & (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)))));
        bufp->chgBit(oldp+125,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc00U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgBit(oldp+126,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc80U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgBit(oldp+127,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc02U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgBit(oldp+128,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc82U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgBit(oldp+129,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc01U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgBit(oldp+130,(((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                & (0xc81U == (0xfffU 
                                              & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))));
        bufp->chgCData(oldp+131,((0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                           >> 7U))),5);
        bufp->chgIData(oldp+132,(((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                                    == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0xfU))) 
                                   & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                      & (0U != (0x1fU 
                                                & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                   >> 0xfU)))))
                                   ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                                   : ((0U == (0x1fU 
                                              & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0xfU)))
                                       ? 0U : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                                      [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0xfU))]))),32);
        bufp->chgIData(oldp+133,(((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdW) 
                                    == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0x14U))) 
                                   & ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RegWriteW) 
                                      & (0U != (0x1fU 
                                                & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                   >> 0x14U)))))
                                   ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                                   : ((0U == (0x1fU 
                                              & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0x14U)))
                                       ? 0U : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank
                                      [(0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0x14U))]))),32);
        bufp->chgBit(oldp+134,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcAE_i__q));
        bufp->chgBit(oldp+135,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__AluSrcBE_i__q));
        bufp->chgBit(oldp+136,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q));
        bufp->chgBit(oldp+137,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q));
        bufp->chgBit(oldp+138,((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))));
        bufp->chgIData(oldp+139,(((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q)
                                   ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE
                                   : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE)),32);
        bufp->chgIData(oldp+140,(((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q))
                                   ? (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                       & (0xc02U == 
                                          (0xfffU & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)))
                                       ? (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__csr_unit_i__DOT__instr_counter)
                                       : (((~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
                                           & (0xc82U 
                                              == (0xfffU 
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
                                               : ((
                                                   (~ (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__CsrOpE_i__q)) 
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
                                                     : 0U))))))
                                   : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultE)),32);
        bufp->chgIData(oldp+141,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__execute_stage_i__DOT__SrcFWD_BE),32);
        bufp->chgIData(oldp+142,((vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                  >> 7U)),25);
        bufp->chgBit(oldp+143,(((((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
                                  == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                               >> 0xfU))) 
                                 | ((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__RdE) 
                                    == (0x1fU & (vlSelfRef.kianv_harris_pipelined_edition__DOT__InstrD 
                                                 >> 0x14U)))) 
                                & ((3U != (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)) 
                                   & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__ResultSrcE_i__q)))));
        bufp->chgIData(oldp+144,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[0]),32);
        bufp->chgIData(oldp+145,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[1]),32);
        bufp->chgIData(oldp+146,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[2]),32);
        bufp->chgIData(oldp+147,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[3]),32);
        bufp->chgIData(oldp+148,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[4]),32);
        bufp->chgIData(oldp+149,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[5]),32);
        bufp->chgIData(oldp+150,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[6]),32);
        bufp->chgIData(oldp+151,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[7]),32);
        bufp->chgIData(oldp+152,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[8]),32);
        bufp->chgIData(oldp+153,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[9]),32);
        bufp->chgIData(oldp+154,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[10]),32);
        bufp->chgIData(oldp+155,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[11]),32);
        bufp->chgIData(oldp+156,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[12]),32);
        bufp->chgIData(oldp+157,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[13]),32);
        bufp->chgIData(oldp+158,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[14]),32);
        bufp->chgIData(oldp+159,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[15]),32);
        bufp->chgIData(oldp+160,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[16]),32);
        bufp->chgIData(oldp+161,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[17]),32);
        bufp->chgIData(oldp+162,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[18]),32);
        bufp->chgIData(oldp+163,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[19]),32);
        bufp->chgIData(oldp+164,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[20]),32);
        bufp->chgIData(oldp+165,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[21]),32);
        bufp->chgIData(oldp+166,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[22]),32);
        bufp->chgIData(oldp+167,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[23]),32);
        bufp->chgIData(oldp+168,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[24]),32);
        bufp->chgIData(oldp+169,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[25]),32);
        bufp->chgIData(oldp+170,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[26]),32);
        bufp->chgIData(oldp+171,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[27]),32);
        bufp->chgIData(oldp+172,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[28]),32);
        bufp->chgIData(oldp+173,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[29]),32);
        bufp->chgIData(oldp+174,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[30]),32);
        bufp->chgIData(oldp+175,(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__register_file32_i__DOT__bank[31]),32);
        bufp->chgCData(oldp+176,((3U & vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__AluResultW)),2);
        bufp->chgBit(oldp+177,((0U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))));
        bufp->chgBit(oldp+178,((1U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))));
        bufp->chgBit(oldp+179,((2U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))));
        bufp->chgBit(oldp+180,((3U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))));
        bufp->chgBit(oldp+181,((4U == (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__memory_stage_i__DOT____Vcellout__LoadOpW_t__q))));
    }
    bufp->chgBit(oldp+182,(vlSelfRef.clk));
    bufp->chgBit(oldp+183,(vlSelfRef.resetn));
    bufp->chgBit(oldp+184,(vlSelfRef.halt));
    bufp->chgIData(oldp+185,(vlSelfRef.Instr),32);
    bufp->chgIData(oldp+186,(vlSelfRef.ReadDataM),32);
    bufp->chgIData(oldp+187,(vlSelfRef.PCF),32);
    bufp->chgCData(oldp+188,(vlSelfRef.WriteMaskM),4);
    bufp->chgBit(oldp+189,(vlSelfRef.ReadMemM));
    bufp->chgIData(oldp+190,(vlSelfRef.AluResultM),32);
    bufp->chgIData(oldp+191,(vlSelfRef.WriteDataM),32);
    bufp->chgIData(oldp+192,(((IData)(4U) + vlSelfRef.PCF)),32);
    bufp->chgIData(oldp+193,(((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE)
                               ? (((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__decode_stage_i__DOT____Vcellout__PCTargetSrcE_i__q)
                                    ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCE
                                    : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__SrcAE) 
                                  + vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ImmExtE)
                               : ((IData)(4U) + vlSelfRef.PCF))),32);
    bufp->chgBit(oldp+194,(((IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__PCSrcE) 
                            & (~ (IData)(vlSelfRef.halt)))));
    bufp->chgBit(oldp+195,(((~ (IData)(vlSelfRef.halt)) 
                            & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__CsrInstrIncE))));
    bufp->chgBit(oldp+196,((1U & (~ (IData)(vlSelfRef.halt)))));
    bufp->chgIData(oldp+197,(((2U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE))
                               ? vlSelfRef.AluResultM
                               : ((1U & (IData)(vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ForwardAE))
                                   ? vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__ResultW
                                   : vlSelfRef.kianv_harris_pipelined_edition__DOT__datapath_unit_i__DOT__Rd1E))),32);
    bufp->chgCData(oldp+198,((3U & vlSelfRef.AluResultM)),2);
}

void Vkianv_harris_pipelined_edition___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkianv_harris_pipelined_edition___024root__trace_cleanup\n"); );
    // Init
    Vkianv_harris_pipelined_edition___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkianv_harris_pipelined_edition___024root*>(voidSelf);
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
