#include <stdio.h>
#include <math.h>
#define f(x, y) 2 * (y) / (x)

int main()
{
    float x, xo, yo, y, xp, h, m1, m2;
    printf("Enter the initial values of X and Y:\n");
    scanf("%f%f", &xo, &yo);
    printf("Enter X at which function is to be evaluated:\n");
    scanf("%f", &xp);
    printf("Enter the step size:\n");
    scanf("%f", &h);
    y = yo;
    x = xo;
    for (x = xo; x < xp; x = x + h)
    {
        m1 = f(x, y);
        m2 = f(x + h, y + h * m1);
        y = y + (h / 2 )* (m1 + m2);
    }
    printf("Function Value at x=%f is:%f", xp, y);
    return 0;
}