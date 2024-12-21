#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "../memory/memory.h"
#include "cpu.h"

typedef enum Command {
    NOP = 0x00,
    HLT = 0x01,
    ERR = 0x02,

    ADD = 0x03,
    SUB = 0x04,
    AND = 0x05,
    OR  = 0x06,
    XOR = 0x07,
    NOT = 0x08,
    CPL = 0x09,
    CMP = 0x0A,

    LDA = 0x0B,
    STA = 0x0C,
    MOV = 0x0D,
    LDI = 0x0E,

    JMP = 0x0F,
    JEQ = 0x10,
    JNE = 0x11,

    CLL = 0x12,
    RET = 0x13,

    PSH = 0x14,
    POP = 0x15,

    INT = 0x16
} Command;

void opcode_add(CPU* cpu);
void opcode_sub(CPU* cpu);
void opcode_and(CPU* cpu);
void opcode_or(CPU* cpu);
void opcode_xor(CPU* cpu);
void opcode_not(CPU* cpu);
void opcode_cpl(CPU* cpu);
void opcode_cmp(CPU* cpu);
void opcode_lda(CPU* cpu);
void opcode_sta(CPU* cpu);
void opcode_mov(CPU* cpu);
void opcode_ldi(CPU* cpu);
void opcode_jmp(CPU* cpu);
void opcode_jeq(CPU* cpu);
void opcode_jne(CPU* cpu);
void opcode_cll(CPU* cpu);
void opcode_ret(CPU* cpu);
void opcode_psh(CPU* cpu);
void opcode_pop(CPU* cpu);
void opcode_nop(CPU* cpu);
void opcode_int(CPU* cpu);
void opcode_mov(CPU* cpu);

void set_flags(CPU* cpu, uint16_t result);
void set_z_flag(CPU* cpu, uint16_t result);
void set_s_flag(CPU* cpu, uint16_t result);
void set_c_flag(CPU* cpu, uint16_t result);
void set_o_flag(CPU* cpu, uint16_t result);

uint16_t get_value(CPU* cpu);
void set_value(CPU* cpu);

#endif