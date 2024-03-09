
import matplotlib.pyplot as plt

def find_symmetry(nex_x, nex_y, cen_x, cen_y):
    print(f"\t\t({nex_x+cen_x},{nex_y+cen_y})",end="\t")
    plt.plot(nex_x+cen_x, nex_y+cen_y, marker='o', color='blue')
    
    print(f"({-nex_x+cen_x},{nex_y+cen_y})",end=" ")
    plt.plot(-nex_x+cen_x, nex_y+cen_y, marker='o', color='blue')
    
    print(f"({-nex_x+cen_x},{-nex_y+cen_y})",end=" ")
    plt.plot(-nex_x+cen_x, -nex_y+cen_y, marker='o', color='blue')
    
    print(f"({nex_x+cen_x},{-nex_y+cen_y})")
    plt.plot(nex_x+cen_x, -nex_y+cen_y, marker='o', color='blue')

x, y = map(float, input("Enter the center co-ordinate: ").split())
plt.plot(x, y, marker='o', color='red')
rx, ry = map(float, input("Enter the x and y-radius of ellipse: ").split())

nex_x = 0
nex_y = ry

print('For region 1')
# for first region
p = pow(ry, 2) - pow(rx, 2)*ry + (1/4)*pow(rx, 2)
k = 1

print('Iteration\tp\t(xk+1,yk+1)\t2ry^2(xk+1)\t2rx^2(yk+1)\t(x,y)\t(-x,y)\t (-x,-y)   (x,-y)')

while pow(ry, 2)*nex_x <= pow(rx, 2)*nex_y:
    
    p1 = 2*pow(ry, 2)*nex_x
    p2 = 2*pow(rx, 2)*nex_y
    if p<0:
        p += p1+ pow(ry, 2)
    else:
        nex_y -= 1
        p += p1 - p2 +pow(ry, 2)
    nex_x += 1
    k+=1
    print(f"{k}\t\t{p}\t({round(nex_x, 1)},{round(nex_y, 1)})\t\t{round(p1,1)}\t\t{round(p2, 1)}",end="")
    plt.plot(nex_x, nex_y, marker='o', color='blue')
    find_symmetry(round(nex_x, 1), round(nex_y, 1), round(x), round(y))


print("For Region 2")
print('Iteration\tp\t(xk+1,yk+1)\t2ry^2(xk+1)\t2rx^2(yk+1)\t(x,y)\t\t(-x,y) \t(-x,-y)\t(x,-y)')
# for second region
p = pow(ry, 2)*pow((nex_x + (1/2)),2)+ pow(rx, 2)*pow((nex_y - 1),2) - (rx*rx*ry*ry)
k = 0
while nex_y!=0:
    
    p1 = 2*pow(ry, 2)*nex_x
    p2 = 2*pow(rx, 2)*nex_y
    if p>0:
        p += -p2 + pow(rx, 2)
    else:
        nex_x+=1
        p += -p2 + pow(rx, 2) +p1
    nex_y -= 1
    k+=1
    
    print(f"{k}\t\t{p}\t({round(nex_x, 1)},{round(nex_y, 1)})\t\t{round(p1,1)}\t\t{round(p2, 1)}",end="")
    plt.plot(nex_x, nex_y, marker='o', color='blue')
    find_symmetry(round(nex_x, 1), round(nex_y, 1), round(x, 1), round(y, 1))
plt.title("Midpoint Ellipse Drawing Algorithm")
plt.show()
plt.close()



