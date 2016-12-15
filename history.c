#include <assert.h>
#include <string.h>
#include "context.h"
#include "history.h"
#include "lylib.h"
#include "aux.h"
#include "functions.h"
#define HDEBUG 1

Plottables pastObjects[MAX_NUM_OBJECTS];
int pastObjectsCount;

void updateObjects(Plottables p) {
  int i;
  int l;

  l = p.ip;
  for(i=0;i<l;i++) {//points
    int ip = pastObjects[pastObjectsCount].ip++;
    pastObjects[ pastObjectsCount ].points[ ip ] = p.points[i];
    pastObjectsCount ++;
  }

  l = p.ils;
  for(i=0;i<l;i++) {//line segments
    int ils = pastObjects[pastObjectsCount].ils++;
    pastObjects[ pastObjectsCount ].lineSegments[ ils ] = p.lineSegments[i];
    pastObjectsCount ++;
  }

  l = p.ia;
  for(i=0;i<l;i++) {//arcs
    int ia = pastObjects[pastObjectsCount].ia++;
    pastObjects[ pastObjectsCount ].arcs[ ia ] = p.arcs[i];
    pastObjectsCount ++;
  }

  l = p.iln;
  for(i=0;i<l;i++) {//lines
    int iln = pastObjects[pastObjectsCount].iln++;
    pastObjects[ pastObjectsCount ].lines[ iln ] = p.lines[i];
    pastObjectsCount ++;
  }

  l = p.ic;
  for(i=0;i<l;i++) {//circles
    int ic = pastObjects[pastObjectsCount].ic++;
    pastObjects[ pastObjectsCount ].circles[ ic ] = p.circles[i];
    pastObjectsCount ++;
  }

  l = p.ian;
  for(i=0;i<l;i++) {//angles
    int ian = pastObjects[pastObjectsCount].ian++;
    pastObjects[ pastObjectsCount ].angles[ ian ] = p.angles[i];
    pastObjectsCount ++;  
  }
}

Plottables getObjectAtPosition(int i) {
  assert(i<pastObjectsCount);
  Plottables ret;
  Plottables last = pastObjects[i];
  if(isObjectAngle(last)) {
    ret.angles[ret.ian++] = last.angles[last.ian-1];
  } else if(isObjectCircle(last)) {
    ret.circles[ret.ic++] = last.circles[last.ic-1];
  } else if(isObjectLine(last)) {
    ret.lines[ret.iln++] = last.lines[last.iln-1];
  } else if(isObjectArc(last)) {
    int i=0;
    for(i=0;i<last.ia;i++) {
      ret.arcs[ret.ia++] = last.arcs[i]; 
    }
  } else if(isObjectLineSegment(last)) {
    ret.lineSegments[ret.ils++] = last.lineSegments[last.ils-1];
  } else if(isObjectPoint(last)) {
    ret.points[ret.ip++] = last.points[last.ip-1];
  }
  return ret;
}

bool isObjectAngle(Plottables p) {
  if(p.ian == 0)
    return false;
  else
    return true;
}

bool isObjectCircle(Plottables p) {
  if(p.ic == 0)
    return false;
  else
    return true;
}

bool isObjectLine(Plottables p) {
  if(p.iln == 0)
    return false;
  else
    return true;
}

bool isObjectArc(Plottables p) {
  if(p.ia == 0)
    return false;
  else
    return true;
}

bool isObjectLineSegment(Plottables p) {
  if(p.ils == 0)
    return false;
  else
    return true;
}

bool isObjectPoint(Plottables p) {
  if(p.ip == 0)
    return false;
  else
    return true;
}

Plottables getIntersectableObjectBeforePosition(int n) {
  int i;
  for(i=n-1;i>=0;i--) {
    Plottables object = getObjectAtPosition(i);
    if(isIntersectable(object))
       return object;
  }
  Plottables object;
  return object;
}

bool isIntersectable(Plottables p) {
  if(isObjectCircle(p) || isObjectLine(p) || isObjectArc(p) || isObjectLineSegment(p))
    return true;
  else
    return false;
}

bool isPerpendicularBisectable(Plottables p) {
  if(isObjectLineSegment(p))
    return true;
  else
    return false;
}

bool isBisectable(Plottables p) {
  if(isObjectAngle(p) || isObjectLineSegment(p))
    return true;
  else
    return false;
}

bool isLabelable(Plottables p) {
  if(isObjectPoint(p) || isObjectLineSegment(p) || isObjectArc(p)
      ||isObjectLine(p) || isObjectCircle(p))
    return true;
  else
    return false;
}

Plottables getPerpendicularBisectableObjectBeforePosition(int n) {
  int i;
  for(i=n-1;i>=0;i--) {
    Plottables object = getObjectAtPosition(i);
    if(isPerpendicularBisectable(object))
       return object;
  }
  Plottables object;
  return object;
}

Plottables getBisectableObjectBeforePosition(int n) {
  int i;
  for(i=n-1;i>=0;i--) {
    Plottables object = getObjectAtPosition(i);
    if(isBisectable(object))
       return object;
  }
  Plottables object;
  return object;
}

