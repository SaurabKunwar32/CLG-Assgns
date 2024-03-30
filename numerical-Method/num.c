#include <stdio.h>
#include <math.h>

#define e 2.71828
#define f(x) (cos(x) + 2*sin(x) + x*x)


int main() {
    float x, E, x_root, Error;

    printf("Enter the initial guess: \n");
    scanf("%f", &x);`

    printf("Enter precision: ");
    scanf("%f", &E);

    do {
        x_root = x - (f(x) / (2*sin(x) + 2*x));

        // Absolute error calculation
        Error = fabs(x_root - x);

        printf("Iteration: x = %.5f, f(x) = %.5f, Error = %.5f\n", x_root, f(x_root), Error);

        if (Error < E) {
            printf("Root found: %.5f\n", x_root);
            break;
        }

        x = x_root;
    } while (1);

    return 0;
}
