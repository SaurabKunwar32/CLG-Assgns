#lab 1 
# WAP that prompts the user to enter the co ordinates for points and then display them
# import matplotlib.pyplot as plt
# x1, y1=map(float,input("Enter the first coordinates : \n").split(" "))
# print(f"Point 1 coordinates is :({x1},{y1}")
# x2, y2=map(float,input("Enter the second co ordinates : \n").split(" "))
# print(f"Point 1 coordinates is :({x2},{y2}")

# plt.plot([x1,x2],[y1,y2],'-bo')

# plt.xlabel('X-axis')
# plt.ylabel('Y-axis')

# plt.title("Subash Katwal ")
# plt.grid(True)
# plt.show()


#WAP to implement DDA algorithm
# import matplotlib.pyplot as plt
# x1, x2 = map(int, input(" Enter x coordinates of a line :").split())
# y1, y2 = map(int, input("Enter y coordinates of a line ").split())
# print(f"The x coordinates are{x1,x2} and y coordinates are{y1,y2}")

# dx = x2 - x1
# dy = y2 - y1

# x = x1
# y = y1
# M = (y2 - y1) / (x2 - x1)


# if abs(dx) > abs(y) or M < 1:
#     steps = abs(dx)
# else:
#     steps = abs(dy)


# X_incr = dx / float(steps)
# Y_incr = dy / float(steps)
# xs = [x]
# ys = [y]
# print("Step\tX\tY\tRounded X\tRounded Y")
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
# plt.title("Subash Katwal")
# plt.xlabel("X-axis")
# plt.ylabel("Y-axis")
# plt.grid(True)
# plt.show()



#WAP to implement BLD algorithm

"""
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
        plt.title("Subash Katwal")
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
        plt.title("Subash Katwal")
    plt.grid(True)
    plt.title("Subash Katwal")
    plt.show()
"""




# WAP to implement circle drawing algorithm 

# radius 10 h and k 2 3 hana
"""
import matplotlib.pyplot as plt

def draw_circle(radius, h, k):
    x, y = 0, radius
    P = 1 - radius

    print(f"Steps\tXk+1\tYk+1\tPk\t(x,y)\t(-x,y)\t(x,-y)\t(-x,-y)\t(y,x)\t(-y,x)\t(y,-x)\t(-y,-x)\t")

    while x <= y:
        print(f"{x}\t{h + x}\t{k + y}\t{P}\t"
              f"({x + h},{y + k})\t({-x + h},{y + k})\t"
              f"({x + h},{-y + k})\t({-x + h},{-y + k})\t"
              f"({y + h},{x + k})\t({-y + h},{x + k})\t"
              f"({y + h},{-x + k})\t({-y + h},{-x + k})\t")

        plt.scatter(x + h, y + k, )
        plt.scatter(-x + h, y + k,)
        plt.scatter(x + h, -y + k,)
        plt.scatter(-x + h, -y + k)
        plt.scatter(y + h, x + k, )
        plt.scatter(-y + h, x + k,)
        plt.scatter(y + h, -x + k,)
        plt.scatter(-y + h, -x + k)

        if P <= 0:
            P = P + 2 * x + 3
        else:
            P = P + 2 * x - 2 * y + 5
            y -= 1

        x += 1

    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.grid(True)
    plt.axis('equal')
    plt.show()

def main():
    radius = int(input("Enter the radius: "))
    h, k = map(int, input("Enter the h and k: ").split(" "))
    draw_circle(radius, h, k)

if __name__ == "__main__":
    main()
"""




