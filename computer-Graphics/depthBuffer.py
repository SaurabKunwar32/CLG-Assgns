
import numpy as np
import matplotlib.pyplot as plt

#simple primitive class to represent triangles
class Primitive:
    def __init__(self, vertices, color):
        self.vertices = vertices
        self.color = color

# Check if a point (x, y) is inside a triangle defined by its vertices
def is_pixel_inside_triangle(x, y, v0, v1, v2):
    def sign(p1, p2, p3):
        return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])

    b1 = sign((x, y), v0, v1) < 0.0
    b2 = sign((x, y), v1, v2) < 0.0
    b3 = sign((x, y), v2, v0) < 0.0

    return (b1 == b2 == b3)

# Calculate the depth (z-coordinate) of a point (x, y) in a triangle
def calculate_depth(x, y, v0, v1, v2):
    a = (v1[1] - v2[1]) * (x - v2[0]) + (v2[0] - v1[0]) * (y - v2[1])
    b = (v2[1] - v0[1]) * (x - v2[0]) + (v0[0] - v2[0]) * (y - v2[1])
    c = -((x - v2[0]) * (v0[1] - v1[1]) - (v0[0] - v1[0]) * (y - v2[1]))

    total_area = (v1[1] - v2[1]) * (v0[0] - v2[0]) + (v2[0] - v1[0]) * (v0[1] - v2[1])

    alpha = a / total_area
    beta = b / total_area
    gamma = c / total_area

    return alpha * v0[2] + beta * v1[2] + gamma * v2[2]


def depth_buffer_method(primitives, width, height):
    color_buffer = np.zeros((height, width, 3)) 
    depth_buffer = np.full((height, width), float('inf')) 

    for primitive in primitives:
        v0, v1, v2 = primitive.vertices
        color = primitive.color

        for x in range(width):
            for y in range(height):
                if is_pixel_inside_triangle(x, y, v0, v1, v2):
                    depth = calculate_depth(x, y, v0, v1, v2)
                    if depth < depth_buffer[y, x]:
                        depth_buffer[y, x] = depth
                        color_buffer[y, x] = color

    return color_buffer

# Main function
def main():
    
    primitives = [
        Primitive([(100, 100, 1), (200, 300, 2), (300, 100, 3)], (1, 0, 0)), 
        Primitive([(200, 200, 4), (400, 400, 5), (100, 400, 6)], (0, 1, 0)),  
        Primitive([(300, 300, 7), (500, 100, 8), (600, 300, 9)], (0, 0, 1))  
    ]

    
    width, height = 800, 600


    rendered_image = depth_buffer_method(primitives, width, height)
    
    plt.imshow(rendered_image)
    plt.axis('off')
    plt.title('Depth Buffer Algorithm')
    plt.show()

if __name__ == "__main__":
    main()