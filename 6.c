// Program using lseek() system call that reads 10 characters from file “seeking”
// and print on screen. Skip next 5 characters and again read 10 characters and write on
// screen.

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int n, f;
    char buff[40];
    f = open("seeking", O_RDWR);
    lseek(f, 5, SEEK_CUR);
    read(f, buff, 10);
    write(1, buff, 10);
    return 0;
}