#include "lylib.h"
#include "aux.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define ADEBUG 1
Intersection* newIntersection() {
  Intersection *i = (Intersection*)malloc(sizeof(Intersection));
  memset((void*)i, 0, sizeof(Intersection));
  return i;
}

Bisector* newBisector() {
  return (Bisector*)malloc(sizeof(Bisector));
}

Parallelization* newParallelization() {
  Parallelization* par = (Parallelization*)malloc(sizeof(Parallelization));
  memset(par, 0, sizeof(Parallelization));
  return par;
}

Perpendicularization* newPerpendicularization() {
  Perpendicularization* per = (Perpendicularization*)malloc(sizeof(Perpendicularization));
  memset(per, 0, sizeof(Perpendicularization));
  return per;
}

Cut* newCut() {
  Cut *c = (Cut*)malloc(sizeof(Cut));
  memset(c, 0, sizeof(Cut));
  return c;
}

Point getCircleIntersectionPoint(Circle a, Circle b, bool above){
  return _getArcIntersectionPoint(a.center, a.radius, b.center, b.radius, above);
}

Point getArcIntersectionPoint(Arc a, Arc b, bool above){
  return _getArcIntersectionPoint(a.center, a.radius, b.center, b.radius, above);
}

Point _getArcIntersectionPoint(Point p0, double r0, Point p1, double r1, bool above){
  if(ADEBUG){
   printf("Centers and Radii (%lf, %lf) %lf (%lf, %lf) %lf\n", p0.x, p0.y, r0, p1.x, p1.y, r1);
  }
  float x = p1.x - p0.x, y = p1.y - p0.y;
  float d = sqrt(x*x+y*y);
  float a = (float)(r0*r0 - r1*r1 + d*d) / (float)(2*d);
  float h = sqrt((float)(r0*r0 - a*a));
  
  float x2 = p0.x + a*x/d;
  float y2 = p0.y + a*y/d;
  float x31 = x2+h*y/d;
  float y31 = y2-h*x/d;
  float x32 = x2-h*y/d;
  float y32 = y2+h*x/d;

  if(ADEBUG){
   printf("Intersection points (%lf, %lf) (%lf, %lf) above:%d\n", x31, y31, x32, y32, above);
  }

  Point ret;
  if(y31>y32) {
   if(above){
     ret.x = x31;
     ret.y = y31;
   } else {
     ret.x = x32;
     ret.y = y32;
   }
  } else {
   if(above){
     ret.x = x32;
     ret.y = y32;
   } else {
     ret.x = x31;
     ret.y = y31;
   }   
  }
  return ret;
}

int getIntersectableObject(Intersection i1) {
  if(i1.ls1) {
    return 1;
  } else if(i1.l1) {
    return 2;
  } else if(i1.a1) {
    return 3;
  } else if(i1.c1) {
    return 4;
  } else if(i1.an1) {
    return 5;
  } else if(i1.r1) {
    return 6;
  } else {
    return -1;
  }
}

