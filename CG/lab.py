# lab 1 Q1
# import matplotlib.pyplot as plt
# x1, y1=map(float,input("Enter the first coordinates:").split(" "))
# print(f"The first coordinates is:({x1},{y1})")
# x2, y2=map(float,input("Enter the second coordinates:").split(" "))
# print(f"The second coordinates is:({x2},{y2})")
# plt.plot([x1,x2],[y1,y2],'-bo')
# plt.xlabel('X-axis')
# plt.ylabel('Y-axis')
# plt.title("Saurab Kunwar ")
# plt.grid(True)
# plt.show()





# lab 1 Q2
# import matplotlib.pyplot as plt

# x1, x2 = map(int, input(" Enter the x coordinates of a line:").split())
# y1, y2 = map(int, input("Enter the y coordinates of a line:").split())
# print(f"The x coordinates are {x1,x2} and y the coordinates are{y1,y2}.")

# dx = x2 - x1
# dy = y2 - y1

# x = x1
# y = y1
# M = (y2 - y1) / (x2 - x1)


# if abs(dx) > abs(dy) or M < 1:
#     steps = abs(dx)
# else:
#     steps = abs(dy)


# X_incr = dx / float(steps)
# Y_incr = dy / float(steps)
# xs = [x]
# ys = [y]
# print("Step\tX\tY\tRounded X\tRounded Y")
# print("-" * 50)
# for i in range(steps):
#     if i < steps:
#         x += X_incr
#         y += Y_incr
#         xs.append(x)
#         ys.append(y)
        
#         round_x = round(x)
#         round_y = round(y)

#         print(f"{i + 1}\t{x:.2f}\t{y:.2f}\t{round_x}\t\t{round_y}")

# plt.plot(xs, ys,'bo-')
# plt.title("Saurab Kunwar")
# plt.xlabel("X-axis")
# plt.ylabel("Y-axis")
# plt.grid(True)
# plt.show()



# lab 1 Q3
import math
import matplotlib.pyplot as plt

x1 = float(input("Enter first x co-ordinate  x1:"))
y1 = float(input("Enter first y co-ordinate y1:"))
x2 = float(input("Enter second x co-ordinate x2:"))
y2 = float(input("Enter second y co-ordinate y2:"))

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
    plt.grid(True)
    plt.title("Saurab Kunwar")
    plt.show()






# lab 3
# write a program tp implement 2D geomertic transformation
# a)translastion  (b)rotation (c)scaling

# import matplotlib.pyplot as plt
 