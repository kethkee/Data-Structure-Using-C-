#include<stdio.h>
int n;
int queue[20];
int front = 0;
int rear = 0;
int count = 0;
void enqueue(int x)
{
	if(count == n)
	{
		printf("Circular queue is full!\n");
		return;
	}
	queue[rear] = x;
	rear = (rear+1)%n;
	count++;
}	
void dequeue()
{
	if(count == 0)
	{
		printf("Circular queue is empty!\n");
		return;
	}
	int x = queue[front];
	front = (front+1)%n;
	count--;
	printf("Removed element from circular queue is: %d\n",x);
}
void display()
{
	if(count == 0)
	{
		printf("Circular queue is empty!\n");
		return;
	}	
	printf("Circular queue elements: \n");
	int i = front;
	for(int j =0;j<count;j++)
	{
		printf("%d\t",queue[i]);
		i = (i+1)%n;
	}
	printf("\n");
}
void main()
{
	printf("Enter size of the queue:");
	scanf("%d",&n);
	int choice,x;
	while(1)
	{
		printf("***QUEUE OPEARTIONS***");
		printf("\n1.ENQUEUE");
		printf("\n2.DEQUEUE");
		printf("\n3.DISPLAY");
		printf("\n4.EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter enqueue element:");
			      scanf("%d",&x);
			      enqueue(x);
			      break;
		     	case 2:dequeue();
		     	       break;
		     	case 3:display();
		     	       break;
		     	case 4:printf("Code executed successfully\n");
		     	       return;
		     	default:printf("Invalid");
		}
	}
}			     	                     	      
			      
									