Point getIntersectableIntersectableIntersection(Intersection i1, Intersection i2, bool above) {
  int l1 = getIntersectableObject(i1);
  int l2 = getIntersectableObject(i2);
  if(l1==1 && l2==1) {
    //ls and ls
    return getLsLsIntersection(*(i1.ls1), *(i2.ls1), above);
  } else if(l1==1 && l2==3) {
    //ls and arc
    return getLsArcIntersection(*(i1.ls1), *(i2.a1), above);
  } else if(l1==1 && l2==4) {
    //ls and circle
    return getLsCircleIntersection(*(i1.ls1), *(i2.c1), above);
  } else if(l1==3 && l2==1) {
    //Arc and ls
    return getLsArcIntersection(*(i2.ls1), *(i1.a1), above);
  } else if(l1==3 && l2==3) {
    //arc and arc
    return getArcArcIntersection(*(i1.a1), *(i2.a1), above);
  } else if(l1==3 && l2==4) {
    //arc and circle
    return getArcCircleIntersection(*(i1.a1), *(i2.c1), above);
  } else if(l1==4 && l2==1) {
    //circle and ls
    return getLsCircleIntersection(*(i2.ls1), *(i1.c1), above);
  } else if(l1==4 && l2==3) {
    // circle and arc
    return getArcCircleIntersection(*(i2.a1), *(i1.c1), above);
  } else if(l1==4 && l2==4) {
    //circle and circle
    return getCircleCircleIntersection(*(i1.c1), *(i2.c1), above);
  } else if(l1==5 && l2==3) {
    //angle and arc
    return getAngleArcIntersection(*(i1.an1), *(i2.a1), above);
  } else if(l1==5 && l2==4) {
    // angle and circle
    return getAngleCircleIntersection(*(i1.an1), *(i2.c1), above);
  } else if(l1==3 && l2==5) {
    //arc and angle
    return getAngleArcIntersection(*(i2.an1), *(i1.a1), above);
  } else if(l1==4 && l2==5) {
    //circle and angle
    return getAngleCircleIntersection(*(i2.an1), *(i1.c1), above);
  } else {
    Point *p = newPoint();
    return *p;
  }
}

Point getArcArcIntersection(Arc a1, Arc a2, bool above) {
  return _getArcIntersectionPoint(a1.center, a1.radius, a2.center, a2.radius, above);
}

Point getArcCircleIntersection(Arc a, Circle c, bool above) {
  return _getArcIntersectionPoint(a.center, a.radius, c.center, c.radius, above);
}

Point getCircleCircleIntersection(Circle c1, Circle c2, bool above) {
  return _getArcIntersectionPoint(c1.center, c1.radius, c2.center, c2.radius, above);
}

Point getLsLsIntersection(LineSegment l1, LineSegment l2, bool above) {
  float x11 = l1.pA.x, y11 = l1.pA.y, x12 = l1.pB.x, y12 = l1.pB.y;
  float x21 = l2.pA.x, y21 = l2.pA.y, x22 = l2.pB.x, y22 = l2.pB.y;
  float m1 = (y12 - y11)/(x12 - x11);
  float m2 = (y22 - y21)/(x22-x21);
  Point ret;
  ret.x = ((y21-y11) + (m2*x21-m1*x11))/(m2-m1);
  ret.y = m1*(ret.x - x11) + y11;
  return ret;
}

Point getLsArcIntersection(LineSegment l, Arc a, bool above) {
  return _getLsArcIntersection(l, a.center, a.radius, above);
}

Point getLsCircleIntersection(LineSegment l, Circle c, bool above) {
  return _getLsArcIntersection(l, c.center, c.radius, above);
}

Point _getLsArcIntersection(LineSegment l, Point c, double r, bool above) {
  double x1 = l.pA.x, y1 = l.pA.y, x2 = l.pB.x, y2 = l.pB.y;
  double xc = c.x, yc = c.y;
  double m = (y2 - y1)/(x2 - x1);
  double c1 = m*(xc-x1) + (y1-yc);
  double b = (2*m*r*c1)/(r*r*(m*m+1));
  double C = (c1*c1 - r*r)/(r*r*(m*m+1));
  double d = sqrt(b*b - 4*C);
  double cos1 = (-b-d)/2;
  double cos2 = (-b+d)/2;
  double x31 = xc+r*cos1;
  double x32 = xc+r*cos2;
  double y31 = m*(x31-x1) + y1;
  double y32 = m*(x32-x1) + y1;
  Point ret;
  if(above){
	if(y31 - y32 > FLOAT_EPSILON) {
	  ret.x = x31;
	  ret.y = y31;
	} else {
	  ret.x = x32;
	  ret.y = y32;
	}
  } else {
	if(y32 - y31 > FLOAT_EPSILON) {
	  ret.x = x31;
	  ret.y = y31;
	} else {
	  ret.x = x32;
	  ret.y = y32;
	}
  }	  
  return ret; 
}

