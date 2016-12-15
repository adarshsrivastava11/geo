#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "context.h"
#include "lylib.h"
#include "aux.h"
#include "history.h"
#include "functions.h"
#define false 0
#define true 1
#define CDEBUG 1

bool isEmpty(Plottables p) {
  if(p.ip == 0 && p.ils == 0 && p.ia == 0 && p.iln == 0 && p.ic==0 && p.ian==0 && p.ilg == 0)
    return true;
  else
    return false;
}

bool comparePoint(Point A, Point B) {
  if(CDEBUG){
    printf("Comparing points: %c %c %lf %lf %lf %lf\n", A.label, B.label,
    A.x, B.x, A.y, B.y);
  }
  if(A.label == B.label && A.x == B.x && A.y == B.y)
    return true;
  else
    return false;
}

bool compareAngles(Angle A, Angle B) {
  if(comparePoint(A.vertex, B.vertex) && ( (comparePoint(A.leftVertex, B.leftVertex) && comparePoint(A.rightVertex, B.rightVertex)) || (comparePoint(A.leftVertex, B.rightVertex) && comparePoint(A.rightVertex, B.leftVertex)) ) && A.degree == B.degree)
    return true;
  else
    return false;
}

double getLsLength(LineSegment l) {
  double x = l.pA.x - l.pB.x;
  double y = l.pA.y - l.pB.y;
  return sqrt(x*x + y*y);
}

Command* newCommand() {
  return (Command*)malloc(sizeof(Command));
}

void executeCommand(Command command){
  assert(!isEmpty(command.plottables));
  writeDiff(command.plottables);
  updateObjects(command.plottables);
  updateContext(command.plottables);
  writeContext();
  writeHistory();
  if(CDEBUG){
   printContext();
   printHistory();
  }
}
		  
void readContext(){
  context.ip = context.ils = context.iln = context.ia = context.ic = context.ian = 0;
  //read the context file here
  char *line;
  size_t len = 0;
  ssize_t read = 0;
  FILE *f = fopen(contextFilename, "r");
  if(f) {
    if(feof(f)){
      return;
    }
    getline(&line, &len, f);
    while((read = getline(&line, &len, f)) != -1) {
      if(strcmp(line, "~LINESEGMENTS\n") == 0)
	break;
      //parse and update point
      SplitString vec_line = split(line, ' ');
      context.points[context.ip].label = vec_line.array[0][0];
      context.points[context.ip].x = stod(vec_line.array[1]);
      context.points[context.ip].y = stod(vec_line.array[2]);
      context.ip++;
    }
    while((read = getline(&line, &len, f)) != -1) {
      if(strcmp(line, "~LINES\n") == 0)
	break;
      //parse and update linesegments
      Point P1 = getPoint(line[0]);
      context.lineSegments[context.ils].pA.label = P1.label;
      context.lineSegments[context.ils].pA.x = P1.x;
      context.lineSegments[context.ils].pA.y = P1.y;
      Point P2 = getPoint(line[2]);
      context.lineSegments[context.ils].pB.label = P2.label;
      context.lineSegments[context.ils].pB.x = P2.x;
      context.lineSegments[context.ils].pB.y = P2.y;
      context.lineSegments[context.ils].length = getLsLength(context.lineSegments[context.ils]);
      context.ils++;
    }
    while((read = getline(&line, &len, f)) != -1) {
      if(strcmp(line, "~ARCS\n") == 0)
	break;
      //parse and update lines
      context.lines[context.iln].label = line[0];
      context.iln++;
    }
    while((read = getline(&line, &len, f)) != -1) {
      if(strcmp(line, "~ANGLE\n") == 0)
	break;
      //parse and update arcs
      SplitString vec_line = split(line, ' ');
      Point P1 = getPoint(vec_line.array[0][0]);
      context.arcs[context.ia].center.label = P1.label;
      context.arcs[context.ia].center.x = P1.x;
      context.arcs[context.ia].center.y = P1.y;
      context.arcs[context.ia].radius = stod(vec_line.array[1]);
      context.ia++;
    }
    while((read = getline(&line, &len, f)) != -1) {
      if(strcmp(line, "~CIRCLE\n") == 0)
	break;
      //parse and update angles
      SplitString vec_line = split(line, ' ');
      Point P1 = getPoint(vec_line.array[0][0]);
      context.angles[context.ian].vertex.label = P1.label;
      context.angles[context.ian].vertex.x = P1.x;
      context.angles[context.ian].vertex.y = P1.y;
      Point P2 = getPoint(vec_line.array[1][0]);
      context.angles[context.ian].leftVertex.label = P2.label;
      context.angles[context.ian].leftVertex.x = P2.x;
      context.angles[context.ian].leftVertex.y = P2.y;
      Point P3 = getPoint(vec_line.array[2][0]);
      context.angles[context.ian].rightVertex.label = P3.label;
      context.angles[context.ian].rightVertex.x = P3.x;
      context.angles[context.ian].rightVertex.y = P3.y;
      context.angles[context.ian].degree = stod(vec_line.array[3]);
      context.ian++;
    }
    while((read = getline(&line, &len, f)) != -1) {
      //parse and update circles
      SplitString vec_line = split(line, ' ');
      Point P1 = getPoint(vec_line.array[0][0]);
      context.circles[context.ic].center.label = P1.label;
      context.circles[context.ic].center.x = P1.x;
      context.circles[context.ic].center.y = P1.y;
      context.circles[context.ic].radius = stod(vec_line.array[1]);
      context.ic++;
    }
  }
  fclose(f);
}

