// Write a program to show the usage of sleep() system call

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("Fork failed");
    }
    if (pid == 0)
    {
        int n;
        int count = 0;
        while (count < n)
        {
            printf("I am child,my parent pid is %u \n", getppid());
            count++;
        }
    }
    else
    {
        printf("I am parent and my id is %u\n", getpid());
        sleep(1);
        printf("I am done \n");
    }
    return 0;
}