double getSlope(Point a, Point b){
  double deltax = b.x - a.x;
  double deltay = b.y - a.y;

  if(abs(deltax) <= FLOAT_EPSILON){
    if(deltay >= FLOAT_EPSILON) return 90.0;
    else return -90.0;
  }

  double slope = atan2(deltay, deltax) * RADIANS_TO_DEGREES;
  return slope;
}

double getSlopeLs(LineSegment ls) {
  return getSlope(ls.pA, ls.pB);
}

Point getMidPoint(Point a, Point b){
  Point c;
  c.x = (a.x + b.x) * 0.5;
  c.y = (a.y + b.y) * 0.5;
  return c;
}

Point locatePoint(Point source, double slope, double distance){
  Point c;
  while(slope < 0.0) slope += 360.0;
  while(slope > 360.0) slope -= 360.0;
  c.x = source.x + distance*cos(slope*DEGREES_TO_RADIANS);
  c.y = source.y + distance*sin(slope*DEGREES_TO_RADIANS);
  return c;
}

void printPoint(Point p){
  printf("Point %c %lf %lf\b", p.label, p.x, p.y);
}

LineSegment getPerpendicularBisector(LineSegment ls){
  
  double baseSlope = getSlope(ls.pA, ls.pB);
  
  Point midPoint = getMidPoint(ls.pA, ls.pB);

  Point pbEndPoint1 = locatePoint(midPoint, baseSlope + 90.0, DEFAULT_LINE_SEGMENT_LENGTH);
  Point pbEndPoint2 = locatePoint(midPoint, baseSlope - 90.0, DEFAULT_LINE_SEGMENT_LENGTH);

  pbEndPoint1.label = reserveNextPointLabel();
  pbEndPoint2.label = reserveNextPointLabel();
  
  LineSegment pb;//the perpendicular bisector
  pb.pA = pbEndPoint1;
  pb.pB = pbEndPoint2;
  
  return pb;
}

LineSegment getAngleBisector(Angle a){

  double rslope = getSlope(a.rightVertex, a.vertex),
    lslope = getSlope(a.leftVertex, a.vertex);
  double midSlope = 0.5 * (rslope + lslope);
  Point res = locatePoint(a.vertex, midSlope, DEFAULT_ANGLE_ARM_LENGTH);
  
  LineSegment ls;
  ls.pA = a.vertex;
  ls.pB = res;
  
  return ls;
}

LineSegment getPerpendicularPassingThrough(LineSegment ls, Point passingThrough){
  
  double slope = getSlopeLs(ls);
  double pslope = slope + 90.0;
  double c = 0.0; //y = mx + c

  if(abs(abs(pslope) - 90.0) <= FLOAT_EPSILON){
    c = passingThrough.x;
  } else {
    //   c = y - mx
    c = passingThrough.y - passingThrough.x * tan(pslope * DEGREES_TO_RADIANS);
  }

  Point dummyPoint;
  dummyPoint.x = passingThrough.x + 2.0;
  dummyPoint.y = c + dummyPoint.x * tan(pslope * DEGREES_TO_RADIANS);

  LineSegment dummyLs;
  dummyLs.pA = passingThrough;
  dummyLs.pB = dummyPoint;

  Point in = getLsLsIntersection(ls, dummyLs, true);

  LineSegment res;
  res.pA = passingThrough;
  res.pB = in;

  return res;
}

LineSegment getParallelPassingThrough(LineSegment ls, Point passingThrough){
  
  double slope = getSlopeLs(ls);
  double pslope = slope;
  double c = 0.0; //y = mx + c

  if(abs(abs(pslope) - 90.0) <= FLOAT_EPSILON){
    c = passingThrough.x;
  } else {
    //   c = y - mx
    c = passingThrough.y - passingThrough.x * tan(pslope * DEGREES_TO_RADIANS);
  }

  Point dummyPoint = locatePoint(passingThrough, pslope, DEFAULT_LINE_SEGMENT_LENGTH);

  LineSegment res;
  res.pA = passingThrough;
  res.pB = dummyPoint;
  res.pB.label = reserveNextPointLabel();

  return res;
}

