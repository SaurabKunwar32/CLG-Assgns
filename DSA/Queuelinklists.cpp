#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedListQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            exit(EXIT_FAILURE);
        }

        int dequeueValue = front->data;
        Node *temp = front;

        if (front == rear)
        {
            // only one element in the queue

            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }

        delete temp;
        return dequeueValue;
    }

    bool isEmpty() const
    {
        return (front == nullptr);
    }

    ~LinkedListQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main(){
    LinkedListQueue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(50);
    queue.enqueue(15);
    queue.enqueue(65);

    // dequeue and print

    while (!queue.isEmpty()){
        cout<<"Dequeued:"<<queue.dequeue()<<endl;
    }

    return 0;
}