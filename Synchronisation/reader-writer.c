#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex, wrt; 
int read_cnt = 0;

void *Read(void *arg) {
   
    int id = *((int *)arg), i;
    int repeat = rand()%5 + 2;
    for(i = 0; i < repeat; i++) {
       
        usleep(3000000);

        sem_wait(&mutex);
        
        read_cnt++;
        if(read_cnt == 1)
            sem_wait(&wrt);

        sem_post(&mutex);

        printf("%d Reader is reading\n", id);
        usleep(3000000);
        printf("%d Reader is Idle\n", id);

        sem_wait(&mutex);

        read_cnt--;
        if(read_cnt == 0)
            sem_post(&wrt);

        sem_post(&mutex);
        
    }
}

void *Write(void *arg) {
    
    int id = *((int *)arg), i;
    int repeat = rand()%5 + 2;
    for(i = 0; i < repeat; i++) {
        
        usleep(3000000);

        sem_wait(&wrt);

        printf("%d Writer is writing\n", id);
        usleep(3000000);
        printf("%d Writer is idle\n", id);

        sem_post(&wrt);
    }
}


int main() {
    
    srand(time(0));
    
    int n,m,i;
    printf("Enter number of readers and writers: ");
    scanf("%d %d", &n, &m);
    
    pthread_t reader[n], writer[m]; 

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    
    for(i = 0; i < n; i++) {
        pthread_create(&reader[i], NULL, Read, &i);
    }
    for(i = 0; i < m; i++) {
        pthread_create(&writer[i], NULL, Write, &i); 
    }   
    for(i = 0; i < n; i++) {
        pthread_join(reader[i], NULL);
    }
    for(i = 0; i < m; i++) {
        pthread_join(writer[i], NULL);
    }   

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
