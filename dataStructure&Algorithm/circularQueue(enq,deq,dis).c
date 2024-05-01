#include <stdio.h>
#include <conio.h>
#define N 5

int Cirqueue[N];
int front = -1;
int rear = -1;

void Enqueue(int x)
{

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Cirqueue[rear] = x;
        printf("Queued item is:%d\n", Cirqueue[rear]);
    }
    else if ((rear + 1) % N == front)
    {
        printf("Queue is full");
    }
    else
    {
        rear = (rear + 1) % N;
        Cirqueue[rear] = x;
        printf("Queued item is:%d\n", Cirqueue[rear]);
    }
}

void Dequeue()
{

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\nDequed item is:%d\n", Cirqueue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!");
    }
    else
    {
        printf("Queue items are:\n");
        int i = front;
        while (i != rear)
        {
            printf("%d\t", Cirqueue[i]);
            i = (i + 1) % N;
        }
        printf("%d",Cirqueue[rear]);
    }
}

int main()
{
    Enqueue(20);
    Enqueue(50);
    Enqueue(70);
    Enqueue(90);
    display();
    Dequeue();
    display();
}