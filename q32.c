#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 10
#define NUM_FRAMES 5
#define NUM_ACCESSES 20

int page_table[NUM_PAGES];
int frames[NUM_FRAMES];
int access_time[NUM_FRAMES];
int page_faults = 0;

int find_frame_to_replace() {
    int oldest_time = access_time[0];
    int oldest_frame = 0;
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (access_time[i] < oldest_time) {
            oldest_time = access_time[i];
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
        access_time[i] = 0;
    }

    int time = 0;
    for (int i = 0; i < NUM_ACCESSES; i++) {
        time++;
        int page_number = rand() % NUM_PAGES;
        int frame_number;
        if (page_table[page_number] == -1) {
            page_faults++;
            frame_number = find_frame_to_replace();
            frames[frame_number] = page_number;
            page_table[page_number] = frame_number;
            access_time[frame_number] = time;
        } else {
            frame_number = page_table[page_number];
            access_time[frame_number] = time;
        }
    }

    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
