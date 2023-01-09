// FCFS Program
#include<stdio.h>
int main(){
    int queue[20], n, head,i,j,k,seek=0,max,diff;
    float avg;
    printf("Enter the max range of disk: ");
    scanf("%d",&max);
    printf("Enter the size of queue request: ");
    scanf("%d",&n);
    printf("Enter the queue of the disk positions to be read: ");
    for (i=1; i,n; i++){
        diff = abs(queue[j+1]-queue[j]);
        seek+=diff;
        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
    }
    printf("Total Seek time: %d\n",seek);
    avg = seek/(float)n;
    printf("Average seek time is: %f\n",avg);
    return 0;
}