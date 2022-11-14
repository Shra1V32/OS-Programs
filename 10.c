#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#define SHMSIZE 128
int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    key = 1234;
    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
        printf("Shared memort impl failed\n");
        return -1;
    }
    if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        printf("Shared memory attach failed\n");
        return -1;
    }
    for (s = shm; *s != '\0'; s++)
    {
        putchar(*s);
    }
    putchar('\n');
    *shm = '*';
    return 0;
}