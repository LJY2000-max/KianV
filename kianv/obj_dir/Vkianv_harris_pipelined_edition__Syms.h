// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VKIANV_HARRIS_PIPELINED_EDITION__SYMS_H_
#define VERILATED_VKIANV_HARRIS_PIPELINED_EDITION__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vkianv_harris_pipelined_edition.h"

// INCLUDE MODULE CLASSES
#include "Vkianv_harris_pipelined_edition___024root.h"
#include "Vkianv_harris_pipelined_edition___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vkianv_harris_pipelined_edition__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vkianv_harris_pipelined_edition* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vkianv_harris_pipelined_edition___024root TOP;

    // CONSTRUCTORS
    Vkianv_harris_pipelined_edition__Syms(VerilatedContext* contextp, const char* namep, Vkianv_harris_pipelined_edition* modelp);
    ~Vkianv_harris_pipelined_edition__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
