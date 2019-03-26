#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 1000

sem_t mutex, empty, full;
int buffer[N];
int n, front = 0, rear = 0, cnt = 0; 

void push(int x)
{
	if(cnt==N)
		return;

	buffer[rear] = x;
	rear = (rear +1)%N;
	cnt++;
}

int pop()
{
	if(cnt==0)
		return -1;

	int ret = buffer[front];
	front = (front +1)%N;
	cnt--;
	return ret;
}

void* produce(void *iteration_produce) {
    
    for(int i = 0; i < *((int *)iteration_produce); i++) {
       
        int produce = rand()%1000;

        sem_wait(&empty);
        sem_wait(&mutex);
        
        push(produce);

        usleep(1000000);
        
        sem_post(&mutex);
        sem_post(&full);

        printf("Produce item : %d\n", produce);
        fflush(stdout);
    }
}

void *consume(void *iterations_consume) {
    
    for(int i = 0; i < *((int *)iterations_consume); i++) {
        
        int consume;

        sem_wait(&full);
        sem_wait(&mutex);

        consume = pop();

        usleep(1000000);

        sem_post(&mutex);
        sem_post(&empty);

        printf("Consume item : %d\n", consume);
        fflush(stdout);
    }
}


int main() {

    srand(time(0));

    pthread_t producer[5], consumer[5];
    int iterations_consume = rand()%10 + 6;
    int iterations_produce = rand()%10 + iterations_consume; 

    int n;
    printf("Enter the size of buffer: "); 
    scanf("%d", &n);

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, n);
        
    for(int i = 0; i < 5; i++) {
        pthread_create(&producer[i], NULL, produce, &iterations_consume);
        pthread_create(&consumer[i], NULL, consume, &iterations_produce);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(producer[i], NULL);
        pthread_join(consumer[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
