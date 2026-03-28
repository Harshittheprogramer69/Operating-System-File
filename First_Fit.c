#include <stdio.h>
int main() {
    int blockSize[20],processSize[20];
    int allocation[20];
    int m,n,i,j;
    printf("Enter numbers of Memory blocks: ");
    scanf("%d",&m);
    printf("Enter size of each block: \n");
    for(i = 0; i < m; i++) {
        printf("Block Size -> ");
        scanf("%d",&blockSize[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter size of each Process: ");
    for(i = 0; i < n; i++) {
        printf("Process Size -> ");
        scanf("%d",&processSize[i]);
    }
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t",i+1,processSize[i]);

        if(allocation[i] != -1) {
            printf("%d\n",allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}