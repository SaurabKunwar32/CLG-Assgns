import numpy as np

# Given data points
x = np.array([1, 4, 14, 5, 25])
y = np.array([2, 0, 4, 1, 2])

# Function to calculate linear regression prediction
def regression(x_val, b0, b1):
    return b0 + b1 * x_val

# Number of data points
n = len(x)

# Calculating the sums
sum_x = np.sum(x)
sum_y = np.sum(y)
sum_xy = np.sum(x * y)
sum_xsq = np.sum(x ** 2)

# Calculating coefficients b1 and b0
b1 = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - sum_x ** 2)
b0 = np.mean(y) - b1 * np.mean(x)

# Printing coefficients and equation with 3 decimal places
print(f'Calculated coefficients: b0 = {b0:.3f}, b1 = {b1:.3f}')
print(f'Equation of the line: Y = {b0:.3f} + {b1:.3f}X')
