#include <stdio.h>
#include <stdlib.h>

#include "../main.h"
#include "memory.h"

// improvised assembly instructions for tests

#define HLT(start_index) \
    ram->memory[PROGRAM_START + start_index] = 0x0100;

#define ERR(start_index) \
    ram->memory[PROGRAM_START + start_index] = 0x0200;

#define ADD(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0300; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define SUB(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0400; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define AND(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0500; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define OR(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0600; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define XOR(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0700; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define NOT(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0800; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define CPL(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0900; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define CMP(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0A00; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define LDA(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0B00; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define STA(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0C00; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define MOV(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0D00; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define LDI(start_index, address, value) \
    ram->memory[PROGRAM_START + start_index] = 0x0E00; \
    ram->memory[PROGRAM_START + start_index+1] = address; \
    ram->memory[PROGRAM_START + start_index+2] = value

#define JMP(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x0F00; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define JEQ(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1000; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define JNE(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1100; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define CLL(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1200; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define RET(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1300; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define PSH(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1400; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define POP(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1500; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define NOP(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1600; \
    ram->memory[PROGRAM_START + start_index+1] = address

#define INT(start_index, address) \
    ram->memory[PROGRAM_START + start_index] = 0x1700; \
    ram->memory[PROGRAM_START + start_index+1] = address


int check_memory(RAM* ram) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        ram->memory[i] = 0;
    }
    return 0;
}

int load_program(RAM* ram, const char *path, const char *filename) {
    // program code for now

    // test LDI
    LDI(0, 0x0F01, 0x0001);
    LDI(3, 0x0F02, 0x0004);

    // test logical operations
    ADD(6, 0x0F01);
    ADD(8, 0x0F02);
    SUB(10, 0x0F01);
    LDI(12, 0x0F01, 0x0300);
    OR(15, 0x0F01);

    // test jump operations


    // test stack operations
    

    // test HLT
    HLT(17);
    return 0;
}