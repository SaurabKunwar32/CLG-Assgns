#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f1(x, y, z) (z)
#define f2(x, y, z) 6 * (x)

int main()
{
    float xa, xb, ya, yb, x0, y0, x, y, z, z0, xp, h, sol, ny, nz, error, E, g[3], v[3], gs;
    int i;
    printf("Enter the boundary conditions:\n");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);
    printf("Enter the value of x at which value is required\n");
    scanf("%f", &xp);
    printf("Enter the step size\n");
    scanf("%f", &h);
    printf("Enter the accuracy limit\n");
    scanf("%f", &E);
    x = xa;
    y = ya;
    g[1] = z = (yb - ya) / (xb - xa);
    printf("g=%f\n", g[1]);
    while (x < xb)
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;
        if (x == xp)
            sol = y;
    }
    v[1] = y;
    if (y < yb)
        g[2] = z = 2 * g[1];
    else
        g[2] = z = 1 / 2 * g[1];
    printf("g=%f\n", g[2]);
    while (x < xb)
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;
        if (x == xp)
            sol = y;
    }
    while (1)
    {
        x = xa;
        y = ya;
        gs = z = g[2] - (v[2] - yb) / (v[2] - v[1]) * (g[2] - g[1]);
        while (x < xb)
        {
            ny = y + (f1(x, y, z)) * h;
            nz = z + (f2(x, y, z)) * h;
            x = x + h;
            y = ny;
            z = nz;
            if (x == xp)
                sol = y;
        }
        error = fabs(y - yb) / y;
        v[1] = v[2];
        v[2] = y;
        g[1] = g[2];
        g[2] = gs;
        if (error < E)
        {
            printf("y(%f)=%f", xp, sol);
            break;
        }
    }
    return 0;
}