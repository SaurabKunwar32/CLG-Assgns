#include <stdio.h>
#include <math.h>
#define f(x, y) 2 * y / x

int main()
{
    float x, xo, yo, y, xp, h;
    printf("Enter the initial values of X and Y:\n");
    scanf("%f%f", &xo, &yo);
    printf("Enter X at which function is to be evaluated:\n");
    scanf("%f", &xp);
    printf("Enter the step size:\n");
    scanf("%f", &h);
    y = yo;
    x=xo;
    for(x=xo;x<xp;x=x+h){
        y=y+f(x,y)*h;
    }
    printf("Function Value at x=%f is:%f", xp, y);
    return 0;
}