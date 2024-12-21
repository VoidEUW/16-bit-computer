#ifndef CPU_H
#define CPU_H

#include <stdio.h>

#include "../memory/memory.h"

// Enumerations for CPU architecture

typedef enum Status {
    OK = 0,
    INVALID_INSTRUCTION = 1,
    INVOKED_ERROR = 2,
    HALT = 3
} Status;

typedef enum Flags {
    CARRY = 0,
    ZERO = 1,
    NEGATIVE = 2,
    OVERFLOW = 3
} Flags;

// Structs for CPU architecture

typedef struct Registers {
    u_int16_t pc;   // Program Counter
    u_int16_t fa;   // Flags
    u_int16_t ac;   // Accumulator
    u_int16_t sp;   // Stack Pointer
    u_int16_t bp;   // Base Pointer
    u_int16_t ix;   // Index Register
} Registers;

typedef struct CPU {
    RAM* ram;
    Registers* registers;
} CPU;


// Function prototypes

// cpu.c

Status run_cpu(CPU* cpu);
Status execute_instruction(CPU* cpu);
CPU* reset_cpu();

#endif