#include <stdio.h>
int main() {
    // FCFS = First Come First Serve CPU Scheduling
    int n;
    int bt[10], wt[10], tat[10];
    float avg_wt = 0, avg_tat = 0;
    printf("FCFS Scheduling\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nProcess\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);
    return 0;
}
