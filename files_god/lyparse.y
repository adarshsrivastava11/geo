%{	
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "./context.h"
#include "./aux.h"
#include "./lylib.h"
#include "./history.h"
#define true 1
#define false 0
#define PDEBUG 1
  
  int yyerror(char* s){
    printf("ERROR: %s\n", s);
    return 0;
  }
  int yyparse(void);
  int yylex(void);
  int yydebug = 1;

  double epsilon = 1.0;

%}

%union{		//union declared to store the $$ = value of tokens
  int ival;
  char* sval;
  double dval;
  struct _Command* command;
  struct _Plottables* plottables;
  struct _Length* length;
  struct _Degree* degree;
  struct _Angle* angle;
  struct _Operation* operation;
  struct _LineSegment* lineSegment;
  struct _VecLineSegments* vecLineSegments;
  struct _VecLengths* vecLengths;
  struct _Line* line;
  struct _Condition* condition;
  struct _Point* point;
  struct _VecPoints* vecPoints;
  struct _VecArcs* vecArcs;
  struct _VecStrings* vecStrings;
  struct _String* string;
  struct _Circle * circle;
  //  struct _Object * object;
  struct _Cut *cut;
  struct _Arc *arc;
  struct _Intersection *intersection;
  struct _Parallelization *parallelization;
  struct _Perpendicularization *perpendicularization;
  struct _Location *location;
  void* voidPtr;
  
 }
//tokentypes for different tokens
%token <ival> INTEGER_T KEYWORD_T
%token <dval> REAL_T
%token <sval> POINTSINGLET_T POINTPAIR_T POINTTRIPLET_T LINELABEL_T

%type <sval> POINTSINGLET POINTPAIR POINTTRIPLET LINELABEL
%type <ival> INTEGER
%type <dval> REAL

%token <voidPtr> CONSTRUCT_T LENGTH_T CM_T FROM_T THIS_T CUT_T GIVEN_T THAT_T TWICE_T EQUALS_T LINE_T SEGMENT_T DIFFERENCE_T AND_T CENTER_T ANY_T RADIUS_T ARC_T INTERSECTING_T AT_T TWO_T POINTS_T CENTERS_T GREATER_T THAN_T ARCS_T CUTTING_T EACHOTHER_T JOIN_T SAME_T POINT_T ON_T OTHER_T SIDE_T DRAW_T MARK_T IT_T NOT_T CIRCLE_T HALF_T ITS_T INTERSECTION_T PREVIOUS_T BISECTOR_T DIVIDE_T INTO_T PARTS_T DIAMETER_T ANGLE_T VERTEX_T ARM_T THEIR_T RAYS_T ORIGIN_T PASSING_T THROUGH_T MEASURE_T DEGREES_T RIGHT_T BISECT_T PERPENDICULAR_T TO_T CHORD_T BISECTORS_T CHORDS_T THESE_T OUTSIDE_T PARALLEL_T DISTANCE_T TRIANGLE_T EQUILATERAL_T ISOSCELES_T EQUAL_T SIDES_T BETWEEN_T THEM_T ANGLED_T DEGREE_T HYPOTENUSE_T FIRSTLEG_T RAY_T SUM_T BASE_T ALONG_T QUADRILATERAL_T SQUARE_T AS_T MAKING_T EACH_T OF_T ANGLES_T CIRCLES_T CONVENIENT_T DIVITDE_T HAS_T INITIAL_T INTERSECTIONS_T INTERSECT_T IS_T LABEL_T LESS_T LINES_T MINUS_T ORTHOGONAL_T SEGMENTS_T THOSE_T THRICE_T TIMES_T

%type <ival> numChords;
%start command
%type <length> addressLength addressLength1 addressLength2 addressLength3 distanceFromCenterClause
%type <degree> addressDegree addressDegree1 addressDegree2 addressDegree3
%type <angle> addressAngle addressAngleRays
%type <operation> operation
%type <command> command constructCommand markCommand cutCommand joinCommand divideCommand bisectCommand

%type <plottables> constructibleAndProperties lineSegmentAndProperties lineAndProperties arcAndProperties circleAndProperties angleAndProperties rayAndProperties perpendicularBisectorAndProperties bisectorAndProperties perpendicularAndProperties parallelAndProperties genericAngleAndProperties rightAngleAndProperties bisectableAndProperties cuttableAndProperties angleArmPointsAndProperties markableAndProperties divisibleAndProperties chordAndProperties arcProperties pointAndProperties intersectionPointsAndProperties arcsProperties arcsAndProperties

%type <lineSegment> addressLineSegment divisibleObject addressChord

%type < vecLineSegments > addressChords addressPerpendicularBisectableObjects

%type <length> lineSegmentProperties radiusClause
%type <vecLengths> radiiClause

%type <vecStrings> addressPointPairs

%type <line> addressLine

%type <condition> conditions condition

%type <point> addressPoint originClause centerClause passingThroughClause
%type < vecPoints > centersClause mutualIntersectionClause


%type <circle> addressCircle
%type <vecArcs> addressArc

%type <plottables> objects intersectableObjects object intersectableObject addressIndefinitePreviousObjects addressPreviousObjects addressIntersectablePreviousObjects

%type <cut> fromClause atPoints

%type <intersection> labelable pointAndPropertiesNotOnCase pointAndPropertiesOnCase addressIntersectableObject intersectionClause addressIntersectingObject

%type <parallelization> parallelConditionClause parallelToClause

%type <perpendicularization> perpendicularConditionClause perpendicularToClause


%type <location> markConditionClause

%type <voidPtr> LENGTH TIMES CM GREATERTHAN LESSTHAN TWICE THRICE HALF GIVENTHAT CONSTRUCT adjectiveFree ANGLE ANY ARC ARCS ARM AT BISECT BISECTOR BISECTORS CENTER CENTERS CHORD CHORDS CIRCLE CIRCLES CUT DEGREES DIAMETER DISTANCE DISTANCEFROM DIVIDE EACHOTHER EQUALS FREEVARIABLE FROM INTERSECTING INTERSECTIONPOINTS INTO IT ITS JOIN LINE LINES LINESEGMENT LINESEGMENTS MARK NOTON ON ORIGIN PARALLEL PARTS PASSINGTHROUGH PERPENDICULAR PERPENDICULARBISECTOR PERPENDICULARBISECTORS POINT POINTS PREVIOUS previousDegree previousLength RADIUS RAY RAYS RIGHT THEIR THEM THESE THIS THOSE VERTEX DIFFERENCE SUM adjectivePrevious



%%	
addressLength :
    addressLength3  {
                      $$ = $1;
                    }
  | addressLength2  {
                      $$ = $1;
                    }
  | addressLength1  {
                      $$ = $1;
                    }
;

addressLength1 :
    REAL CM         {
                      Length* length = newLength();
                      length->length = $1;
                      $$ = length;
                    }
  | REAL            {
                      Length* length = newLength();
                      length->length = $1;
                      $$ = length;                      
                    }
  | INTEGER CM      {
                      Length* length = newLength();
                      length->length = (double)$1;
                      $$ = length;
                    }
  | INTEGER         {
                      Length* length = newLength();
                      length->length = (double)$1;
                      $$ = length;                      
                    }
  | FREEVARIABLE    {
                      Length* length = newLength();
                      length->length = 4;//generate random number here
                      $$ = length;                                            
                    }
  | previousLength  {
                      Length* length = newLength();
                      Length* ll = getLastLength();
                      length->length = ll->length;
                      $$ = length;
                    }
  | LENGTH addressLineSegment
                    {
                      //assert(existsLineSegmentLabel($2->pA.label, $2->pB.label));                      
                      Length* length = newLength();
                      length->length = $2->length;
                      $$ = length;
                    }
  | addressLineSegment
                    {
                      //assert(existsLineSegmentLabel($1->pA.label, $1->pB.label));
                      Length* length = newLength();
                      length->length = $1->length;
                      $$ = length;
                    }
;

addressLength2 :
    GREATERTHAN addressLength1
                    {
                      Length* length = newLength();
                      length->length = epsilon + $2->length;
                      $$ = length;
                    }    
  | LESSTHAN addressLength1
                    {
                      Length* length = newLength();
                      length->length = -epsilon + $2->length;
                      $$ = length;                    }    
  | TWICE addressLength1
                    {
                      Length* length = newLength();
                      length->length = $2->length * 2;
                      $$ = length;
                    }      
  | THRICE addressLength1
                    {
                      Length* length = newLength();
                      length->length = $2->length * 3;
                      $$ = length;
                    }        
  | REAL TIMES addressLength1
                    {
                      Length* length = newLength();
                      length->length = $3->length * $1;
                      $$ = length;
                    }        
  | INTEGER TIMES addressLength1
                    {
                      Length* length = newLength();
                      length->length = $3->length * $1;
                      $$ = length;
                    }
  | HALF addressLength1
                    {
                      Length* length = newLength();
                      length->length = $2->length * 0.5;
                      $$ = length;
                    }        
  | operation addressLength1 addressLength1
                    {
                      double result = getResult($1, $2->length, $3->length);
                      Length* length = newLength();
                      length->length = result;
                      $$ = length;
                    }
;