LineSegment getPerpendicularAt(LineSegment ls, Point at){

  if(ADEBUG){
	  printf("getPerpendicularAt(");
	  printLineSegment(ls);
	  printPoint(at);
	  printf(")\n");
  }
  
  double slope = getSlopeLs(ls);
  double pslope = slope - 90.0;

  if(ADEBUG){
	  printf("Slope=%lf\n", slope);
  }
  
  Point dummyPoint;
  if(abs(abs(pslope) - 90.0) <= FLOAT_EPSILON){
    dummyPoint.x = at.x;
    dummyPoint.y = at.y - DEFAULT_LINE_SEGMENT_LENGTH;
  } else {
    dummyPoint = locatePoint(at, pslope, DEFAULT_LINE_SEGMENT_LENGTH);
  }
  printPoint(dummyPoint);
  dummyPoint.label = reserveNextPointLabel();
  LineSegment res;
  res.pA = at;
  res.pB = dummyPoint;

  return res;
}

Point getAngleArcIntersection(Angle an, Arc a, bool above) {
  if(above) {
    LineSegment L;
    L.pA = an.vertex;
    L.pB = an.leftVertex;
    return getLsArcIntersection(L, a, above);
  } else {
    LineSegment L;
    L.pA = an.vertex;
    L.pB = an.rightVertex;
    return getLsArcIntersection(L, a, above);
  }
  Point P = *newPoint();
  return P;
}

Point getAngleCircleIntersection(Angle an, Circle c, bool above) {
  if(above) {
    LineSegment L;
    L.pA = an.vertex;
    L.pB = an.leftVertex;
    return getLsCircleIntersection(L, c, above);
  } else {
    LineSegment L;
    L.pA = an.vertex;
    L.pB = an.rightVertex;
    return getLsCircleIntersection(L, c, above);
  }
  Point P = *newPoint();
  return P;
}

Point getArcIntersectableIntersection(Arc a, Intersection i, bool above) {
  Intersection i2;
  i2.a1 = &a;
  return getIntersectableIntersectableIntersection(i2, i, above);
}

char nextAvailableLineLabel = 'a';

char reserveNextLineLabel(){
  char label = nextAvailableLineLabel;
  nextAvailableLineLabel++;
  return label;
}

Point getPointOnLabelable(Intersection i, Location *l) {
  int n = getIntersectableObject(i);
  if(n==1) { //line segment
    if(l==NULL) {
      Point P;
      P.x = 0.5 * (i.ls1->pA.x + i.ls1->pB.x);
      P.y = 0.5 * (i.ls1->pA.y + i.ls1->pB.y);
      return P;
    } else {
      Circle c;
      c.center = l->fromPoint;
      c.radius = l->distance;
      Point p = getLsCircleIntersection(*i.ls1, c, true);
      //First make sure p actually lies on ls1
      if(liesOn(p, *i.ls1)){
		  return p;
	  } else {
		  return getLsCircleIntersection(*i.ls1, c, false);
	  }
    }
  } else if(n==3) {
    Point P;
    double randAngle = rand()%360;
    P.x = i.a1->center.x + (i.a1->radius) * cos(randAngle);
    P.y = i.a1->center.y + (i.a1->radius) * sin(randAngle);
    return P;
  } else if(n==4) {
    Point P;
    double randAngle = rand()%360;
    P.x = i.c1->center.x + (i.c1->radius) * cos(randAngle);
    P.y = i.c1->center.y + (i.c1->radius) * sin(randAngle);
    return P;
  }
  Point P = *newPoint();
  return P;
}

