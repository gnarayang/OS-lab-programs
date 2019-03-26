#include<stdio.h>

struct disk
{
	int index;
	int check;
};

struct disk a[100];

int sub(int a, int b)
{
	if(a>b)
		return a-b;
	else
		return b-a;
}

void main(){
	int i,j,k,n,low,high,temp,min,head,check1 = 1,distl,distr,sum=0;
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
	for(i=0; i<n; i++)
	//while(check1)
	{
		min = -1;
		for(j=0; j<n; j++)
		{
			if(a[j].check == 0) {
			if(min == -1)
				min = j;
			else if(sub(a[j].index, head) < sub(a[min].index, head))
				min = j;
			}
		}
		printf("%d %d\n", a[min].index, a[min].check);
		sum+= sub(a[min].index, head);
		head = a[min].index;
		a[min].check = 1;
		check1 = 0;
		for(j=0; j<n; j++)
		{
			if(a[j].check == 0)
			{
				printf("%d\n", j);
				check1 = 1;
				break;
			}
		}
	}

	printf("Total seek time = %d\n", sum);

	// for(i=0; i<n-1; i++)
	// {
	// 	min = i;
	// 	for(j=i+1; j<n; j++)
	// 	{
	// 		if(a[j] < a[min])
	// 			min = j;
	// 	}
	// 	temp = a[i];
	// 	a[i] = a[min];
	// 	a[min] = temp;
	// }

	// i=0;
	// while(head < a[i])
	// 	i++;
	// i--;

	// while(check1)
	// {
	// 	if(i!=0)
	// 	{
	// 		j = i-1;
	// 		while(check[j] == 1)
	// 		{
	// 			j--;
	// 		}
	// 		distl = head - a[j];
	// 	}
	// 	else
	// 		distl = 10000;
	// 	if(i!=n-1)
	// 	{
	// 		k = i+1;
	// 		while(check[k] == 1)
	// 		{
	// 			k++;
	// 		}
	// 		distr = a[k] - he;
	// 	}
	// 	else
	// 		distr = 10000;
	// 	if()

	// }

	// for(i=0; i<n; i++)
	// 	printf("%d %d\n", i, a[i]);

}