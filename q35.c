#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_BLOCK_SIZE 50

struct Block {
    char data[MAX_BLOCK_SIZE];
} blocks[MAX_BLOCKS];

int index_block[MAX_BLOCKS];
int current_block = 0;

void add_block(char* data) {
    strcpy(blocks[current_block].data, data);
    index_block[current_block] = current_block;
    current_block++;
}

void read_block(int block_number) {
    int block_index = index_block[block_number];
    printf("%s\n", blocks[block_index].data);
}

int main() {
    add_block("Block 1");
    add_block("Block 2");
    add_block("Block 3");
    add_block("Block 4");

    read_block(2);

    return 0;
}
