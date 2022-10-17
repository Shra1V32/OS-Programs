#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fd[2], a;
    pid_t pid;
    char pstr[10], cstr[10];
    printf("Enter the word: ");
    scanf(" %s", cstr);
    a = pipe(fd); // introduce piping
    pid = fork();
    // printf("%d",sizeof(cstr));
    if (a != 1)
    {
        if (pid > 0) // If it is a parent process
        {
            write(fd[1], cstr, sizeof(cstr) + 1);
        }
        else // Child Process
        {
            read(fd[0], pstr, sizeof(pstr) + 1); // Inherit data from cstr to pstr
            printf("Child process received %s\n", pstr);
        }
    }
}