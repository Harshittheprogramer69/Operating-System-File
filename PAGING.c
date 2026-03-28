#include <stdio.h>
int main() {
    int pages, frames, i;
    int page_table[50];
    printf("Enter Number of Pages: ");
    scanf("%d",&pages);
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    if(pages > frames) {
        printf("Paging cannot be done since pages > frames.");
        return 0;
    }
    printf("\n\nEnter Frame number for each page\n\n");
    for(i = 0; i < pages; i++) {
        printf("Pages %d-> Frame: ",i);
        scanf("%d",&page_table[i]);
    }
    printf("\nPAGE TABLE:\n");
    printf("Page No\tFrame No\n");
    for(i = 0; i < pages; i++) {
        printf("%d\t%d\n",i,page_table[i]);
    }
    return 0;
}