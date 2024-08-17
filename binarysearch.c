#include<stdio.h>
void main()
{
	int n,x,flag=0,left,mid,i,time=0,space;
	time=time+2;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	time=time+2;
	int right,A[n];
	for(i=0;i<n;i++)
	{
	        time++;
		printf("Enter element %d:",i+1);
		scanf("%d",&A[i]);
		time=time+2;
	}
	time++;
	printf("Enter element to search:\n");
	scanf("%d",&x);
	time=time+2;
	left=0,right=n-1;
	time=time+2;
	while(left<=right)
	{
			time++;
			mid=(left+right)/2;
			time++;
			if(x==A[mid])
			{
				time++;
				flag=1;
				time++;
				break;	
			}	
			else if(x>A[mid])
			{
				time++;
				left=mid+1;
				time++;
			}	
			else if(x<A[mid])
			{	
				time++;
				right=mid-1;
				time++;
			}	
	}
	time++;	
		
	if(flag==0)
	{
		time++;
		printf("Element not found\n");
		time++;
	}	
	else
	{
		time++;
		printf("Element found\n");
		time++;
	}
	printf("Space complexity = %d\n",36+(n*4));
	time++;
	printf("Time complexity = %d",time+1);	
}							