addressLength3 :
    GREATERTHAN addressLength2
                    {
                      Length* length = newLength();
                      length->length = epsilon + $2->length;
                      $$ = length;
                    }    
  | LESSTHAN addressLength2
                    {
                      Length* length = newLength();
                      length->length = -epsilon + $2->length;
                      $$ = length;                    }    
  | TWICE addressLength2
                    {
                      Length* length = newLength();
                      length->length = $2->length * 2;
                      $$ = length;
                    }      
  | THRICE addressLength2
                    {
                      Length* length = newLength();
                      length->length = $2->length * 3;
                      $$ = length;
                    }        
  | REAL TIMES addressLength2
                    {
                      Length* length = newLength();
                      length->length = $3->length * $1;
                      $$ = length;
                    }        
  | INTEGER TIMES addressLength2
                    {
                      Length* length = newLength();
                      length->length = $3->length * $1;
                      $$ = length;
                    }        
  | HALF addressLength2
                    {
                      Length* length = newLength();
                      length->length = $2->length * 0.5;
                      $$ = length;
                    }        
  | operation addressLength2 addressLength2
                    {
                      double result = getResult($1, $2->length, $3->length);
                      Length* length = newLength();
                      length->length = result;
                      $$ = length;
                    }
;

addressDegree :
    addressDegree3  { $$ = $1; }
  | addressDegree2  { $$ = $1; }
  | addressDegree1  { $$ = $1; }
;

addressDegree1 :
    REAL DEGREES    {
                      Degree *degree = newDegree();
                      degree->degree = $1;
                      $$ = degree;
                    }
  | REAL            {
                      Degree *degree = newDegree();
                      degree->degree = $1;
                      $$ = degree;
                    }
  | INTEGER         {
                      Degree *degree = newDegree();
                      degree->degree = $1;
                      $$ = degree;
                    }
  | INTEGER DEGREES {
                      Degree *degree = newDegree();
                      degree->degree = $1;
                      $$ = degree;
                    }                    
  | FREEVARIABLE    {
                      Degree *degree = newDegree();
                      degree->degree = 30;
                      $$ = degree;
                    }
  | previousDegree  {
                      assert(existsLastAngle());
                      Angle la = getLastAngle();
                      Degree *degree = newDegree();
                      degree->degree = la.degree;
                      $$ = degree;
                    }
  | addressAngle    {
		      char name[3];
		      name[0] = $1->leftVertex.label;
		      name[1] = $1->vertex.label;
		      name[2] = $1->rightVertex.label;
		      assert(existsAngle(name));
                      Degree *degree = newDegree();
                      degree->degree = $1->degree;
                      $$ = degree;
                    }
;

addressDegree2 :
    GREATERTHAN addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = epsilon + $2->degree;
                      $$ = degree;
                    }        
  | LESSTHAN addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = -epsilon + $2->degree;
                      $$ = degree;
                    }        
  | TWICE addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 2;
                      $$ = degree;
                    }          
  | THRICE addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 3;
                      $$ = degree;
                    }            
  | REAL TIMES addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = $3->degree * $1;
                      $$ = degree;
                    }          
  | INTEGER TIMES addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = $3->degree * $1;
                      $$ = degree;
                    }          
  | HALF addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 0.5;
                      $$ = degree;
                    }          
  | operation addressDegree1 addressDegree1
                    {
                      Degree* degree = newDegree();
                      degree->degree = getResult($1, $2->degree, $3->degree);
                      $$ = degree;
                    }
;

addressDegree3 :
    GREATERTHAN addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = epsilon + $2->degree;
                      $$ = degree;
                    }        
  | LESSTHAN addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = -epsilon + $2->degree;
                      $$ = degree;
                    }        
  | TWICE addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 2;
                      $$ = degree;
                    }          
  | THRICE addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 3;
                      $$ = degree;
                    }            
  | REAL TIMES addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = $3->degree * $1;
                      $$ = degree;
                    }   
  | INTEGER TIMES addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = $3->degree * $1;
                      $$ = degree;
                    }                               
  | HALF addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = $2->degree * 0.5;
                      $$ = degree;
                    }          
  | operation addressDegree2 addressDegree2
                    {
                      Degree* degree = newDegree();
                      degree->degree = getResult($1, $2->degree, $3->degree);
                      $$ = degree;
                    }
;

TIMES :
    TIMES_T   { $$ = NULL;  }
;

HALF :
    HALF_T    { $$ = NULL;  }
;

GREATERTHAN :
    GREATER_T THAN_T  { $$ = NULL;  }
;

LESSTHAN :
    LESS_T THAN_T     { $$ = NULL;  }
;

command :
    constructCommand  { $$ = $1; executeCommand(*$1); }
  | markCommand       { $$ = $1; executeCommand(*$1); }
  | cutCommand        { $$ = $1; executeCommand(*$1); }
  | joinCommand       { $$ = $1; executeCommand(*$1); }
  | divideCommand     { $$ = $1; executeCommand(*$1); }
  | bisectCommand     { $$ = $1; executeCommand(*$1); }
;

constructCommand : 
  CONSTRUCT constructibleAndProperties
                      {
                        Command *command = newCommand();
                        command->plottables = *$2;
                        $$ = command;
                      }
;

CONSTRUCT :
    CONSTRUCT_T       { $$ = NULL;  }
  | DRAW_T            { $$ = NULL;  }
;

constructibleAndProperties : 
    lineSegmentAndProperties  { $$ = $1;  }
  | lineAndProperties         { $$ = $1;  }
  | arcAndProperties          { $$ = $1;  }
  | arcsAndProperties         { $$ = $1;  }
  | circleAndProperties       { $$ = $1;  }
  | angleAndProperties        { $$ = $1;  }
  | rayAndProperties          { $$ = $1;  }
  | perpendicularBisectorAndProperties  { $$ = $1;  }
  | bisectorAndProperties       { $$ = $1;  }
  | perpendicularAndProperties  { $$ = $1;  }
  | chordAndProperties          { $$ = $1;  }
  | parallelAndProperties       { $$ = $1;  }
;

lineSegmentAndProperties : 
    LINESEGMENT addressLineSegment GIVENTHAT conditions
      {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = $4->ls;
        LineSegment thisLineSegment = *$2;
        if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){
          spitError("line segment not same");
        }
        
        $2->length = $4->length;
	if(!existsPoint($2->pA)){
	  if(!existsPoint($2->pB)){
	    //default position is (0,0)
	    $2->pA.x = $2->pA.y = 0.0;
	    $2->pB.x = $2->length;
	    $2->pB.y = 0.0;
	  } else {
	    $2->pA.x = $2->pB.x - $2->length;
	    $2->pA.y = $2->pB.y;
	  }
	} else {
	  if(!existsPoint($2->pB)){
	    $2->pB.x = $2->pA.x + $2->length;
	    $2->pB.y = $2->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *$2);
        $$ = p;
      }
  | LINESEGMENT addressLineSegment lineSegmentProperties
      {
        Plottables *p = newPlottables(); 
        $2->length = $3->length;
        
	if(!existsPoint($2->pA)){
	  if(!existsPoint($2->pB)){
	    //default position is (0,0)
	    $2->pA.x = $2->pA.y = 0.0;
	    $2->pB.x = $2->length;
	    $2->pB.y = 0.0;
	  } else {
	    $2->pA.x = $2->pB.x - $2->length;
	    $2->pA.y = $2->pB.y;
	  }
	} else {
	  if(!existsPoint($2->pB)){
	    $2->pB.x = $2->pA.x + $2->length;
	    $2->pB.y = $2->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *$2);
        $$ = p;
      }
  | LINESEGMENT addressLineSegment perpendicularToClause perpendicularConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }
  | LINESEGMENT addressLineSegment parallelToClause parallelConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }
  | LINESEGMENT GIVENTHAT conditions
      {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = $3->ls;
        /* LineSegment thisLineSegment = *$2; */
        /* if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){ */
        /*   spitError("line segment not same"); */
        /* } */
        
	LineSegment *thisLineSegment = newLineSegment();
	thisLineSegment->length = $3->length;
	thisLineSegment->pA.label = reserveNextPointLabel();
	thisLineSegment->pB.label = reserveNextPointLabel();
	if(!existsPoint(thisLineSegment->pA)){
	  if(!existsPoint(thisLineSegment->pB)){
	    //default position is (0,0)
	    thisLineSegment->pA.x = thisLineSegment->pA.y = 0.0;
	    thisLineSegment->pB.x = thisLineSegment->length;
	    thisLineSegment->pB.y = 0.0;
	  } else {
	    thisLineSegment->pA.x = thisLineSegment->pB.x - thisLineSegment->length;
	    thisLineSegment->pA.y = thisLineSegment->pB.y;
	  }
	} else {
	  if(!existsPoint(thisLineSegment->pB)){
	    thisLineSegment->pB.x = thisLineSegment->pA.x + thisLineSegment->length;
	    thisLineSegment->pB.y = thisLineSegment->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *thisLineSegment);
	free(thisLineSegment);
        $$ = p;
      }
  | LINESEGMENT lineSegmentProperties
      {
        Plottables *p = newPlottables(); 
	LineSegment *thisLineSegment = newLineSegment();
        thisLineSegment->length = $2->length;
	thisLineSegment->pA.label = reserveNextLineLabel();
	thisLineSegment->pB.label = reserveNextLineLabel();
        
	if(!existsPoint(thisLineSegment->pA)){
	  if(!existsPoint(thisLineSegment->pB)){
	    //default position is (0,0)
	    thisLineSegment->pA.x = thisLineSegment->pA.y = 0.0;
	    thisLineSegment->pB.x = thisLineSegment->length;
	    thisLineSegment->pB.y = 0.0;
	  } else {
	    thisLineSegment->pA.x = thisLineSegment->pB.x - thisLineSegment->length;
	    thisLineSegment->pA.y = thisLineSegment->pB.y;
	  }
	} else {
	  if(!existsPoint(thisLineSegment->pB)){
	    thisLineSegment->pB.x = thisLineSegment->pA.x + thisLineSegment->length;
	    thisLineSegment->pB.y = thisLineSegment->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *thisLineSegment);
	free(thisLineSegment);
        $$ = p;
      }
  | LINESEGMENT perpendicularToClause perpendicularConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }
  | LINESEGMENT parallelToClause parallelConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }
  | addressLineSegment GIVENTHAT conditions
      {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = $3->ls;
        LineSegment thisLineSegment = *$1;
        if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){
          spitError("line segment not same");
        }
        
        $1->length = $3->length;
	if(!existsPoint($1->pA)){
	  if(!existsPoint($1->pB)){
	    //default position is (0,0)
	    $1->pA.x = $1->pA.y = 0.0;
	    $1->pB.x = $1->length;
	    $1->pB.y = 0.0;
	  } else {
	    $1->pA.x = $1->pB.x - $1->length;
	    $1->pA.y = $1->pB.y;
	  }
	} else {
	  if(!existsPoint($1->pB)){
	    $1->pB.x = $1->pA.x + $1->length;
	    $1->pB.y = $1->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *$1);
        $$ = p;
      }
  | addressLineSegment lineSegmentProperties
      {
        Plottables *p = newPlottables(); 
        $1->length = $2->length;
        
	if(!existsPoint($1->pA)){
	  if(!existsPoint($1->pB)){
	    //default position is (0,0)
	    $1->pA.x = $1->pA.y = 0.0;
	    $1->pB.x = $1->length;
	    $1->pB.y = 0.0;
	  } else {
	    $1->pA.x = $1->pB.x - $1->length;
	    $1->pA.y = $1->pB.y;
	  }
	} else {
	  if(!existsPoint($1->pB)){
	    $1->pB.x = $1->pA.x + $1->length;
	    $1->pB.y = $1->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *$1);
        $$ = p;
      }
  | addressLineSegment perpendicularToClause perpendicularConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }
  | addressLineSegment parallelToClause parallelConditionClause
      {
        Plottables *p = newPlottables();
        //not implemented now
        $$ = p;
      }

