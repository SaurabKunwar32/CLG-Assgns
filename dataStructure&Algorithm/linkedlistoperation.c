// WRONG 


// #include<stdio.h>
// #include<stdlib.h>


// struct node
//  {
//     int data;
//     struct node* link;
// };

// struct node* head = NULL;

// void creatList(int arr[], int size){
//     head = (struct node*) malloc (sizeof(struct node));
//     head->data = arr[0];
//     head->link = NULL;

//     struct node* temp;
//     struct node* end = head;


//     for(int i=1; i<size;i++){
//         temp = (struct node*) malloc (sizeof(struct node));
//         temp->data = arr[i];
//         temp->link = NULL;

//         end -> link = temp;
//         end = temp;
//     }

//     printf("Linked list created successfully\n");

// }


// void countList(){
//     int count = 0;
//     struct node* ptr = head;
//     while (ptr!=NULL) {
//         count++;
//         ptr = ptr->link;
//     }
//     printf("Total no.of elements:%d\n",count);
// }



// void printList(){
//     struct node* ptr = head;
//     printf("Elements:[ ");
//     while(ptr != NULL){
//         printf("%d",ptr->data);
//         ptr = ptr->link;
//     }
//     printf("]\n");
// }


// void insertAtBegin(int value){
//     struct node* newNode =(struct node*) malloc (sizeof(struct node));
//     newNode->data = value;
//     newNode->link = head;
//     head = newNode;
//     printf("%d successfully inserted at the beginning:\n",value);
// }


// void insertAtEnd(int value){
//     struct node* newNode = (struct node*) malloc(sizeof(struct node));
//     newNode->data = value;
//     newNode->link = NULL;
//     struct node* ptr = head;

//     while(ptr-> link != NULL){
//         ptr = ptr->link;
//     }


//     ptr->link = newNode;
//     printf("%d successfully inserted at the end:\n",value);
    
// }



// void deleteAtBegin(){
//     struct node* temp = head;
//     printf("Value deleted from the beginning = %d \n", head->data);
//     head = head->link;
//     free(temp);

// }


// void deleteAtLast(){
//     struct node* last = head;
//     struct node* secondLast = NULL;
//     while(last->link != NULL){
//         secondLast = last;
//         last = last->link;
//     }

//     if(secondLast = NULL){
//         head = NULL;
//     }else {
//         secondLast->link = NULL;
//     }

//     printf("Value deleted from the end = %d \n",last->data);
//     free(last);
// }



// void insertAtPosition(int value, int position){
//     if(position < 1) {
//         printf("Invalid  position.\n");
//         return;
//     }

//     struct node* new_node = (struct node*)malloc(sizeof(struct node));
//     new_node->data = value;

//     if(position = 1) {
//         // insert at the beginning
//         new_node-> link = head;
//         head = new_node;
//         return;
//     }


// // transverse to the node at position -1

//     struct node* current = head;
//     for(int i=1; i < position-1 && current != NULL; i++){
//         current = current->link;
//     } 

//     if(current=NULL){
//         printf("Invalid position\n");
//         free(new_node);
//         return;
//     }


// // Insert the new node at the specified position 
//   new_node->link = current->link;
//   current->link = new_node;

//   printf("%d inserted at position %d\n",value,position);
// }



// void deleteAtPosition(int position){
//     if(head = NULL || position < 1){
//         printf("Invalid postion. Cannot deleted.\n");
//         return;
//     }

//     if(position = 1){
//         deleteAtBegin();
//         return;
//     }

//     struct node* current = head;
//     struct node* prev = NULL;


//     // Traverse to the node at the specified position 
//     for(int i=1; i < position && current != NULL; i++){
//         prev = current;
//         current = current->link;
//     }

//     if(current = NULL){
//         printf("Invalid position. Cannot deleted.\n");
//         return;
//     }


//     // Update the previous node's link to skip the current node
//     prev->link = current->link;
//     printf("Value deleted from position %d = %d\n",position,current->data);
//     free(current);
// }


// int main(){

//     int arr[5] = {5,3,5,4,45};
//     creatList(arr,5);

//     countList();
//     printList();

//     insertAtBegin(80);
//     printList();

//     insertAtEnd(533);
//     printList();

//     deleteAtBegin();
//     printList();

//     deleteAtLast();
//     printList();
// }