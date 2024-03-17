
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 0.001
#define f(x) 2 * x *x + 4 * x - 10
 
int main()
{
    float Xn, Xp, Xr;
    float fXr;
    int i = 0;
    printf("Enter the value of initial guesses Xn and Xp:\n");
    scanf("%f%f", &Xn, &Xp);
    if (f(Xn) * f(Xp) < 0)
    {
        do
        {
            Xr = (Xn + Xp) / 2;
            fXr = f(Xr);
 
            if (fXr > 0)
            {
                Xp = Xr;
            }
            else if (fXr < 0)
            {
                Xn = Xr;
            }
            else
            {
                printf("Root of the equation is: %f", Xr);
            }
 
            i++;
 
            printf("Iteration :%d", i);
            printf("\t Root(Xr):%.5f", Xr);
            printf("\t f(Xr):%.5f", fXr);
            printf("\n");
        }
 
        while (fabs(fXr) > e);
    }
    else
    {
        printf("Invalid Initial Gusses");
    }
 
    printf("The approximate root of the equation is :%.5f", Xr);
    return 0;
}