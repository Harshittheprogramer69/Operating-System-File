#include <stdio.h>
int main() {
    int n,i;
    int base[10],limit[10];
    int seg,offset;
    printf("Enter number of Segements: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        printf("Enter Base address of segement %d: ", i);
        scanf("%d",&base[i]);
        printf("Enter limit of segment %d: ",i);
        scanf("%d",&limit[i]);
    }
    printf("\nEnter segment number:\n");
    scanf("%d",&seg);
    printf("Enter offset: ");
    scanf("%d",&offset);
    if(seg < n && offset < limit[seg]) {
        int physical_address = base[seg] + offset;
        printf("Physical Address = %d\n",physical_address);
    } else {
        printf("Invalid logical address(Segementation Fault).\n");
    }
    return 0;
}