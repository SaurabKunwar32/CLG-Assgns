

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void displayFibonacci(int num)
{
    cout << "Fibonacci Series:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << fibonacci(i) << "\t";
    }
}

int main()
{
    int n;
    cout << "Enter the number:";
    cin >> n;
    displayFibonacci(n);
    return 0;
}
