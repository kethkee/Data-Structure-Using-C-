#include<stdio.h>
void main()
{
	int i,j,m=1,r,c,A[10][10],B[10][3];
	printf("Enter number of rows and columns: ");
	scanf("%d%d",&r,&c);
	printf("Enter matrix elements:\n");
	for(i=0;i<r;i++)
	{
		printf("Enter elements of row %d: ",i+1);
		for(j=0;j<c;j++)
		{
		
			scanf("%d",&A[i][j]);
			
		}
	}
	printf("The matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",A[i][j]);
			
		}
		printf("\n");
		
	}
	B[0][0]=r;
	B[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(A[i][j]!=0)
			{
				B[m][0]=i;
				B[m][1]=j;
				B[m][2]=A[i][j];
				m++;
			}
		}
		
	}
	
	B[0][2]=m-1;
	printf("\nROW\tCOLUMN\tVALUE\n");
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<3;j++)			
		{
			
			printf("%d\t",B[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}			
			
