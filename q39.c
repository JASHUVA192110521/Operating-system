#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int requests[MAX_REQUESTS];
int current_request = 0;

int current_position = 50;
int max_track = 199;

void add_request(int request) {
    requests[current_request] = request;
    current_request++;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void CSCAN() {
    int total_distance = 0;
    qsort(requests, current_request, sizeof(int), compare);

    for (int i = 0; i < current_request; i++) {
        if (requests[i] >= current_position) {
            for (int j = i; j < current_request; j++) {
                total_distance += abs(requests[j] - current_position);
                current_position = requests[j];
            }
            current_position = 0;
            for (int j = 0; j < current_request; j++) {
                if (requests[j] > current_position) {
                    total_distance += abs(requests[j] - current_position);
                    current_position = requests[j];
                }
            }
            break;
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

}
