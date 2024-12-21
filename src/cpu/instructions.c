#include <stdio.h>

#include "cpu.h"
#include "instructions.h"

#include "../main.h"

#define ACCUMULATOR cpu->registers->ac
#define PROGRAM_POINTER cpu->registers->pc
#define INDEX_REGISTER cpu->registers->ix

#define GET_VALUE(address) cpu->ram->memory[address]

void opcode_add(CPU* cpu) {
    uint16_t address = GET_VALUE(++PROGRAM_POINTER);
    printf("ADD 0x%04X(ADR) -> 0x%04X(AC) + ", address, ACCUMULATOR);
    ACCUMULATOR += GET_VALUE(address);
    printf("0x%04X = 0x%04X\n", GET_VALUE(address), ACCUMULATOR);
}

void opcode_sub(CPU* cpu) {
    uint16_t address = GET_VALUE(++PROGRAM_POINTER);
    printf("SUB 0x%04X(ADR) -> 0x%04X(AC) - ", address, ACCUMULATOR);
    ACCUMULATOR -= GET_VALUE(address);
    printf("0x%04X = 0x%04X\n", GET_VALUE(address), ACCUMULATOR);
}

void opcode_and(CPU* cpu) {
    printf("AND\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_or(CPU* cpu) {
    printf("OR\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_xor(CPU* cpu) {
    printf("XOR\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_not(CPU* cpu) {
    printf("NOT\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_cpl(CPU* cpu) {
    printf("CPL\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_cmp(CPU* cpu) {
    printf("CMP\n");
    uint16_t address = cpu->ram->memory[++cpu->registers->pc];
}

void opcode_ldi(CPU* cpu) {
    uint16_t address = GET_VALUE(++PROGRAM_POINTER);
    GET_VALUE(address) = GET_VALUE(++PROGRAM_POINTER);
    printf("LDI 0x%04X(ADR) <- 0x%04X(VAL)\n", address, GET_VALUE(address));
}

void opcode_mov(CPU* cpu) {
    
}