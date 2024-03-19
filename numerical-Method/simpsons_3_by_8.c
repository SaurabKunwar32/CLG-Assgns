#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - x * x)

int main()
{
    float h, x0, x1, x2, x3, fx0, fx1, fx2, fx3, v;
    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &x3);
    h = (x3 - x0) / 3;
    x1 = x0 + h;
    x2 = x0 + 2 * h;
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    fx3 = f(x3);

    v = 3 / 8.0 *h* (fx0 + 3 * fx1 + 3 * fx2 + fx3);
    printf("Value of Integration is:%f", v);
    return 0;
}