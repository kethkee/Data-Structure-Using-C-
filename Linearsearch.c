#include<stdio.h>
void main()
{
	int n,i,x,count=0,time=0;
	time=time+2;
	
	printf("Enter the number of elements:");
	time++;
	scanf("%d",&n);
	time++;
	int A[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element %d:",i+1);
		time++;
		scanf("%d",&A[i]);
		time++;
		time++;
	}
	time++;
	printf("Enter search element:");
	time++;
	scanf("%d",&x);
	time++;
	for(i=0;i<n;i++)
	{
	        time++;
		if(A[i]==x)
		{
			count++;
			time++;
			printf("Element found at position %d \n",i+1);
			time++;
		}
	}
	time++;
	if(count>0)
	{
	        time++;
		printf("Item is found %d times\n",count);
		time++;
	}	
	else
	{
		time++;
		printf("Item not found");
		time++;
	}	
	printf("Space complexity = %d\n",(5*4)+(n*4));
	time++;
	printf("Time complexity = %d",time+1);
	
	
}				
				
