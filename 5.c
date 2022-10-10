// C program to create, open and read a file using file management system calls
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1, k;
    char str[40];
    // printf("Enter the string: ");
    // scanf("%s",str);
    fd1 = open("/home/mvsr/113/noname.txt", O_RDONLY);
    k = read(fd1, str, sizeof(str) + 1);
    close(fd1);
    printf("%d %s", k, str);
    return 0;
}