;

conditions :
    condition   { $$ = $1;  }
;

condition :
    EQUALS LENGTH addressLineSegment addressLength
      {
        Condition *c = newCondition();
        setLineSegment(c, *$3);
        c->length = $4->length;
      }
  | EQUALS addressLineSegment addressLength
      {
        Condition *c = newCondition();
	setLineSegment(c, *$2);
	c->length = $3->length;
      }
  | EQUALS addressAngle addressAngle
      {
        Condition *c = newCondition();
	if($2->degree != 0) {
	  c->angle = *$3;
	  c->degree = $2->degree;
	} else {
	  c->angle = *$2;
	  c->degree = $3->degree;
	}
      }  
;

GIVENTHAT :
    GIVEN_T THAT_T    { $$ = NULL;  }
  | GIVEN_T           { $$ = NULL;  }
;

LINESEGMENT :
  LINE_T SEGMENT_T    { $$ = NULL;  }
;

lineSegmentProperties : 
    LENGTH addressLength  { $$ = $2;  }
  | addressLength         { $$ = $1;  }
;

LENGTH :
  LENGTH_T            { $$ = NULL;  }
;

CM :
  CM_T                { $$ = NULL;  }
;

addressLineSegment :
    LINESEGMENT POINTPAIR
      {
        LineSegment* ls = newLineSegment();
		char lineSeg[2];
		lineSeg[0] = yylval.sval[0];
		lineSeg[1] = yylval.sval[1];
        if(existsLineSegment(lineSeg)){
          *ls = getLineSegment(lineSeg);
        } else {
		  ls->pA.label = lineSeg[0];
		  ls->pB.label = lineSeg[1];
		  bool existA=false, existB=false;
		  if(existsPoint(ls->pA)) {
			ls->pA = getPoint(ls->pA.label);
			existA = true;
		  } 
		  if(existsPoint(ls->pB)) {
			ls->pB = getPoint(ls->pB.label);
			existB = true;
		  }
		  if(existA && existB){
			ls->length = getDistance(ls->pA, ls->pB);
		  }
		}
		$$ = ls;
      }
  | POINTPAIR
      {
        LineSegment *ls = newLineSegment();
		char lineSeg[2];
		lineSeg[0] = yylval.sval[0];
		lineSeg[1] = yylval.sval[1];
        if(existsLineSegment(lineSeg)){
          *ls = getLineSegment(lineSeg);
        } else {
		  ls->pA.label = lineSeg[0];
		  ls->pB.label = lineSeg[1];
		  bool existA=false, existB=false;
		  if(existsPoint(ls->pA)) {
			ls->pA = getPoint(ls->pA.label);
			existA = true;
		  } 
		  if(existsPoint(ls->pB)) {
			ls->pB = getPoint(ls->pB.label);
			existB = true;
		  }
		  if(existA && existB){
			ls->length = getDistance(ls->pA, ls->pB);
		  }
        }
        $$ = ls;
      }
  | adjectivePrevious LINESEGMENT
      {
        assert(existsLastLineSegment());
        LineSegment ls = getLastLineSegment();
        //TODO: $$ = the last segment present in the context
        LineSegment *l = newLineSegment();
	// Copies attributes from ls to *l
	LineSegmentCopy(ls, l);
        $$ = l;
      }  
  | adjectiveFree LINESEGMENT
      {
        //assert(existsLastLineSegment());
        //LineSegment ls = getLastLineSegment();
        //TODO: $$ = the last segment present in the context
        LineSegment *l = newLineSegment();
	//LineSegmentCopy(ls, l);
	//This does not mean the last drawn line segment
        $$ = l;
      }  
;

angleAndProperties :
    genericAngleAndProperties   { $$ = $1; }
  | rightAngleAndProperties     { $$ = $1; }
;

genericAngleAndProperties :
    ANGLE VERTEX addressPoint addressDegree
      {
        Plottables *p = newPlottables();

        char c1 = reserveNextPointLabel();
        char c2 = reserveNextPointLabel();

	assert(!existsPoint(*$3));
	Angle* angle = newAngle();
	angle->vertex = *$3;
	angle->leftVertex.label = c1;
	angle->rightVertex.label = c2;
	angle->degree = $4->degree;

	//command is like "construct angle O of 34 degrees"
	//default position is origin
	angle->vertex.x = angle->vertex.y = 0.0;
	angle->rightVertex.x = 0.0 + DEFAULT_ANGLE_ARM_LENGTH;
	angle->rightVertex.y = 0.0;

	angle->leftVertex.x = DEFAULT_ANGLE_ARM_LENGTH*cos((angle->degree)*DEGREES_TO_RADIANS);
	angle->rightVertex.y = DEFAULT_ANGLE_ARM_LENGTH*sin((angle->degree)*DEGREES_TO_RADIANS);

	updatePlottablesAngle(p, *angle);
        $$ = p;
      
      }
    
  | ANGLE addressAngle addressDegree
      {
        Plottables *p = newPlottables();
	//e.g. angle ABC

	if(!existsPoint($2->vertex)){
	  //default place is origin
	  $2->vertex.x = $2->vertex.y = 0.0;
	}

	$2->degree = $3->degree;
	if(!existsPoint($2->leftVertex) && existsPoint($2->rightVertex)){
	  //A doesn't exist but C exists
	  double deltax = $2->rightVertex.x - $2->vertex.x;
	  double deltay = $2->rightVertex.y - $2->vertex.y;
	  double base_slope;//angle subtended by BA on X-axis
	  if(abs(deltax) <= FLOAT_EPSILON){//avoid division by zero
	    if(deltay >= FLOAT_EPSILON){
	      base_slope = 90.0 * DEGREES_TO_RADIANS;
	    }else{
	      base_slope = -90.0 * DEGREES_TO_RADIANS;
	    }
	  }else{
	    base_slope = atan2(deltay, deltax);
	  }

	  double this_slope = base_slope + ($2->degree) * DEGREES_TO_RADIANS ;
	  $2->rightVertex.x = $2->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  $2->rightVertex.y = $2->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);
	}else if(existsPoint($2->leftVertex) && !existsPoint($2->rightVertex)){
	  //C doesn't exist but A exists
	  double deltax = $2->leftVertex.x - $2->vertex.x;
	  double deltay = $2->leftVertex.y - $2->vertex.y;
	  double base_slope;//angle subtended by BA on X-axis
	  if(abs(deltax) <= FLOAT_EPSILON){//avoid division by zero
	    if(deltay >= FLOAT_EPSILON){
	      base_slope = 90.0 * DEGREES_TO_RADIANS;
	    }else{
	      base_slope = -90.0 * DEGREES_TO_RADIANS;
	    }
	  }else{
	    base_slope = atan2(deltay, deltax);
	  }

	  double this_slope = base_slope - ($2->degree) * DEGREES_TO_RADIANS ;
	  $2->rightVertex.x = $2->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  $2->rightVertex.y = $2->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);

	}else if(!existsPoint($2->leftVertex) && !existsPoint($2->rightVertex)){
	  //Both A and C don't exist
	  double base_slope = 0.0 * DEGREES_TO_RADIANS;//angle subtended by BA on X-axis
	  $2->rightVertex.x = $2->vertex.x + DEFAULT_ANGLE_ARM_LENGTH;
	  $2->rightVertex.y = $2->vertex.y;

	  double this_slope = base_slope + ($2->degree) * DEGREES_TO_RADIANS ;
	  $2->leftVertex.x = $2->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  $2->leftVertex.y = $2->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);
	}else{
	  //all vertices exist, may be fishy
	}

	updatePlottablesAngle(p, *$2);
        $$ = p;
      }
  | ANGLE addressDegree
      {
        Plottables *p = newPlottables();

        char c1 = reserveNextPointLabel();
        char c2 = reserveNextPointLabel();
	Point vertex = *newPoint();
	vertex.label = reserveNextPointLabel();	

	//assert(!existsPoint(*$3));
	Angle* angle = newAngle();
	angle->vertex = vertex;
	angle->leftVertex.label = c1;
	angle->rightVertex.label = c2;
	angle->degree = $2->degree;

	//command is like "construct angle of 34 degrees"
	//default position is origin
	angle->vertex.x = angle->vertex.y = 0.0;
	angle->rightVertex.x = 0.0 + DEFAULT_ANGLE_ARM_LENGTH;
	angle->rightVertex.y = 0.0;

	angle->leftVertex.x = DEFAULT_ANGLE_ARM_LENGTH*cos((angle->degree)*DEGREES_TO_RADIANS);
	angle->rightVertex.y = DEFAULT_ANGLE_ARM_LENGTH*sin((angle->degree)*DEGREES_TO_RADIANS);

	updatePlottablesAngle(p, *angle);
        $$ = p;
      
      }
