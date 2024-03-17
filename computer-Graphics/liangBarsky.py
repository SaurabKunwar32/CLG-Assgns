import numpy as np
import matplotlib.pyplot as plt

# Function to perform Liang-Barsky line clipping
def liang_barsky_line_clip(x0, y0, x1, y1, xmin, xmax, ymin, ymax):
    dx = x1 - x0
    dy = y1 - y0
    p = [0, -dx, dx, -dy, dy]
    q = [-(x0 - xmin), (x1 - x0), (xmax - x0), -(y0 - ymin), (y1 - y0)]

    u1 = 0
    u2 = 1

    for i in range(1, 5):
        if p[i] == 0 and q[i] < 0:
            return None  # Line is parallel and outside the clipping window

        if p[i] != 0:
            u = q[i] / p[i]
            if p[i] < 0:
                u1 = max(u1, u)
            else:
                u2 = min(u2, u)

    if u1 > u2:
        return None  # Line segment is completely outside the clipping window

    clipped_x0 = x0 + u1 * dx
    clipped_y0 = y0 + u1 * dy
    clipped_x1 = x0 + u2 * dx
    clipped_y1 = y0 + u2 * dy

    return clipped_x0, clipped_y0, clipped_x1, clipped_y1

# Take user input for line coordinates and window coordinates
x0, y0 = map(int, input("Enter x0 y0 for line (separated by space): ").split())
x1, y1 = map(int, input("Enter x1 y1 for line (separated by space): ").split())
xmin, xmax = map(int, input("Enter xmin xmax for window (separated by space): ").split())
ymin, ymax = map(int, input("Enter ymin ymax for window (separated by space): ").split())

# Clip the line
clipped_line = liang_barsky_line_clip(x0, y0, x1, y1, xmin, xmax, ymin, ymax)

# Plot the original line and window
plt.plot([x0, x1], [y0, y1], 'b', label='Original Line')
plt.plot([xmin, xmax, xmax, xmin, xmin], [ymin, ymin, ymax, ymax, ymin], 'r--', label='Clipping Window')

# Plot the clipped line if it exists
if clipped_line:
    clipped_x0, clipped_y0, clipped_x1, clipped_y1 = clipped_line
    plt.plot([clipped_x0, clipped_x1], [clipped_y0, clipped_y1], 'g', label='Clipped Line')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Liang-Barsky Line Clipping')
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()