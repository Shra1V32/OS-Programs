#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 256
struct msgform
{
long int mtype;
char mtext[MAX];
}
send,recv;
main()
{
int mid;
mid=msgget((key_t)123,IPC_CREAT|0666);
send.mtype=1;
strcpy(send.mtext,"hai");
msgrcv(mid,(struct msgform*)&recv,MAX,0,0);
msgsnd(mid,(struct msgform*)&send,strlen(send.mtext),0);
printf("SERVER:%s",recv.mtext);
}