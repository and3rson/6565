#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef enum {
    M_ABS,      // 0
    M_IND_A_X,  // 1, new in 65C02
    M_A_X,      // 2
    M_A_Y,      // 3
    M_IND_A,    // 4
    M_ACC,      // 5
    M_IMM,      // 6
    M_IMPL,     // 7
    M_REL,      // 8
    M_S,        // 9
    M_ZP,       // 10
    M_IND_ZP_X, // 11
    M_ZPX,      // 12
    M_ZPY,      // 13
    M_IND_ZP,   // 14, new in 65C02
    M_IND_ZP_Y, // 15
} mode_t;

typedef struct {
    short pc;
    byte opcode;
    mode_t mode;
    union {
        union {
            byte b1;
            byte b2;
        } bytes;
        word w;
    } args;
} instr_t;

#endif
