#!/usr/bin/env python
#-*- coding: utf-8 -*-
from Tkinter import *
from functions import *
from math import *

class App:
    def __init__(self,master):
        self.SCALE = 30
        self.X_BASE = 300
        self.Y_BASE = 330
        self.points = {}
        
        frame = Frame(master)
        frame.pack()
        
        frame13 = Frame(frame)
        frame13.pack(side=LEFT, padx=10, pady=2.5)
        #textfr=Frame(frame)
        
        frame12 = Frame(frame)
        frame12.pack()
                
        self.text=Text(frame13,height=25,width=57,background='white')
        self.text.place(x=70, y=40)
        self.text.pack()
        
        self.entry = Entry(frame13,width=50)
        self.entry.place(x=30, y=90)
        self.entry.pack()
        frame2 = Frame(frame13, height=40, width=50)
        frame2.pack()
        self.submit = Button(frame2, text="Submit", fg="black", command = self.submit_token)
        self.submit.pack(side=LEFT, padx=10, pady=2.5)
        self.clean = Button(frame2, text="Clean Canvas", fg="black", command = self.clean)
        self.clean.pack(side=LEFT, padx=10, pady=2.5)

        self.w = Canvas(frame12, width=800, height=600)
        self.w.pack()

    def clean(self):
        self.w.delete("all")
        self.entry.delete(0,END)
        self.text.delete(END)
        self.points = {}

    def submit_token(self):
        strg = self.entry.get() + '\n'
        if len(strg)==0:
            self.entry.delete(0,END)
        else:
            sys_exec("rm -f drawing.txt")
            sys_exec("rm -f triangle.txt")
            f=open("triangle.txt", "w")
            f.write(strg.encode('utf8').strip())
            f.close()
            #print sys_exec("./interpret1 < triangle.in")
            sys_exec("./interpret1.out < triangle.txt")
            self.draw("drawing.txt")
            self.text.insert(END, strg)
            self.entry.delete(0,END)

    def getCircleIntersectionPoint(self, c0, c1, r0, r1):
        x0 = self.points[c0][0]
        y0 = self.points[c0][1]
        x1 = self.points[c1][0]
        y1 = self.points[c1][1]
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
            
    def display_point(self, text, x, y):    
        self.w.create_text(x, y, anchor="nw", text=text)

    def takeAction(self, action_number, constructible, length, point, center, radii):
        if action_number == 1:
            if constructible == 101:
                if point[0] not in self.points.keys():
                    self.points[point[0]] = [self.X_BASE, self.Y_BASE]
                if point[1] not in self.points.keys():
                    self.points[point[1]] = [self.points[point[0]][0]+length * self.SCALE, self.Y_BASE]
                self.display_point(point[0], self.points[point[0]][0], self.points[point[0]][1])
                self.display_point(point[1], self.points[point[1]][0], self.points[point[1]][1])
                self.w.create_line(self.points[point[0]][0], self.points[point[0]][1], self.points[point[1]][0], self.points[point[1]][1], fill = "black", width=2)
                        
            elif constructible == 103:
                if point[0] not in self.points.keys():
                    self.points[center[0]] = [self.X_BASE, self.Y_BASE]
                radius = radii[0]*self.SCALE
                self.display_point(center[0], self.points[center[0]][0], self.points[center[0]][1])
                self.w.create_oval(self.points[center[0]][0]-radius, self.points[center[0]][1]-radius, self.points[center[0]][0]+radius, self.points[center[0]][1]+radius, outline="black", width=2, dash=(4,4))
                            
            elif constructible == 102:
                if center[0] not in self.points.keys():
                    print "First Point not Valid"
                    return
                if center[1] not in self.points.keys():
                    print "Second Point not Valid"
                    return
                radius0 = radii[0]*self.SCALE
                radius1 = radii[1]*self.SCALE
                self.display_point(center[0], self.points[center[0]][0], self.points[center[0]][1])
                self.display_point(center[1], self.points[center[1]][0], self.points[center[1]][1])
                                    
                self.w.create_oval(self.points[center[0]][0]-radius0, self.points[center[0]][1]-radius0, self.points[center[0]][0]+radius0, self.points[center[0]][1]+radius0, outline="black", width=2, dash=(4,4))
                self.w.create_oval(self.points[center[1]][0]-radius1, self.points[center[1]][1]-radius1, self.points[center[1]][0]+radius1, self.points[center[1]][1]+radius1, outline="black", width=2, dash=(4,4))
                x,y = self.getCircleIntersectionPoint(center[0], center[1], radius0, radius1)
                self.points[point[0]] = [x,y]
                self.display_point(point[0], self.points[point[0]][0], self.points[point[0]][1])
                
        elif action_number == 5:
            if point[0] not in self.points.keys():
                print "First Point not Valid"
                return
            if point[1] not in self.points.keys():
                print "Second Point not Valid"
                return
            self.display_point(point[0], self.points[point[0]][0], self.points[point[0]][1])
            self.display_point(point[1], self.points[point[1]][0], self.points[point[1]][1])
            self.w.create_line(self.points[point[0]][0], self.points[point[0]][1], self.points[point[1]][0], self.points[point[1]][1], fill = "black", width=2)
                                            
            
    def draw(self, filename):
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
                self.takeAction(action_number, constructible, length, point, center, radii)
            else:
                continue
                                
root=Tk()
root.title('Project')
app = App(root)

def loop():
    root.after(1000, loop)

root.after(1, loop) #pass loop for 15min Sync, loop3 for event driven
root.mainloop()

