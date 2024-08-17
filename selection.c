#include<stdio.h>
void main()
{
	int n,A[100],i=0,j=0,small,temp,time=0;
	time=time+3;
	printf("Enter the number of elements:");
	time++;
	scanf("%d",&n);
	time++;
	printf("Enter elements:");
	time++;
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		time=time+2;
	}
	time++;	
	for(i=0;i<n;i++)
	{
		time++;
		small=i;
		j=i+1;
		time=time+2;
	
	
	while(j<n)
	{
		time++;
		if(A[small]>A[j])
		{
			small=j;
			j=j+1;
			time=time+3;
		}
		else
		{
			j=j+1;
			time=time+2;
		}
		
	}
	time++;
	if(small!=i)
	{
		temp=A[i];
		A[i]=A[small];
		A[small]=temp;
		time=time+3;
	}
	}
	printf("Sorted list:\n");
	time=time+1;
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
		time=time+2;
	}
	time++;
		
					
		
		
			
	printf("\nSpace complexity = %d\n",28+(n*4));
	time++;
	printf("Time complexity = %d",time+1);
}	
							