;

rightAngleAndProperties :
    RIGHT ANGLE VERTEX addressPoint
      {
	Plottables *p = newPlottables();

	Angle *a = newAngle();
	a->vertex = *$4;
	a->vertex.x = a->vertex.y = 0.0;
	a->leftVertex.x = 0.0;
	a->leftVertex.y = DEFAULT_ANGLE_ARM_LENGTH;
	a->rightVertex.x = DEFAULT_ANGLE_ARM_LENGTH;
	a->rightVertex.y = 0.0;
	a->leftVertex.label = reserveNextPointLabel();
	a->rightVertex.label = reserveNextPointLabel();
	a->degree = 90.0;

	updatePlottablesAngle(p, *a);

        $$ = p;
      }    
  | RIGHT ANGLE addressAngle
      {
	Plottables *p = newPlottables();
	
	bool existsLeftVertex = existsPoint($3->leftVertex),
	  existsRightVertex = existsPoint($3->rightVertex);

	$3->degree = 90.0;
	if(!existsPoint($3->vertex)){
	  $3->vertex.x = $3->vertex.y = 0.0;
	} else {
	  $3->vertex = getPoint($3->vertex.label);
	}

	if(!existsLeftVertex && !existsRightVertex){
	  $3->rightVertex.x = $3->vertex.x + DEFAULT_ANGLE_ARM_LENGTH;
	  $3->rightVertex.y = $3->vertex.y;
	  existsRightVertex = true;
	}

	if(existsLeftVertex && !existsRightVertex){
	  double ldeltax = $3->leftVertex.x - $3->vertex.x,
	    ldeltay = $3->leftVertex.y - $3->vertex.y;
	  double lvslope;
	  if(abs(ldeltax) <= FLOAT_EPSILON){
	    if(ldeltay >= FLOAT_EPSILON) lvslope = 90.0;
	    else lvslope = -90.0;
	  } else {
	    lvslope = atan2(ldeltay, ldeltax) * RADIANS_TO_DEGREES;
	  }

	  double rvslope = lvslope - 90.0;

	  $3->rightVertex.x = $3->vertex.x
	    + DEFAULT_ANGLE_ARM_LENGTH*cos(rvslope * DEGREES_TO_RADIANS);
	  $3->rightVertex.y = $3->vertex.y
	    + DEFAULT_ANGLE_ARM_LENGTH*sin(rvslope * DEGREES_TO_RADIANS);

	} else if(!existsLeftVertex && existsRightVertex){
	  double rdeltax = $3->rightVertex.x - $3->vertex.x,
	    rdeltay = $3->rightVertex.y - $3->vertex.y;
	  double rvslope;
	  if(abs(rdeltax) <= FLOAT_EPSILON){
	    if(rdeltay >= FLOAT_EPSILON) rvslope = 90.0;
	    else rvslope = -90.0;
	  } else {
	    rvslope = atan2(rdeltay, rdeltax) * RADIANS_TO_DEGREES;
	  }

	  double lvslope = rvslope + 90.0;

	  $3->leftVertex.x = $3->vertex.x
	    + DEFAULT_ANGLE_ARM_LENGTH*cos(lvslope * DEGREES_TO_RADIANS);
	  $3->leftVertex.y = $3->vertex.y
	    + DEFAULT_ANGLE_ARM_LENGTH*sin(lvslope * DEGREES_TO_RADIANS);
	  
	} else {
	  //both points exist, may be fishy
	}
	
	updatePlottablesAngle(p, *$3);
	$$ = p;

      }  
;

RIGHT :
    RIGHT_T               { $$ = NULL;  }
; 

VERTEX :
    VERTEX_T              { $$ = NULL;  }
;

ANGLE :
    ANGLE_T               { $$ = NULL;  }
;

addressAngle :
    ANGLE POINTTRIPLET
      {
	Angle* na = newAngle();
	char leftVertex = yylval.sval[0],
	  vertex = yylval.sval[1],
	  rightVertex = yylval.sval[2];

	na->leftVertex.label = leftVertex;
	na->vertex.label = vertex;
	na->rightVertex.label = rightVertex;
	
	bool leftVertexExists = false, rightVertexExists = false,
	  vertexExists = false;
	if(existsPointLabel(leftVertex)){
	  na->leftVertex = getPoint(leftVertex);
	  leftVertexExists = true;
	}
	if(existsPointLabel(vertex)){
	  na->vertex = getPoint(vertex);
	  vertexExists = true;
	}
	if(existsPointLabel(rightVertex)){
	  na->rightVertex = getPoint(rightVertex);
	  rightVertexExists = true;
	}

	if(leftVertexExists && rightVertexExists && vertexExists){
	  double ldeltax = na->leftVertex.x - na->vertex.x;
	  double ldeltay = na->leftVertex.y - na->vertex.y;
	  double lv_slope;
	  if(abs(ldeltax) <= FLOAT_EPSILON){
	    if(ldeltay >= FLOAT_EPSILON) lv_slope = 90.0 * DEGREES_TO_RADIANS;
	    else lv_slope = -90.0 * DEGREES_TO_RADIANS;
	  } else {
	    lv_slope = atan2(ldeltax, ldeltay);
	  }

	  double rdeltax = na->rightVertex.x - na->vertex.x;
	  double rdeltay = na->rightVertex.y - na->vertex.y;
	  double rv_slope;
	  if(abs(rdeltax) <= FLOAT_EPSILON){
	    if(rdeltay >= FLOAT_EPSILON) rv_slope = 90.0 * DEGREES_TO_RADIANS;
	    else rv_slope = -90.0 * DEGREES_TO_RADIANS;
	  } else {
	    rv_slope = atan2(rdeltax, rdeltay);
	  }

	  na->degree = (lv_slope - rv_slope) * RADIANS_TO_DEGREES;

	}

        $$ = na;
      }    
  | POINTTRIPLET
      {
	Angle* na = newAngle();
	char leftVertex = yylval.sval[0],
	  vertex = yylval.sval[1],
	  rightVertex = yylval.sval[2];

	na->leftVertex.label = leftVertex;
	na->vertex.label = vertex;
	na->rightVertex.label = rightVertex;
	
	bool leftVertexExists = false, rightVertexExists = false,
	  vertexExists = false;
	if(existsPointLabel(leftVertex)){
	  na->leftVertex = getPoint(leftVertex);
	  leftVertexExists = true;
	}
	if(existsPointLabel(vertex)){
	  na->vertex = getPoint(vertex);
	  vertexExists = true;
	}
	if(existsPointLabel(rightVertex)){
	  na->rightVertex = getPoint(rightVertex);
	  rightVertexExists = true;
	}

	if(leftVertexExists && rightVertexExists && vertexExists){
	  double ldeltax = na->leftVertex.x - na->vertex.x;
	  double ldeltay = na->leftVertex.y - na->vertex.y;
	  double lv_slope;
	  if(abs(ldeltax) <= FLOAT_EPSILON){
	    if(ldeltay >= FLOAT_EPSILON) lv_slope = 90.0 * DEGREES_TO_RADIANS;
	    else lv_slope = -90.0 * DEGREES_TO_RADIANS;
	  } else {
	    lv_slope = atan2(ldeltax, ldeltay);
	  }

	  double rdeltax = na->rightVertex.x - na->vertex.x;
	  double rdeltay = na->rightVertex.y - na->vertex.y;
	  double rv_slope;
	  if(abs(rdeltax) <= FLOAT_EPSILON){
	    if(rdeltay >= FLOAT_EPSILON) rv_slope = 90.0 * DEGREES_TO_RADIANS;
	    else rv_slope = -90.0 * DEGREES_TO_RADIANS;
	  } else {
	    rv_slope = atan2(rdeltax, rdeltay);
	  }

	  na->degree = (lv_slope - rv_slope) * RADIANS_TO_DEGREES;

	}

        $$ = na;
      }
  | adjectivePrevious ANGLE
      {
       if(!existsLastAngle()){
         spitError("No previous angle");
       }
       Angle *a = newAngle();
       *a = getLastAngle();
       $$ = a;
      }      
;

DEGREES :
    DEGREE_T              { $$ = NULL;  }
  | DEGREES_T             { $$ = NULL;  }
; 

