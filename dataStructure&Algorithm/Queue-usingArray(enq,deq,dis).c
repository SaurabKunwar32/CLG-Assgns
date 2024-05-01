#include <stdio.h>
#include <conio.h>
#define N 5

int quque[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{

    if (rear == N - 1)
    {
        printf("Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        quque[rear] = x;
        printf("Enqued item is :%d\n", x);
    }
    else
    {
        rear++;
        quque[rear] = x;
        printf("Enqued item is:%d\n", x);
    }
}

void dequeue()
{

    if (front == -1 && rear == -1)
    {
        printf("UnderFlow");
    }
    else if (front == rear)
    {
        printf("Dequed item is %d:\n", quque[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequed item is:%d\n", quque[front]);
        front++;
    }
}

void display()
{

    if (front == -1 && rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("Queue items are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", quque[i]);
        }
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("\nThe peek item is:%d\n", quque[front]);
    }
}

void main()
{
    enqueue(5);
    enqueue(15);
    enqueue(50);
    display();
    peek();
    dequeue();
    display();
}