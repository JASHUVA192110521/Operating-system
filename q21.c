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
    int worst_block = -1;
    int worst_block_size = 0;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (block_status[i] == 0 && block_size[i] >= size) {
            if (block_size[i] > worst_block_size) {
                worst_block = i;
                worst_block_size = block_size[i];
            }
        }
    }
    if (worst_block != -1) {
        block_status[worst_block] = 1;
        