circleAndProperties : 
    CIRCLE CENTER addressPoint RADIUS addressLength
      {
	Plottables *p = newPlottables();
	Circle c;
	c.center = *$3;
	if(!existsPoint(c.center)){
	  c.center.x = c.center.y = 0.0;
	}
	c.radius = $5->length;
	updatePlottablesCircle(p, c);

        $$ = p;
      }        
  | CIRCLE CENTER addressPoint DIAMETER addressLength
      {
	Plottables *p = newPlottables();
	Circle c;
	c.center = *$3;
	if(!existsPoint(c.center)){
	  c.center.x = c.center.y = 0.0;
	}
	c.radius = 0.5 * ($5->length);
	updatePlottablesCircle(p, c);

        $$ = p;	
      }      
  | CIRCLE RADIUS addressLength
      {
	Plottables *p = newPlottables();
	Circle c;
	c.center.label = reserveNextPointLabel();
	c.center.x = c.center.y = 0.0;
	c.radius = ($3->length);
	updatePlottablesCircle(p, c);

        $$ = p;	
      }      
  | CIRCLE DIAMETER addressLength
      {
	Plottables *p = newPlottables();
	Circle c;
	c.center.label = reserveNextPointLabel();
	c.center.x = c.center.y = 0.0;
	c.radius = 0.5 * ($3->length);
	updatePlottablesCircle(p, c);

        $$ = p;	
      }    
;

CIRCLE :
  CIRCLE_T                  { $$ = NULL;  }
;

LINE :
    LINE_T                  { $$ = NULL;  }
;

lineAndProperties : 
    LINE [a-z] perpendicularToClause perpendicularConditionClause
      {
        $$ = newPlottables();
      }    
  | LINE [a-z] parallelToClause parallelConditionClause
      {
        $$ = newPlottables();
      }    
  | LINE [a-z]
      {
        $$ = newPlottables();
      }      
;

arcsAndProperties :
  ARCS arcsProperties
    {
      $$ = $2;
    }
;

ARCS :
    ARCS_T
;

arcsProperties :
    centersClause radiiClause mutualIntersectionClause
      {
	Plottables *p = newPlottables();
	Arc a,b;
	
	a.center = $1->points[0];
	a.radius = $2->lengths[0].length;

	updatePlottablesArc(p, a);
  printf("%lf %lf\n", a.center.x, a.center.y);
	b.center = $1->points[1];
	b.radius = $2->lengths[1].length;
  printf("%lf %lf\n", b.center.x, b.center.y);
	updatePlottablesArc(p, b);

	Point pA = getArcArcIntersection(a,b,true);
  printf("%lf %lf\n", pA.x, pA.y);
	pA.label = $3->points[0].label;
	updatePlottablesPoint(p, pA);
	if($3->n >= 2){
	  //if both the intersection points are to be marked
	  Point pB = getArcArcIntersection(a,b,false);
	  pB.label = $3->points[1].label;
	  updatePlottablesPoint(p, pB);
	}

	$$ = p;
      }
  |  centersClause radiiClause
      {
	Plottables *p = newPlottables();
	Arc a,b;
	
	a.center = $1->points[0];
	a.radius = $2->lengths[0].length;

	updatePlottablesArc(p, a);
  printf("%lf %lf\n", a.center.x, a.center.y);
	b.center = $1->points[1];
	b.radius = $2->lengths[1].length;
  printf("%lf %lf\n", b.center.x, b.center.y);
	updatePlottablesArc(p, b);

	$$ = p;
      }
;


arcAndProperties :
  ARC arcProperties
      {
        $$ = $2;
      }    
  
;

ARC :
    ARC_T                     { $$ = NULL;  }
;

arcProperties :
    centerClause radiusClause intersectionClause
      {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *$1;
	a.radius = $2->length;
	updatePlottablesArc(p, a);
	Point in = getArcIntersectableIntersection(a, *$3, true);
	in.label = $3->p1->label;
	updatePlottablesPoint(p, in);

	if($3->p2 != NULL){
	  //the other intersection point is also to be marked
	  Point in2 = getArcIntersectableIntersection(a, *$3, false);
	  in2.label = $3->p2->label;
	  updatePlottablesPoint(p, in2);
	}

	$$ = p;
      }
  | centerClause radiusClause
      {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *$1;
	a.radius = $2->length;
	updatePlottablesArc(p, a);
	$$ = p;
      }
  | centerClause passingThroughClause
      {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *$1;
	a.radius = getDistance(*$1, *$2);
	updatePlottablesArc(p, a);
	$$ = p;
      }  
;

passingThroughClause :
    PASSINGTHROUGH addressPoint
      {
	$$ = $2;
      }    
;

PASSINGTHROUGH :
    PASSING_T THROUGH_T         { $$ = NULL;  }
  | THROUGH_T                   { $$ = NULL;  }
;

mutualIntersectionClause :
    INTERSECTING EACHOTHER AT POINTSINGLET POINTSINGLET
      {
	assert(!existsPointLabel($4[0]));
	assert(!existsPointLabel($5[0]));
	VecPoints *vec = newVectorPoints();

	Point a,b;
	a.label = $4[0];
	b.label = $5[0];
	vec->points[vec->n++] = a;
	vec->points[vec->n++] = b;
	
	$$ = vec;
      }    
  | INTERSECTING AT POINTSINGLET POINTSINGLET
      {
	assert(!existsPointLabel($3[0]));
	assert(!existsPointLabel($4[0]));
	VecPoints *vec = newVectorPoints();

	Point a,b;
	a.label = $3[0];
	b.label = $4[0];
	vec->points[vec->n++] = a;
	vec->points[vec->n++] = b;
	
	$$ = vec;
      }    
  | INTERSECTING EACHOTHER AT POINTSINGLET
      {
	assert(!existsPointLabel($4[0]));

	VecPoints *vec = newVectorPoints();
	Point a;
	a.label = $4[0];
	vec->points[vec->n++] = a;
	$$ = vec;
      }      
  | INTERSECTING AT POINTSINGLET
      {
	assert(!existsPointLabel($3[0]));

	VecPoints *vec = newVectorPoints();
	Point a;
	a.label = $3[0];
	vec->points[vec->n++] = a;
	$$ = vec;
      }      
;

centerClause :
    CENTER POINTSINGLET
      {
	Point *p = newPoint();
	p->label = $2[0];
	if(existsPointLabel(p->label)){
	  *p = getPoint(p->label);
	} else {
	  p->x = p->y = 0.0;
	}
	$$ = p;
      }        
;

centersClause :
    CENTERS POINTSINGLET POINTSINGLET
      {
	VecPoints *vec = newVectorPoints();
	Point a,b;
	a.label = $2[0];
	if(existsPoint(a)){
	  a = getPoint(a.label);
	} else {
	  printf("Point %c does not exist\n", a.label);
	  spitError("No such point(s) exist(s)\n");
	}

	b.label = $3[0];
	if(existsPoint(b)){
	  b = getPoint(b.label);
	} else {
	  printf("Point %c does not exist\n", a.label);
	  spitError("No such point(s) exist(s)\n");
	}

	vec->points[vec->n++]= a;
	vec->points[vec->n++]= b;
        $$ = vec;
      }        
;

radiusClause :
    RADIUS addressLength
      {
	$$ = $2;
      }        
;

radiiClause :
    RADIUS addressLength addressLength
      {
	VecLengths *vec = newVectorLengths();
	
	vec->lengths[vec->n] = *$2;
	vec->n++;
	vec->lengths[vec->n] = *$3;
	vec->n++;

	$$ = vec;
      }        
;

intersectionClause :
    INTERSECTING addressIntersectableObject AT POINTSINGLET POINTSINGLET
      {
	Point *pA = newPoint(),
	  *pB = newPoint();
	pA->label = $4[0];
	pB->label = $5[0];
	$2->p1 = pA;
	$2->p2 = pB;
	$$ = $2;
      }        
  | INTERSECTING addressIntersectableObject AT POINTSINGLET
      {
	Point *pA = newPoint();
	pA->label = $4[0];
	$2->p1 = pA;
	$$ = $2;
      }      
;

addressIntersectableObject :
    addressLineSegment
      {      
	Intersection *i = newIntersection();
	i->ls1 = $1;
	$$ = i;
      }          
  | addressLine
      {
	Intersection *i = newIntersection();
	i->l1 = $1;
	$$ = i;
      }        
  | addressArc
      {
	Intersection *i = newIntersection();
	i->a1 = &($1->arcs[0]);
	if($1->n >=2){
	  i->a2 = &($1->arcs[1]);
	}
	$$ = i;
      }        
  | addressCircle
      {
	Intersection *i = newIntersection();
	i->c1 = $1;
	$$ = i;
      }        
  | addressAngleRays
      {
	Intersection *i = newIntersection();
	//i->r1 = $1;
	$$ = i;
      }        
;

addressAngleRays :
    RAYS ANGLE addressAngle
      {
	$$ = $3;
      }          
;

CENTER :
  CENTER_T                  { $$ = NULL;  }
;

RADIUS :
  RADIUS_T                  { $$ = NULL;  }
;

DIAMETER :
  DIAMETER_T                  { $$ = NULL;  }
;

INTERSECTING :
    INTERSECTING_T                  { $$ = NULL;  }
  | CUTTING_T                  { $$ = NULL;  }
  | CUT_T                  { $$ = NULL;  }
  | INTERSECT_T                  { $$ = NULL;  }
;

EACHOTHER :
    EACHOTHER_T                  { $$ = NULL;  }
  | EACH_T OTHER_T                  { $$ = NULL;  }
;

CENTERS :
    CENTERS_T                  { $$ = NULL;  }
;

AT :
    AT_T                  { $$ = NULL;  }
;

rayAndProperties :
    RAY POINTPAIR originClause
      {
	$$ = newPlottables();
      }          
  | RAYS POINTPAIR POINTPAIR originClause
      {
	$$ = newPlottables();
      }          
  | RAY POINTPAIR
      {
	$$ = newPlottables();
      }            
  | RAYS POINTPAIR POINTPAIR
      {
	$$ = newPlottables();
      }            
;

originClause :
    ORIGIN addressPoint
      {
	$$ = newPoint();
      }              
;