#lab 3
# WAP to find implement scan-line polygon fill algorithm
'''
import matplotlib.pyplot as plt

def draw_polygon(vertices):
    for i in range(len(vertices)):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % len(vertices)]
        plt.plot([x1, x2], [y1, y2], color='black')

def scanline_fill(vertices, fill_color):
    ymin = int(min(v[1] for v in vertices))
    ymax = int(max(v[1] for v in vertices))

    edges = []
    for i in range(len(vertices)):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % len(vertices)]
        if y1 != y2:
            edges.append((min(y1, y2), max(y1, y2), x1, y1, (y2 - y1) / (x2 - x1)))

    edges.sort(key=lambda edge: edge[0])

    active_edges = []
    for y in range(ymin, ymax + 1):
        active_edges = [edge for edge in active_edges if edge[1] > y]
        active_edges.extend(edge for edge in edges if edge[0] == y)

        active_edges.sort(key=lambda edge: edge[2])

        fill = False
        for i in range(0, len(active_edges), 2):
            x1 = int(active_edges[i][2])
            x2 = int(active_edges[i + 1][2])
            plt.plot(range(x1, x2 + 1), [y] * (x2 - x1 + 1), color=fill_color)
            fill = not fill

        for i in range(len(active_edges)):
            active_edges[i] = (active_edges[i][0], active_edges[i][1], active_edges[i][2] + active_edges[i][4]) if len(active_edges[i]) > 4 else active_edges[i]

def main():
    plt.figure()

    # Ask the user to enter polygon vertices
    vertices = []
    num_vertices = int(input("Enter the number of vertices: "))
    for i in range(num_vertices):
        x, y = map(float, input(f"Enter the coordinates for vertex {i + 1} (x y): ").split())
        vertices.append((x, y))

    # Draw the polygon
    draw_polygon(vertices)

    # Fill the polygon using scan-line algorithm with color 'green'
    scanline_fill(vertices, fill_color='black')

    plt.title("Scan-Line Polygon Fill")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
'''




#boundary fill algo and flood fill algo
'''
import matplotlib.pyplot as plt

def scan_line_algorithm(vertices):
    edges = []
    for i in range(len(vertices)):
        p1 = vertices[i]
        p2 = vertices[(i + 1) % len(vertices)]
        if p1[1] != p2[1]:
            edges.append((min(p1[1], p2[1]), max(p1[1], p2[1]), p1[0], (p2[0] - p1[0]) / (p2[1] - p1[1])))
    edges.sort(key=lambda x: x[0])
    active_edges = []
    for y in range(edges[0][0], edges[-1][1] + 1):
        for edge in edges:
            if edge[0] == y:
                active_edges.append(edge)
        active_edges.sort(key=lambda x: x[2])
        i = 0
        while i < len(active_edges):
            if i + 1 < len(active_edges):
                for x in range(int(active_edges[i][2]), int(active_edges[i + 1][2]) + 1):
                    plt.plot(x, y, '-bo')
            i += 2
        for edge in active_edges:
            if edge[1] == y:
                active_edges.remove(edge)
        for i in range(len(active_edges)):
            active_edges[i] = (active_edges[i][0], active_edges[i][1], active_edges[i][2] + active_edges[i][3], active_edges[i][3])

def flood_fill(image, x, y, old_color, new_color):
    if x < 0 or x >= len(image[0]) or y < 0 or y >= len(image) or image[y][x] == new_color or image[y][x] == old_color:
        return
    image[y][x] = new_color
    flood_fill(image, x + 1, y, old_color, new_color)
    flood_fill(image, x - 1, y, old_color, new_color)
    flood_fill(image, x, y + 1, old_color, new_color)
    flood_fill(image, x, y - 1, old_color, new_color)

def main():
    choice = int(input("Choose an algorithm:\n1. Scan Line Algorithm\n2. Flood Fill Algorithm\n 3.Exit\n Enter your choice: "))
    
    if choice == 1:
        vertices = []
        num_vertices = int(input("Enter the number of vertices: "))
        for i in range(num_vertices):
            x, y = map(int, input(f"Enter vertex {i+1} (x, y): ").split())
            vertices.append((x, y))
        scan_line_algorithm(vertices)
        plt.title('Subash Katwal')
        plt.show()
        
    elif choice == 2:
        num_vertices = int(input("Enter the number of vertices: "))
        vertices = []
        for i in range(num_vertices):
            while True:
                try:
                    x, y = map(int, input(f"Enter vertex {i+1} (x, y): ").split())
                    vertices.append((x, y))
                    break
                except ValueError:
                    print("Invalid input. Please enter integers for x and y coordinates.")
        image = [[0] * (max(x for x, _ in vertices) + 1) for _ in range(max(y for _, y in vertices) + 1)]
        for j in range(num_vertices - 1):
            plt.plot([vertices[j][0], vertices[j+1][0]], [vertices[j][1], vertices[j+1][1]], color='black')
        plt.plot([vertices[-1][0], vertices[0][0]], [vertices[-1][1], vertices[0][1]], color='black')
        plt.show()
        x, y = map(int, input("Enter the starting point (x, y): ").split())
        flood_fill(image, x, y, 0, 1)
        plt.imshow(image, cmap='hot', interpolation='nearest')
        plt.show()
    elif choice==3:
        print("Exiting the program ")
        exit()   
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
'''
#LAB 4
#WAP to implement 2D geometric transformation a) translation b)rotation c) scaling 
# import matplotlib.pyplot as plt
# import math
# import numpy as np