Plottables getLastObject() {
  return getObjectAtPosition(pastObjectsCount-1);
}

Plottables getLastPerpendicularBisectableObject() {
  return getPerpendicularBisectableObjectBeforePosition(pastObjectsCount-1);
}

Plottables getLastBisectableObject() {
  return getBisectableObjectBeforePosition(pastObjectsCount-1);
}

Plottables getLastIntersectableObject() {
  return getIntersectableObjectBeforePosition(pastObjectsCount);
}

void printPlottableToFile(Plottables p) {
  int i;
  FILE* f = fopen("history.txt", "a");
  fprintf(f, "~POINTS\n");
  int l = p.ip;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf %lf\n", p.points[i].label, p.points[i].x, p.points[i].y);
  }
  fprintf(f, "~LINESEGMENTS\n");
  l = p.ils;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %c\n", p.lineSegments[i].pA.label, p.lineSegments[i].pB.label);
  }
  fprintf(f, "~LINES\n");
  l = p.iln;
  for(i=0;i<l;i++) {
    fprintf(f, "%c\n", p.lines[i].label);
  }
  fprintf(f, "~ARCS\n");
  l = p.ia;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf\n", p.arcs[i].center.label, p.arcs[i].radius);
  }
  fprintf(f, "~ANGLE\n");
  l = p.ian;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %c %c %lf\n", p.angles[i].vertex.label, p.angles[i].leftVertex.label, p.angles[i].rightVertex.label, p.angles[i].degree);
  }
  fprintf(f, "~CIRCLE\n");
  l = p.ic;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf\n", p.circles[i].center.label, p.circles[i].radius);
  }
  fprintf(f, "~PLOTTABLE END\n");
  fclose(f);
}

bool isEmptyPlottable(Plottables p) {
  if(p.ip == 0 && p.ia == 0 && p.ic == 0 && p.ils == 0 && p.iln == 0 && p.ian == 0)
    return true;
  else
    return false;
}

void writeHistory() {
  FILE *fp = fopen("history.txt", "w");
  fclose(fp);
  int i;
  for(i=0;i<pastObjectsCount;i++) {
    if(!isEmptyPlottable(pastObjects[i]))
      printPlottableToFile(pastObjects[i]);
  }
}

bool isEmptyFile(FILE *file) {
  long savedOffset = ftell(file);
  fseek(file, 0, SEEK_END);
  
  if (ftell(file) == 0) {
    return true;
  }
  
  fseek(file, savedOffset, SEEK_SET);
  return false;
}

void readHistory() {
  //read the context file here
  pastObjectsCount = 0;
  char *line;
  size_t len = 0;
  ssize_t read = 0;
  FILE *f = fopen("history.txt", "r");
  if(f) {
    while(!feof(f)) {
      getline(&line, &len, f);
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~LINESEGMENTS\n") == 0)
	  break;
	//parse and update point
	SplitString vec_line = split(line, ' ');
	pastObjects[pastObjectsCount].points[pastObjects[pastObjectsCount].ip].label = vec_line.array[0][0];
	pastObjects[pastObjectsCount].points[pastObjects[pastObjectsCount].ip].x = stod(vec_line.array[1]);
	pastObjects[pastObjectsCount].points[pastObjects[pastObjectsCount].ip].y = stod(vec_line.array[2]);
	pastObjects[pastObjectsCount].ip++;
      }
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~LINES\n") == 0)
	  break;
	//parse and update linesegments
	Point P1 = getPoint(line[0]);
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pA.label = P1.label;
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pA.x = P1.x;
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pA.y = P1.y;
	Point P2 = getPoint(line[2]);
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pB.label = P2.label;
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pB.x = P2.x;
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].pB.y = P2.y;
	pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils].length = getLsLength(pastObjects[pastObjectsCount].lineSegments[pastObjects[pastObjectsCount].ils]);
	pastObjects[pastObjectsCount].ils++;
      }
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~ARCS\n") == 0)
	  break;
	//parse and update lines
	pastObjects[pastObjectsCount].lines[pastObjects[pastObjectsCount].iln].label = line[0];
	pastObjects[pastObjectsCount].iln++;
      }
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~ANGLE\n") == 0)
	  break;
	//parse and update arcs
	SplitString vec_line = split(line, ' ');
	Point P1 = getPoint(vec_line.array[0][0]);
	pastObjects[pastObjectsCount].arcs[pastObjects[pastObjectsCount].ia].center.label = P1.label;
	pastObjects[pastObjectsCount].arcs[pastObjects[pastObjectsCount].ia].center.x = P1.x;
	pastObjects[pastObjectsCount].arcs[pastObjects[pastObjectsCount].ia].center.y = P1.y;
	pastObjects[pastObjectsCount].arcs[pastObjects[pastObjectsCount].ia].radius = stod(vec_line.array[1]);
	pastObjects[pastObjectsCount].ia++;
      }
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~CIRCLE\n") == 0)
	  break;
	//parse and update angles
	SplitString vec_line = split(line, ' ');
	Point P1 = getPoint(vec_line.array[0][0]);
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].vertex.label = P1.label;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].vertex.x = P1.x;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].vertex.y = P1.y;
	Point P2 = getPoint(vec_line.array[1][0]);
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].leftVertex.label = P2.label;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].leftVertex.x = P2.x;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].leftVertex.y = P2.y;
	Point P3 = getPoint(vec_line.array[2][0]);
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].rightVertex.label = P3.label;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].rightVertex.x = P3.x;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].rightVertex.y = P3.y;
	pastObjects[pastObjectsCount].angles[pastObjects[pastObjectsCount].ian].degree = stod(vec_line.array[3]);
	pastObjects[pastObjectsCount].ian++;
      }
      while((read = getline(&line, &len, f)) != -1) {
	if(strcmp(line, "~PLOTTABLE END\n") == 0)
	  break;
	//parse and update circles
	SplitString vec_line = split(line, ' ');
	Point P1 = getPoint(vec_line.array[0][0]);
	pastObjects[pastObjectsCount].circles[pastObjects[pastObjectsCount].ic].center.label = P1.label;
	pastObjects[pastObjectsCount].circles[pastObjects[pastObjectsCount].ic].center.x = P1.x;
	pastObjects[pastObjectsCount].circles[pastObjects[pastObjectsCount].ic].center.y = P1.y;
	pastObjects[pastObjectsCount].circles[pastObjects[pastObjectsCount].ic].radius = stod(vec_line.array[1]);
	pastObjects[pastObjectsCount].ic++;
      }
      if(!isEmptyPlottable(pastObjects[pastObjectsCount]))
	pastObjectsCount++;
    }
  }
  fclose(f);
}

