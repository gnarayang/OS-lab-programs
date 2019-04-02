#include <stdio.h>
#include <stdlib.h>


int blocks[100];
int n, diskCapacity, blockCapacity, starting, ending;

int ceilDivision(int a, int b){
	return a/b + (a%b != 0);
}

void printDisk()
{
	for(int i=0; i<n; i++)
	{
		printf("%d ", blocks[i]);
	}
	printf("\n");
}

int findStartBlock(int siz)
{
	int i=0, count=0;
	while(i<n)
	{
		if(blocks[i] != -1)
		{
			i++;
			continue;
		}
		i++;
		break;
	}
	while(i<n)
	{
		if(blocks[i] == -1)
		{
			count++;
		}
		i++;
	}
	if(count < siz)
		return -1;
	else
		return 1;
}


int main()
{
	int ch;
	printf("Enter Disk Capacity\n");
	scanf("%d", &diskCapacity);

	printf("Enter Block Capacity\n");
	scanf("%d", &blockCapacity);

	n = diskCapacity/blockCapacity;
	for(int i=0; i<n; i++)
		blocks[i] = -1;

	do
	{
		printf("Enter\n1 to Add File\n2 to Remove File\n3 to Search\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			int id, siz;
			printf("Enter file ID\n");
			scanf("%d", &id);

			printf("Enter file size\n");
			scanf("%d", &siz);

			siz = ceilDivision(siz, blockCapacity);
			printf("Enter the starting and ending location\n");
			scanf("%d%d", &starting, &ending);
			if(blocks[starting]!= -1 && blocks[ending]!= -1)
			{
				printf("Entered starting and ending index is not empty\n");
			}
			else
			{
				// printf("check\n");
				int pos = findStartBlock(siz);
				if(pos == -1)
				{
					printf("F%d : Not enough memory\n", id);
				}
				else
				{
					int i = 0;
					int location;
					if(siz == 1)
					{
						blocks[starting] = id;
					}
					else
					{
						blocks[starting] = id;
						blocks[ending] = id; 
						while(i < siz - 2)
						{
							location = rand()%n;
							if(blocks[location] == -1)
							{
								blocks[location] = id;
								i++;
							}
						}
					}
				}
			}
		}
		else if(ch == 2)
		{
			int id;
			printf("Enter file id to remove\n");
			scanf("%d", &id);

			for(int i=0; i<n; i++)
				if(blocks[i] == id)
					blocks[i] = -1;
		}
		else if(ch == 3)
		{
			int id;
			printf("Enter file id to search for\n");
			scanf("%d", &id);

			int flag = 0;
			for(int i=0; i<n; i++)
				flag += (blocks[i] == id);

			if(!flag)
				printf("File not found in Disk\n");
			else
			{
				printf("Blocks in which F%d is present in\n", id);
				for(int i=0; i<n; i++)
					if(blocks[i] == id)
						printf("%d ", i);
				printf("\n");
			}
		}

		printDisk();
	}while(ch >= 1 && ch <= 3);
}