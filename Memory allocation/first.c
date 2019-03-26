#include<stdio.h>


void main()
{
	int process[100], block[100], process1[100];
	int i,j,p,b;
	printf("Enter the number of blocks\n");
	scanf("%d",&b);
	printf("Enter the memory in each block\n");
	for(i=0; i<b; i++)
	{
		//printf("%d ",i);
		scanf("%d",&block[i]);
	}
	printf("Enter the number of processes\n");
	scanf("%d",&p);
	printf("\n");
	printf("Enter the memory required for each process\n");
	for(i=0; i<p; i++)
	{
		//printf("%d ",i);
		scanf("%d",&process[i]);
		process1[i] = -1;
	}
	
	for(i=0; i<p; i++)
	{
		for(j=0; j<b; j++)
		{
			if(process[i] <= block[j])
			{
				process1[i] = j;
				block[j] -= process[i];
				break;
			}
		}
	}
	printf("Process\tProcess size\tBlock Assigned\t\n");
	for(i=0; i<p; i++)
	{
		printf("%d\t", i);
		printf("%d\t\t", process[i]);
		if(process1[i] == -1)
			printf("Block not assigned\n");
		else
			printf("%d\n", process1[i]);
	}
}