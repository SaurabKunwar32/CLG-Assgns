#include <stdio.h>
#include <math.h>

int fact(int n)
{
    if ( n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main()
{
    float x, xo, yxo, yx, fdy, sdy, tdy;
    printf("Enter the initial values of X and Y:\n");
    scanf("%f%f", &xo, &yxo);
    printf("Enter X at which function is to be eveluated:\n");
    scanf("%f", &x);
    fdy = (xo) * (xo) + (yxo) * (yxo);
    sdy = 2 * (xo) + 2 * (yxo)*fdy;
    tdy = 2 + 2 * (yxo)*sdy + 2 * fdy * fdy;
    yx = yxo + (x - xo) * fdy + (x - xo) * (x - xo) * sdy / fact(2) + (x - xo) * (x - xo) * (x - xo) * tdy / fact(3);
    printf("Function Value at x=%f is:%f", x, yx);
    return 0;
}