Point getPoint(char label) {
  Point X;
  int i;
  for(i=0;i<context.ip;i++) {
    if(context.points[i].label == label) {
      X.label = context.points[i].label;
      X.x = context.points[i].x;
      X.y = context.points[i].y;
      break;
    }
  }
  return X;
}

void updateContext(Plottables p) {
  int i;
  int l = p.ip;
  for(i=0;i<l;i++) {
    if(existsPoint(p.points[i])) {
      Point X = getPoint(p.points[i].label);
      assert(comparePoint(X, p.points[i]));
    } else {
      context.points[context.ip].label = p.points[i].label;
      context.points[context.ip].x = p.points[i].x;
      context.points[context.ip].y = p.points[i].y;
      context.ip++;
    }
  }

  l = p.ils;
  for(i=0;i<l;i++) {
    if(existsLineSegmentLabel(p.lineSegments[i].pA.label, p.lineSegments[i].pB.label)) {
      ; // do nothing
    } else {
      context.lineSegments[context.ils].pA.label = p.lineSegments[i].pA.label;
      context.lineSegments[context.ils].pA.x = p.lineSegments[i].pA.x;
      context.lineSegments[context.ils].pA.y = p.lineSegments[i].pA.y;
      context.lineSegments[context.ils].pB.label = p.lineSegments[i].pB.label;
      context.lineSegments[context.ils].pB.x = p.lineSegments[i].pB.x;
      context.lineSegments[context.ils].pB.y = p.lineSegments[i].pB.y;
      context.ils++;
    }
  }

  l = p.ia;
  for(i=0;i<l;i++) {
    // no need to check in arcs
    // there can be many arcs with the same center
    // radii don't matter
    // No names for arcs so this is not required
    context.arcs[context.ia].center.label = p.arcs[i].center.label;
    context.arcs[context.ia].center.x = p.arcs[i].center.x;
    context.arcs[context.ia].center.y = p.arcs[i].center.y;
    context.arcs[context.ia].radius = p.arcs[i].radius;
    context.ia++;
  }

  l = p.iln;
  for(i=0;i<l;i++) {
    if(existsLine(p.lines[i].label)) {
      // Line has only a label, if label exists
      // Then line exists, do nothing
      ;
    } else {
      context.lines[context.iln].label = p.lines[i].label;
      context.iln++;
    }
  }

  l = p.ic;
  for(i=0;i<l;i++) {
    // Similar to arcs, no need to check in circles
    context.circles[context.ic].center.label = p.circles[i].center.label;
    context.circles[context.ic].center.x = p.circles[i].center.x;
    context.circles[context.ic].center.y = p.circles[i].center.y;
    context.circles[context.ic].radius = p.circles[i].radius;
    context.ic++;
  }

  l = p.ian;
  for(i=0;i<l;i++) {
    char angle[3];
    angle[0] = p.angles[i].vertex.label;
    angle[1] = p.angles[i].leftVertex.label;
    angle[2] = p.angles[i].rightVertex.label;
    if(existsAngle(angle)) {
      Angle X = getAngle(angle);
      assert(compareAngles(X, p.angles[i]));
    } else {
      context.angles[context.ian].vertex.label = p.angles[i].vertex.label;
      context.angles[context.ian].vertex.x = p.angles[i].vertex.x;
      context.angles[context.ian].vertex.y = p.angles[i].vertex.y;
      context.angles[context.ian].leftVertex.label = p.angles[i].leftVertex.label;
      context.angles[context.ian].leftVertex.x = p.angles[i].leftVertex.x;
      context.angles[context.ian].leftVertex.y = p.angles[i].leftVertex.y;
      context.angles[context.ian].rightVertex.label = p.angles[i].rightVertex.label;
      context.angles[context.ian].rightVertex.x = p.angles[i].rightVertex.x;
      context.angles[context.ian].rightVertex.y = p.angles[i].rightVertex.y;
      context.angles[context.ian].degree = p.angles[i].degree;
      context.ian++;
    }
  }
}

