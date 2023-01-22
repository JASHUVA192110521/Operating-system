#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
sem_t wrt;
int readcount = 0;
int shared_variable = 0;

void *reader(void *arg) {
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) {
        sem_wait(&wrt);
    }
    sem_post(&mutex);
    printf("Reader %d: Value read: %d\n", (int)arg, shared_variable);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) {
        sem_post(&wrt);
    }
    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg) {
    sem_wait(&wrt);
    shared_variable++;
    printf("Writer %d: Value written: %d\n", (int)arg, shared_variable);
    sem_post(&wrt);
    return NULL;
}
