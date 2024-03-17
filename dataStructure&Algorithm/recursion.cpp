// FINDING THE SUMS OF 'n' TILL 'n-1'********************************************************************************************************

// #include<iostream>
// using namespace std;

// int Sum(int n){
//     if(n==0){
//         return 0;
//     }

// int preSum=Sum(n-1);
// return n + preSum;
// }



// int main(){

//     int n;
//     cout<<"Enter the number to get the sum:"<<endl;
//     cin>>n;

//     cout<<"Total sum is:" << Sum(n) << endl;
//     return 0;
// }





// FINDING THE POWER OF ANY NUMBER******************************************************************************************************

// #include<iostream>
// using namespace std;

// int Power(int n, int p){
//     if(p==0){
//         return 1;
//     }

//     int prevpower=Power(n,p-1);
//         return n*prevpower;
// }

// int main(){
//     int n,p;
//     cout<<"Enter the value of n & power p:\t";
//     cin>>n>>p;
//     cout<<"Required value is:"<< Power(n,p)<<endl;
// }




// FACTORIAL OF ANY NUMBER ****************************************************************************************************************

// #include<iostream>
// using namespace std;


// int factorial(int n){
//     if(n==0){
//     return 1;
// }
//     int prefacto=factorial(n-1);
//     return n*prefacto;
// }

// int main(){
//     int n;
//     cout<<"Enter the value to get factorial:";
//     cin>>n;
//     cout<<"Required Factorial is:"<<factorial(n)<<endl;
// }



// FINDING THE FIBONACCI NUMBER OF ANY NUMBER***********************************************************************************************

// #include<iostream>
// using namespace std;

// int fibo(int n){
//     if(n==0 || n==1){
//         return n;
//     }

//     return fibo(n-1)+fibo(n-2); 

// }

// int main(){
//     int n;
//     cout<<"Enter the number:";
//     cin>>n;
//     cout<<"The required fibonacci number is:"<<fibo(n)<<endl;
// }









// QUERY USING LINKED LISTS

// #include<iostream>
// using namespace std;

// class Node {
//     public:
//             int data;
//             Node* link;
//             Node(int value){
//                 data = value;
//             };


// class LinkedQueue {
//     private:
//             Node* front;
//             Node* rear;
//             LinkedQueue(){
//                 front=nullptr;
//                 rear=nullptr;
//             }
//     void enqueue (int value){
//         Node* newNode=new Node(value);
//         if(isEmpty()){
//             front=rear=newNode;
//         }
//         rear -> link =newNode;
//         rear = newNode;
//     }

// int dequeue(){
//     if(isEmpty()){
//         printf("Queue underflow");
//         return;
//     }

// int dequeuevalue= front -> data;
// Node* temp= front;
// if(front == rear){
//     front = rear =nullptr;
// }
// else {
//     front = front -> link;
// }
// delete temp;
// return dequeuevalue;
// }
// }
// }


// int main(){

//     int isEmpty();

// }


// #include<iostream>
// #include<cctype>
// using namespace std;

// void evaluate postfix(string exp){
//   stack<int> st;
//   for (int i=0; i<exp.length();i++){
//     if(isdigit (exp[i])){
//         st.push (exp[i]-'0');
//     }
//     else{
//         int op2=st.top();
//         st.pop();
//         int op1=st.top();
//         st.pop();


//     switch(exp[i]){
//         case '+':
//                  st.push(op1+op2);
//                  break;

//         case '-':
//                  st.push(op1-op2);
//                  break;
            
//         case '*':
//                 st.push(op1*op2);
//                 break;

//         case '/':
//                 st.push(op1/op2);
//                 break;
//         default:
//                 print("Invalid");
//                 return -1;
//     }
//     }
//   }
// }
// cout<<"Result = "<<st.top()<<endl;