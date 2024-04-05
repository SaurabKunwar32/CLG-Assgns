#include <stdio.h>

// Define the function f(x, y)
float f(float x, float y) {
    return  (x*x) + (y*y);
}

// Implement the Runge-Kutta 4th order method
float rungeKutta(float x0, float y0, float xp, float h) {
    float k1, k2, k3, k4;
    float y = y0;
    float x = x0;

    while (x < xp) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }

    return y;
}

int main() {
    float x0, y0, xp, h;

    // Input initial values, x value for evaluation, and step size
    printf("Enter the initial values of X and Y:\n");
    scanf("%f %f", &x0, &y0);
    printf("Enter X at which function is to be evaluated:\n");
    scanf("%f", &xp);
    printf("Enter the step size:\n");
    scanf("%f", &h);

    // Calculate the result using Runge-Kutta method
    float result = rungeKutta(x0, y0, xp, h);

    // Output the result
    printf("Function Value at x=%f is: %f\n", xp, result);

    return 0;
}