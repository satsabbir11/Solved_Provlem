#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* task(void* arg) {
    sem_wait(&semaphore); // Wait (P operation)
    printf("In the critical section: %s\n", (char*)arg);
    sleep(1);
    sem_post(&semaphore); // Signal (V operation)
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&semaphore, 0, 1); // Initialize semaphore with a value of 1

    pthread_create(&t1, NULL, task, "Thread 1");
    pthread_create(&t2, NULL, task, "Thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);
    return 0;
}
