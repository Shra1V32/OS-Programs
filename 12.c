/*
Implementing SJF (Premptive)using Process Scheduling Algorithm

Algorithm:
1. Start the process
2. Declare the array size
3. Get the number of processes to be inserted
4. Select the process which has shortest burst time will execute first
5. If two processes have same burst time, then FCFS Algorithm will be used
6. Make the average waiting the length of next process
7. Start with the first process from its selection as above and let other process be in the queue
8. Calculate the total number of burst time
9. Display the value
10. Stop the process
*/

#include <stdio.h>
int main()
{
    int i, n, j, temp, temp1, temp2, pr[10], b[10], t[10], w[10], p[10];
    float att = 0, awt = 0;
    for (i = 0; i < 10; i++)
    {
        b[i] = 0;
        w[i] = 0;
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        p[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (b[i] > b[j])
            {
                temp = b[i];
                temp1 = p[i];
                b[i] = b[j];
                p[i] = p[j];
                b[j] = temp;
                p[j] = temp1;
            }
        }
    }
    w[0] = 0;
    for (i = 0; i < n; i++)
        w[i + 1] = w[i] + b[i];
    for (i = 0; i < n; i++)
    {
        t[i] = w[i] + b[i];
        awt = awt + w[i];
        att = att + t[i];
    }
    awt = awt / n;
    att = att / n;
    printf("\nProcess Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t\t%d\n", p[i], w[i], t[i]);
    }
    printf("Average waiting time is: %f\n", awt);
    printf("Average turn around time: %f\n", att);
    return 0;
}
