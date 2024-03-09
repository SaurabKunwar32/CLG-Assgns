
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






'''
#boundary fill algo and flood fill algo
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
    while True:
        choice = int(input("Choose an algorithm:\n1. Scan Line Algorithm\n2. Flood Fill Algorithm\n3. Exit\nEnter your choice: "))
        
        if choice == 1:
            vertices = []
            num_vertices = int(input("Enter the number of vertices: "))
            for i in range(num_vertices):
                x, y = map(int, input(f"Enter vertex {i+1} (x, y): ").split())
                vertices.append((x, y))
            scan_line_algorithm(vertices)
            plt.title('Subash Katwal')  # Set the plot title
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
                plt.plot([vertices[j][0], vertices[j+1][0]], [vertices[j][1], vertices[j+1][1]], color='blue')
            plt.plot([vertices[-1][0], vertices[0][0]], [vertices[-1][1], vertices[0][1]], color='blue')
            plt.show()
            x, y = map(int, input("Enter the starting point (x, y): ").split())
            flood_fill(image, x, y, 0, 1)
            plt.imshow(image, cmap='hot', interpolation='nearest')
            plt.show()
        elif choice == 3:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
'''



# LAB 4
# WAP to implement 2D geometric transformation a) translation b)rotation c) scaling 
'''
import matplotlib.pyplot as plt
import math

def translation():
    x1, y1 = map(int, input("Enter the first coordinate of the line: ").split(" "))
    x2, y2 = map(int, input("Enter the second coordinate of the line: ").split(" "))
    tx, ty = map(int, input("Enter the translated coordinate of the line: ").split(" "))

    var1 = x1 + tx
    var = y1 + ty

    var2 = x2 + tx
    var3 = y2 + ty

    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")

    plt.plot([x1, x2], [y1, y2], label='Original Line')
    plt.plot([var1, var2], [var, var3], label='Translated Line')
    plt.grid(True)
    plt.title("Transformation")
    plt.legend()
    plt.show()


def rotation(x1, y1, x2, y2, angle):
    # Calculate sine and cosine of the angle
    c = math.cos(math.radians(angle))
    s = math.sin(math.radians(angle))

    # Perform rotation
    x1_new = x1 * c + y1 * s
    y1_new = -x1 * s + y1 * c
    x2_new = x2 * c + y2 * s
    y2_new = -x2 * s + y2 * c
    
    print("Point before rotation:")
    print("[{}, {}]".format(x1, y1))
    print("[{}, {}]".format(x2, y2))

    print("\nPoint after rotation:")
    print("[{:.2f}, {:.2f}]".format(x1_new, y1_new))
    print("[{:.2f}, {:.2f}]".format(x2_new, y2_new))

    # Initialize the graphics window
    plt.figure()
    plt.axis('equal')

    # Draw the original line
    plt.plot([x1, x2], [y1, y2], color='red', label='Original Line')

    # Draw the rotated line
    plt.plot([x1_new, x2_new], [y1_new, y2_new], color='blue', label='Rotated Line')

    # Set labels and title
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Rotation of a line')

    # Show legend
    plt.legend()

    # Show plot
    plt.grid(True)
    plt.show()


def scaling():
    x1, y1 = map(int, input("Enter the first coordinate of the line: ").split(" "))
    x2, y2 = map(int, input("Enter the second coordinate of the line: ").split(" "))
    tx, ty = map(int, input("Enter the scaling coordinate of the line: ").split(" "))

    var1 = x1 * tx
    var = y1 * ty

    var2 = x2 * tx
    var3 = y2 * ty

    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")

    plt.plot([x1, x2], [y1, y2], label='Original Line')
    plt.plot([var1, var2], [var, var3], label='Scaled Line')
    plt.legend()
    plt.title("Scaling")
    plt.grid(True)
    plt.show()

while True:
    print("\n1. Translation\n2. Rotation\n3. Scaling\n4. Exit")
    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        translation()
    elif choice == '2':
        x1, y1 = map(int, input("Enter the coordinates of the starting point of the line: ").split(" "))
        x2, y2 = map(int, input("Enter the coordinates of the ending point of the line: ").split(" "))
        angle = float(input("Enter the rotation angle in degrees: "))
        rotation(x1, y1, x2, y2, angle)
    elif choice == '3':
        scaling()
    elif choice == '4':
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a valid option.")

'''