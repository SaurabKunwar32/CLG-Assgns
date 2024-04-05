#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x) {
    return (x* x * x)+1;
}

// Gaussian quadrature weights and abscissas for n = 2
const double weights[] = {1.0, 1.0};
const double abscissas[] = {-0.577350, 0.577350};

int main() {
    // Declare variables
    double a, b, integral = 0.0;

    // Get input from the user
    printf("Enter Lower and Upper Limit:\n");
    scanf("%lf %lf", &a, &b);

    // Apply Gaussian quadrature formula
    for (int i = 0; i < 2; ++i) {
        double x = (a + b) / 2 + (b - a) / 2 * abscissas[i];
        integral += weights[i] * f(x);
    }

    // Scale the result by the interval width
    integral *= (b - a) / 2;

    // Print the result
    printf("Value of Integration is: %f\n", integral);

    return 0;
} 