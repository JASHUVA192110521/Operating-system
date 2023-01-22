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
    int best_block = -1;
    int best_block_size = BLOCK_SIZE*NUM_BLOCKS;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (block_status[i] == 0 && block_size[i] >= size) {
            if (block_size[i] < best_block_size) {
                best_block = i;
                best_block_size = block_size[i];
            }
        }
    }
    if (best_block != -1) {
        block_status[best_block] = 1;
        block_size[best_block] = size;
        return best_block*BLOCK_SIZE;
    } else {
        printf("Error: Not enough memory available\n");
        return -1;
    }
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
