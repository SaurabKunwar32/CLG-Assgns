#include <stdio.h>
#include<conio.h>
#define max 5

    int stack[max];
    int top = -1; /// means stack is empty

    void push(int item) 
    {
        if (top == max - 1) // stack is full
        {
            printf("Satck Overflow \n") ;
        }
        else
        {
            stack[++top] = item;
            printf("Item Pushed is:");
            printf("%d \n",item);
        }
    }

    void pop()
    {
        if (top == -1)
        {
              printf("Satck Underflow \n") ;
        }
        else
        {
           top-- ;
           
        }
    }

    void peek()
    {
        if (top == -1)
        {
            printf("Satck is Empty \n") ;
        }
        else
        {
            printf("Top of the stack is:%d \n",stack[top] );
        }
    }

    void display()
    {
        if (top == -1)
        {
             printf("Satck is Empty \n") ;
        }
        else
        {
             printf("Satck Items are \n") ;
            int i;
            for (i = top; i >= 0; i--)
            {
                printf("%d \n",stack[i]);
            }
        }
    }

int main()
{
    push(4);
    push(65);
    push(34);
    push(74);
    push(50);
    peek();
    pop();
    pop();
    pop();
    // pop();
    // pop();
    display();
    push(7);
}