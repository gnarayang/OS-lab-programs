#include<stdio.h>

struct frame
{
	int page;
	int count;
};

struct frame frames[100];

int f, p, i, j, k, pages[100], check, hit=0, miss=0, max_rank=0, min;

int print_frames(){
	int i;
	for (i = 0; i < f; ++i)
	{
		printf("%d ",frames[i].page);
	}
	printf("\n");
}

void main(){		
	printf("Enter the number of frames\n");
	scanf("%d",&f);
	printf("Enter the number of pages\n");
	scanf("%d",&p);
	printf("Enter the page numbers in order\n");
	for(i=0; i<p; i++)
	{
		scanf("%d",&pages[i]);
	}
	for (i = 0; i < f; ++i)
	{
		frames[i].page = -1;
		frames[i].count = 0;
	}
	printf("Enter the \n");
	for(i=0; i<p; i++)
	{
		printf("%d ",pages[i]);
		check = 0;
		for(j=0; j<f; j++)
		{
			if(pages[i] == frames[j].page)
			{
				check = 1;
				printf("HIT ");
				hit++;
				max_rank++;
				frames[j].count = max_rank;
				print_frames();
				break;
			}
		}
		if(check == 0)
		{
			printf("MISS ");
			miss++;
			min = 0;
			for(j = 0; j<f; j++)
			{
				if(frames[j].count < frames[min].count)
				{
					min = j;
				}
			}
			max_rank++;
			frames[min].page = pages[i];
			frames[min].count = max_rank;
			print_frames(); 
		}
	}
	printf("The number of hits = %d and misses = %d\n",hit, miss);
	printf("\n");
}

