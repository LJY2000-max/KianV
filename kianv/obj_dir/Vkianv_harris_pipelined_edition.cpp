// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vkianv_harris_pipelined_edition::Vkianv_harris_pipelined_edition(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vkianv_harris_pipelined_edition__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , resetn{vlSymsp->TOP.resetn}
    , halt{vlSymsp->TOP.halt}
    , WriteMaskM{vlSymsp->TOP.WriteMaskM}
    , ReadMemM{vlSymsp->TOP.ReadMemM}
    , Instr{vlSymsp->TOP.Instr}
    , ReadDataM{vlSymsp->TOP.ReadDataM}
    , PCF{vlSymsp->TOP.PCF}
    , AluResultM{vlSymsp->TOP.AluResultM}
    , WriteDataM{vlSymsp->TOP.WriteDataM}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vkianv_harris_pipelined_edition::Vkianv_harris_pipelined_edition(const char* _vcname__)
    : Vkianv_harris_pipelined_edition(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vkianv_harris_pipelined_edition::~Vkianv_harris_pipelined_edition() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vkianv_harris_pipelined_edition___024root___eval_debug_assertions(Vkianv_harris_pipelined_edition___024root* vlSelf);
#endif  // VL_DEBUG
void Vkianv_harris_pipelined_edition___024root___eval_static(Vkianv_harris_pipelined_edition___024root* vlSelf);
void Vkianv_harris_pipelined_edition___024root___eval_initial(Vkianv_harris_pipelined_edition___024root* vlSelf);
void Vkianv_harris_pipelined_edition___024root___eval_settle(Vkianv_harris_pipelined_edition___024root* vlSelf);
void Vkianv_harris_pipelined_edition___024root___eval(Vkianv_harris_pipelined_edition___024root* vlSelf);

void Vkianv_harris_pipelined_edition::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkianv_harris_pipelined_edition::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vkianv_harris_pipelined_edition___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vkianv_harris_pipelined_edition___024root___eval_static(&(vlSymsp->TOP));
        Vkianv_harris_pipelined_edition___024root___eval_initial(&(vlSymsp->TOP));
        Vkianv_harris_pipelined_edition___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vkianv_harris_pipelined_edition___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vkianv_harris_pipelined_edition::eventsPending() { return false; }

uint64_t Vkianv_harris_pipelined_edition::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vkianv_harris_pipelined_edition::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vkianv_harris_pipelined_edition___024root___eval_final(Vkianv_harris_pipelined_edition___024root* vlSelf);

VL_ATTR_COLD void Vkianv_harris_pipelined_edition::final() {
    Vkianv_harris_pipelined_edition___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vkianv_harris_pipelined_edition::hierName() const { return vlSymsp->name(); }
const char* Vkianv_harris_pipelined_edition::modelName() const { return "Vkianv_harris_pipelined_edition"; }
unsigned Vkianv_harris_pipelined_edition::threads() const { return 1; }
void Vkianv_harris_pipelined_edition::prepareClone() const { contextp()->prepareClone(); }
void Vkianv_harris_pipelined_edition::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vkianv_harris_pipelined_edition::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vkianv_harris_pipelined_edition___024root__trace_decl_types(VerilatedVcd* tracep);

void Vkianv_harris_pipelined_edition___024root__trace_init_top(Vkianv_harris_pipelined_edition___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vkianv_harris_pipelined_edition___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkianv_harris_pipelined_edition___024root*>(voidSelf);
    Vkianv_harris_pipelined_edition__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vkianv_harris_pipelined_edition___024root__trace_decl_types(tracep);
    Vkianv_harris_pipelined_edition___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vkianv_harris_pipelined_edition___024root__trace_register(Vkianv_harris_pipelined_edition___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vkianv_harris_pipelined_edition::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vkianv_harris_pipelined_edition::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vkianv_harris_pipelined_edition___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
