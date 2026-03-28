#include <stdio.h>
int main() {
    // SJF = Shortest Job First CPU Scheduling
    int n;
    int bt[10], wt[10], tat[10], p[10];
    float avg_wt = 0, avg_tat = 0;
    printf("SJF Scheduling\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
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
    printf("\nProcess Burst Waiting Turnaround\n");
    for(int i = 0; i < n; i++)
        printf("P%d      %d      %d        %d\n", p[i], bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    return 0;
}