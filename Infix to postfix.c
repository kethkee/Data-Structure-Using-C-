#include<stdio.h>
#include<ctype.h>
void push(char);
void pop();
int priority(char),top = -1;
char stack[50];
void main()
{
    char infix[50];
    printf("Enter the infix expression: ");
    scanf("%s",&infix);
    printf("The corresponding postfix expression is: ");
    int i = 0;
    
    char ch,item;
    while(infix[i]!='\0')
    {
        ch = infix[i];
        if(ch == '(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            printf("%c",ch);
        }
        else if(ch == ')')
        {
            while(stack[top]!='(')
            {
                printf("%c",stack[top]);
                pop();
                
            }
            pop();
        }
        else
        {
        while (top != -1 && priority(stack[top]) >= priority(ch))
        {
            printf("%c", stack[top]);  
            pop();  
        }
        push(ch);  
        }
        
     
        i++;
        
    }
    while (top != -1)
    {
        printf("%c", stack[top]);
        pop();
    }
}    
void push(char ch)
{
    if(top>=49)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
void pop()
{
  if(top == -1)
  {
      printf("Stack underflow");
  }
  else
  {
      
      top --;
  }
}
int priority(char ch)
{
    if(ch == '(')
        return 0;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}
