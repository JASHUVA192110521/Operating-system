#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int requests[MAX_REQUESTS];
int current_request = 0;

int current_position = 50;
int max_track = 199;
int direction = 1;

void add_request(int request) {
    requests[current_request] = request;
    current_request++;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void SCAN() {
    int total_distance = 0;
    qsort(requests, current_request, sizeof(int), compare);

    for (int i = 0; i < current_request; i++) {
        if (requests[i] > current_position) {
            for (int j = i; j < current_request; j++) {
                total_distance += abs(requests[j] - current_position);
                current_position = requests[j];
            }
            direction = -1;
            break;
        }
    }

    if (direction == -1) {
        for (int i = current_request - 1; i >= 0; i--) {
            if (requests[i] < current_position) {
                total_distance += abs(requests[i] - current_position);
                current_position = requests[i];
            }
        }
    }

    printf("Total Distance: %d\n", total_distance);
}

int main() {
    add_request(95);
    add_request(180);
    add_request(34);
    add_request(119);
    add_request(11);

    SCAN();

    return 0;
}