ORIGIN :
    ORIGIN_T                  { $$ = NULL;  }
  | INITIAL_T POINT_T                  { $$ = NULL;  }
;

RAY :
    RAY_T                  { $$ = NULL;  }
;

RAYS :
    RAYS_T                  { $$ = NULL;  }
;

perpendicularBisectorAndProperties :
    PERPENDICULARBISECTOR addressPerpendicularBisectableObjects
      {
	Plottables *p = newPlottables();
	LineSegment ls = $2->lineSegments[0];
	LineSegment pb = getPerpendicularBisector(ls);
  printPoint(pb.pA);
  printPoint(pb.pB);
	updatePlottablesLineSegment(p, pb);
	$$ = p;
      }
  | PERPENDICULARBISECTORS addressPerpendicularBisectableObjects addressPerpendicularBisectableObjects
      {
	$$ = newPlottables();
      }
  | PERPENDICULARBISECTOR addressIndefinitePreviousObjects
      {
 resolvePlottables($2);
	Plottables *p = newPlottables();
	LineSegment pb = getPerpendicularBisectorPlottable(*$2);
	updatePlottablesLineSegment(p, pb);
	$$ = p;
      }  
  | PERPENDICULARBISECTORS addressIndefinitePreviousObjects
      {
	$$ = newPlottables();
      }  
;

addressPerpendicularBisectableObjects :
    addressLineSegment
      {
	VecLineSegments *vec =  newVectorLineSegments();
	vec->lineSegments[0] = *$1;
	vec->n++;
	$$ = vec;
      }
  | addressChord
    {
	$$ = newVectorLineSegments();
    }
  | addressChords
    {
	$$ = $1;
    }  
;

addressChord :
    adjectivePrevious CHORD
      {
	$$ = newLineSegment();
      }
;

addressChords :
    adjectivePrevious CHORDS
      {
	$$ = newVectorLineSegments();
      }
;

PERPENDICULARBISECTOR :
    PERPENDICULAR_T BISECTOR_T           { $$ = NULL;  }
;

bisectorAndProperties :
    BISECTOR addressLineSegment
      {
	$$ = newPlottables();
      }
  | BISECTOR addressAngle
      {
	Plottables *p = newPlottables();
	LineSegment ab = getAngleBisector(*$2);
	updatePlottablesLineSegment(p, ab);
	$$ = p;
      }  
  | BISECTOR addressIndefinitePreviousObjects
      {
	Plottables *p = newPlottables();
	Angle a = getLastAngle();
	LineSegment ab = getAngleBisector(a);
	updatePlottablesLineSegment(p, ab);
	$$ = p;
      }  
;

parallelToClause :
    PARALLEL addressLineSegment
      {
	Parallelization *par =  newParallelization();
	par->ls = $2;
	$$ = par;
      }    
  | PARALLEL addressLine
      {
	Parallelization *par =  newParallelization();
	par->l = $2;
	$$ = par;
      }      
;

perpendicularToClause :
    PERPENDICULAR addressLineSegment
      {
	Perpendicularization *per = newPerpendicularization();
	per->ls = $2;
	$$ = per;
      }
  | PERPENDICULAR addressLine
      {
	Perpendicularization *per = newPerpendicularization();
	per->l = $2;
        $$ = per;
      }
;

perpendicularAndProperties :
    perpendicularToClause perpendicularConditionClause
      {
	LineSegment ls;
	Plottables *p = newPlottables();

	if($2->passingThroughPoint != NULL){
	  ls = getPerpendicularPassingThrough(*($1->ls), *($2->passingThroughPoint));
	} else {
	  ls = getPerpendicularAt(*($1->ls), *($2->atPoint));
	}

	updatePlottablesLineSegment(p, ls);

        $$ = p;
      }
;

PERPENDICULAR :
    PERPENDICULAR_T                  { $$ = NULL;  }
  | ORTHOGONAL_T                  { $$ = NULL;  }
;

perpendicularConditionClause :
    AT addressPoint
      {
	Perpendicularization *per = newPerpendicularization();
	per->atPoint = $2;
	$$ = per;
      }
  | passingThroughClause
      {
	Perpendicularization *per = newPerpendicularization();
	per->passingThroughPoint = $1;
	$$ = per;
      }  
;

chordAndProperties :
    CHORD addressCircle
      {
	$$ = newPlottables();
      }
  | CHORD addressCircle distanceFromCenterClause
      {
	$$ = newPlottables();
      }
  | CHORDS addressCircle numChords
      {
	$$ = newPlottables();  
      }
  | CHORD addressIndefinitePreviousObjects
      {
	$$ = newPlottables();  
      }  
  | CHORD addressIndefinitePreviousObjects distanceFromCenterClause
      {
	$$ = newPlottables();  
      }  
  | CHORDS addressIndefinitePreviousObjects numChords
      {
	$$ = newPlottables();  
      }  
;

distanceFromCenterClause :
    DISTANCE addressLength FROM CENTER
      {	
	$$ = $2;
      }
;

DISTANCE :
    DISTANCE_T                  { $$ = NULL;  }
;

numChords :
    INTEGER			{ $$ = yylval.ival; }
;

PARALLEL :
    PARALLEL_T                  { $$ = NULL;  }
;

parallelAndProperties :
    parallelToClause parallelConditionClause
      {
		LineSegment ls;
		Plottables *p = newPlottables();

		if($2->passingThroughPoint != NULL){
		  ls = getParallelPassingThrough(*($1->ls), *($2->passingThroughPoint));
		} else {
		  assert(0);
		}
		
		updatePlottablesLineSegment(p, ls);

		$$ = p;
      }
;

parallelConditionClause :
    AT addressPoint
      {
		Parallelization *par =  newParallelization();
		par->passingThroughPoint = $2;
		$$ = par;
	}    
  | passingThroughClause
      {
		Parallelization *par =  newParallelization();
		par->passingThroughPoint = $1;
		$$ = par;
      }  

;

divideCommand :
    DIVIDE divisibleAndProperties
      {
	Command *command = newCommand();
	command->plottables = *$2;
	$$ = command;
      }
;

DIVIDE :
    DIVITDE_T                  { $$ = NULL;  }
;

divisibleAndProperties :
    divisibleObject INTO INTEGER PARTS
      {
	// $$ = newPlottables();
	LineSegment lS = *$1;
	Plottables *p = newPlottables();
	int number = $3;
	double slope = getSlope(lS.pA, lS.pB);
	double distance = getDistance(lS.pA, lS.pB);
	int i;
	for(i=0;i<number;i++) {
	  Point P1 = locatePoint(lS.pA, slope, (distance*(i+1))/number);
	  P1.label = reserveNextPointLabel();
	  updatePlottablesPoint(p, P1);
	}
	$$=p;
      }
;

PARTS :
  PARTS_T                  { $$ = NULL;  }
;

INTO :
  INTO_T                  { $$ = NULL;  }
;

divisibleObject :
    addressLineSegment
      {
	// $$ = newLineSegment();
	$$ = $1;
      }
  | addressIndefinitePreviousObjects
      {
	$$ = newLineSegment();
	//Jeetesh
      }  
;

joinCommand : 
  JOIN addressPointPairs
      {
	Command *c = newCommand();
	Plottables *p = newPlottables();

	int i;
	for(i = 0; i < $2->n; i++){
	  char* pp = $2->strings[i];
	  LineSegment ls;
	  ls.pA = getPoint(pp[0]);
	  ls.pB = getPoint(pp[1]);
	  updatePlottablesLineSegment(p, ls);
	}

	c->plottables = *p;
	$$ = c;
      }  
;

JOIN :
  JOIN_T                  { $$ = NULL;  }
;

addressPointPairs : 
    POINTPAIR
      {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = $1;
	$$ = vec;
      }    
  | POINTPAIR POINTPAIR
      {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = $1;
	vec->strings[vec->n++] = $2;
	$$ = vec;
      }    
  | POINTPAIR POINTPAIR POINTPAIR
      {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = $1;
	vec->strings[vec->n++] = $2;
	vec->strings[vec->n++] = $3;
	$$ = vec;
      }    
  | adjectivePrevious POINTS
      {
	VecStrings *vec = newVectorStrings();
	int num = getNumberOfPoints();
	char* arr = (char*)malloc(sizeof(char)*3);
	arr[0] = getPointAtPosition(num-1).label;
	arr[1] = getPointAtPosition(num-2).label;
	arr[2] = '\0';
	vec->strings[vec->n++] = arr;
	$$ = vec;
      }      
;

markCommand :
    MARK markableAndProperties
      {
	Command *c = newCommand();
	c->plottables = *$2;
	$$ = c;
      }        
;

MARK : 
    MARK_T                  { $$ = NULL;  }
  | DRAW_T                  { $$ = NULL;  }
  | LABEL_T                  { $$ = NULL;  }
;

markableAndProperties :
    intersectionPointsAndProperties
      {
	$$ = $1;
      }        
  | pointAndProperties
      {
	$$ = $1;
      }        
  | angleArmPointsAndProperties
      {
	$$ = $1;
      }          
;

angleArmPointsAndProperties :
    POINT POINTSINGLET ON ARM addressAngle POINTSINGLET ON ARM addressAngle
      {
	$$ = newPlottables();
      }            
;

ARM :
  ARM_T                  { $$ = NULL;  }
;

