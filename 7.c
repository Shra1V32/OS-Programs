// IPC using pipes, For sending the message from parent to child
#include <stdio.h>
#include <sys/types.h>
int main()
{
    int fd[2], a;
    pid_t pid;
    char str1[10] = "Welcome";
    char str2[10];
    a = pipe(fd); // Introduce piping by this syscall
    pid = fork(); // Create a child process
    if (a != -1)  // -1 represents piping failed, so negation
    {
        if (pid > 0) // If the process is parent process
        {
            write(fd[1], str1, 10); // We'll always write from the end fd[1]
        }
        else // If the process if child
        {
            read(fd[0], str2, 10); // We'll always read from the start fd[0]
            printf("\nIn Child");
            printf("\nData received in child %s\n", str2);
        }
    }
}