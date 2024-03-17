
# WAP to implement circle drawing algorithm 

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
    plt.title("Saurab Kunwar")
    plt.show()

def main():
    radius = int(input("Enter the radius: "))
    h, k = map(int, input("Enter the h and k: ").split(" "))
    draw_circle(radius, h, k)

if __name__ == "__main__":
    main()