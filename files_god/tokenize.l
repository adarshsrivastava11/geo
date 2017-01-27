%{
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include "./y.tab.h"
#define true 1
#define false 0
#define bool int

//prints all lexical phase information
#define TDEBUG 1

char *strdump(char* str) {
  char *ret = (char*)malloc(sizeof(char)*1000);
  int i=0;
  while(str[i]!='\0') {
    ret[i] = str[i];
    i++;
  }
  ret[i] = '\0';
  return ret;
}

double toDouble(char str[]) {
  int length = 0;
  int i = 0;
  while(str[i] != '\0') {
    i++;
    length++;
  }
  bool decimal = false;
  double n = 0;
  double power = 1;
  if(str[0] == '-')
    i=1;
  else
    i=0;
  for(;i<length;i++) {
    if(str[i] == '.') {
      decimal = true;
      power = 10;
      continue;
    }
    if(decimal) {
      n = n + (str[i] - '0')/power;
      power = power*10;
    } else {
      n = n*10 + (str[i] - '0');
    }
  }
  if(str[0] == '-')
    n*=(-1);
  return n;
}

%}
		
KEYWORD construct|length|cm|from|this|cut|given|that|twice|equals|line|segment|difference|and|center|any|radius|arc|intersecting|at|two|points|centers|greater|than|arcs|cutting|eachother|join|same|point|on|other|side|draw|mark|it|not|circle|half|its|intersection|previous|bisector|divide|into|parts|diameter|angle|vertex|arm|their|rays|origin|passing|through|measure|degrees|right|bisect|perpendicular|to|chord|bisectors|chords|these|outside|parallel|distance|triangle|equilateral|isosceles|equal|sides|between|them|angled|degree|hypotenuse|firstLeg|ray|sum|base|along|quadrilateral|square|as|making|each|of|angles|arcs
 

%%
"construct" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CONSTRUCT_T;}
"length" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return LENGTH_T;}
"cm" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CM_T;}
"from" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return FROM_T;}
"this" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THIS_T;}
"cut" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CUT_T;}
"given" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return GIVEN_T;}
"that"				{if(TDEBUG) printf("Keyword %s\n", yytext); return THAT_T;}
"twice" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return TWICE_T;}
"equals" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return EQUALS_T;}
"line" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return LINE_T;}
"segment" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SEGMENT_T;}
"difference" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DIFFERENCE_T;}
"and" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return AND_T;}
"center" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CENTER_T;}
"any" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ANY_T;}
"one" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ANY_T;}
"radius" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return RADIUS_T;}
"arc" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ARC_T;}
"arcs" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ARCS_T;}
"intersecting" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return INTERSECTING_T;}
"at" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return AT_T;}
"two" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return TWO_T;}
"points" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return POINTS_T;}
"centers" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CENTERS_T;}
"greater" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return GREATER_T;}
"than" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THAN_T;}
"arcs" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ARCS_T;}
"cutting" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CUTTING_T;}
"eachother" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return EACHOTHER_T;}
"join" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return JOIN_T;}
"same" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SAME_T;}
"point" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return POINT_T;}
"on" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ON_T;}
"other" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return OTHER_T;}
"side" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SIDE_T;}
"draw" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DRAW_T;}
"mark" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return MARK_T;}
"it" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return IT_T;}
"not" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return NOT_T;}
"circle" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CIRCLE_T;}
"half" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return HALF_T;}
"its" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ITS_T;}
"intersection" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return INTERSECTION_T;}
"previous" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return PREVIOUS_T;}
"bisector" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return BISECTOR_T;}
"divide" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DIVIDE_T;}
"into" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return INTO_T;}
"parts" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return PARTS_T;}
"diameter" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DIAMETER_T;}
"angle" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ANGLE_T;}
"vertex" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return VERTEX_T;}
"arm" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ARM_T;}
"their" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THEIR_T;}
"rays" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return RAYS_T;}
"origin" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ORIGIN_T;}
"passing" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return PASSING_T;}
"through" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THROUGH_T;}
"measure" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return MEASURE_T;}
"degrees" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DEGREES_T;}
"right" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return RIGHT_T;}
"bisect" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return BISECT_T;}
"perpendicular" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return PERPENDICULAR_T;}
"to" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return TO_T;}
"chord" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CHORD_T;}
"bisectors" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return BISECTORS_T;}
"chords" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return CHORDS_T;}
"these" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THESE_T;}
"outside" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return OUTSIDE_T;}
"parallel" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return PARALLEL_T;}
"distance" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DISTANCE_T;}
"triangle" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return TRIANGLE_T;}
"equilateral" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return EQUILATERAL_T;}
"isosceles" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ISOSCELES_T;}
"equal" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return EQUAL_T;}
"sides" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SIDES_T;}
"between" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return BETWEEN_T;}
"them" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return THEM_T;}
"angled" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ANGLED_T;}
"degree" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return DEGREE_T;}
"hypotenuse" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return HYPOTENUSE_T;}
"firstLeg" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return FIRSTLEG_T;}
"ray" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return RAY_T;}
"sum" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SUM_T;}
"base" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return BASE_T;}
"along" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ALONG_T;}
"quadrilateral" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return QUADRILATERAL_T;}
"square" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return SQUARE_T;}
"as" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return AS_T;}
"making" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return MAKING_T;}
"each" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return EACH_T;}
"of" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return OF_T;}
"angles" 				{if(TDEBUG) printf("Keyword %s\n", yytext); return ANGLES_T;}

[A-Z][A-Z][A-Z]   {
                    yylval.sval = (char*)malloc((strlen(yytext)+1)*sizeof(char));
                    strncpy(yylval.sval, yytext, strlen(yytext));
                    yylval.sval[strlen(yytext)] = '\0';
                    if(TDEBUG) printf("POINTTRIPLET %s\n", yytext);
                    return POINTTRIPLET_T;
                  }

[A-Z][A-Z]  {
              yylval.sval = (char*)malloc((strlen(yytext)+1)*sizeof(char));
              strncpy(yylval.sval, yytext, strlen(yytext));
              yylval.sval[strlen(yytext)] = '\0';
              if(TDEBUG) printf("POINTPAIR %s\n", yytext);
              return POINTPAIR_T;
            }

[A-Z]       {
              yylval.sval = (char*)malloc((strlen(yytext)+1)*sizeof(char));
              strncpy(yylval.sval, yytext, strlen(yytext));
              yylval.sval[strlen(yytext)] = '\0';
              if(TDEBUG) printf("POINTSINGLET %s\n", yytext);
              return POINTSINGLET_T;
            }

[a-z]       {
              yylval.sval = (char*)malloc((strlen(yytext)+1)*sizeof(char));
              strncpy(yylval.sval, yytext, strlen(yytext));
              yylval.sval[strlen(yytext)] = '\0';
              if(TDEBUG) printf("LINELABEL %s\n", yytext);
              return LINELABEL_T;
            }

[0-9]+      {
              yylval.ival = atoi(yytext);
              if(TDEBUG) printf("INTEGER %d\n", yylval.ival);
              return INTEGER_T;
            }

[0-9]+(.[0-9]+)  {
                   yylval.dval = toDouble(yytext);
                   if(TDEBUG) printf("REAL %lf\n", yylval.dval);
                   return REAL_T;
                 }

%%
int yywrap(){return 1;}
