#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    // {
        return 1;
    // }
    // int prefacto = factorial(n - 1);
    return n * factorial(n-1);
}

int main()
{
    int n;
    cout << "Enter the value to get factorial:";
    cin >> n;
    cout << "Required Factorial is:" << factorial(n) << endl;
}
