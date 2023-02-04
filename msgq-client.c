#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define MAX 256
struct msgform
{
long int mtype;
char mtext[MAX];
}
send,recv;
int main()
{
int mid;
mid=msgget((key_t)123,IPC_CREAT|0666);
send.mtype=1;
strcpy(send.mtext,"hello");
msgsnd(mid,(struct msgform*)&send,strlen(send.mtext),0);
msgrcv(mid,(struct msgform*)&recv,MAX,0,0);
printf("client:%s",recv.mtext);
}