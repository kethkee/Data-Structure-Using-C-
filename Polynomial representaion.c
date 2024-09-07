#include<stdio.h>
struct poly
{
	int coeff;
	int expo;
};
void main()
{
	int n,i;
	printf("Enter the number of terms in the polynomial: ");
	scanf("%d",&n);
	struct poly A[n];
	printf("Enter the terms in the polynomial:\n");
	printf("HINT: In descending order\n");
	for(i=0;i<n;i++)
	{
		printf("Coefficient %d: ",i+1);
		scanf("%d",&A[i].coeff);
		printf("Exponent %d: ",i+1);
		scanf("%d",&A[i].expo);
	}
	printf("The polynomial is:\n");
	for(i=0;i<n;i++)
	{
		if(i<n-1)
			printf("(%dx^%d)+",A[i].coeff,A[i].expo);
		else
					
			printf("(%dx^%d)",A[i].coeff,A[i].expo);
	}
}			
