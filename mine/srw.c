#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(0));
    
    int resource = 0, wrt;

    while(1) {
            
        printf("1. Read 2. Write 3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Reader reading %d\n", resource);
                break;
            case 2:
                wrt = rand()%1000;
                resource = wrt;
                printf("Writer writes %d\n", resource);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
