#include <stdio.h>

#include "cpu.h"

#include "../main.h"
#include "../memory/memory.h"
#include "instructions.h"

Status run_cpu(CPU* cpu) {
    printf("CPU running.\n");
    // for each instruction
    for (cpu->registers->pc = PROGRAM_START; cpu->registers->pc < PROGRAM_END; cpu->registers->pc++) {
        // check if program counter is out of bounds
        if (cpu->registers->pc >= MEMORY_SIZE) {
            return 1;
        }
        // execute instruction
        Status status = execute_instruction(cpu);
        if (status != OK) {
            return status;
        }
    }
    return 0;
}

Status execute_instruction(CPU* cpu) {
    // prepare instruction and operand
    Command opcode = (Command)(cpu->ram->memory[cpu->registers->pc] >> 8) & 0xFF; // shift right 8 bits and mask
    // switch statement instruction
    switch (opcode) {
        case NOP:
            printf("NOP\n");
            return OK;
        case HLT:
            printf("HALT\n");
            return HALT;
        case ERR:
            printf("ERR\n");
            return INVOKED_ERROR;
        case ADD:
            opcode_add(cpu);
            return OK;
        case SUB:
            opcode_sub(cpu);
            return OK;
        case LDI:
            opcode_ldi(cpu);
            return OK;
        default:
            return INVALID_INSTRUCTION;
    }
}

CPU* reset_cpu() {
    // allocate memory for CPU, RAM, and Registers
    CPU* cpu = safe_malloc(sizeof(CPU));
    cpu->ram = safe_malloc(sizeof(RAM));
    cpu->registers = safe_malloc(sizeof(Registers));

    // set registers to default values
    cpu->registers->pc = 0;
    cpu->registers->fa = 0;
    cpu->registers->ac = 0;
    cpu->registers->sp = MEMORY_SIZE - 1;
    cpu->registers->bp = 0;
    cpu->registers->ix = 0;

    return cpu;
}