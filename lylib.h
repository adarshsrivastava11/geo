#pragma once

#include<math.h>
#include<stdio.h>
#define MAX_PLOTTABLES 15
#define VECT_SIZE 3

//types
#define INDEFINITE_D 0
#define POINT_D 1
#define LINE_SEGMENT_D 2
#define LINE_D 3
#define ARC_D 4
#define CIRCLE_D 5
#define ANGLE_D 6

//classes
#define INTERSECTABLE_D 50
#define BISECTABLE_D 51
#define PERPENDICULAR_BISECTABLE_D 52
#define LABELABLE_D 53

typedef int bool;

typedef struct _Length{
  double length;
} Length;

typedef struct _VecLengths{
  Length* lengths;
  int n;
} VecLengths;

typedef struct _Degree{
  double degree;
} Degree;

typedef struct _Point{
  char label;
  double x, y;
} Point;

typedef struct _VecPoints{
  Point* points;
  int n;
} VecPoints;

typedef struct _Angle{
  Point vertex, leftVertex, rightVertex;
  double degree;
} Angle;

typedef struct _Arc{
  Point center;
  double radius;
} Arc;

typedef struct _VecArcs{
  Arc* arcs;
  int n;
} VecArcs;

typedef struct _Line{
    char label;
} Line;

typedef struct _LineSegment{
    Point pA, pB;
    double length;
} LineSegment;

typedef struct _VecLineSegments{
  LineSegment* lineSegments;
  int n;
} VecLineSegments;

typedef struct _Circle{
  Point center;
  double radius;
} Circle;

typedef struct _Plottables{  
  int type, class;
  bool singleton;
  int ip, ils, ia, iln, ic, ian, ilg;
  Point points[MAX_PLOTTABLES];
  LineSegment lineSegments[MAX_PLOTTABLES];
  Arc arcs[MAX_PLOTTABLES];
  Line lines[MAX_PLOTTABLES];
  Circle circles[MAX_PLOTTABLES];
  Angle angles[MAX_PLOTTABLES];
  Length lengths[MAX_PLOTTABLES];
} Plottables;

typedef struct _Condition{
  LineSegment ls;
  double length;
  Angle angle;
  double degree;
} Condition;

typedef struct _Location{
  double distance;
  Point fromPoint;
} Location;

typedef struct _Operation{
  char label;
} Operation;

typedef struct _Ray	{
  
} Ray;

typedef struct _VecStrings{
  char** strings;
  int n;
} VecStrings;

/* Functions */
Length* newLength();
Degree* newDegree();
Point* newPoint();
Angle* newAngle();
Arc* newArc();
Line* newLine();
LineSegment* newLineSegment();
Circle* newCircle();
Plottables* newPlottables();
void updatePlottablesPoint(Plottables* p, Point pn);
void updatePlottablesLineSegment(Plottables* p, LineSegment ls);
void updatePlottablesArc(Plottables* p, Arc a);
void updatePlottablesLine(Plottables* p, Line l);
void updatePlottablesCircle(Plottables *p, Circle c);
void updatePlottablesAngle(Plottables *p, Angle a);
Condition* newCondition();
Location* newLocation();
Operation* newOperation();
double getResult(Operation* op, double a, double b);
Ray* newRay();
void spitError(char* error);
VecLineSegments* newVectorLineSegments();
VecLengths* newVectorLengths();
VecArcs* newVectorArcs();
VecPoints* newVectorPoints();
VecStrings* newVectorStrings();
char* newString(char *s);
double getDegree(Angle *an);
bool areSameLineSegment(LineSegment l1, LineSegment l2);
void setLineSegment(Condition *c, LineSegment l);
void setAngle(Condition *c, Angle a);
void resolvePlottables(Plottables *p);
