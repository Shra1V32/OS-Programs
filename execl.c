#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    execl("/bin/date","",NULL);
}