void writeDiff(Plottables p) {
  int i;
  FILE* f = fopen(diffFilename, "w");
  fprintf(f, "~POINTS\n");
  int l = p.ip;
  for(i=0;i<l;i++) {
    if(!existsPoint(p.points[i])){
     fprintf(f, "%c %lf %lf\n", p.points[i].label, p.points[i].x, p.points[i].y);
    }
  }
  fprintf(f, "~LINESEGMENTS\n");
  l = p.ils;
  for(i=0;i<l;i++) {
    if(!existsLineSegmentLabel(p.lineSegments[i].pA.label, p.lineSegments[i].pB.label)){
     fprintf(f, "%c %c\n", p.lineSegments[i].pA.label, p.lineSegments[i].pB.label);
    }
  }
  fprintf(f, "~LINES\n");
  l = p.iln;
  for(i=0;i<l;i++) {
    fprintf(f, "%c\n", p.lines[i].label);
  }
  fprintf(f, "~ARCS\n");
  l = p.ia;
  for(i=0;i<l;i++) {
    if(!existsArc(p.arcs[i])){
     fprintf(f, "%c %lf\n", p.arcs[i].center.label, p.arcs[i].radius);
    }
  }
  fprintf(f, "~ANGLE\n");
  l = p.ian;
  for(i=0;i<l;i++) {
    if(!existsAngleLabel(p.angles[i].leftVertex.label, p.angles[i].vertex.label, p.angles[i].rightVertex.label)){
     fprintf(f, "%c %c %c %lf\n", p.angles[i].vertex.label, p.angles[i].leftVertex.label, p.angles[i].rightVertex.label, p.angles[i].degree);
    }
  }
  fprintf(f, "~CIRCLE\n");
  l = p.ic;
  for(i=0;i<l;i++) {
    if(!existsCircle(p.circles[i])){
     fprintf(f, "%c %lf\n", p.circles[i].center.label, p.circles[i].radius);
    }
  }
  fclose(f);
}

void writeContext() {
  int i;
  FILE* f = fopen(contextFilename, "w");
  fprintf(f, "~POINTS\n");
  int l = context.ip;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf %lf\n", context.points[i].label, context.points[i].x, context.points[i].y);
  }
  fprintf(f, "~LINESEGMENTS\n");
  l = context.ils;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %c\n", context.lineSegments[i].pA.label, context.lineSegments[i].pB.label);
  }
  fprintf(f, "~LINES\n");
  l = context.iln;
  for(i=0;i<l;i++) {
    fprintf(f, "%c\n", context.lines[i].label);
  }
  fprintf(f, "~ARCS\n");
  l = context.ia;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf\n", context.arcs[i].center.label, context.arcs[i].radius);
  }
  fprintf(f, "~ANGLE\n");
  l = context.ian;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %c %c %lf\n", context.angles[i].vertex.label, context.angles[i].leftVertex.label, context.angles[i].rightVertex.label, context.angles[i].degree);
  }
  fprintf(f, "~CIRCLE\n");
  l = context.ic;
  for(i=0;i<l;i++) {
    fprintf(f, "%c %lf\n", context.circles[i].center.label, context.circles[i].radius);
  }
  fclose(f);
}

bool existsPoint(Point p){
  return existsPointLabel(p.label);
}

bool existsPointLabel(char label) {
  int i;
  int l = context.ip;
  bool found=false;
  for(i=0;i<l;i++) {
    if(context.points[i].label == label){
      found = true;
      break;
    }
  }
  return found;
}

bool existsCircle(Circle c) {
  char center = c.center.label;
  double radius = c.radius;
  int i;
  int l = context.ic;
  bool found = false;
  for(i=0;i<l;i++) {
    if(context.circles[i].center.label == center && context.circles[i].radius == radius) {
      found = true;
      break;
    }
  }
  return found;
}

bool existsArc(Arc a) {
  char center = a.center.label;
  double radius = a.radius;
  int i;
  int l = context.ia;
  bool found = false;
  for(i=0;i<l;i++) {
    if(context.arcs[i].center.label == center && context.arcs[i].radius == radius) {
      found = true;
      break;
    }
  }
  return found;
}

bool existsLineSegment(char pointpair[]){
  return existsLineSegmentLabel(pointpair[0], pointpair[1]);
}

