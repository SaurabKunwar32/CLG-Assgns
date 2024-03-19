#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - x * x)

int main()
{
    float h, x0, x1, x2, fx0, fx1, fx2, v;
    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &x2);
    h = (x2 - x0) / 2;
    x1 = x0 + h;
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    v = h / 3 * (fx0 + 4 * fx1 + fx2);
    printf("Value of Integration is:%.3f", v);
    return 0;
} 