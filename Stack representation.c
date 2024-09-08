#include <stdio.h>
void push();
void pop();
void display();
int item,top=-1,A[20],i,maxsize;
void main()
{
    int ch;
    printf("Enter limit:");
    scanf("%d",&maxsize);
    while(ch!=4)
    {
        printf("1.PUSH\t2.POP\t3.DISPLAY\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                  break;
            case 2:pop();
                  break;
            case 3:display();    
                  break;
            case 4:break;
        }
    }
}   
    void push()
    {
        if(top==maxsize-1)
        {
            printf("Overflow\n");
        }
        else
        {
            printf("Element to be pushed:");
            scanf("%d",&item);
            top++;
            A[top]=item;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            printf("Underflow\n");
        }
        else
        {
           item = A[top];
           top--;
           printf("Deleted item is %d\n",item);
           
        }
    }
    void display()
    {
        printf("Stack is:");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",A[i]);
        }
    }
