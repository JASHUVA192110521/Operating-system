#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 10
#define NUM_FRAMES 5
#define NUM_ACCESSES 20

int page_table[NUM_PAGES];
int frames[NUM_FRAMES];
int page_faults = 0;

int find_frame_to_replace() {
    int oldest_frame = frames[0];
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (frames[i] < oldest_frame) {
            oldest_frame = frames[i];
        }
    }
    return oldest_frame;
}

int main() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1;
    }

    for (int i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < NUM_ACCESSES; i++) {
        int page_number = rand() % NUM_PAGES;
        int frame_number;
        if (page_table[page_number] == -1) {
            page_faults++;
            frame_number = find_frame_to_replace();
            frames[frame_number] = page_number;
            page_table[page_number] = frame_number;
        }
    }

    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
