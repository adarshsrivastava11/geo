#pragma once

#include<assert.h>
#include<stdio.h>
#include "lylib.h"
#include "aux.h"
#define contextFilename "./context.txt"
#define diffFilename "./diff.txt"
extern int pastObjectsCount;

typedef struct _Context{
  int ip, ils, ia, iln, ic, ian, ilg;
  Point points[MAX_PLOTTABLES];
  LineSegment lineSegments[MAX_PLOTTABLES];
  Arc arcs[MAX_PLOTTABLES];
  Line lines[MAX_PLOTTABLES];
  Circle circles[MAX_PLOTTABLES];
  Angle angles[MAX_PLOTTABLES];
  Length lengths[MAX_PLOTTABLES];
} Context;

Context context;

typedef struct _Command{
  Plottables plottables;
} Command;

/* Functions */
Command* newCommand();
void executeCommand(Command command);
double stod(char str[]);
void readContext();
Point getPoint(char label);
void updateContext(Plottables p);
void writeDiff(Plottables p);
void writeContext();
bool existsPoint(Point p);
bool existsCircle(Circle c);
bool existsArc(Arc a);
bool existsPointLabel(char label);
bool existsLineSegment(char pointpair[]);
bool existsLineSegmentLabel(char point1Label, char point2Label);
bool existsLine(char name);
bool existsLastAngle();
bool existsAngle(char name[]);
LineSegment getLineSegment(char pointpair[]);
LineSegment getLineSegmentLabel(char point1Label, char point2Label);
Line getLine(char name);
Angle getAngle(char name[]);
Point getPointAtPosition(int i);
Point getLastPoint();
Point getSecondLastPoint();
int getNumberOfPoints();
int getNumberOfArcs();
LineSegment getLastLineSegment();
LineSegment getSecondLastLineSegment();
Line getLastLine();
Line getSecondLastLine();
Arc getLastArc();
Arc getSecondLastArc();
Arc getArcAtPosition(int i);
Circle getLastCircle();
Circle getSecondLastCircle();
Circle getCircleAtPosition(int i);
Angle getLastAngle();
Angle getSecondLastAngle();
Length *getLastLength();
bool existsLastLineSegment();
char reserveNextPointLabel();
void LineSegmentCopy(LineSegment ls, LineSegment *l);
double getLength(Length l);
void setLength(Condition *c, double l);
bool isEmpty(Plottables p);
bool comparePoint(Point A, Point B);
bool compareAngles(Angle A, Angle B);
void printPlottable(Plottables p);
void printContext();
LineSegment getLineSegmentAtPosition(int i);
int getNumLineSegments();
int getNumPoints();
int getNumArcs();
int getNumCircles();
bool existsAngleLabel(char leftVertex, char vertex, char rightVertex);
