#include <iostream>
#include <queue>
using namespace std;
#define max 5

class QueueOperations
{
public:
    int queue[max];
    int front = -1;
    int rear = -1;

    void enqueue(int item)
    {
        if (rear == max - 1)
        {
            cout << "Queue overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0; // means both front and rear is pointing same index so item will be enqued
            queue[rear] = item;
            cout << "Enqued item is:" << item << endl;
        }
        else
        {
            queue[++rear] = item; // after first element is enqued then we should always enqueue item from rear side so we will increase the index of rear
            cout << "Enqued item is:" << item << endl;
        }
    }
    void dequeue()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is underflow" << endl;
        }
        else if (front == rear)
        {
            cout << "Deque item is:" << queue[front] << endl;
            front = rear = -1; // both front and rear is same so after dequeing queue will be empty
        }
        else
        {
            cout << "Deque item is:" << queue[front] << endl;
            front++; // after dequeuing index shifts to next as we always deque from front so we increase the index of front
        }
    }
    void peek()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front of the queue is:" << queue[front] << endl;
        }
    }
    void display()
    {
        if (front == -1 & rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue items are:" << endl;
            int i;
            for (i = front; i <= rear; i++) // stating from front to index equal to rear after that queue will be empty
            {
                cout << queue[i] << "\t";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    QueueOperations qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.dequeue();
    qu.peek();
    qu.dequeue();
    qu.dequeue();
    qu.display();
    qu.enqueue(7);
    qu.dequeue();
}