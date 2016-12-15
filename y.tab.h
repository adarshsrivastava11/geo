/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_T = 258,
     KEYWORD_T = 259,
     REAL_T = 260,
     POINTSINGLET_T = 261,
     POINTPAIR_T = 262,
     POINTTRIPLET_T = 263,
     LINELABEL_T = 264,
     CONSTRUCT_T = 265,
     LENGTH_T = 266,
     CM_T = 267,
     FROM_T = 268,
     THIS_T = 269,
     CUT_T = 270,
     GIVEN_T = 271,
     THAT_T = 272,
     TWICE_T = 273,
     EQUALS_T = 274,
     LINE_T = 275,
     SEGMENT_T = 276,
     DIFFERENCE_T = 277,
     AND_T = 278,
     CENTER_T = 279,
     ANY_T = 280,
     RADIUS_T = 281,
     ARC_T = 282,
     INTERSECTING_T = 283,
     AT_T = 284,
     TWO_T = 285,
     POINTS_T = 286,
     CENTERS_T = 287,
     GREATER_T = 288,
     THAN_T = 289,
     ARCS_T = 290,
     CUTTING_T = 291,
     EACHOTHER_T = 292,
     JOIN_T = 293,
     SAME_T = 294,
     POINT_T = 295,
     ON_T = 296,
     OTHER_T = 297,
     SIDE_T = 298,
     DRAW_T = 299,
     MARK_T = 300,
     IT_T = 301,
     NOT_T = 302,
     CIRCLE_T = 303,
     HALF_T = 304,
     ITS_T = 305,
     INTERSECTION_T = 306,
     PREVIOUS_T = 307,
     BISECTOR_T = 308,
     DIVIDE_T = 309,
     INTO_T = 310,
     PARTS_T = 311,
     DIAMETER_T = 312,
     ANGLE_T = 313,
     VERTEX_T = 314,
     ARM_T = 315,
     THEIR_T = 316,
     RAYS_T = 317,
     ORIGIN_T = 318,
     PASSING_T = 319,
     THROUGH_T = 320,
     MEASURE_T = 321,
     DEGREES_T = 322,
     RIGHT_T = 323,
     BISECT_T = 324,
     PERPENDICULAR_T = 325,
     TO_T = 326,
     CHORD_T = 327,
     BISECTORS_T = 328,
     CHORDS_T = 329,
     THESE_T = 330,
     OUTSIDE_T = 331,
     PARALLEL_T = 332,
     DISTANCE_T = 333,
     TRIANGLE_T = 334,
     EQUILATERAL_T = 335,
     ISOSCELES_T = 336,
     EQUAL_T = 337,
     SIDES_T = 338,
     BETWEEN_T = 339,
     THEM_T = 340,
     ANGLED_T = 341,
     DEGREE_T = 342,
     HYPOTENUSE_T = 343,
     FIRSTLEG_T = 344,
     RAY_T = 345,
     SUM_T = 346,
     BASE_T = 347,
     ALONG_T = 348,
     QUADRILATERAL_T = 349,
     SQUARE_T = 350,
     AS_T = 351,
     MAKING_T = 352,
     EACH_T = 353,
     OF_T = 354,
     ANGLES_T = 355,
     CIRCLES_T = 356,
     CONVENIENT_T = 357,
     DIVITDE_T = 358,
     HAS_T = 359,
     INITIAL_T = 360,
     INTERSECTIONS_T = 361,
     INTERSECT_T = 362,
     IS_T = 363,
     LABEL_T = 364,
     LESS_T = 365,
     LINES_T = 366,
     MINUS_T = 367,
     ORTHOGONAL_T = 368,
     SEGMENTS_T = 369,
     THOSE_T = 370,
     THRICE_T = 371,
     TIMES_T = 372
   };
#endif
/* Tokens.  */
#define INTEGER_T 258
#define KEYWORD_T 259
#define REAL_T 260
#define POINTSINGLET_T 261
#define POINTPAIR_T 262
#define POINTTRIPLET_T 263
#define LINELABEL_T 264
#define CONSTRUCT_T 265
#define LENGTH_T 266
#define CM_T 267
#define FROM_T 268
#define THIS_T 269
#define CUT_T 270
#define GIVEN_T 271
#define THAT_T 272
#define TWICE_T 273
#define EQUALS_T 274
#define LINE_T 275
#define SEGMENT_T 276
#define DIFFERENCE_T 277
#define AND_T 278
#define CENTER_T 279
#define ANY_T 280
#define RADIUS_T 281
#define ARC_T 282
#define INTERSECTING_T 283
#define AT_T 284
#define TWO_T 285
#define POINTS_T 286
#define CENTERS_T 287
#define GREATER_T 288
#define THAN_T 289
#define ARCS_T 290
#define CUTTING_T 291
#define EACHOTHER_T 292
#define JOIN_T 293
#define SAME_T 294
#define POINT_T 295
#define ON_T 296
#define OTHER_T 297
#define SIDE_T 298
#define DRAW_T 299
#define MARK_T 300
#define IT_T 301
#define NOT_T 302
#define CIRCLE_T 303
#define HALF_T 304
#define ITS_T 305
#define INTERSECTION_T 306
#define PREVIOUS_T 307
#define BISECTOR_T 308
#define DIVIDE_T 309
#define INTO_T 310
#define PARTS_T 311
#define DIAMETER_T 312
#define ANGLE_T 313
#define VERTEX_T 314
#define ARM_T 315
#define THEIR_T 316
#define RAYS_T 317
#define ORIGIN_T 318
#define PASSING_T 319
#define THROUGH_T 320
#define MEASURE_T 321
#define DEGREES_T 322
#define RIGHT_T 323
#define BISECT_T 324
#define PERPENDICULAR_T 325
#define TO_T 326
#define CHORD_T 327
#define BISECTORS_T 328
#define CHORDS_T 329
#define THESE_T 330
#define OUTSIDE_T 331
#define PARALLEL_T 332
#define DISTANCE_T 333
#define TRIANGLE_T 334
#define EQUILATERAL_T 335
#define ISOSCELES_T 336
#define EQUAL_T 337
#define SIDES_T 338
#define BETWEEN_T 339
#define THEM_T 340
#define ANGLED_T 341
#define DEGREE_T 342
#define HYPOTENUSE_T 343
#define FIRSTLEG_T 344
#define RAY_T 345
#define SUM_T 346
#define BASE_T 347
#define ALONG_T 348
#define QUADRILATERAL_T 349
#define SQUARE_T 350
#define AS_T 351
#define MAKING_T 352
#define EACH_T 353
#define OF_T 354
#define ANGLES_T 355
#define CIRCLES_T 356
#define CONVENIENT_T 357
#define DIVITDE_T 358
#define HAS_T 359
#define INITIAL_T 360
#define INTERSECTIONS_T 361
#define INTERSECT_T 362
#define IS_T 363
#define LABEL_T 364
#define LESS_T 365
#define LINES_T 366
#define MINUS_T 367
#define ORTHOGONAL_T 368
#define SEGMENTS_T 369
#define THOSE_T 370
#define THRICE_T 371
#define TIMES_T 372



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 26 "lyparse.y"
		//union declared to store the $$ = value of tokens
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
  
 

/* Line 2053 of yacc.c  */
#line 324 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
