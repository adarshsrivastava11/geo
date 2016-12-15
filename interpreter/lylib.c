#include "lylib.h"
#include "aux.h"
#include<assert.h>
#include<stdlib.h>
#include <string.h>

/* Do not touch */
#define false 0
#define true 1
/* */

Length* newLength(){
  return (Length*)malloc(sizeof(Length));
}

Degree* newDegree(){
  return (Degree*)malloc(sizeof(Degree));
}

Point* newPoint(){
  return (Point*)malloc(sizeof(Point));
}

Angle* newAngle(){
  return (Angle*)malloc(sizeof(Angle));
}

Arc* newArc(){
  return (Arc*)malloc(sizeof(Arc));
}

Line* newLine(){
  return (Line*)malloc(sizeof(Line));
}

LineSegment* newLineSegment(){
  return (LineSegment*)malloc(sizeof(LineSegment));
}

Circle* newCircle(){
  return (Circle*)malloc(sizeof(Circle));
}

char* newString(char *s){
  char *d = (char*)malloc((strlen(s)+1)*sizeof(char));
  strcpy(d, s);
  return d;
}

Plottables* newPlottables(){
  Plottables *p = (Plottables*)malloc(sizeof(Plottables));
  p->type = INDEFINITE_D;
  p->class = INDEFINITE_D;
  p->singleton = false;
  p->ip = p->ils = p->ia = p->iln = p->ic = p->ian = p->ilg = 0;
  return p;
}

void updatePlottablesPoint(Plottables* p, Point pn){
  if(!existsPointLabel(pn.label)) {
    p->points[p->ip++] = pn;
  }
}

void updatePlottablesLineSegment(Plottables* p, LineSegment ls){
  if(!existsLineSegmentLabel(ls.pA.label, ls.pB.label)) {
    p->points[p->ip++] = ls.pA;
    p->points[p->ip++] = ls.pB;
    p->lineSegments[p->ils++] = ls;
  }
}
  
void updatePlottablesArc(Plottables* p, Arc a){
  if(!existsArc(a)) {
    p->points[p->ip++] = a.center;
    p->lengths[p->ilg++].length = a.radius;
    p->arcs[p->ia++] = a;
  }
}

void updatePlottablesLine(Plottables* p, Line l){
  if(!existsLine(l.label)) {
    p->lines[p->iln++] = l;
  }
}

void updatePlottablesCircle(Plottables *p, Circle c){
  if(!existsCircle(c)) {
    p->points[p->ip++] = c.center;
    p->lengths[p->ilg++].length = c.radius;
    p->circles[p->ic++] = c;
  }
}
void updatePlottablesAngle(Plottables *p, Angle a){
  char angle[4];
  angle[0] = a.leftVertex.label;
  angle[1] = a.vertex.label;
  angle[2] = a.rightVertex.label;
  if(!existsAngle(angle)) {
    p->angles[p->ian++] = a;
    p->points[p->ip++] = a.vertex;
    p->points[p->ip++] = a.leftVertex;
    p->points[p->ip++] = a.rightVertex;
    
    LineSegment lv, rv;
    lv.pA = a.leftVertex;
    lv.pB = a.vertex;
    rv.pA = a.rightVertex;
    rv.pB = a.vertex;
    
    p->lineSegments[p->ils++] = lv;
    p->lineSegments[p->ils++] = rv;
  }
}

Condition* newCondition(){
  return (Condition*)malloc(sizeof(Condition));
}

Location* newLocation(){
  Location *l = (Location*)malloc(sizeof(Location));
  memset(l, 0, sizeof(Location));
  return l;
}

Operation* newOperation(){
  return (Operation*)malloc(sizeof(Operation));
}

double getResult(Operation* op, double a, double b){
  char l = op->label;
  switch(l){
    case '+': return a+b; break;
    case '-': return abs(a-b); break;
    default: assert(false); break;
  }
}

Ray* newRay(){
  return (Ray*)malloc(sizeof(Ray));
}

void spitError(char* error){
  printf("%s\n", error);
  exit(1);
}

VecLineSegments* newVectorLineSegments() {
  VecLineSegments* vls = (VecLineSegments*)malloc(sizeof(VecLineSegments));
  vls->lineSegments = (LineSegment*)malloc(sizeof(LineSegment)*VECT_SIZE);
  vls->n = 0;
  return vls;
}

VecLengths* newVectorLengths() {
  VecLengths* vl = (VecLengths*)malloc(sizeof(VecLengths));
  vl->lengths = (Length*)malloc(sizeof(Length)*VECT_SIZE);
  vl->n = 0;
  return vl;
}

VecArcs* newVectorArcs() {
  VecArcs* va = (VecArcs*)malloc(sizeof(VecArcs));
  va->arcs = (Arc*)malloc(sizeof(Arc)*VECT_SIZE);
  va->n=0;
  return va;
}

VecPoints* newVectorPoints() {
  VecPoints* vp = (VecPoints*)malloc(sizeof(VecPoints));
  vp->points = (Point*)malloc(sizeof(Point)*VECT_SIZE);
  vp->n=0;
  return vp;
}

VecStrings* newVectorStrings() {
  VecStrings* vs = (VecStrings*)malloc(sizeof(VecStrings));
  vs->strings = (char**)malloc(sizeof(char*)*VECT_SIZE);
  vs->n=0;
  return vs;
}

double getDegree(Angle *an) {
  return an->degree;
}

bool areSameLineSegment(LineSegment l1, LineSegment l2) {
  if(l1.pA.label == l2.pA.label && l1.pA.x == l2.pA.x && l1.pA.y == l2.pA.y && l1.pB.label == l2.pB.label && l1.pB.x == l2.pB.x && l1.pB.y == l2.pB.y && l1.length == l2.length)
    return true;
  else
    return false;
}

void setLineSegment(Condition *c, LineSegment l) {
  c->ls.pA.label = l.pA.label;
  c->ls.pA.x = l.pA.x;
  c->ls.pA.y = l.pA.y;
  c->ls.pB.label = l.pB.label;
  c->ls.pB.x = l.pB.x;
  c->ls.pB.y = l.pB.y;
  c->length = getLsLength(l);
}

void setAngle(Condition *c, Angle a) {
  c->angle.vertex.label = a.vertex.label;
  c->angle.vertex.x = a.vertex.x;
  c->angle.vertex.y = a.vertex.y;
  c->angle.leftVertex.label = a.leftVertex.label;
  c->angle.leftVertex.x = a.leftVertex.x;
  c->angle.leftVertex.y = a.leftVertex.y;
  c->angle.rightVertex.label = a.rightVertex.label;
  c->angle.rightVertex.x = a.rightVertex.x;
  c->angle.rightVertex.y = a.rightVertex.y;
  c->degree = a.degree;
}
