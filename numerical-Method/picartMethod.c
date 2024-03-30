#include <stdio.h>
#include <math.h>
#define y1(x) 2 + (x) - 2 / 3 * pow(x, 3)
#define y2(x) 2 + (x) + pow(x, 2) - 2 / 3 * pow(x, 3) + pow(x, 4) / 4
#define y3(x) 2 + (x) + pow(x, 2) - pow(x, 4) / 3 * pow(x, 5) / 15

int main()
{
    float x, xo, yo, y;
    printf("Enter the initial values of X and Y:\n");
    scanf("%f%f", &xo, &yo);
    printf("Enter X at which function is to be eveluated:\n");
    scanf("%f", &x);
    y = yo;
    y = yo + y1(x);
    y = yo + y2(x);
    y = yo + y3(x);
    printf("Function Value at x=%f is:%f", x, y);
    return 0;
}