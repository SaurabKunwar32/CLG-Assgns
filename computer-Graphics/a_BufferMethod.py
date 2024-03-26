
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

class ABufferRenderer:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.color_buffer = np.zeros((height, width, 3))  # RGB color buffer
        self.depth_buffer = np.full((height, width), np.inf)  # Depth buffer initialized with infinity

    def clear_buffers(self):
        self.color_buffer.fill(0)  # Clear color buffer
        self.depth_buffer.fill(np.inf)  # Clear depth buffer

    def set_fragment(self, x, y, depth, color):
        if 0 <= x < self.width and 0 <= y < self.height:
            if depth < self.depth_buffer[y, x]:
                self.depth_buffer[y, x] = depth
                self.color_buffer[y, x] = color

    def render(self):
        # Check if depth buffer contains valid values
        if np.isnan(np.min(self.depth_buffer)) or np.isnan(np.max(self.depth_buffer)):
            print("Invalid depth values in the depth buffer. Rendering aborted.")
            return

        plt.imshow(self.color_buffer, origin='lower')
        plt.title("A-Buffer Rendering")
        plt.axis('off')
        plt.show()

# Example usage
renderer = ABufferRenderer(400, 300)
renderer.clear_buffers()

# Draw a triangle with varying depths
renderer.set_fragment(100, 100, 0.5, [1, 0, 0])  # Red
renderer.set_fragment(200, 200, 0.3, [0, 1, 0])  # Green
renderer.set_fragment(300, 100, 0.7, [0, 0, 1])  # Blue

# Render the image
renderer.render()



class ABufferRenderer:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.color_buffer = np.zeros((height, width, 3))  # RGB color buffer
        self.depth_buffer = np.full((height, width), np.inf)  # Depth buffer initialized with infinity

    def clear_buffers(self):
        self.color_buffer.fill(0)  # Clear color buffer
        self.depth_buffer.fill(np.inf)  # Clear depth buffer

    def set_fragment(self, x, y, depth, color):
        if 0 <= x < self.width and 0 <= y < self.height:
            if depth < self.depth_buffer[y, x]:
                self.depth_buffer[y, x] = depth
                self.color_buffer[y, x] = color

    def render(self):
        fig, ax = plt.subplots()
        ax.imshow(self.color_buffer, origin='lower')
        plt.title("A-Buffer Rendering")
        plt.axis('off')

        # Draw the triangles with white fill and black borders
        red_triangle = Polygon([(100, 100), (200, 100), (150, 200)], closed=True, facecolor='white', edgecolor='black')
        ax.add_patch(red_triangle)

        blue_triangle = Polygon([(150, 150), (250, 150), (200, 250)], closed=True, facecolor='white', edgecolor='black')
        ax.add_patch(blue_triangle)

        # Annotate overlapping fragments inside the triangles
        for y in range(self.height):
            for x in range(self.width):
                if self.color_buffer[y, x].any() != 0:
                    plt.text(x, y, "Overlap", color='black', fontsize=8, ha='center', va='center')

        plt.show()

# Example usage
renderer = ABufferRenderer(400, 300)
renderer.clear_buffers()

# Draw two overlapping triangles
for y in range(100, 200):
    for x in range(100, 200):
        renderer.set_fragment(x, y, 0.3, [1, 0, 0])  # Red triangle

for y in range(150, 250):
    for x in range(150, 250):
        renderer.set_fragment(x, y, 0.5, [0, 0, 1])  # Blue triangle

# Render the image
renderer.render()