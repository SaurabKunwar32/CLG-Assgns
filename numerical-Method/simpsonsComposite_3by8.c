#include <stdio.h>
#include<conio.h>
#include <math.h>
#define f(x) (x) * (x) * (x) + 3 * (x) * (x)

int main() 
{
    int i, k;
    float a, h, x0, xn, fx0, fxn, term, v;
    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter number of segments:");
    scanf("%d", &k);
    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = (fx0 + fxn);
    for (int i = 1; i <= k - 1; i++)
    {
        if (i % 3 != 0)
        {

            a = x0 + i * h;
            term = term + 3 * (f(a));
        }
        else
        {
            a = x0 + i * h;
            term = term + 2 * (f(a));
        }
    }
    v = (3 / 8.0) * h * term;
    printf("Value of Integration is:%f", v);
    return 0;
}