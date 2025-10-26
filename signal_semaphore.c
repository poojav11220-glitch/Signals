#include <stdio.h>
#include <semaphore.h>
int main() {
sem_t sem;
sem_init(&sem, 0, 1);
printf("Trying to enter critical section...\n");
sem_wait(&sem);
printf("Inside critical section!\n");
printf("Leaving critical section...\n");
sem_post(&sem); 
sem_destroy(&sem); 
return 0;
}

