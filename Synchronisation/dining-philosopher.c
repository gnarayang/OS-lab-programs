#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define N 4
#define THINKING 0
#define EATING 1

sem_t chopstick[N], mutex;

void *eat(void * phil) {

    int id =  (int)phil;
    
    int iter = 2, i;

    for(i = 0; i < iter; i++) {
        
        //if(id%2 == 0 ) {
            sem_wait(chopstick+id);
            sem_wait(chopstick+(id+1)%N);
        //}
        //else {
        //    sem_wait(chopstick+(id+1)%N);
        //    sem_wait(chopstick+id);
        //}

        //sem_wait(&mutex);
        
        printf("Eating : %d\n", id+1);
        
        //sem_post(&mutex);
        //sleep(1);
        
        sem_post(chopstick+(id+1)%N);
        sem_post(chopstick+id);

        printf("Thinking : %d\n", id+1);
    }
}

int main() {
    int i;
    srand(time(0)); 
    pthread_t phil[N];

    for(i = 0; i < N; i++) {
        printf("Thinking : %d\n", i+1);
    }

    for(i = 0; i < N; i++)
        sem_init(chopstick + i, 0, 1);

    for(i = 0; i < N; i++) 
        pthread_create(&phil[i], NULL, eat, (void*)i);

    for(i = 0; i < N; i++)
        pthread_join(phil[i], NULL);

    for(i = 0; i < N; i++) {
        sem_destroy(chopstick+i);
    }
    
    return 0;
}
