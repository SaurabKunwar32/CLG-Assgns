#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void createList(int arr[], int size)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = arr[0];
    head->link = NULL;

    struct node *end = head;
    struct node *temp;

    for (int i = 1; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = NULL;
        end->link = temp;
        end = temp;
    }
}

void countList()
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    cout << "Total Elements in the List:" << count << endl;
}

void printListElements()
{
    struct node *ptr = head;
    cout << "Elements:[";
    while (ptr != NULL)
    {
        cout << "\t" << ptr->data;
        ptr = ptr->link;
    }
    cout << "]" << endl;
    ;
}

void insertAtBegining(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = head;
    head = newnode;
}

void insertAtEnd(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *end = head;
    while (end->link != NULL)
    {
        end = end->link;
    }
    end->link = newnode;
}
void deleteAtBegining()
{
    if (head == NULL)
    {
        cout << "List is Empty.." << endl;
    }
    struct node *temp = head;
    head = head->link;
    cout << "Deleted item from list is:" << temp->data << endl;
    free(temp);
}
void deleteAtEnd()
{
    struct node *secondlast = head;
    while (secondlast->link->link != NULL)
    {
        secondlast = secondlast->link;
    }
    free(secondlast->link);
    secondlast->link = NULL;
}
void insertAtPosition(int data, int position)
{
    if (position < 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    struct node *current = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (position == 1)
    {/* 
        newnode->link = head;
        head = newnode;
        return; */
        insertAtBegining(data);
    }
    for (int i = 1; i < position - 1; i++)
    {
        current = current->link;
    }
    if (current == NULL)
    {
        cout << "Invalid Position" << endl;
        free(newnode);
        return;
    }
    newnode->link = current->link;
    current->link = newnode;
    cout << data << "is inserted at the position" << position << endl;
}

void deleteAtPosition(int position)
{
    if (head == NULL || position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1)
    {
        deleteAtBegining();
        return;
    }
    struct node *current = head;
    struct node *prev = NULL;
    for (int i = 1; i < position && current != NULL; i++)
    {
        prev = current;
        current = current->link;
    }
    if (current == NULL)
    {
        cout << "Invalid position ! cannot delete.." << endl;
        return;
    }
    prev->link = current->link;
    cout << "Data deleted at the position" << position << "is" << current->data << endl;
    free(current);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    createList(arr, 5);
    cout << "Linked List After Creation" << endl;
    printListElements();
    insertAtBegining(7);
    cout << "Linked List After inserting at Begining" << endl;
    printListElements();
    insertAtEnd(8);
    cout << "Linked List After inserting at End" << endl;
    printListElements();
    countList();
    deleteAtEnd();
    printListElements();
    deleteAtBegining();
    printListElements();
    insertAtPosition(8,4);
    printListElements();
    deleteAtPosition(4);
    printListElements();

}