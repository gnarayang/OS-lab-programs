#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(0));
    
    int resource = 0, wrt;

    while(1) {
            
        printf("Press\n1 to Read\n2 to Write\n3 to Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Reader reading %d\n\n", resource);
                break;
            case 2:
                wrt = rand()%1000;
                resource = wrt;
                printf("Writer writes %d\n\n", resource);
                break;
            case 3:
                printf("Exiting...\n\n");
                return 0;
            default:
                printf("Invalid choice!\n\n");
        }
    }

    return 0;
}
