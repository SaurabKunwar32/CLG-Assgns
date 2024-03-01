
import matplotlib.pyplot as plt
x1, x2 = map(int, input(" Enter x coordinates of a line :").split())
y1, y2 = map(int, input("Enter y coordinates of a line ").split())
print(f"The x coordinates are{x1,x2} and y coordinates are{y1,y2}")

dx = x2 - x1
dy = y2 - y1

x = x1
y = y1
M = (y2 - y1) / (x2 - x1)


if abs(dx) > abs(y) or M < 1:
    steps = abs(dx)
else:
    steps = abs(dy)


X_incr = dx / float(steps)
Y_incr = dy / float(steps)
xs = [x]
ys = [y]
print("Step\tX\tY\tRounded X\tRounded Y")
for i in range(steps):
    if i < steps:
        x += X_incr
        y += Y_incr
        xs.append(x)
        ys.append(y)
        
        round_x = round(x)
        round_y = round(y)

        print(f"{i + 1}\t{x:.2f}\t{y:.2f}\t{round_x}\t\t{round_y}")

plt.plot(xs, ys,'bo-')
plt.title("Subash Katwal")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.grid(True)
plt.show()

