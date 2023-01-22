#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 10
#define NUM_FRAMES 5
#define NUM_ACCESSES 20

int page_table[NUM_PAGES];
int frames[NUM_FRAMES];
int page_faults = 0;

int find_frame_to_replace() {
    int future_time[NUM_FRAMES];
    for (int i = 0; i < NUM_FRAMES; i++) {
        future_time[i] = NUM_ACCESSES + 1;
    }

    for (int i = 0; i < NUM_FRAMES; i++) {
        int page = frames[i];
        for (int j = 0; j < NUM_ACCESSES; j++) {
            if (page_table[j] == page) {
                future_time[i] = j;
                break;
            }
        }
    }

    int oldest_time = future_time[0];
    int oldest_frame = 0;
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (future_time[i] > oldest_time) {
            oldest_time = future_time[i];
            oldest_frame = i;
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
    }
   }
