#include <stdio.h>

#define MAX_REQUESTS 100

int requests[MAX_REQUESTS];
int current_request = 0;

int current_position = 50;

void add_request(int request) {
    requests[current_request] = request;
    current_request++;
}

void FCFS() {
    int total_distance = 0;

    for (int i = 0; i < current_request; i++) {
        total_distance += abs(requests[i] - current_position);
        current_position = requests[i];
    }

    printf("Total Distance: %d\n", total_distance);
}

int main() {
    add_request(95);
    add_request(180);
    add_request(34);
    add_request(119);
    add_request(11);

    FCFS();

    return 0;
}
