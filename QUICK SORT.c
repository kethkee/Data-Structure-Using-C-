#include<stdio.h>
void swap(int A[], int s, int e);
int partition(int A[], int low, int high);
void quicksort(int A[], int low, int high);
int A[20];
void main()
{
   int n,i;
   printf("Enter the size of the array: ");
   scanf("%d",&n);
   printf("Enter array elements\n");
   for(i=0;i<n;i++)
   {
       printf("Element %d: ",i+1);
       scanf("%d",&A[i]);
   }
   printf("Array is\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t",A[i]);
   }
   quicksort(A, 0, n - 1);
   printf("\nSorted array is\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t",A[i]);
   }
}
void swap(int A[20],int s,int e)
{
    int temp;
    temp = A[s];
    A[s] = A[e];
    A[e] = temp;
}
int partition(int A[20], int low, int high) {
    int pivot = A[low];
    int start = low+1;
    int end = high;
    
    while (start <= end) 
    {
        while (A[start] <= pivot && start <= end)
        {
            start++;
        }
        while (A[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        {
            swap(A, start, end);
        }
    }
    swap(A, low, end); 
    return end;
}
void quicksort(int A[20], int low, int high) 
{
    if (low < high) 
    {
        int pivot_index = partition(A, low, high);
        quicksort(A, low, pivot_index - 1);
        quicksort(A, pivot_index + 1, high);
    }
}

