#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "cpu/cpu.h"
#include "memory/memory.h"


int main() {
    CPU* cpu = reset_cpu();

    check_memory(cpu->ram);
    load_program(cpu->ram, "disk/%s", "disk.bin");

    Status state = run_cpu(cpu);
    if (state != HALT) {
        if (state == INVOKED_ERROR) {
            printf("An Error occured...");
        }
        else {
            printf("An Invalid command has been made...");
        }
    }
    free_cpu(cpu);

    printf("Computer halts.\n");

    return 0;
}

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    return ptr;
}

void free_cpu(CPU* cpu) {
    free(cpu->ram->memory);
    free(cpu->ram);
    free(cpu);
}