#include<stdio.h>
void main()
{
    int n,temp,i,j,t=0;
    t++;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    t=t+2;
    int A[n];
    printf("Enter array elements:\n");
    t++;
    for(i=0;i<n;i++)
    {
        t++;
        printf("Enter element %d:",i+1);
        scanf("%d",&A[i]);
        t=t+2;
    }
    t++;
    for(i=0;i<n-1;i++)
    {
        t++;
        for(j=0;j<n-i-1;j++)
        {
            t++;
            if(A[j]>A[j+1])
            {
                t++;
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                t=t+3;
            }
        }
        t++;
    }
    t++;
    printf("Sorted array is:\n");
    t++;
    for(i=0;i<n;i++)
    {
        t++;
        printf("%d\t",A[i]);
        t++;
    }
    t++;
    printf("\nSpace complexity = %d\n",24+(n*4));
    t++;
    printf("Time complexity = %d",t+1);
}
