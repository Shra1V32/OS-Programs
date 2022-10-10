// C program to create, open and Write into a file using file management system
// calls.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int fd1;
    char str[3];
    printf("Enter the string: ");
    scanf("%s", str);
    fd1 = open("/home/mvsr/113/file.txt", O_CREAT | O_WRONLY, 0777);
    write(fd1, str, sizeof(str) + 1);
    close(fd1);
    return 0;
}