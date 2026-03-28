#include <stdio.h>
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int process_id[n], burst_time[n], priority[n]; 
    int waiting_time[n], turnaround_time[n];
    int i, j; // Loops
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        process_id[i] = i + 1;
        printf("Enter Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
    }
    // Bubble Sorting
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {
                swap(&priority[i],&priority[j]);
                swap(&burst_time[i],&burst_time[j]);
                swap(&process_id[i],&process_id[j]);
            }
        }
    }
    waiting_time[0] = 0;
    for(i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    printf("\nPID\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
               process_id[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    return 0;
}