intersectionPointsAndProperties : 
    INTERSECTIONPOINTS addressIntersectingObject addressIntersectingObject addressPoint addressPoint
      {
	Plottables *p = newPlottables();
	Point p1 = getIntersectableIntersectableIntersection(*$2, *$3, true);
	p1.label = $4->label;
	Point p2 = getIntersectableIntersectableIntersection(*$2, *$3, false);
	p2.label = $5->label;
	updatePlottablesPoint(p, p1);
	updatePlottablesPoint(p, p2);
	$$ = p;
      }            
  | INTERSECTIONPOINTS addressIntersectingObject addressIntersectingObject addressPoint
      {
	Plottables *p = newPlottables();
	printf("Interection 1\n");
	printIntersection(*$2);
	printf("Interection 2\n");
	printIntersection(*$3);
	Point p1 = getIntersectableIntersectableIntersection(*$2, *$3, true);
	p1.label = $4->label;
	updatePlottablesPoint(p, p1);
  printf("%c %lf %lf\n", p->points[0].label, p->points[0].x, p->points[0].y);
	$$ = p;
      }              
  | INTERSECTIONPOINTS addressIntersectablePreviousObjects addressPoint addressPoint
      {    
 resolvePlottables($2);
	Intersection *l = getIntersectionFromPlottables(*$2);
	Point p1 = getIntersectableIntersection(*l, true);
	Point p2 = getIntersectableIntersection(*l, false);	
 Plottables *p = newPlottables();
	p1.label = $3->label;
	updatePlottablesPoint(p, p1);
	p2.label = $4->label;
	updatePlottablesPoint(p, p2);
	$$ = p;
      }       
  | INTERSECTIONPOINTS addressIntersectablePreviousObjects addressPoint
      {    
 resolvePlottables($2);
	Intersection *l = getIntersectionFromPlottables(*$2);
	Point p1 = getIntersectableIntersection(*l, false);
	p1.label = $3->label;
 Plottables *p = newPlottables();
	updatePlottablesPoint(p, p1);
	$$ = p;
      }              
;

INTERSECTIONPOINTS :
    INTERSECTION_T POINTS_T                  { $$ = NULL;  }
  | INTERSECTION_T POINT_T                  { $$ = NULL;  }
  | INTERSECTION_T                  { $$ = NULL;  }
  | INTERSECTIONS_T                  { $$ = NULL;  }
;

addressIntersectingObject : 
    addressArc
      {
	Intersection *i = newIntersection();
	i->a1 = &($1->arcs[0]);
	$$ = i;
      }                
  | addressCircle
      {
	Intersection *i = newIntersection();
	i->c1 = $1;
	$$ = i;
      }              
  | addressLine
      {
	$$ = newIntersection();
      }              
  | addressLineSegment
      {
	Intersection *i = newIntersection();
	i->ls1 = $1;
	$$ = i;
      }              
  | addressPreviousObjects
      {
 $1->class = INTERSECTABLE_D;
 resolvePlottables($1);
	$$ = getIntersectionFromPlottables(*$1);
      }              
;

pointAndProperties : 
    addressPoint pointAndPropertiesNotOnCase
      {
	Plottables *p = newPlottables();
	Point pt = getPointNotOnLabelable(*$2, NULL);
	pt.label = $1->label;
	updatePlottablesPoint(p, pt);
	$$ = p;
      }                
  | addressPoint pointAndPropertiesOnCase markConditionClause
      {
	Plottables *p = newPlottables();
	Point pt = getPointOnLabelable(*$2, $3);
	pt.label = $1->label;
	updatePlottablesPoint(p, pt);
	$$ = p;
      }              
  | addressPoint pointAndPropertiesOnCase  
      {
	Plottables *p = newPlottables();
	Point pt = getPointOnLabelable(*$2, NULL);
	pt.label = $1->label;
	updatePlottablesPoint(p, pt);
	$$ = p;
      }
  | addressPoint
    {
     Plottables *p = newPlottables();
     $1->x = (rand() % DEFAULT_LINE_SEGMENT_LENGTH)
      -(DEFAULT_LINE_SEGMENT_LENGTH/2);
     $1->y = (rand() % DEFAULT_LINE_SEGMENT_LENGTH)
      -(DEFAULT_LINE_SEGMENT_LENGTH/2);
     updatePlottablesPoint(p, *$1);
     $$ = p;
    
    }
;

markConditionClause :
    DISTANCEFROM addressPoint addressLength
      {
	Location *l = newLocation();
	l->distance = $3->length;
	l->fromPoint = *$2;
	$$ = l;
      }                
;

DISTANCEFROM :
    DISTANCE_T FROM_T                  { $$ = NULL;  }
;

pointAndPropertiesOnCase :
    ON labelable
      {
	$$ = $2;
      }                
;

pointAndPropertiesNotOnCase :
    NOTON labelable
      {
	$$ = $2;
      }                
;

ON :
  ON_T                  { $$ = NULL;  }
;

NOTON :
    NOT_T ON_T                  { $$ = NULL;  }
  | OUTSIDE_T                  { $$ = NULL;  }
;

labelable :
    addressLineSegment
      {
	Intersection *i = newIntersection();
	i->ls1 = $1;
	$$ = i;
      }                
  | addressArc
      {
	Intersection *i = newIntersection();
	i->a1 = &($1->arcs[0]);
	$$ = i;
 
      }              
  | addressLine
      {
	Intersection *i = newIntersection();
	i->l1 = $1;
	$$ = i;
      }              
  | addressPreviousObjects
      {
    $1->class = LABELABLE_D;
    resolvePlottables($1);
    Intersection *i = getIntersectionFromPlottables(*$1);
    $$ = i;
      }              
;

addressLine :
    LINELABEL
      {
	Line *l = newLine();
	l->label = $1[0];
	$$ = l;
      }                  
  | LINE LINELABEL
      {
	Line *l = newLine();
	l->label = $2[0];
	$$ = l;
      }               
  | adjectivePrevious LINE
      {
	Line *l = newLine();
	*l = getLastLine();
	$$ = l;
      }                 
  | adjectiveFree LINE
      {
	Line *l = newLine();
	l->label = reserveNextLineLabel();
	$$ = l;
      }                 
;

addressArc :
    adjectivePrevious ARC
      {
	VecArcs *vec = newVectorArcs();
	vec->arcs[vec->n++] = getLastArc();
	$$ = vec;
      }                 
  | adjectivePrevious ARCS
      {
	VecArcs *vec = newVectorArcs();
	int num = getNumberOfArcs();
	vec->arcs[vec->n++] = getArcAtPosition(num-1);
	vec->arcs[vec->n++] = getArcAtPosition(num-2);
	$$ = vec;
      }                   
;

adjectivePrevious :
    THIS		
  | THESE
  | PREVIOUS
  | THOSE
;

addressIntersectablePreviousObjects :
   THIS intersectableObject
   {
    $2->class = INTERSECTABLE_D;
    $$ = $2;
   }
 | THESE intersectableObjects
   {
    $2->class = INTERSECTABLE_D;
    $$ = $2;
   }
 | PREVIOUS intersectableObject
   {
    $2->class = INTERSECTABLE_D;
    $$ = $2;
   }  
 | PREVIOUS intersectableObjects
   {
    $2->class = INTERSECTABLE_D;
    $$ = $2;
   }  
 | THOSE intersectableObjects
   {
    $2->class = INTERSECTABLE_D;
    $$ = $2;
   }  
 | addressIndefinitePreviousObjects
   {
    $1->class = INTERSECTABLE_D;
    $$ = $1;
   }  
;

addressPreviousObjects :
   THIS object
   {
    $$ = $2;
   }      
 | THESE objects
      {
    $$ = $2;
      }        
  | PREVIOUS object
      {
    $$ = $2;
      }      
  | PREVIOUS objects
      {
    $$ = $2;
      }        
  | THOSE objects
      {
    $$ = $2;
      }        
  | addressIndefinitePreviousObjects
      {
    $$ = $1;
      }        
;

addressIndefinitePreviousObjects :
   THIS	
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    $$ = p;
   }
 | THESE	
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    $$ = p;
   }
 | IT
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    $$ = p;
   }
 | ITS
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    $$ = p;
   }
 | THEM
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    $$ = p;
   }
 | THOSE
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    $$ = p;
   }
 | THEIR
   {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    $$ = p;
   }
;

THEIR :
    THEIR_T                  { $$ = NULL;  }
;

ITS :
    ITS_T                  { $$ = NULL;  }
;

THIS :
  THIS_T                  { $$ = NULL;  }
;

THESE :
    THESE_T                  { $$ = NULL;  }
;

PREVIOUS :
  PREVIOUS_T                  { $$ = NULL;  }
;

IT :
  IT_T                  { $$ = NULL;  }
;

THEM :
  THEM_T                  { $$ = NULL;  }
;

THOSE :
  THOSE_T                  { $$ = NULL;  }
;

intersectableObject :
   LINESEGMENT
   {
    Plottables * p = newPlottables();
    p->type = LINE_SEGMENT_D;
    p->singleton = true;
    $$ = p;
   }    
 | LINE
   {
    Plottables * p = newPlottables();
    p->type = LINE_D;
    p->singleton = true;
    $$ = p;
   }    
 | CIRCLE
   {
    Plottables * p = newPlottables();
    p->type = CIRCLE_D;
    p->singleton = true;
    $$ = p;
   }    
 | ARC
   {
    Plottables * p = newPlottables();
    p->type = ARC_D;
    p->singleton = true;
    $$ = p;
   }    
 | PERPENDICULARBISECTOR
   {
    $$ = newPlottables();
   }  
 | BISECTOR
   {
    $$ = newPlottables();
   }  
 | CHORD
   {
    $$ = newPlottables();
   }  
 | RAY
   {
    $$ = newPlottables();
   }  
;

object : 
   intersectableObject
   {
    $$ = $1;
   }    
 | POINT
   {
    Plottables *p = newPlottables();
    p->type = POINT_D;
    p->singleton = true;
    $$ = p;
   }      
