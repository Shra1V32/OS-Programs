// Program to implement IPC using shared memory Client
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#define SHMSIZE 128
int main()
{
    int shmid;
    key_t key;
    char ch, *shm, *s;
    key = 1234;
    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
        printf("Shared memory impl failed");
        return -1;
    }
    if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        printf("\nShared memory attachment failed");
        return -1;
    }
    s = shm;
    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        *s++ = ch;
    }
    *s = '\0';
    // while (*shm != '*')
    //     sleep(1);
    return 0;
}