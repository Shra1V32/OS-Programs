/*
Implementing FCFS using Process Scheduling Algorithm

Algorithm:
1. Start the process
2. Declare the array size
3. Get the number of processes to be inserted
4. Get the value
5. Start with the first process
6. Calculate the total number of burst time
7. Display the values
8. Stop the process
*/

#include <stdio.h>
int main()
{
    int n, a[10], b[10], t[10], w[10], g[10], i, m;
    float att = 0, awt = 0;
    for (i = 0; i < 10; i++)
    {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf(" %d", &n);
    printf("Enter the burst time: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]); // var b denotes burst time
    }
    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]); // var a denotes arrival time
    g[0] = 0;
    for (i = 0; i < 10; i++)
    {
        g[i + 1] = g[i] + b[i]; // Gant Chart
    }
    for (i = 0; i < n; i++)
    {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt = awt + w[i];
        att = att + t[i];
    }
    awt = awt / n; // Calculate Average wait Time
    att = att / n; // Calculate Average Arrival Time
    printf("\nProcess\t\tWaiting Time\t\tTurn around time\n");
    for (i = 0; i < n; i++)
    {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    printf("The average wait time is: %f\n", awt);
    printf("The average turn around time is: %f\n", att);
}