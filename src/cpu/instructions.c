#include <stdio.h>

#include "cpu.h"
#include "instructions.h"

#include "../main.h"

#define ACCUMULATOR cpu->registers->ac
#define PROGRAM_POINTER cpu->registers->pc
#define INDEX_REGISTER cpu->registers->ix

void opcode_add(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    printf("ADD 0x%04X(ADR) -> 0x%04X(AC) + ", address, ACCUMULATOR);
    ACCUMULATOR += get_value(cpu, address);
    printf("0x%04X = 0x%04X\n", get_value(cpu, address), ACCUMULATOR);
}

void opcode_sub(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    printf("SUB 0x%04X(ADR) -> 0x%04X(AC) - ", address, ACCUMULATOR);
    ACCUMULATOR -= get_value(cpu, address);
    printf("0x%04X = 0x%04X\n", get_value(cpu, address), ACCUMULATOR);
}

void opcode_and(CPU* cpu) {
    printf("AND\n");
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    printf("AND 0x%04X(ADR) -> 0x%04X(AC) & ", address, ACCUMULATOR);
    ACCUMULATOR &= get_value(cpu, address);
    printf("0x%04X = 0x%04X\n", get_value(cpu, address), ACCUMULATOR);
}

void opcode_or(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    printf("OR 0x%04X(ADR) -> 0x%04X(AC) | ", address, ACCUMULATOR);
    ACCUMULATOR |= get_value(cpu, address);
    printf("0x%04X = 0x%04X\n", get_value(cpu, address), ACCUMULATOR);
}

void opcode_xor(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    ACCUMULATOR ^= get_value(cpu, address);
    printf("XOR 0x%04X(ADR) -> 0x%04X(AC) ^ 0x%04X = 0x%04X\n", address, ACCUMULATOR, get_value(cpu, address), ACCUMULATOR);
}

void opcode_not(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    ACCUMULATOR = ~get_value(cpu, address);
    printf("NOT 0x%04X(ADR) -> ~0x%04X = 0x%04X\n", address, get_value(cpu, address), ACCUMULATOR);
}

void opcode_cpl(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    ACCUMULATOR = ~get_value(cpu, address) + 1;
    printf("CPL 0x%04X(ADR) -> ~0x%04X + 1 = 0x%04X\n", address, get_value(cpu, address), ACCUMULATOR);
}

void opcode_cmp(CPU* cpu) {
    printf("CMP\n");
}

void opcode_ldi(CPU* cpu) {
    uint16_t address = get_value(cpu, ++PROGRAM_POINTER);
    uint16_t value = get_value(cpu, ++PROGRAM_POINTER);
    cpu->ram->memory[address] = value;
    printf("LDI 0x%04X(ADR) <- 0x%04X(VAL)\n", address, value);
}

void opcode_mov(CPU* cpu) {
    
}

uint16_t get_value(CPU* cpu, uint16_t address) {
    return cpu->ram->memory[address];
}