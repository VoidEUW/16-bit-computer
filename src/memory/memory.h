#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 0xFFFF // 65535 bytes = 64 KB

typedef enum MemorySegment {
    // Instruction Code
    INSTRUCTION_START = 0x0000,
    INSTRUCTION_END   = 0x0FFF,

    // Program Code
    PROGRAM_START     = 0x1000, 
    PROGRAM_END       = 0x7FFF,

    // Stack
    STACK_START       = 0x8000,
    STACK_END         = 0xFFFF
} MemorySegment;

typedef struct RAM {
    uint16_t memory[MEMORY_SIZE];
    uint16_t size;
} RAM;

int check_memory(RAM* ram);
int load_program(RAM* ram, const char *path, const char *filename);

#endif