;

intersectableObjects :
   LINESEGMENTS
   {
    Plottables *p = newPlottables();
    p->type = LINE_SEGMENT_D;
    p->singleton = false;
    $$ = p;
   }
 | LINES
   {
    Plottables *p = newPlottables();
    p->type = LINE_D;
    p->singleton = false;
    $$ = p;
   }      
 | CIRCLES
   {
    Plottables *p = newPlottables();
    p->type = CIRCLE_D;
    p->singleton = false;
    $$ = p;
   }      
 | ARCS
   {
    Plottables *p = newPlottables();
    p->type = ARC_D;
    p->singleton = false;
    $$ = p;
   }      
 | PERPENDICULARBISECTORS
   {
    $$ = newPlottables();
   }      
 | BISECTORS
   {
    $$ = newPlottables();
   }      
 | CHORDS
   {
    $$ = newPlottables();
   }      
 | RAYS
   {
    $$ = newPlottables();
   }      
;

LINESEGMENTS :
    LINE_T SEGMENTS_T                  { $$ = NULL;  }
;

LINES :
    LINES_T                  { $$ = NULL;  }
;

CIRCLES :
    CIRCLES_T                  { $$ = NULL;  }
;

PERPENDICULARBISECTORS :
    PERPENDICULAR_T BISECTORS_T                  { $$ = NULL;  }
;

BISECTORS :
    BISECTORS_T                  { $$ = NULL;  }
;

CHORDS :
    CHORDS_T                  { $$ = NULL;  }
;

CHORD :
    CHORD_T                  { $$ = NULL;  }
;

objects :
   intersectableObjects
   {
    $$ = $1;
   }        
 | POINTS
   {
    Plottables *p = newPlottables();
    p->type = POINT_D;
    p->singleton = false;
    $$ = p;
   }      
;

BISECTOR :
    BISECTOR_T                  { $$ = NULL;  }
;

ARCS :
    ARCS_T                  { $$ = NULL;  }
;

cutCommand :
  CUT cuttableAndProperties
      {
	Command *c = newCommand();

	c->plottables = *$2;
	$$ = c;
      }      
;

CUT :
  CUT_T                  { $$ = NULL;  }
;

addressPoint :
    POINTSINGLET
      {
	Point *p = newPoint();
	p->label = yylval.sval[0];
	if(existsPoint(*p)) *p = getPoint(p->label);
	$$ = p;
      }        
  | POINT POINTSINGLET
      {
	Point *p = newPoint();
	p->label = yylval.sval[0];
	if(existsPoint(*p)) *p = getPoint(p->label);
	$$ = p;
      }          
  | adjectivePrevious POINT
      {
	if(!existsLastPoint()){
	  spitError("No previous points exist\n");
	}
	Point *p = newPoint();
	*p = getLastPoint();
	$$ = p;
      }          
  | adjectiveFree POINT
      {
	Point *p = newPoint();
	p->label = reserveNextPointLabel();
	$$ = p;
      }          
;

adjectiveFree :
    ANY                  { $$ = NULL;  }
;

ANY :
  ANY_T                  { $$ = NULL;  }
;

POINT :
    POINT_T                  { $$ = NULL;  }
;

POINTS :
    POINTS_T                  { $$ = NULL;  }
;

cuttableAndProperties :
    addressLineSegment addressLength fromClause
      {
	Plottables *p = newPlottables();
	LineSegment cutting = *$1;
	LineSegment cuttingFrom = *($3->ls);
	
	char toPlot;
	Point src, dest;
	if(cutting.pA.label == cuttingFrom.pA.label){
	  toPlot = cutting.pB.label;
	  src = cuttingFrom.pA;
	  dest = cuttingFrom.pB;
	} else if(cutting.pA.label == cuttingFrom.pB.label){
	  toPlot = cutting.pB.label;
	  src = cuttingFrom.pB;
	  dest = cuttingFrom.pA;
	} else if (cutting.pB.label == cuttingFrom.pA.label){
	  toPlot = cutting.pA.label;
	  src = cuttingFrom.pA;
	  dest = cuttingFrom.pB;
	} else { //cutting.pB.label == cuttingFrom.pB.label)
	  toPlot = cutting.pA.label;
	  src = cuttingFrom.pB;
	  dest = cuttingFrom.pA;
	}

	double slope = getSlope(src, dest);
	Point res = locatePoint(src, slope, $2->length);

	updatePlottablesPoint(p, res);
	$$ = p;
      }            
  | addressLineSegment conditions
      {
	$$ = newPlottables();
      }              
  | addressLine atPoints
      {
	$$ = newPlottables();
      }              
  | addressArc atPoints
      {
	Plottables *p = newPlottables();
	Intersection *i = newIntersection();
	i->a1 = &($1->arcs[0]);

	Point p1 = getPointOnLabelable(*i, NULL);
	p1.label = $2->p1->label;
	updatePlottablesPoint(p, p1);

	if($2->p2 != NULL){
	  Point p2 = getPointOnLabelable(*i, NULL);
	  p2.label = $2->p2->label;
	  updatePlottablesPoint(p, p2);
	}

	$$ = p;
      }              
  | addressCircle atPoints
      {
	Plottables *p = newPlottables();
	Intersection *i = newIntersection();
	i->c1 = $1;

	Point p1 = getPointOnLabelable(*i, NULL);
	p1.label = $2->p1->label;
	updatePlottablesPoint(p, p1);

	if($2->p2 != NULL){
	  Point p2 = getPointOnLabelable(*i, NULL);
	  p2.label = $2->p2->label;
	  updatePlottablesPoint(p, p2);
	}

	$$ = p;
      }              
;

atPoints :
    AT addressPoint
      {
	Cut *c = newCut();
	c->p1 = $2;
	$$ = c;
      }                
  | AT addressPoint addressPoint
      {
	Cut *c = newCut();
	c->p1 = $2;
	c->p2 = $3;
	$$ = c;
      }                  
;

fromClause :
    FROM addressLineSegment
      {
	Cut *c = newCut();
	c->ls = $2;
	$$ = c;	
      }                    
  | FROM addressLine
      {
	$$ = newCut();
      }                  
  | FROM addressPreviousObjects
      {
	$$ = newCut();
      }                
;

addressCircle : 
    CIRCLE AT POINTSINGLET
      {
	Circle *c = newCircle();
	c->center.label = $3[0];
	$$ = c;
      }                
  | CIRCLE CENTER POINTSINGLET
      {
	Circle *c = newCircle();
	c->center.label = $3[0];
	$$ = c;
      }                  
  | adjectivePrevious CIRCLE
      {
	Circle *c = newCircle();
	*c = getLastCircle();
	$$ = c;
      }                  
  | adjectiveFree CIRCLE
      {
	Circle *c = newCircle();
	c->center.label = reserveNextPointLabel();
	c->radius = 2.0; //generate random radius here
	$$ = c;
      }                  
;

FROM :
  FROM_T                  { $$ = NULL;  }
;

TWICE :
  TWICE_T                  { $$ = NULL;  }
;

THRICE :
  THRICE_T                  { $$ = NULL;  }
;

EQUALS :
    EQUALS_T                  { $$ = NULL;  }
  | EQUAL_T                  { $$ = NULL;  }
  | IS_T                  { $$ = NULL;  }
  | HAS_T                  { $$ = NULL;  }
;

previousLength :
    SAME_T                  { $$ = NULL;  }
  | PREVIOUS_T                  { $$ = NULL;  }    
;

previousDegree :
    SAME_T                  { $$ = NULL;  }
;

operation :
    DIFFERENCE
      {
	Operation *o = newOperation();
	o->label = '-';
	$$ = o;
      }                    
  | SUM
      {
	Operation *o = newOperation();
	o->label = '+';
	$$ = o;
      }                  
;

DIFFERENCE :
    MINUS_T                  { $$ = NULL;  }
  | DIFFERENCE_T                  { $$ = NULL;  }
;

SUM :
    SUM_T                  { $$ = NULL;  }
;

FREEVARIABLE :
    ANY_T                  { $$ = NULL;  }
  | CONVENIENT_T                  { $$ = NULL;  }
;

bisectCommand :
    BISECT bisectableAndProperties
      {
	Command *c = newCommand();
	c->plottables = *$2;
	$$ = c;
      }                    
;

BISECT :
    BISECT_T                  { $$ = NULL;  }
;

bisectableAndProperties :
    addressLineSegment
      {
	Plottables *p = newPlottables();
	Point md = getMidPoint($1->pA, $1->pB);
	updatePlottablesPoint(p, md);
	$$ = p;
      }                    
  | addressAngle
      {
	Plottables *p = newPlottables();
	LineSegment ls = getAngleBisector(*$1);
	updatePlottablesLineSegment(p, ls);
	$$ = p;
      }                      
 | addressIndefinitePreviousObjects
   {
    $1->class = BISECTABLE_D;
    resolvePlottables($1);
    $$ = $1;
   }                      
;

POINTSINGLET :
    POINTSINGLET_T
      {
	$$ = newString(yylval.sval);
      }
;

POINTPAIR :
    POINTPAIR_T
      {
	$$ = newString(yylval.sval);
      }
;

POINTTRIPLET :
    POINTTRIPLET_T
      {
	$$ = newString(yylval.sval);
      }
;

LINELABEL :
    LINELABEL_T
      {
	$$ = newString(yylval.sval);
      }
;

INTEGER :
    INTEGER_T
      {
	$$ = yylval.ival;
      }
;

REAL :
    REAL_T
      {
	$$ = yylval.dval;
      }
;

%%
int main()
{
  srand(time(NULL));
  readContext();
  readHistory();
  yyparse();
  return 0;
}
