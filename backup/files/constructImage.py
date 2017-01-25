from Tkinter import *
from math import *

SCALE = 35
X_BASE = 300
Y_BASE = 500

master = Tk()
w = Canvas(master, width=1000, height=1000)
w.pack()

#w.create_line(0, 0, 200, 100)
#w.create_line(0, 100, 200, 0, fill="red", dash=(4, 4))
#w.create_rectangle(50, 25, 150, 75, fill="blue")
#w.create_oval(200,200,300,300, outline="black", width=2, dash=(4,4))

points = {}

def getCircleIntersectionPoint(c0, c1, r0, r1):
    x0 = points[c0][0]
    y0 = points[c0][1]
    x1 = points[c1][0]
    y1 = points[c1][1]
    d = sqrt( float((x1-x0)*(x1-x0)) + float((y1-y0)*(y1-y0)) )
    a = float(r0*r0 - r1*r1 + d*d) / float(2*d)
    h = sqrt(float(r0*r0 - a*a))

    x2 = x0 + float(a*(x1-x0))/d
    y2 = y0 + float(a*(y1-y0))/d
    x31 = x2 + float(h*(y1-y0))/d
    y31 = y2 - float(h*(x1-x0))/d
    x32 = x2 - float(h*(y1-y0))/d
    y32 = y2 + float(h*(x1-x0))/d
    if y31 < y32:
        return x31, y31
    else:
        return x32, y32

def display_point(text, x, y):    
    w.create_text(x, y, anchor="nw", text=text)
    
def takeAction(action_number, constructible, length, point, center, radii):
    if action_number == 1:
        if constructible == 101:
            if point[0] not in points.keys():
                points[point[0]] = [X_BASE, Y_BASE]
            if point[1] not in points.keys():
                points[point[1]] = [points[point[0]][0]+length * SCALE, Y_BASE]
            display_point(point[0], points[point[0]][0], points[point[0]][1])
            display_point(point[1], points[point[1]][0], points[point[1]][1])
            w.create_line(points[point[0]][0], points[point[0]][1], points[point[1]][0], points[point[1]][1], fill = "black", width=2)

        elif constructible == 103:
            if point[0] not in points.keys():
                points[center[0]] = [X_BASE, Y_BASE]
            radius = radii[0]*SCALE
            display_point(center[0], points[center[0]][0], points[center[0]][1])
            w.create_oval(points[center[0]][0]-radius, points[center[0]][1]-radius, points[center[0]][0]+radius, points[center[0]][1]+radius, outline="black", width=2, dash=(4,4))

        elif constructible == 102:
            if center[0] not in points.keys():
                print "First Point not Valid"
                return
            if center[1] not in points.keys():
                print "Second Point not Valid"
                return
            radius0 = radii[0]*SCALE
            radius1 = radii[1]*SCALE
            display_point(center[0], points[center[0]][0], points[center[0]][1])
            display_point(center[1], points[center[1]][0], points[center[1]][1])

            w.create_oval(points[center[0]][0]-radius0, points[center[0]][1]-radius0, points[center[0]][0]+radius0, points[center[0]][1]+radius0, outline="black", width=2, dash=(4,4))
            w.create_oval(points[center[1]][0]-radius1, points[center[1]][1]-radius1, points[center[1]][0]+radius1, points[center[1]][1]+radius1, outline="black", width=2, dash=(4,4))
            x,y = getCircleIntersectionPoint(center[0], center[1], radius0, radius1)
            points[point[0]] = [x,y]
            display_point(point[0], points[point[0]][0], points[point[0]][1])
            
    elif action_number == 5:
        if point[0] not in points.keys():
            print "First Point not Valid"
            return
        if point[1] not in points.keys():
            print "Second Point not Valid"
            return
        display_point(point[0], points[point[0]][0], points[point[0]][1])
        display_point(point[1], points[point[1]][0], points[point[1]][1])
        w.create_line(points[point[0]][0], points[point[0]][1], points[point[1]][0], points[point[1]][1], fill = "black", width=2)


def draw(filename):
    f = open(filename)
    lines = f.readlines()
    
    for i in range(0,len(lines)):
        tmp = lines[i].split(':')
        if tmp[0] == "Action":
            action_number = int(lines[i].split(':')[1])
            constructible = int(lines[i+1].split(':')[1])
            length = float(lines[i+2].split(':')[1])
            point = []
            point.append(lines[i+3].split(':')[1].strip()[0].strip())
            point.append(lines[i+3].split(':')[1].strip()[1].strip())
            point.append(lines[i+3].split(':')[1].strip()[2].strip())
            center = [] 
            center.append(lines[i+4].split(':')[1].strip()[0].strip())
            center.append(lines[i+4].split(':')[1].strip()[1].strip())
            radii = []
            radii.append(float(lines[i+5].split(':')[1].split()[0]))
            radii.append(float(lines[i+5].split(':')[1].split()[1]))
            takeAction(action_number, constructible, length, point, center, radii)
        else:
            continue

draw("drawing_instructions.txt")
mainloop()