void printHistory() {
  int i;
  printf("----------History Begin---------\n");
  for(i=0;i<pastObjectsCount;i++) {
    printPlottable(pastObjects[i]);
  }
  printf("----------History End---------\n");
}

void resolvePlottables(Plottables *p){
 if(isResolved(p)){
  return;
 }

 if(p->type == POINT_D){
  p->points[p->ip] = getLastPoint();
  p->ip ++ ;
  if(p->singleton == false){
   p->points[p->ip] = getSecondLastPoint();
   p->ip ++ ;
  }
 } else if(p->type == LINE_SEGMENT_D){
  p->lineSegments[p->ils] = getLastLineSegment();
  p->ils ++ ;
  if(p->singleton == false){
   p->lineSegments[p->ils] = getSecondLastLineSegment();
   p->ils ++ ;
  }
 } else if(p->type == LINE_D){
  p->lines[p->iln] = getLastLine();
  p->iln ++ ;
  if(p->singleton == false){
   p->lines[p->iln] = getSecondLastLine();
   p->iln ++ ;
  }
 } else if(p->type == ARC_D){
  p->arcs[p->ia] = getLastArc();
  p->ia ++ ;
  if(p->singleton == false){
   p->arcs[p->ia] = getSecondLastArc();
   p->ia ++ ;
  }
 } else if(p->type == CIRCLE_D){
  p->circles[p->ic] = getLastCircle();
  p->ic ++ ;
  if(p->singleton == false){
   p->circles[p->ic] = getSecondLastCircle();
   p->ic ++ ;
  }
 } else if(p->type == ANGLE_D){
  p->angles[p->ian] = getLastAngle();
  p->ian ++ ;
  if(p->singleton == false){
   p->angles[p->ian] = getSecondLastAngle();
   p->ian ++ ;
  }
 }
 
 if(isResolved(p)){
  return;
 }
 
 int wanted = 0;
 if(p->singleton == false){
  wanted = 2;
 } else {
  wanted = 1;
 }
 
 if(p->class == INTERSECTABLE_D){
  int i;
  for(i=pastObjectsCount-1; i>=0 && wanted > 0; i--){
   if(isIntersectable(pastObjects[i])){
    *p = combinePlottables(*p, pastObjects[i]);
    wanted--;
   }
  }
 } else if(p->class == BISECTABLE_D){
  int i;
  for(i=pastObjectsCount-1; i>=0 && wanted > 0; i--){
   if(isBisectable(pastObjects[i])){
    *p = combinePlottables(*p, pastObjects[i]);
    wanted--;
   }  
  }
 } else if(p->class == PERPENDICULAR_BISECTABLE_D){
  int i;
  for(i=pastObjectsCount-1; i>=0 && wanted > 0; i--){
   if(isPerpendicularBisectable(pastObjects[i])){
    *p = combinePlottables(*p, pastObjects[i]);
    wanted--;
   }  
  }
 } else if(p->class == LABELABLE_D){
  int i;
  for(i=pastObjectsCount-1; i>=0 && wanted > 0; i--){
   if(isLabelable(pastObjects[i])){
    *p = combinePlottables(*p, pastObjects[i]);
    wanted--;
   }  
  }
 }

 if(HDEBUG && ! isResolved(p) ){
  printf("Could not resolve Plottable\n");
 }

 return;

}

bool isResolved(Plottables *p){
 return p->ip > 0 || p->ils > 0 || p->ia > 0 || p->iln > 0 || p->ic > 0 || p->ian > 0
  || p->ilg > 0;
}
