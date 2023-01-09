// Dining Philosopher
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t semname[5];
int n;

int main()
{
    pid_t cpid[5];
    char semname[5];
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        cpid[i] = fork();
        if (cpid[i] == 0)
        {
            break;
        }
        if (i == n)
        {
            int status;
            for (i = 0; i < n; i++)
            {
            }
        }
    }
}