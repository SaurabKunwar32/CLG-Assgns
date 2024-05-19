// ***************************************factorial*****************************************

// #include<stdio.h>

// int facto(int n){
//     if(n==0){
//         return 1;
//     }else{
//         return   n*facto(n-1);
//     }
// }

// int main(){
//     int n;
//     printf("Enter the number:");
//     scanf("%d",&n);
//     facto(n);
//     printf("%d",facto(n));
// }


// ***************************************fibonacci Series*****************************************

// #include<stdio.h>
// int fibo(int n){
//     if(n <=1){
//         return n;
//     }else{
//         return fibo(n-1)+fibo(n-2);
//     }
// }

// int main(){
//     int n;
//     printf("Enter the number:");
//     scanf("%d",&n);
//      fibo(n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t",fibo(i));
//     }
// }


// ***************************************  GCD  *****************************************

// #include<stdio.h>
// int gcd(int a , int b){
//     if(b==0){
//         return a;
//     }else{
//         return (b,a%b);
//     }
// }


// int main(){
//     int a ,b;
//     printf("Enter the numbers:");
//     scanf("%d%d",&a,&b);
//     int c=gcd(a,b);
//     printf("The gcd of %d and %d is %d",a,b,c);

// }



// ***************************************  TOH  *****************************************

#include<stdio.h>

int TOH(int n, char A,char B ,char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,B);
        TOH(n-1,C,B,A);
       return 0;
    }
   
}


int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    TOH(n,'A','B','C');
     return 0;
}