Point getPointNotOnLabelable(Intersection i, Location *l) {
  int n = getIntersectableObject(i);
  if(n==1) {
    if(l==NULL) {
      double slope = getSlopeLs(*i.ls1);
      Point P;
      int xm = (i.ls1->pA.x + i.ls1->pB.x)/2,
       ym = (i.ls1->pA.y + i.ls1->pB.y)/2;
      double randSlope = slope + ((rand()%90) + 45);
      double randRad = rand()%DEFAULT_LINE_SEGMENT_LENGTH
       + DEFAULT_LINE_SEGMENT_LENGTH/2;
      P.x = xm + cos(randSlope)*randRad;
      P.y = ym + sin(randSlope)*randRad;
      return P;
    }
  } else if(n==3) {
    Point P;
    double randAngle = rand()%360;
    P.x = i.a1->center.x + (i.a1->radius+1) * cos(randAngle);
    P.y = i.a1->center.y + (i.a1->radius+1) * sin(randAngle);
    return P;
  } else if(n==4) {
    Point P;
    double randAngle = rand()%360;
    P.x = i.c1->center.x + (i.c1->radius+1) * cos(randAngle);
    P.y = i.c1->center.y + (i.c1->radius+1) * sin(randAngle);
    return P;
  }
  Point P = *newPoint();
  return P;
}

Intersection *getIntersectionFromPlottables(Plottables p){
  Intersection *i = newIntersection();

  if(p.ic >=1){
    Circle *c1 = newCircle();
    *c1 = p.circles[0];
    i->c1 = c1;

    if(p.ic >=2){
      Circle *c2 = newCircle();
      *c2 = p.circles[1];
      i->c2 = c2;
    }
  }

  if(p.iln >=1){
    Line *l1 = newLine();
    *l1 = p.lines[0];
    i->l1 = l1;

    if(p.iln >=2){
      Line *l2 = newLine();
      *l2 = p.lines[1];
      i->l2 = l2;
    }
  }

  if(p.ia >=1){
    Arc *a1 = newArc();
    *a1 = p.arcs[0];
    i->a1 = a1;

    if(p.ia >=2){
      Arc *a2 = newArc();
      *a2 = p.arcs[1];
      i->a2 = a2;
    }
  }

  if(p.ils >=1){
    LineSegment *ls1 = newLineSegment();
    *ls1 = p.lineSegments[0];
    i->ls1 = ls1;

    if(p.ils >=2){
      LineSegment *ls2 = newLineSegment();
      *ls2 = p.lineSegments[1];
      i->ls2 = ls2;
    }
  }

  if(p.ip >=1){
    Point *p1 = newPoint();
    *p1 = p.points[0];
    i->p1 = p1;

    if(p.ip >= 2){
      Point *p2 = newPoint();
      *p2 = p.points[1];
      i->p2 = p2;    
    }
  }

  return i;
}

bool containsMultipleObjects(Plottables p) { 
  if(p.ip>1 || p.ils>1 || p.ia>1 || p.ic>1 || p.iln>1 || p.ian>1)
    return true;
  else
    return false;
}

Plottables combinePlottables(Plottables a, Plottables b) {
  Plottables p;
  p.ip = a.ip + b.ip;
  p.ic = a.ic + b.ic;
  p.ia = a.ia + b.ia;
  p.ils = a.ils + b.ils;
  p.iln = a.iln + b.iln;
  p.ian = a.ian + b.ian;
  
  int i;
  for(i=0;i<a.ip;i++) {
    p.points[i] = a.points[i];
  }
  for(i=0;i<a.ils;i++) {
    p.lineSegments[i] = a.lineSegments[i];
  }
  for(i=0;i<a.iln;i++) {
    p.lines[i] = a.lines[i];
  }
  for(i=0;i<a.ic;i++) {
    p.circles[i] = a.circles[i];
  }
  for(i=0;i<a.ia;i++) {
    p.arcs[i] = a.arcs[i];
  }
  for(i=0;i<a.ian;i++) {
    p.angles[i] = a.angles[i];
  }  

  for(i=0;i<b.ip;i++) {
    p.points[a.ip+i] = b.points[i];
  }
  for(i=0;i<b.ils;i++) {
    p.lineSegments[a.ils+i] = b.lineSegments[i];
  }
  for(i=0;i<b.iln;i++) {
    p.lines[a.iln+i] = b.lines[i];
  }
  for(i=0;i<b.ic;i++) {
    p.circles[a.ic+i] = b.circles[i];
  }
  for(i=0;i<b.ia;i++) {
    p.arcs[a.ia+i] = b.arcs[i];
  }
  for(i=0;i<b.ian;i++) {
    p.angles[a.ian+i] = b.angles[i];
  }  
  return p;
}

