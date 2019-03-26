#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N=100;

int buffer[100];
int n, front = 0, rear = 0, cnt = 0; 

void push(int x)
{
	if(cnt==N)
		return;

	buffer[rear] = x;
	rear = (rear +1)%N;
	cnt++;
}

int pop()
{
	if(cnt==0)
		return -1;

	int ret = buffer[front];
	front = (front +1)%N;
	cnt--;
	return ret;
}

int main() {
    
    srand(time(0));
        
    int n;
    printf("Enter size of buffer: ");
    scanf("%d", &n);

    while(1) {
        
        printf("Press\n1 to Produce\n2 to Consume\n3 to Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(cnt == n)
                    printf("Buffer is full!\n\n");
                else {
                    int item = rand()%1000;
                    push(item);
                    printf("Producer produces %d\n\n", item); 
                }   
                break;
            case 2:
                if(cnt == 0)
                    printf("Buffer is empty!\n\n");
                else {
                    int item = pop();
                    printf("Consumer consumes %d\n\n", item);
                }
                break;
            case 3:
                printf("Exiting...\n\n");
                return 0;
            default:
                printf("Invalid input!\n\n");
        }
    }

    return 0;
}
