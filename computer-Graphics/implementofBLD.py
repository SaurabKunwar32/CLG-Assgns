#WAP to implement BLD algorithm


import math
import matplotlib.pyplot as plt

x1 = float(input("Enter starting co-ordinate x1:"))
y1 = float(input("Enter starting co-ordinate y1:"))
x2 = float(input("Enter ending co-ordinate x2:"))
y2 = float(input("Enter ending co-ordinate y2:"))

plt.plot([x1, x2], [y1, y2])

dx = x2 - x1
dy = y2 - y1
m = dy / dx
xk = x1
yk = y1
plt.scatter(xk, yk)

print(f"{'Step':<5}\t{'xk':<5}\t{'yk':<5}\t{'pk':<5}\t{'xk+1':<7}\t{'yk+1':<7}\t")
print("-" * 45)

if abs(m) < 1:
    i = 1
    po = 2 * dy - dx
    pk = po
    steps = dx
    while i <= steps:
        if pk < 0:
            xk += 1
            pk = pk + 2 * dy
        else:
            xk += 1
            yk += 1
            pk = pk + 2 * dy - 2 * dx
        i = i + 1
        print(f"{i:<5}\t{xk:<5}\t{yk:<5}\t{pk:<5}\t{xk+1:<7}\t{yk+1:<7}\t")
        plt.scatter(xk, yk)
        plt.grid(True)
        plt.title("Saurab Kunwar")
    plt.show()

else:
    i = 1
    po = 2 * dx - dy
    pk = po
    steps = dy
    while i <= steps:
        if pk < 0:
            yk += 1
            pk = pk + 2 * dy
        else:
            xk += 1
            yk += 1
            pk = pk + 2 * dx - 2 * dy
        i = i + 1
        print(f"{i:<5}\t{xk:<5}\t{yk:<5}\t{pk:<5}\t{xk+1:<7}\t{yk+1:<7}\t")
        plt.scatter(xk, yk)
        plt.title("Saurab Kunwar")
    plt.grid(True)
    plt.title("Saurab Kunwar")
    plt.show()
