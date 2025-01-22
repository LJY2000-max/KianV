// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkianv_harris_pipelined_edition.h for the primary calling header

#ifndef VERILATED_VKIANV_HARRIS_PIPELINED_EDITION___024UNIT_H_
#define VERILATED_VKIANV_HARRIS_PIPELINED_EDITION___024UNIT_H_  // guard

#include "verilated.h"


class Vkianv_harris_pipelined_edition__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkianv_harris_pipelined_edition___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vkianv_harris_pipelined_edition__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vkianv_harris_pipelined_edition___024unit(Vkianv_harris_pipelined_edition__Syms* symsp, const char* v__name);
    ~Vkianv_harris_pipelined_edition___024unit();
    VL_UNCOPYABLE(Vkianv_harris_pipelined_edition___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