bool existsLineSegmentLabel(char point1Label, char point2Label) {
  int i;
  int l=context.ils;
  for(i=0;i<l;i++) {
    if( (context.lineSegments[i].pA.label == point1Label && context.lineSegments[i].pB.label == point2Label) || (context.lineSegments[i].pA.label == point2Label && context.lineSegments[i].pB.label == point1Label) )
      return true;
  }
  return false;
}

bool existsLine(char name) {
  int i;
  int l = context.iln;
  for(i=0;i<l;i++) {
    if(context.lines[i].label == name)
      return true;
  }
  return false;
}

bool existsLastAngle(){
  return context.ian != 0 ? true : false;
}

bool existsLastPoint(){
  return context.ip != 0 ? true : false;
}

bool existsAngleLabel(char leftVertex, char vertex, char rightVertex){
 char name[3];
 name[0] = leftVertex;
 name[1] = vertex;
 name[2] = rightVertex;
 return existsAngle(name);
}

bool existsAngle(char name[]) {
  int i;
  int l = context.ian;
  for(i=0;i<l;i++) {
    if( (context.angles[i].vertex.label == name[1]) && ( (context.angles[i].rightVertex.label == name[0] && context.angles[i].leftVertex.label == name[2]) || (context.angles[i].leftVertex.label == name[2] && context.angles[i].rightVertex.label == name[0]) ) )
      return true;
    if( (context.angles[i].vertex.label == name[1]) && ( (context.angles[i].rightVertex.label == name[2] && context.angles[i].leftVertex.label == name[0]) || (context.angles[i].leftVertex.label == name[2] && context.angles[i].rightVertex.label == name[0]) ) )
      return true;
  }
  return false;
}

LineSegment getLineSegment(char pointpair[]){
  return getLineSegmentLabel(pointpair[0], pointpair[1]);
}

LineSegment getLineSegmentLabel(char point1Label, char point2Label) {
  int i;
  int l=context.ils;
  for(i=0;i<l;i++) {
    if( (context.lineSegments[i].pA.label == point1Label && context.lineSegments[i].pB.label == point2Label) || (context.lineSegments[i].pA.label == point2Label && context.lineSegments[i].pB.label == point1Label) )
      return context.lineSegments[i];
  }
  LineSegment l1;
  return l1;
}

Line getLine(char name) {
  int i;
  int l = context.iln;
  for(i=0;i<l;i++) {
    if(context.lines[i].label == name)
      return context.lines[i];
  }
  Line l1;
  return l1;
}

Angle getAngle(char name[]) {
  int i;
  int l = context.ian;
  for(i=0;i<l;i++) {
    if( (context.angles[i].vertex.label == name[1]) && ( (context.angles[i].rightVertex.label == name[0] && context.angles[i].leftVertex.label == name[2]) || (context.angles[i].leftVertex.label == name[2] && context.angles[i].rightVertex.label == name[0]) ) )
      return context.angles[i];
  }
  Angle a;
  return a;
}
    
Point getPointAtPosition(int i) {
  assert(i<context.ip && i >=0);
  return context.points[i];
}

LineSegment getLineSegmentAtPosition(int i) {
  assert(i<context.ils && i >=0);
  return context.lineSegments[i];
}
    
Point getLastPoint(){
  assert(context.ip > 0);
  return context.points[context.ip-1];
}

Point getSecondLastPoint(){
  assert(context.ip > 1);
  return context.points[context.ip-2];
}
    
int getNumberOfPoints() {
  return context.ip;
}

int getNumberOfArcs() {
  return context.ia;
}

LineSegment getLastLineSegment() {
  assert(context.ils > 0);
  return context.lineSegments[context.ils-1];
}

LineSegment getSecondLastLineSegment() {
  assert(context.ils > 1);
  return context.lineSegments[context.ils-2];
}

Line getLastLine() {
  assert(context.iln > 0);
  return context.lines[context.iln-1];
}

Line getSecondLastLine() {
  assert(context.iln > 1);
  return context.lines[context.iln-2];
}

Arc getLastArc(){
  assert(context.ia > 0);
  return context.arcs[context.ia-1];
}


Arc getSecondLastArc(){
  assert(context.ia > 1);
  return context.arcs[context.ia-2];
}

Arc getArcAtPosition(int i) {
  assert(i<context.ia && i >=0);
  return context.arcs[i];
}

Circle getLastCircle(){
  assert(context.ic > 0);
  return context.circles[context.ic-1];
}

Circle getSecondLastCircle(){
  assert(context.ic > 1);
  return context.circles[context.ic-2];
}

