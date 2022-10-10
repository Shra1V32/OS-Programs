// Read and write file using sys calls using args

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char str[20];
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);
    read(fd1, str, sizeof(str) + 1);
    write(fd2, str, sizeof(str) + 1);
    close(fd1);
    close(fd2);
    return 0;
}