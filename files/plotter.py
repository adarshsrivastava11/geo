#!/usr/bin/env python
#-*- coding: utf-8 -*-
from Tkinter import *
from functions import *
from math import *
#from drawing.models import *
import sys
import os

class App:
    def __init__(self):
        self.SCALE = 30
        self.X_BASE = 300
        self.Y_BASE = 330
        self.contextPoints = {}
        self.contextLS = []
        self.contextLines = []
        self.contextArcs = {}
        self.contextAngles = {}
        self.contextCircles = {}
        self.diffPoints = {}
        self.diffLS = []
        self.diffLines = []
        self.diffArcs = {}
        self.diffAngles = {}
        self.diffCircles = {}
      
        self.NL = False
        
    def clean(self):

        
        self.contextPoints.clear()
        self.contextLS[:] = []
        self.contextLines[:] = []
        self.contextAngles.clear()
        self.contextArcs.clear()
        self.contextCircles.clear()
        sys_exec("rm -f context.txt history.txt && touch context.txt && touch history.txt")
           

    def submit_token(self,strg):
       
        
        strg = strg + "\n"
        if len(strg)==0:
            self.entry.delete(0,END)
        else:
            sys_exec("rm -f drawing.txt")
            sys_exec("rm -f triangle.txt")
            sys_exec("rm -f preOrder.txt")
            #if self.NL:
            print "NL Parsing"
            f=open("triangle.txt", "w")
            f.write(strg.encode('utf8').strip())
            f.close()
            interpreter_log = sys_exec("./interpret.out < triangle.txt")
            print interpreter_log[1]
            #else:
             #   f=open("preOrder.txt", "w")
              #  f.write(strg.encode('utf8').strip())
               # f.close()
            lyparser_log = sys_exec("./lyparser.out < preOrder.txt")
            print lyparser_log[1];
            self.readContext()
            self.readDiff()
            #self.updateContext()
            self.draw()
            
   

    def readContext(self):
        f=open("context.txt","r")
        a=f.readlines()
        f.close()
        i=1
        while a[i][:len(a[i])-1] != "~LINESEGMENTS":
            temp = a[i].split()
            if temp[0] not in self.contextPoints.keys():
                self.contextPoints[temp[0]] = [float(temp[1]), float(temp[2])]
            elif self.contextPoints[temp[0]] != [float(temp[1]), float(temp[2])]:
                print "Error"
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~LINES":
            temp1 = a[i][:len(a[i])-1]
            temp = temp1[0]+temp1[2]
            if temp[0] not in self.contextPoints.keys():
                print "Error"
            if temp[1] not in self.contextPoints.keys():
                print "Error"
            if temp not in self.contextLS:
                self.contextLS.append(temp)
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~ARCS":
            temp = a[i][:len(a[i])-1]
            if temp not in self.contextLines:
                self.contextLines.append(temp)
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~ANGLE":
            temp = a[i].split()
            if temp[0] not in self.contextPoints.keys():
                print "Error"
            self.contextArcs[temp[0]] = float(temp[1])
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~CIRCLE":
            temp = a[i].split()
            if temp[0] not in self.contextPoints.keys():
                print "Error"
            if temp[1] not in self.contextPoints.keys():
                print "Error"
            if temp[2] not in self.contextPoints.keys():
                print "Error"
            temp1 = temp[1]+temp[0]+temp[2]
            temp2 = temp[2]+temp[0]+temp[1]
            if temp1 not in self.contextAngles.keys() and temp2 not in self.contextAngles.keys():
                self.contextAngles[temp1] = float(temp[3])
            elif temp1 in self.contextAngles.keys():
                if self.contextAngles[temp1] != float(temp[3]):
                    print "Error"
            elif temp2 in self.contextAngles.keys():
                if self.contextAngles[temp2] != float(temp[3]):
                    print "Error"
            i+=1
        i+=1
        while i<len(a):
            temp = a[i].split()
            if temp[0] not in self.contextPoints.keys():
                print "Error"
            self.contextCircles[temp[0]] = float(temp[1])
            i+=1

        #FIXME self.diff need not have points in general, self.context se self.different hai
    def readDiff(self):
        f=open("diff.txt","r")
        a=f.readlines()
        f.close()
        i=1
        while a[i][:len(a[i])-1] != "~LINESEGMENTS":
            temp = a[i].split()
            if temp[0] not in self.diffPoints.keys():
                self.diffPoints[temp[0]] = [float(temp[1]), float(temp[2])]
            elif self.diffPoints[temp[0]] != [float(temp[1]), float(temp[2])]:
                print "Error"
            if temp[0] in self.contextPoints.keys():
                if self.contextPoints[temp[0]] != [float(temp[1]), float(temp[2])]:
                    print "Error"
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~LINES":
            temp1 = a[i][:len(a[i])-1]
            temp = temp1[0]+temp1[2]
            if temp[0] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            if temp[1] not in self.diffPoints.keys() and temp[1] not in self.contextPoints.keys():
                print "Error"
            if temp not in self.diffLS:
                self.diffLS.append(temp)
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~ARCS":
            temp = a[i][:len(a[i])-1]
            if temp not in self.diffLines:
                self.diffLines.append(temp)
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~ANGLE":
            temp = a[i].split()
            if temp[0] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            self.diffArcs[temp[0]] = float(temp[1])
            i+=1
        i+=1
        while a[i][:len(a[i])-1] != "~CIRCLE":
            temp = a[i].split()
            if temp[0] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            if temp[1] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            if temp[2] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            temp1 = temp[1]+temp[0]+temp[2]
            temp2 = temp[2]+temp[0]+temp[1]
            if temp1 not in self.diffAngles.keys() and temp2 not in self.diffAngles.keys():
                self.diffAngles[temp1] = float(temp[3])
            elif temp1 in self.diffAngles.keys():
                if self.diffAngles[temp1] != float(temp[3]):
                    print "Error"
            elif temp2 in self.diffAngles.keys():
                if self.diffAngles[temp2] != float(temp[3]):
                    print "Error"
            # Sanity check: angle exists in self.contextPoints (value)
            i+=1
        i+=1
        while i<len(a):
            temp = a[i].split()
            if temp[0] not in self.diffPoints.keys() and temp[0] not in self.contextPoints.keys():
                print "Error"
            self.diffCircles[temp[0]] = float(temp[1])
            i+=1

    def updateContext(self):
        for i in self.diffPoints.keys():
            if i not in self.contextPoints.keys():
                self.contextPoints[i] = self.diffPoints[i]
        for i in self.diffLS:
            if i not in self.contextLS:
                self.contextLS.append(i)
        for i in self.diffArcs.keys():
            if i not in self.contextArcs.keys():
                self.contextArcs[i] = self.diffArcs[i]
        for i in self.diffAngles.keys():
            if i not in self.contextAngles.keys():
                self.contextAngles[i] = self.diffAngles[i]
        for i in self.diffCircles.keys():
            if i not in self.contextCircles.keys():
                self.contextCircles[i] = self.diffCircles[i]
        for i in self.diffLines:
            if i not in self.contextLines:
                self.contextLins.append(i)
        self.diffPoints.clear()
        self.diffLS[:] = []
        self.diffLines[:] = []
        self.diffAngles.clear()
        self.diffArcs.clear()
        self.diffCircles.clear()
        print self.contextPoints
        print self.contextLS
        print self.contextLines
        print self.contextArcs
        print self.contextAngles
        print self.contextCircles
        
    def draw(self):
        file_name= "draw_commands.js"
        fo = open(file_name,"wb")

        print "Drawing"
        for i in self.contextPoints.keys():
            text_command = "drawText(\""+str(i)+"\","+str(self.contextPoints[i][0]*self.SCALE+self.X_BASE)+","+str(self.contextPoints[i][1]*self.SCALE+self.Y_BASE)+");"
            fo.write(text_command)
            # self.display_point(i, self.contextPoints[i][0]*self.SCALE+self.X_BASE, self.contextPoints[i][1]*self.SCALE+self.Y_BASE)
        for i in self.contextLS:
            line_command = "drawLine("+str(self.contextPoints[i[0]][0]*self.SCALE+self.X_BASE)+","+str( self.contextPoints[i[0]][1]*self.SCALE+self.Y_BASE)+","+str(self.contextPoints[i[1]][0]*self.SCALE+self.X_BASE)+","+str(self.contextPoints[i[1]][1]*self.SCALE+self.Y_BASE)+");"
            fo.write(line_command)
            # self.display_lineSegment(self.contextPoints[i[0]][0]*self.SCALE+self.X_BASE, self.contextPoints[i[0]][1]*self.SCALE+self.Y_BASE, self.contextPoints[i[1]][0]*self.SCALE+self.X_BASE, self.contextPoints[i[1]][1]*self.SCALE+self.Y_BASE)
        # for i in self.contextArcs.keys():
        # self.display_arc(self.contextPoints[i][0]*self.SCALE+self.X_BASE, self.contextPoints[i][1]*self.SCALE+self.Y_BASE, self.contextArcs[i]*self.SCALE)
        for i in self.contextCircles.keys():

            cirlce_command = "drawCircle("+str(self.contextPoints[i][0]*self.SCALE+self.X_BASE)+","+str(self.contextPoints[i][1]*self.SCALE+self.Y_BASE)+","+str(self.contextCircles[i]*self.SCALE)+");"
            fo.write(cirlce_command)
            # self.display_circle(self.contextPoints[i][0]*self.SCALE+self.X_BASE, self.contextPoints[i][1]*self.SCALE+self.Y_BASE, self.contextCircles[i]*self.SCALE)
        fo.close()

user_name = sys.argv[1]
os.chdir('files_'+user_name)
A = App()
#A.clean()
with open("all_commands.txt","r") as f:
    for line in f:
        A.submit_token(line)
# file_name = "all_commands.txt"
#         draw_commands = open(file_name,"r")
# A.submit_token()



