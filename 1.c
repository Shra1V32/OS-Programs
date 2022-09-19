/*
Aim: Familiarity and usage of process management system calls of LINUX.

a)fork() b)exec() c) wait() d) sleep().,
A)Write a program to show the usage of fork() ,wait(),exec() system calls

ALGORITHM:
1. Uses fork() API to create a child process
2. Uses execv API to call 'whoami' command.
3. Uses wait() API to get the termination status of child in the parent. Note that this API holds the
execution of the parent until child terminates or changes its state.
*/

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t child_id;
    int status;
    child_id = fork();
    if (child_id >= 0)
    {
        if (child_id == 0)
        {
            printf("CHILD PROCESS: \n");
            printf("Child pid = %d, parent_pid = %d\n", getpid(), getppid());
            char *cmd[] = {"who", (char *)0};
            system("/bin/sleep 10s");
        }
        else
        {
            printf("PARENT PROCESS: \n");
            printf("parent_id = %d, child_id = %d\n", getpid(), child_id);
            wait(&status);
        }

        printf("Child exit code = %d\n", WEXITSTATUS(status));
        printf("Parent says bye!");
        exit(0);
    }
    else
    {
        perror("fork");
        exit(0);
    }
}