// #include <iostream>
// using namespace std;

// struct  node {
//     int data;
//     struct node* left; 
//     struct node* right; 
// }

// struct node* root=nullptr;
// struct node* delete(struct node* root , int key);



// struct node*  delete (struct node* root , int key){

//     if(root== nullptr){
//         return nullptr;
//     }

//     if(key < root->data){
//         root -> left = delete (root->left , key);
//     }

//