#include <iostream>
#include <conio.h>
using namespace std;
#define MAX_SIZE 5

class PriorityQueueOperation
{
public:
    int size = 0;
    int data[MAX_SIZE];
    int priority[MAX_SIZE];

    void enqueue(int newData, int newPriority)
    {
        if (size == MAX_SIZE)
        {
            cout << "Queue is full.Cannot enqueue. \n";
            return;
        }

        int i = size;
        while (i > 0 && newPriority > priority[i - 1])
        {
            data[i] = data[i - 1];
            priority[i] = priority[i - 1];
            i--;
        }

        data[i] = newData;
        priority[i] = newPriority;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty.Cannot dequeue. \n";
            return -1;
        }

        int dequeuedData = data[0];

        for (int i = 1; i < size; i++)
        {
            data[i - 1] = data[i];
            priority[i - 1] = priority[i];
        }
        size--;
        return dequeuedData;
    }

    void displayQueue()
    {
        if (size == 0)
        {
            cout << "Queue is empty \n";
            return;
        }
        cout << "Priority Queue:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "(" << data[i] << "," << priority[i] << ")";
        }
        cout << "\n";
    }
};
int main()
{
    PriorityQueueOperation pq;
    pq.enqueue(50, 2);
    pq.enqueue(20, 8);
    pq.enqueue(30, 3);
    pq.displayQueue();
    int dequeuedData = pq.dequeue();
    cout << "Dequeued element:" << dequeuedData << endl;
    pq.displayQueue();
    return 0;
}