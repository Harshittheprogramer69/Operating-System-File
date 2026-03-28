#include <stdio.h>
int main() {
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter size of blocks:\n");
    for(i = 0; i < m; i++) {
        printf("Block Size -> ");
        scanf("%d", &blockSize[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of processes:\n");
    for(i = 0; i < n; i++) {
        printf("Process Size -> ");
        scanf("%d", &processSize[i]);
    }
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for(i = 0; i < n; i++) {
        int worstIndex = -1;
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if(worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}