# def translation():
#     x1, y1 = map(int, input("Enter the first coordinate of the line: ").split(" "))
#     x2, y2 = map(int, input("Enter the second coordinate of the line: ").split(" "))
#     tx, ty = map(int, input("Enter the translated coordinate of the line: ").split(" "))

#     var1 = x1 + tx
#     var = y1 + ty

#     var2 = x2 + tx
#     var3 = y2 + ty

#     plt.xlabel("X-axis")
#     plt.ylabel("Y-axis")

#     plt.plot([x1, x2], [y1, y2], label='Original Line')
#     plt.plot([var1, var2], [var, var3], label='Translated Line')
#     plt.grid(True)
#     plt.title("Transformation")
#     plt.legend()
#     plt.show()

# def rotation():
#     angle = float(input("Enter the angle in degrees: "))
#     sin = math.sin(math.radians(angle))
#     cos = math.cos(math.radians(angle))

#     x, y = map(int, input("Enter the coordinates of the point: ").split(" "))

#     point = np.array([x, y])

#     rotation_matrix = np.array([[cos, -sin],
#                                 [sin, cos]])

#     print("Point before rotation:", point)

#     result = np.matmul(rotation_matrix, point)

#     print("\nPoint after rotation:", result)

#     # Plotting vectors
#     vectors = [point, result]
#     colors = ['r', 'b']
#     labels = ['Original Point', 'Rotated Point']

#     for vector, color, label in zip(vectors, colors, labels):
#         plt.plot(vector[0], vector[1], 'o', color=color, label=label)

#     plt.xlabel("X-label")
#     plt.ylabel("Y-label")
#     plt.title("Rotation")
#     plt.legend(loc='upper right')
#     plt.grid(True)
#     plt.show()


# def scaling():
#     x1, y1 = map(int, input("Enter the first coordinate of the line: ").split(" "))
#     x2, y2 = map(int, input("Enter the second coordinate of the line: ").split(" "))
#     tx, ty = map(int, input("Enter the scaling coordinate of the line: ").split(" "))

#     var1 = x1 * tx
#     var = y1 * ty

#     var2 = x2 * tx
#     var3 = y2 * ty

#     plt.xlabel("X-axis")
#     plt.ylabel("Y-axis")

#     plt.plot([x1, x2], [y1, y2], label='Original Line')
#     plt.plot([var1, var2], [var, var3], label='Scaled Line')
#     plt.legend()
#     plt.title("Scaling")
#     plt.grid(True)
#     plt.show()

# while True:
#     print("\n1. Translation\n2. Rotation\n3. Scaling\n4. Exit")
#     choice = input("Enter your choice (1-4): ")

#     if choice == '1':
#         translation()
#     elif choice == '2':
#         rotation()
#     elif choice == '3':
#         scaling()
#     elif choice == '4':
#         print("Exiting the program.")
#         break
#     else:
#         print("Invalid choice. Please enter a valid option.")
