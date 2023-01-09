#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
char buf[10];
sem_t empty, full, mutex;
void *thread_fun1(void *arg)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buf[i] = i;
        printf("Item produced is %d\n", buf[i]);
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    pthread_exit("producer\n");
}

void *thread_fun2(void *arg)
{
    int j;
    printf("Inside consumer: ");
    for (j = 0; j < 10; j++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        j = buf[j];
        printf("Consumed item: %d\n", buf[j]);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(5);
    }
    pthread_exit("Consumer\n");
}

int main()
{
    pthread_t pid1, pid2;
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 1, 1);
    void *status;
    pthread_create(&pid1, NULL, thread_fun1, NULL);
    pthread_create(&pid2, NULL, thread_fun2, NULL);
    pthread_join(pid1, &status);
    printf("Exited status of 1st is %s\n", (char *)status);
    pthread_join(pid2, &status);
    printf("The exited status %s\n", (char *)status);
    return 0;
}