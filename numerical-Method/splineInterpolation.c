#include <stdio.h>

#define MAX_POINTS 10

typedef struct {
    double x;
    double y;
} DataPoint;

// Function to perform cubic spline interpolation
double cubicSplineInterpolation(DataPoint data[], int n, double xv) {
    // Define arrays to store coefficients
    double h[MAX_POINTS - 1], alpha[MAX_POINTS - 1];
    double l[MAX_POINTS + 1], mu[MAX_POINTS - 1], z[MAX_POINTS + 1];
    double c[MAX_POINTS], b[MAX_POINTS], d[MAX_POINTS];

    // Calculate differences of x-values (h)
    for (int i = 0; i < n - 1; i++) {
        h[i] = data[i + 1].x - data[i].x;
    }

    // Calculate alpha values
    for (int i = 1; i < n - 1; i++) {
        alpha[i] = 3 * ((data[i + 1].y - data[i].y) / h[i] - (data[i].y - data[i - 1].y) / h[i - 1]);
    }

    // Calculate l, mu, and z values
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;
    for (int i = 1; i < n - 1; i++) {
        l[i] = 2 * (data[i + 1].x - data[i - 1].x) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    // Calculate cubic spline coefficients (c, b, and d)
    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (data[j + 1].y - data[j].y) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
    }

    // Find the interval containing xv and interpolate
    int k = 0;
    while (data[k + 1].x < xv) {
        k++;
    }
    double dx = xv - data[k].x;
    double interpolatedValue = data[k].y + b[k] * dx + c[k] * dx * dx + d[k] * dx * dx * dx;

    return interpolatedValue;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX_POINTS) {
        printf("Number of data points must be between 2 and %d\n", MAX_POINTS);
        return 1;
    }

    DataPoint data[MAX_POINTS];
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }

    double xv;
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &xv);

    // Perform cubic spline interpolation
    double interpolatedValue = cubicSplineInterpolation(data, n, xv);
    printf("Interpolated value at x = %.2lf is: %lf\n", xv, interpolatedValue);

    return 0;
}