Circle getCircleAtPosition(int i) {
  assert(i<context.ic && i >=0);
  return context.circles[i];
}
    
Angle getLastAngle() {
  assert(context.ian > 0);
  return context.angles[context.ian-1];
}

Angle getSecondLastAngle() {
  assert(context.ian > 1);
  return context.angles[context.ian-2];
}
    
Length* getLastLength() {
  Length *ls = (Length*)malloc(sizeof(Length));
  ls->length = context.lengths[context.ilg-1].length;
  return ls;
}
  
bool existsLastLineSegment(){
  return context.iln!=0 ?true :false;
}

char reserveNextPointLabel(){
  int i, flags[26];
  
  for(i=0; i<26; i++) flags[i] = 0;
  for(i=0; i<context.ip; i++){
	  flags[ (int) (context.points[i].label - 'A')] = 1;
  }
  
  for(i=0; i<26; i++){
	  if(flags[i] == 0){
		//this label has not been used in context
		return (char)(i+'A');
	  }
  }
  
  //return random label in case we are out of labels
  srand(time(NULL));
  return (char)((rand() % 26) + 'A');
}

void LineSegmentCopy(LineSegment ls, LineSegment *l) {
  l->pA.label = ls.pA.label;
  l->pA.x = ls.pA.x;
  l->pA.y = ls.pA.y;
  l->pB.label = ls.pB.label;
  l->pB.x = ls.pB.x;
  l->pB.y = ls.pB.y;
  l->length = ls.length;
}

double getLength(Length l) {
  return l.length;
}

void setLength(Condition *c, double l) {
  c->length = l;
}

void printPlottable(Plottables p) {
  printf("----------Plottable Begin---------\n");
  
  printf("Type: %d, Class: %d, Singleton:%d\n", p.type, p.class, p.singleton);
  
  int i;
  printf("Points: ");
  for(i=0;i<p.ip;i++) {
    printf("%c(%lf,%lf) ", p.points[i].label, p.points[i].x, p.points[i].y);
  }
  printf("\n");
  printf("LineSegments: ");
  for(i=0;i<p.ils;i++) {
    printf("%c%c ", p.lineSegments[i].pA.label, p.lineSegments[i].pB.label);
  }
  printf("\n");
  printf("Angles: ");
  for(i=0;i<p.ian;i++) {
    printf("%c%c%c(%lf) ", p.angles[i].leftVertex.label, p.angles[i].vertex.label, p.angles[i].rightVertex.label, p.angles[i].degree);
  }
  printf("\n");
  printf("Arcs: ");
  for(i=0;i<p.ia;i++) {
    printf("%c(%lf) ", p.arcs[i].center.label, p.arcs[i].radius);
  }
  printf("\n");
  printf("Lines: ");
  for(i=0;i<p.iln;i++) {
    printf("%c ", p.lines[i].label);
  }
  printf("\n");
  printf("Circles: ");
  for(i=0;i<p.ic;i++) {
    printf("%c(%lf) ", p.circles[i].center.label, p.circles[i].radius);
  }
  printf("\n");
  printf("----------Plottable End---------\n");
}

void printContext() {
  printf("----------Context Begin---------\n");
  int i;
  printf("Points: ");
  for(i=0;i<context.ip;i++) {
    printf("%c(%lf,%lf) ", context.points[i].label, context.points[i].x, context.points[i].y);
  }
  printf("\n");
  printf("LineSegments: ");
  for(i=0;i<context.ils;i++) {
    printf("%c%c ", context.lineSegments[i].pA.label, context.lineSegments[i].pB.label);
  }
  printf("\n");
  printf("Angles: ");
  for(i=0;i<context.ian;i++) {
    printf("%c%c%c(%lf) ", context.angles[i].leftVertex.label, context.angles[i].vertex.label, context.angles[i].rightVertex.label, context.angles[i].degree);
  }
  printf("\n");
  printf("Arcs: ");
  for(i=0;i<context.ia;i++) {
    printf("%c(%lf) ", context.arcs[i].center.label, context.arcs[i].radius);
  }
  printf("\n");
  printf("Lines: ");
  for(i=0;i<context.iln;i++) {
    printf("%c ", context.lines[i].label);
  }
  printf("\n");
  printf("Circles: ");
  for(i=0;i<context.ic;i++) {
    printf("%c(%lf) ", context.circles[i].center.label, context.circles[i].radius);
  }
  printf("\n");
  printf("----------Context End---------\n");
}

int getNumLineSegments() {
  return context.ils;
}

int getNumPoints() {
  return context.ip;
}

int getNumArcs() {
  return context.ia;
}

int getNumCircles() {
  return context.ic;
}
