// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vkianv_harris_pipelined_edition__pch.h"
#include "Vkianv_harris_pipelined_edition.h"
#include "Vkianv_harris_pipelined_edition___024root.h"
#include "Vkianv_harris_pipelined_edition___024unit.h"

// FUNCTIONS
Vkianv_harris_pipelined_edition__Syms::~Vkianv_harris_pipelined_edition__Syms()
{
}

Vkianv_harris_pipelined_edition__Syms::Vkianv_harris_pipelined_edition__Syms(VerilatedContext* contextp, const char* namep, Vkianv_harris_pipelined_edition* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(89);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-10);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
