#include<stdio.h>

struct disk
{
	int index;
	int check;
};

struct disk a[100], temp;

int sub(int a, int b)
{
	if(a>b)
		return a-b;
	else
		return b-a;
}

void main(){
	int i,j,k,n,low,high,min,head,check1 = 1,distl,distr,sum=0;
	printf("Enter the number of requests\n");
	scanf("%d",&n);
	printf("Enter the ends of the disk\n");
	scanf("%d %d",&low, &high);
	printf("Enter the storing indices of the requests\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i].index);
		a[i].check = 0;
	}
	printf("Enter starting head\n");
	scanf("%d",&head);
	// for(i=0; i<n; i++)
	// {
	// 	if(a[i].index == head)
	// 	{
	// 		a[i].check = 1;
	// 		printf("%d\n", head);
	// 	}
	// }
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(a[j].index < a[min].index)
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	// for(i=0; i<n; i++)
	// 	printf("%d ", a[i].index);
	if(high - head < head - low)
	{
		i=0;
		while(a[i].index < head)
			i++;
		while(i < n)
		{
			sum+= a[i].index - head;
			a[i].check = 1;
			head = a[i].index;
			i++;
			printf("%d\n", head);
		}
		i--;
		sum+=high - a[n-1].index;
		head = high;
		while(a[i].check == 1)
			i--;
		while(i >= 0)
		{
			sum+= head - a[i].index;
			a[i].check = 1;
			head = a[i].index;
			i--;
			printf("%d\n", head);	
		}
	}
	else
	{
		i=n-1;
		while(a[i].index > head)
			i--;
		while(i >= 0)
		{
			sum+= head - a[i].index;
			a[i].check = 1;
			head = a[i].index;
			i--;
			printf("%d\n", head);
		}
		i++;
		sum+=a[0].index - low;
		head = low;
		while(a[i].check == 1)
			i++;
		while(i < n)
		{
			sum+= a[i].index - head;
			a[i].check = 1;
			head = a[i].index;
			i++;
			printf("%d\n", head);	
		}
	}
	printf("Total seek time = %d\n", sum);
}