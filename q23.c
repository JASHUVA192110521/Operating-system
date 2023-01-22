#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 100
#define NUM_BLOCKS 10

int memory[BLOCK_SIZE*NUM_BLOCKS];
int block_size[NUM_BLOCKS];
int block_status[NUM_BLOCKS]; // 0 = free, 1 = allocated

void init_memory() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        block_size[i] = BLOCK_SIZE;
        block_status[i] = 0;
    }
}

int allocate_memory(int size) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (block_status[i] == 0 && block_size[i] >= size) {
            block_status[i] = 1;
            block_size[i] = size;
            return i*BLOCK_SIZE;
        }
    }
    printf("Error: Not enough memory available\n");
    return -1;
}

void free_memory(int address) {
    int block_num = address/BLOCK_SIZE;
    block_status[block_num] = 0;
}

int main() {
    init_memory();
    int address = allocate_memory(50);
    printf("Allocated memory at address: %d\n", address);
    free_memory(address);
    return 0;
}
