#include <stdio.h>
#include <stdlib.h>


int blocks[100];
int n, diskCapacity, blockCapacity;

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
	int i=0, flag;
	while(i<n)
	{
		if(blocks[i] != -1)
		{
			i++;
			continue;
		}

		flag = 1;
		for(int j=i; j<siz+i; j++)
			if(blocks[j] != -1 || j==n)
			{
				flag = 0;
				i = j;
				break;
			}

		if(flag)
			return i;

		i++;
	}

	return -1;
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
			int pos = findStartBlock(siz);
			if(pos == -1)
			{
				printf("F%d : Not enough memory\n", id);
			}
			else
			{
				for(int i=pos; i<pos+siz; i++)
					blocks[i] = id;
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