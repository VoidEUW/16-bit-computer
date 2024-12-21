#ifndef MAIN_H
#define MAIN_H

#define VERSION "1.0.0"
#define DEBUG 1

#include "memory/memory.h"
#include "cpu/cpu.h"

int main();

void* safe_malloc(size_t size);
void free_cpu(CPU* cpu);

#endif