void printIntersection(Intersection p) {
  if(p.p1)
    printf("%c\n", p.p1->label);
  if(p.p2)
    printf("%c\n", p.p2->label);
  if(p.ls1)
    printf("%c%c\n", p.ls1->pA.label, p.ls1->pB.label);
  if(p.ls2)
    printf("%c%c\n", p.ls2->pA.label, p.ls2->pB.label);
  if(p.a1)
    printf("%c\n", p.a1->center.label);
  if(p.a2)
    printf("%c\n", p.a2->center.label);
  if(p.c1)
    printf("%c\n", p.c1->center.label);
  if(p.c2)
    printf("%c\n", p.c2->center.label);
}

void printLineSegment(LineSegment ls){
	printf("Printing line segment: %c%c %lf\n", ls.pA.label, ls.pB.label, ls.length);
}

double getDistance(Point a, Point b){
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double distance = sqrt(dx*dx + dy*dy);
	return distance;
}

bool liesOn(Point p, LineSegment l){
	double Dx = l.pB.x - l.pA.x, Dy = l.pB.y - l.pA.y;
	double dx = p.x - l.pA.x, dy = p.y - l.pA.y;
	if(abs(Dy/Dx - dy/dx) > FLOAT_EPSILON) return false;
	if( p.x - l.pA.x > FLOAT_EPSILON && p.x - l.pB.x > FLOAT_EPSILON) return false;
	if( l.pA.x - p.x > FLOAT_EPSILON && l.pB.x - p.x > FLOAT_EPSILON) return false;
	if( p.y - l.pA.y > FLOAT_EPSILON && p.y - l.pB.y > FLOAT_EPSILON) return false;
	if( l.pA.y - p.y > FLOAT_EPSILON && l.pB.y - p.y > FLOAT_EPSILON) return false;
	return true;
}

Point getIntersectableIntersection(Intersection i, bool above){
 //Intersection i contains the two objects intersecting eachother
 //We need to construct two new Intersection instances each containing
 //one of the intersecting objects
 Intersection *in = newIntersection();
 
 if(i.p1){
  in->p1 = i.p1;
  i.p1 = i.p2;
  i.p2 = NULL;
 } else if(i.ls1){
  in->ls1 = i.ls1;
  i.ls1 = i.ls2;
  i.ls2 = NULL;
 } else if(i.l1){
  in->l1 = i.l1;
  i.l1 = i.l2;
  i.l2 = NULL;
 } else if(i.a1){
  in->a1 = i.a1;
  i.a1 = i.a2;
  i.a2 = NULL;
 } else if(i.c1){
  in->c1 = i.c1;
  i.c1 = i.c2;
  i.c2 = NULL;
 } else if(i.an1){
  in->an1 = i.an1;
  i.an1 = NULL;
 } else if(i.r1){
  in->r1 = i.r1;
  i.r1 = i.r2;
  i.r2 = NULL;
 }
 
 Point p = getIntersectableIntersectableIntersection(i, *in, above);
 free(in);
 return p;
}

LineSegment getPerpendicularBisectorPlottable(Plottables p){
 assert(false);
 return *newLineSegment();
}
