#pragma once

#include "lylib.h"
#define DEFAULT_ANGLE_ARM_LENGTH 4
#define DEGREES_TO_RADIANS ((2.0 * 3.14) / 360.0)
#define RADIANS_TO_DEGREES (360.0 / (2 * 3.14))
#define FLOAT_EPSILON 0.0000001
#define DEFAULT_LINE_SEGMENT_LENGTH 4
#define true 1
#define false 0

typedef struct _ArcProperties{
  Point center1, center2;
  Length radius1, radius2;
  
  Point ip1, ip2; //intersection points
} ArcProperties;

typedef struct _Intersection{
  Point *p1, *p2;
  LineSegment *ls1, *ls2;
  Line *l1, *l2;
  Arc *a1, *a2;
  Circle *c1, *c2;
  Angle *an1;
  Ray *r1, *r2;
  bool flip;
} Intersection;

typedef struct _Bisector{
  LineSegment *ls;
  Angle *a;
} Bisector;

typedef struct _Parallelization{
  LineSegment* ls;
  Line *l;
  Point* passingThroughPoint;  
} Parallelization;

typedef struct _Perpendicularization{
  LineSegment* ls;
  Line *l;
  Point* atPoint;
  Point* passingThroughPoint;
} Perpendicularization;

typedef struct _Cut{
  Point *p1, *p2;
  LineSegment *ls;
  Line *l;
} Cut;

/* Functions */
Intersection* newIntersection();
//Object* newObject();
Bisector* newBisector();
Parallelization* newParallelization();
Perpendicularization* newPerpendicularization();
Cut* newCut();
Point getCircleCircleIntersectionPoint(Circle a, Circle b, bool above);
Point getArcArcIntersectionPoint(Arc a, Arc b, bool above);
Point _getArcIntersectionPoint(Point p0, double r0, Point p1, double r1, bool above);
int getIntersectableObject(Intersection i1);
Point getIntersectableIntersectableIntersection(Intersection i1, Intersection i2, bool above);
Point getArcArcIntersection(Arc a1, Arc a2, bool above);
Point getArcCircleIntersection(Arc a, Circle c, bool above);
Point getCircleCircleIntersection(Circle c1, Circle c2, bool above);
Point getLsLsIntersection(LineSegment l1, LineSegment l2, bool above);
Point getLsArcIntersection(LineSegment l, Arc a, bool above);
Point getLsCircleIntersection(LineSegment l, Circle a, bool above);
Point _getLsArcIntersection(LineSegment l, Point c, double r, bool above);
Point getAngleArcIntersection(Angle an, Arc a, bool above);
Point getAngleCircleIntersection(Angle an, Circle c, bool above);
Point getArcIntersectableIntersection(Arc a, Intersection i, bool above);
double getSlope(Point a, Point b);
double getSlopeLs(LineSegment ls);
Point getMidPoint(Point a, Point b);
Point locatePoint(Point source, double slope, double distance);
LineSegment getPerpendicularBisector(LineSegment ls);
LineSegment getAngleBisector(Angle a);
LineSegment getPerpendicularPassingThrough(LineSegment ls, Point passingThrough);
LineSegment getParallelPassingThrough(LineSegment ls, Point passingThrough);
LineSegment getPerpendicularAt(LineSegment ls, Point at);
Point getPointOnLabelable(Intersection i, Location *l);
Point getPointNotOnLabelable(Intersection i, Location *l);
Intersection *getIntersectionFromPlottables(Plottables p);
bool containsMultipleObjects(Plottables p);
Plottables combinePlottables(Plottables a, Plottables b);
void printIntersection(Intersection p);
void printPoint(Point p);
void printLineSegment(LineSegment ls);
double getDistance(Point a, Point b);
bool liesOn(Point p, LineSegment l);
Point getIntersectableIntersection(Intersection i, bool above);
LineSegment getPerpendicularBisectorPlottable(Plottables p);
