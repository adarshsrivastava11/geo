/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "lyparse.y"
	
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


/* Line 371 of yacc.c  */
#line 93 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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
  
 

/* Line 387 of yacc.c  */
#line 403 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 431 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1863

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  381
/* YYNRULES -- Number of states.  */
#define YYNSTATES  584

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    17,    19,
      21,    23,    26,    28,    31,    34,    37,    40,    44,    48,
      51,    55,    58,    61,    64,    67,    71,    75,    78,    82,
      84,    86,    88,    91,    93,    95,    98,   100,   102,   104,
     107,   110,   113,   116,   120,   124,   127,   131,   134,   137,
     140,   143,   147,   151,   154,   158,   160,   162,   165,   168,
     170,   172,   174,   176,   178,   180,   183,   185,   187,   189,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   209,
     211,   216,   220,   225,   230,   234,   237,   241,   245,   249,
     252,   256,   260,   262,   267,   271,   275,   278,   280,   283,
     286,   288,   290,   292,   295,   297,   300,   303,   305,   307,
     312,   316,   319,   324,   328,   330,   332,   334,   337,   339,
     342,   344,   346,   352,   358,   362,   366,   368,   370,   374,
     378,   380,   383,   385,   389,   392,   395,   397,   401,   404,
     407,   410,   413,   415,   421,   426,   431,   435,   438,   442,
     445,   449,   455,   460,   462,   464,   466,   468,   470,   474,
     476,   478,   480,   482,   484,   486,   488,   490,   493,   495,
     497,   501,   506,   509,   513,   516,   518,   521,   523,   525,
     528,   532,   535,   538,   540,   542,   544,   547,   550,   553,
     556,   559,   562,   565,   568,   571,   574,   577,   579,   581,
     584,   586,   589,   593,   597,   600,   604,   608,   613,   615,
     617,   619,   622,   625,   627,   630,   632,   637,   639,   641,
     643,   645,   648,   650,   652,   655,   659,   662,   665,   667,
     669,   671,   673,   675,   677,   687,   689,   695,   700,   705,
     709,   712,   715,   717,   719,   721,   723,   725,   727,   729,
     732,   736,   739,   741,   745,   748,   751,   754,   756,   759,
     761,   763,   765,   767,   769,   771,   774,   777,   780,   783,
     786,   788,   790,   792,   794,   797,   800,   803,   806,   809,
     811,   814,   817,   820,   823,   826,   828,   830,   832,   834,
     836,   838,   840,   842,   844,   846,   848,   850,   852,   854,
     856,   858,   860,   862,   864,   866,   868,   870,   872,   874,
     876,   878,   880,   882,   884,   886,   888,   890,   892,   894,
     897,   899,   901,   904,   906,   908,   910,   912,   914,   916,
     918,   921,   923,   925,   928,   931,   934,   936,   938,   940,
     942,   946,   949,   952,   955,   958,   961,   965,   968,   971,
     974,   978,   982,   985,   988,   990,   992,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,
    1020,  1022,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     131,     0,    -1,   122,    -1,   121,    -1,   120,    -1,   282,
     142,    -1,   282,    -1,   281,   142,    -1,   281,    -1,   273,
      -1,   268,    -1,   141,   143,    -1,   143,    -1,   129,   120,
      -1,   130,   120,    -1,   265,   120,    -1,   266,   120,    -1,
     282,   127,   120,    -1,   281,   127,   120,    -1,   128,   120,
      -1,   270,   120,   120,    -1,   129,   121,    -1,   130,   121,
      -1,   265,   121,    -1,   266,   121,    -1,   282,   127,   121,
      -1,   281,   127,   121,    -1,   128,   121,    -1,   270,   121,
     121,    -1,   126,    -1,   125,    -1,   124,    -1,   282,   151,
      -1,   282,    -1,   281,    -1,   281,   151,    -1,   273,    -1,
     269,    -1,   150,    -1,   129,   124,    -1,   130,   124,    -1,
     265,   124,    -1,   266,   124,    -1,   282,   127,   124,    -1,
     281,   127,   124,    -1,   128,   124,    -1,   270,   124,   124,
      -1,   129,   125,    -1,   130,   125,    -1,   265,   125,    -1,
     266,   125,    -1,   282,   127,   125,    -1,   281,   127,   125,
      -1,   128,   125,    -1,   270,   125,   125,    -1,   117,    -1,
      49,    -1,    33,    34,    -1,   110,    34,    -1,   132,    -1,
     211,    -1,   253,    -1,   208,    -1,   202,    -1,   274,    -1,
     133,   134,    -1,    10,    -1,    44,    -1,   135,    -1,   155,
      -1,   159,    -1,   156,    -1,   152,    -1,   144,    -1,   179,
      -1,   184,    -1,   189,    -1,   192,    -1,   195,    -1,   200,
      -1,   139,   143,   138,   136,    -1,   139,   143,   140,    -1,
     139,   143,   191,   194,    -1,   139,   143,   190,   201,    -1,
     139,   138,   136,    -1,   139,   140,    -1,   139,   191,   194,
      -1,   139,   190,   201,    -1,   143,   138,   136,    -1,   143,
     140,    -1,   143,   191,   194,    -1,   143,   190,   201,    -1,
     137,    -1,   267,   141,   143,   119,    -1,   267,   143,   119,
      -1,   267,   150,   150,    -1,    16,    17,    -1,    16,    -1,
      20,    21,    -1,   141,   119,    -1,   119,    -1,    11,    -1,
      12,    -1,   139,   278,    -1,   278,    -1,   229,   139,    -1,
     256,   139,    -1,   145,    -1,   146,    -1,   149,   148,   255,
     123,    -1,   149,   150,   123,    -1,   149,   123,    -1,   147,
     149,   148,   255,    -1,   147,   149,   150,    -1,    68,    -1,
      59,    -1,    58,    -1,   149,   279,    -1,   279,    -1,   229,
     149,    -1,    87,    -1,    67,    -1,   153,   172,   255,   173,
     119,    -1,   153,   172,   255,   174,   119,    -1,   153,   173,
     119,    -1,   153,   174,   119,    -1,    48,    -1,    20,    -1,
     154,   191,   194,    -1,   154,   190,   201,    -1,   154,    -1,
     157,   158,    -1,    35,    -1,   166,   168,   164,    -1,   166,
     168,    -1,   160,   161,    -1,    27,    -1,   165,   167,   169,
      -1,   165,   167,    -1,   165,   162,    -1,   163,   255,    -1,
      64,    65,    -1,    65,    -1,   175,   176,   178,   277,   277,
      -1,   175,   178,   277,   277,    -1,   175,   176,   178,   277,
      -1,   175,   178,   277,    -1,   172,   277,    -1,   177,   277,
     277,    -1,   173,   119,    -1,   173,   119,   119,    -1,   175,
     170,   178,   277,   277,    -1,   175,   170,   178,   277,    -1,
     143,    -1,   227,    -1,   228,    -1,   263,    -1,   171,    -1,
     183,   149,   150,    -1,    24,    -1,    26,    -1,    57,    -1,
      28,    -1,    36,    -1,    15,    -1,   107,    -1,    37,    -1,
      98,    42,    -1,    32,    -1,    29,    -1,   182,   278,   180,
      -1,   183,   278,   278,   180,    -1,   182,   278,    -1,   183,
     278,   278,    -1,   181,   255,    -1,    63,    -1,   105,    40,
      -1,    90,    -1,    62,    -1,   188,   185,    -1,   247,   185,
     185,    -1,   188,   232,    -1,   247,   232,    -1,   143,    -1,
     186,    -1,   187,    -1,   229,   250,    -1,   229,   249,    -1,
      70,    53,    -1,   252,   143,    -1,   252,   150,    -1,   252,
     232,    -1,   199,   143,    -1,   199,   227,    -1,   193,   143,
      -1,   193,   227,    -1,   191,   194,    -1,    70,    -1,   113,
      -1,   178,   255,    -1,   162,    -1,   250,   263,    -1,   250,
     263,   196,    -1,   249,   263,   198,    -1,   250,   232,    -1,
     250,   232,   196,    -1,   249,   232,   198,    -1,   197,   119,
     264,   172,    -1,    78,    -1,   281,    -1,    77,    -1,   190,
     201,    -1,   178,   255,    -1,   162,    -1,   203,   204,    -1,
     103,    -1,   207,   206,   281,   205,    -1,    56,    -1,    55,
      -1,   143,    -1,   232,    -1,   209,   210,    -1,    38,    -1,
     278,    -1,   278,   278,    -1,   278,   278,   278,    -1,   229,
     259,    -1,   212,   213,    -1,    45,    -1,    44,    -1,   109,
      -1,   216,    -1,   219,    -1,   214,    -1,   258,   277,   224,
     215,   150,   277,   224,   215,   150,    -1,    60,    -1,   217,
     218,   218,   255,   255,    -1,   217,   218,   218,   255,    -1,
     217,   230,   255,   255,    -1,   217,   230,   255,    -1,    51,
      31,    -1,    51,    40,    -1,    51,    -1,   106,    -1,   228,
      -1,   263,    -1,   227,    -1,   143,    -1,   231,    -1,   255,
     223,    -1,   255,   222,   220,    -1,   255,   222,    -1,   255,
      -1,   221,   255,   119,    -1,    78,    13,    -1,   224,   226,
      -1,   225,   226,    -1,    41,    -1,    47,    41,    -1,    76,
      -1,   143,    -1,   228,    -1,   227,    -1,   231,    -1,   280,
      -1,   154,   280,    -1,   229,   154,    -1,   256,   154,    -1,
     229,   160,    -1,   229,   157,    -1,   235,    -1,   236,    -1,
     237,    -1,   240,    -1,   235,   241,    -1,   236,   243,    -1,
     237,   241,    -1,   237,   243,    -1,   240,   243,    -1,   232,
      -1,   235,   242,    -1,   236,   251,    -1,   237,   242,    -1,
     237,   251,    -1,   240,   251,    -1,   232,    -1,   235,    -1,
     236,    -1,   238,    -1,   234,    -1,   239,    -1,   240,    -1,
     233,    -1,    61,    -1,    50,    -1,    14,    -1,    75,    -1,
      52,    -1,    46,    -1,    85,    -1,   115,    -1,   139,    -1,
     154,    -1,   153,    -1,   160,    -1,   188,    -1,   252,    -1,
     250,    -1,   182,    -1,   241,    -1,   258,    -1,   244,    -1,
     245,    -1,   246,    -1,   157,    -1,   247,    -1,   248,    -1,
     249,    -1,   183,    -1,    20,   114,    -1,   111,    -1,   101,
      -1,    70,    73,    -1,    73,    -1,    74,    -1,    72,    -1,
     243,    -1,   259,    -1,    53,    -1,    35,    -1,   254,   260,
      -1,    15,    -1,   277,    -1,   258,   277,    -1,   229,   258,
      -1,   256,   258,    -1,   257,    -1,    25,    -1,    40,    -1,
      31,    -1,   143,   119,   262,    -1,   143,   136,    -1,   227,
     261,    -1,   228,   261,    -1,   263,   261,    -1,   178,   255,
      -1,   178,   255,   255,    -1,   264,   143,    -1,   264,   227,
      -1,   264,   231,    -1,   153,   178,   277,    -1,   153,   172,
     277,    -1,   229,   153,    -1,   256,   153,    -1,    13,    -1,
      18,    -1,   116,    -1,    19,    -1,    82,    -1,   108,    -1,
     104,    -1,    39,    -1,    52,    -1,    39,    -1,   271,    -1,
     272,    -1,   112,    -1,    22,    -1,    91,    -1,    25,    -1,
     102,    -1,   275,   276,    -1,    69,    -1,   143,    -1,   150,
      -1,   232,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,     3,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   120,   123,   129,   134,   139,   144,   149,
     154,   160,   167,   177,   183,   188,   194,   200,   206,   212,
     218,   228,   234,   239,   245,   251,   257,   263,   269,   279,
     280,   281,   285,   290,   295,   300,   305,   310,   317,   330,
     336,   342,   348,   354,   360,   366,   372,   381,   387,   393,
     399,   405,   411,   417,   423,   432,   436,   440,   444,   448,
     449,   450,   451,   452,   453,   457,   466,   467,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     486,   515,   539,   545,   551,   584,   612,   618,   624,   653,
     677,   683,   693,   697,   703,   709,   723,   724,   728,   732,
     733,   737,   741,   745,   771,   797,   807,   820,   821,   825,
     853,   917,   949,   968,  1035,  1039,  1043,  1047,  1100,  1153,
    1165,  1166,  1170,  1183,  1196,  1207,  1221,  1225,  1229,  1233,
    1237,  1244,  1251,  1255,  1283,  1304,  1312,  1316,  1336,  1345,
    1357,  1364,  1365,  1369,  1383,  1397,  1407,  1420,  1434,  1461,
    1468,  1482,  1492,  1502,  1508,  1514,  1523,  1529,  1538,  1545,
    1549,  1553,  1557,  1558,  1559,  1560,  1564,  1565,  1569,  1573,
    1577,  1581,  1585,  1589,  1596,  1603,  1604,  1608,  1612,  1616,
    1626,  1630,  1638,  1645,  1652,  1656,  1663,  1670,  1677,  1681,
    1685,  1692,  1703,  1709,  1718,  1724,  1733,  1751,  1752,  1756,
    1762,  1771,  1775,  1779,  1783,  1787,  1791,  1798,  1805,  1809,
    1813,  1817,  1835,  1841,  1851,  1860,  1864,  1883,  1887,  1891,
    1896,  1904,  1924,  1928,  1934,  1941,  1949,  1963,  1972,  1973,
    1974,  1978,  1982,  1986,  1993,  2000,  2004,  2015,  2028,  2041,
    2054,  2055,  2056,  2057,  2061,  2067,  2073,  2077,  2083,  2092,
    2100,  2108,  2116,  2130,  2140,  2144,  2151,  2158,  2162,  2163,
    2167,  2173,  2180,  2186,  2196,  2202,  2208,  2214,  2223,  2229,
    2240,  2241,  2242,  2243,  2247,  2252,  2257,  2262,  2267,  2272,
    2280,  2284,  2288,  2292,  2296,  2300,  2307,  2314,  2321,  2328,
    2335,  2342,  2349,  2359,  2363,  2367,  2371,  2375,  2379,  2383,
    2387,  2391,  2398,  2405,  2412,  2419,  2423,  2427,  2431,  2438,
    2442,  2452,  2459,  2466,  2473,  2480,  2484,  2488,  2492,  2499,
    2503,  2507,  2511,  2515,  2519,  2523,  2527,  2531,  2541,  2545,
    2549,  2559,  2563,  2570,  2577,  2586,  2595,  2599,  2603,  2607,
    2611,  2643,  2647,  2651,  2669,  2690,  2696,  2706,  2712,  2716,
    2723,  2729,  2735,  2741,  2751,  2755,  2759,  2763,  2764,  2765,
    2766,  2770,  2771,  2775,  2779,  2785,  2794,  2795,  2799,  2803,
    2804,  2808,  2817,  2821,  2828,  2835,  2844,  2851,  2858,  2865,
    2872,  2879
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_T", "KEYWORD_T", "REAL_T",
  "POINTSINGLET_T", "POINTPAIR_T", "POINTTRIPLET_T", "LINELABEL_T",
  "CONSTRUCT_T", "LENGTH_T", "CM_T", "FROM_T", "THIS_T", "CUT_T",
  "GIVEN_T", "THAT_T", "TWICE_T", "EQUALS_T", "LINE_T", "SEGMENT_T",
  "DIFFERENCE_T", "AND_T", "CENTER_T", "ANY_T", "RADIUS_T", "ARC_T",
  "INTERSECTING_T", "AT_T", "TWO_T", "POINTS_T", "CENTERS_T", "GREATER_T",
  "THAN_T", "ARCS_T", "CUTTING_T", "EACHOTHER_T", "JOIN_T", "SAME_T",
  "POINT_T", "ON_T", "OTHER_T", "SIDE_T", "DRAW_T", "MARK_T", "IT_T",
  "NOT_T", "CIRCLE_T", "HALF_T", "ITS_T", "INTERSECTION_T", "PREVIOUS_T",
  "BISECTOR_T", "DIVIDE_T", "INTO_T", "PARTS_T", "DIAMETER_T", "ANGLE_T",
  "VERTEX_T", "ARM_T", "THEIR_T", "RAYS_T", "ORIGIN_T", "PASSING_T",
  "THROUGH_T", "MEASURE_T", "DEGREES_T", "RIGHT_T", "BISECT_T",
  "PERPENDICULAR_T", "TO_T", "CHORD_T", "BISECTORS_T", "CHORDS_T",
  "THESE_T", "OUTSIDE_T", "PARALLEL_T", "DISTANCE_T", "TRIANGLE_T",
  "EQUILATERAL_T", "ISOSCELES_T", "EQUAL_T", "SIDES_T", "BETWEEN_T",
  "THEM_T", "ANGLED_T", "DEGREE_T", "HYPOTENUSE_T", "FIRSTLEG_T", "RAY_T",
  "SUM_T", "BASE_T", "ALONG_T", "QUADRILATERAL_T", "SQUARE_T", "AS_T",
  "MAKING_T", "EACH_T", "OF_T", "ANGLES_T", "CIRCLES_T", "CONVENIENT_T",
  "DIVITDE_T", "HAS_T", "INITIAL_T", "INTERSECTIONS_T", "INTERSECT_T",
  "IS_T", "LABEL_T", "LESS_T", "LINES_T", "MINUS_T", "ORTHOGONAL_T",
  "SEGMENTS_T", "THOSE_T", "THRICE_T", "TIMES_T", "$accept",
  "addressLength", "addressLength1", "addressLength2", "addressLength3",
  "addressDegree", "addressDegree1", "addressDegree2", "addressDegree3",
  "TIMES", "HALF", "GREATERTHAN", "LESSTHAN", "command",
  "constructCommand", "CONSTRUCT", "constructibleAndProperties",
  "lineSegmentAndProperties", "conditions", "condition", "GIVENTHAT",
  "LINESEGMENT", "lineSegmentProperties", "LENGTH", "CM",
  "addressLineSegment", "angleAndProperties", "genericAngleAndProperties",
  "rightAngleAndProperties", "RIGHT", "VERTEX", "ANGLE", "addressAngle",
  "DEGREES", "circleAndProperties", "CIRCLE", "LINE", "lineAndProperties",
  "arcsAndProperties", "ARCS", "arcsProperties", "arcAndProperties", "ARC",
  "arcProperties", "passingThroughClause", "PASSINGTHROUGH",
  "mutualIntersectionClause", "centerClause", "centersClause",
  "radiusClause", "radiiClause", "intersectionClause",
  "addressIntersectableObject", "addressAngleRays", "CENTER", "RADIUS",
  "DIAMETER", "INTERSECTING", "EACHOTHER", "CENTERS", "AT",
  "rayAndProperties", "originClause", "ORIGIN", "RAY", "RAYS",
  "perpendicularBisectorAndProperties",
  "addressPerpendicularBisectableObjects", "addressChord", "addressChords",
  "PERPENDICULARBISECTOR", "bisectorAndProperties", "parallelToClause",
  "perpendicularToClause", "perpendicularAndProperties", "PERPENDICULAR",
  "perpendicularConditionClause", "chordAndProperties",
  "distanceFromCenterClause", "DISTANCE", "numChords", "PARALLEL",
  "parallelAndProperties", "parallelConditionClause", "divideCommand",
  "DIVIDE", "divisibleAndProperties", "PARTS", "INTO", "divisibleObject",
  "joinCommand", "JOIN", "addressPointPairs", "markCommand", "MARK",
  "markableAndProperties", "angleArmPointsAndProperties", "ARM",
  "intersectionPointsAndProperties", "INTERSECTIONPOINTS",
  "addressIntersectingObject", "pointAndProperties", "markConditionClause",
  "DISTANCEFROM", "pointAndPropertiesOnCase",
  "pointAndPropertiesNotOnCase", "ON", "NOTON", "labelable", "addressLine",
  "addressArc", "adjectivePrevious", "addressIntersectablePreviousObjects",
  "addressPreviousObjects", "addressIndefinitePreviousObjects", "THEIR",
  "ITS", "THIS", "THESE", "PREVIOUS", "IT", "THEM", "THOSE",
  "intersectableObject", "object", "intersectableObjects", "LINESEGMENTS",
  "LINES", "CIRCLES", "PERPENDICULARBISECTORS", "BISECTORS", "CHORDS",
  "CHORD", "objects", "BISECTOR", "cutCommand", "CUT", "addressPoint",
  "adjectiveFree", "ANY", "POINT", "POINTS", "cuttableAndProperties",
  "atPoints", "fromClause", "addressCircle", "FROM", "TWICE", "THRICE",
  "EQUALS", "previousLength", "previousDegree", "operation", "DIFFERENCE",
  "SUM", "FREEVARIABLE", "bisectCommand", "BISECT",
  "bisectableAndProperties", "POINTSINGLET", "POINTPAIR", "POINTTRIPLET",
  "LINELABEL", "INTEGER", "REAL", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   118,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   128,   129,   130,   131,
     131,   131,   131,   131,   131,   132,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   137,   137,   137,   138,   138,   139,   140,
     140,   141,   142,   143,   143,   143,   143,   144,   144,   145,
     145,   145,   146,   146,   147,   148,   149,   150,   150,   150,
     151,   151,   152,   152,   152,   152,   153,   154,   155,   155,
     155,   156,   157,   158,   158,   159,   160,   161,   161,   161,
     162,   163,   163,   164,   164,   164,   164,   165,   166,   167,
     168,   169,   169,   170,   170,   170,   170,   170,   171,   172,
     173,   174,   175,   175,   175,   175,   176,   176,   177,   178,
     179,   179,   179,   179,   180,   181,   181,   182,   183,   184,
     184,   184,   184,   185,   185,   185,   186,   187,   188,   189,
     189,   189,   190,   190,   191,   191,   192,   193,   193,   194,
     194,   195,   195,   195,   195,   195,   195,   196,   197,   198,
     199,   200,   201,   201,   202,   203,   204,   205,   206,   207,
     207,   208,   209,   210,   210,   210,   210,   211,   212,   212,
     212,   213,   213,   213,   214,   215,   216,   216,   216,   216,
     217,   217,   217,   217,   218,   218,   218,   218,   218,   219,
     219,   219,   219,   220,   221,   222,   223,   224,   225,   225,
     226,   226,   226,   226,   227,   227,   227,   227,   228,   228,
     229,   229,   229,   229,   230,   230,   230,   230,   230,   230,
     231,   231,   231,   231,   231,   231,   232,   232,   232,   232,
     232,   232,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   251,   252,   157,
     253,   254,   255,   255,   255,   255,   256,   257,   258,   259,
     260,   260,   260,   260,   260,   261,   261,   262,   262,   262,
     263,   263,   263,   263,   264,   265,   266,   267,   267,   267,
     267,   268,   268,   269,   270,   270,   271,   271,   272,   273,
     273,   274,   275,   276,   276,   276,   277,   278,   279,   280,
     281,   282
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     2,     1,     2,     2,     2,     2,     3,     3,     2,
       3,     2,     2,     2,     2,     3,     3,     2,     3,     1,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     2,     3,     2,     2,     2,
       2,     3,     3,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     4,     3,     2,     3,     3,     3,     2,
       3,     3,     1,     4,     3,     3,     2,     1,     2,     2,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     4,
       3,     2,     4,     3,     1,     1,     1,     2,     1,     2,
       1,     1,     5,     5,     3,     3,     1,     1,     3,     3,
       1,     2,     1,     3,     2,     2,     1,     3,     2,     2,
       2,     2,     1,     5,     4,     4,     3,     2,     3,     2,
       3,     5,     4,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     4,     2,     3,     2,     1,     2,     1,     1,     2,
       3,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     2,     3,     3,     2,     3,     3,     4,     1,     1,
       1,     2,     2,     1,     2,     1,     4,     1,     1,     1,
       1,     2,     1,     1,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     9,     1,     5,     4,     4,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     3,     2,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       3,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    66,   331,   222,    67,   228,   372,   215,   230,     0,
      59,     0,    63,     0,    62,     0,    60,     0,    61,     0,
      64,     0,     1,   377,   295,   127,   337,   136,   132,   126,
     297,   328,   116,   178,   114,   197,   325,   324,   296,   210,
     177,   198,   300,    65,    68,     0,     0,    73,   107,   108,
       0,     0,    72,     0,   130,    69,    71,     0,    70,     0,
      74,     0,     0,    75,     0,    76,     0,     0,    77,     0,
      78,     0,    79,     0,   270,   271,   272,   273,     0,     0,
       0,     0,     0,   336,   104,     0,   298,   294,   293,   299,
       0,   219,   214,     0,   220,   292,   289,   270,   271,   288,
     290,   273,   221,     0,   223,   376,   338,   242,   243,   227,
     233,   231,     0,   232,     0,   252,     0,     0,   332,   379,
       0,     0,     0,     0,     0,     0,     0,   330,     0,   264,
     378,   373,     0,   374,     0,   375,   371,   118,    98,   188,
     322,   380,   381,   101,    97,   355,   367,   369,     0,   361,
      56,   362,   197,   368,   370,     0,   366,   356,   100,     4,
       3,     2,     0,     0,     0,     0,    85,     0,    12,     0,
       0,     0,     0,    10,     0,   364,   365,     9,   103,     8,
       6,     0,    89,    12,     0,     0,     0,   369,   363,   115,
     111,    31,    30,    29,     0,     0,     0,     0,    38,     0,
       0,     0,    37,     0,    36,    34,    33,   159,   160,   161,
       0,     0,     0,     0,     0,   168,   131,     0,     0,   135,
       0,     0,   172,     0,   183,   179,   184,   185,     0,   181,
     169,     0,   142,   213,     0,     0,   211,   200,     0,   196,
     194,   195,     0,     0,   192,   193,   105,     0,   182,     0,
       0,     0,     0,   204,   201,   189,   190,   191,   106,   103,
     218,     0,   339,   226,   224,   240,   241,   247,     0,   246,
     244,     0,   248,   285,   286,   287,     0,   291,   245,   334,
     257,     0,   259,   251,   249,     0,     0,   335,   333,   357,
     358,   360,   359,     0,   341,    92,     0,     0,     0,     0,
     265,     0,   342,   343,   352,   266,   269,   268,   353,   267,
     344,   117,   119,    96,    57,    58,    19,    27,     0,     0,
       0,     0,     0,     0,     8,     6,    13,    21,    14,    22,
      84,    99,    11,     0,    81,     0,     0,    87,    86,    15,
      23,    16,    24,     0,     0,   102,    55,     0,     7,     0,
       5,    88,    91,    90,     0,   113,    45,    53,     0,     0,
       0,    38,     0,     0,     0,    34,    33,    39,    47,    40,
      48,     0,     0,   110,    41,    49,    42,    50,     0,     0,
     121,   120,     0,    35,     0,    32,     0,   124,   125,   129,
     128,   134,     0,     0,   139,   138,     0,   147,   175,     0,
     170,     0,   173,   187,   186,   141,   140,   212,   199,   180,
     206,   209,   203,   208,   205,     0,   202,     0,   225,     0,
     285,   286,   287,     0,   291,   239,     0,   301,   303,   302,
     304,   308,   305,   309,   280,   307,   306,   310,     0,     0,
     323,   321,   320,   314,   318,   326,   311,   312,   313,   315,
     316,   317,   281,   327,   127,     0,   309,   282,   326,   283,
     326,   284,   258,     0,   250,     0,   260,   255,   262,   261,
       0,   263,   256,     0,   354,   340,     0,    11,     0,     0,
       0,   351,   350,   345,     8,     6,     0,     0,    80,    83,
      82,    20,    28,     0,     0,    18,    26,    17,    25,   112,
      34,    33,     0,     0,   109,   333,    46,    54,     0,     0,
      44,    52,    43,    51,     0,     0,   164,   162,   163,   165,
     133,     0,     0,   148,   137,     0,   149,   176,   174,   171,
       0,   217,   216,   237,   309,   326,   238,   319,   254,     0,
     235,     0,   347,   348,   349,     0,    94,    95,   346,   122,
     123,   166,     0,     0,     0,   150,   153,     0,   157,     0,
     154,   155,   156,     0,   236,   253,     0,    93,   167,     0,
     146,     0,     0,   207,     0,   145,   144,   152,   158,     0,
     143,   151,     0,   234
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   158,   159,   160,   161,   190,   191,   192,   193,   486,
     162,   163,   164,     9,    10,    11,    43,    44,   294,   295,
     165,    90,   166,   296,   348,   183,    47,    48,    49,    50,
     197,   132,   361,   383,    52,   121,   122,    55,    56,   443,
     216,    58,   430,   219,   233,   234,   520,   220,   217,   395,
     391,   524,   557,   558,   210,   211,   212,   521,   553,   218,
     235,    60,   400,   401,   431,   444,    63,   225,   226,   227,
     432,    65,    66,    67,    68,    69,   239,    70,   414,   415,
     410,    71,    72,   236,    12,    13,    92,   532,   261,    93,
      14,    15,   102,    16,    17,   109,   110,   541,   111,   112,
     268,   113,   464,   465,   283,   284,   285,   286,   467,   269,
     270,    73,   271,   272,   420,    95,    96,    74,    75,    76,
      99,   100,    77,   534,   434,   535,   446,   447,   448,   449,
     450,   451,   435,   452,   436,    18,    19,   115,    82,    83,
     372,   453,   127,   302,   475,   278,   476,   171,   172,   297,
     173,   202,   174,   175,   176,   177,    20,    21,   136,   118,
      84,   137,   129,   179,   180
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -277
static const yytype_int16 yypact[] =
{
    1129,  -277,  -277,  -277,    42,  -277,  -277,  -277,  -277,    96,
    -277,  1590,  -277,  1238,  -277,   364,  -277,   550,  -277,   829,
    -277,  1625,  -277,  -277,  -277,    97,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,    69,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  1329,  1329,  -277,  -277,  -277,
      59,  1450,  -277,   143,    22,  -277,  -277,    72,  -277,    19,
    -277,   126,   126,  -277,  1238,  -277,   187,   187,  -277,  1001,
    -277,  1001,  -277,   101,  -277,  -277,  -277,  -277,  1238,  1521,
    1521,  1625,   101,  -277,  -277,    97,  -277,  -277,  -277,  -277,
     126,  -277,  -277,    84,  -277,  -277,  -277,   411,   438,  -277,
    -277,   445,  -277,   133,   126,  -277,  -277,   275,  -277,  -277,
    -277,  -277,  1667,  -277,   117,   305,   117,   169,  -277,  -277,
    1372,    91,   197,   193,   193,   578,   247,  -277,   193,  -277,
    -277,  -277,   216,  -277,    33,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,   212,  -277,  -277,   223,   213,  -277,
    -277,   238,  -277,  -277,  -277,   228,  -277,  -277,  -277,  -277,
    -277,  -277,  1493,  1493,  1493,   225,  -277,  1493,  1329,   187,
     187,  1493,  1493,  -277,  1493,  -277,  -277,  -277,   264,    46,
      46,   225,  -277,  -277,   187,   187,   283,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  1525,  1525,  1525,   456,  1525,    59,
    1525,  1525,  -277,  1525,  -277,   -27,   -27,  -277,  -277,  -277,
     456,  1493,  1493,   187,   187,  -277,  -277,   246,   169,  -277,
      88,   169,   -24,   126,  -277,  -277,  -277,  -277,    51,  -277,
    -277,   211,  -277,  -277,   456,   456,  -277,  -277,   456,  -277,
    -277,  -277,   268,   268,  -277,  -277,  -277,   698,  -277,   241,
     298,   241,   298,   227,   227,  -277,  -277,  -277,  -277,  -277,
    -277,   298,  -277,  -277,   126,  -277,  -277,  -277,  1667,  -277,
    -277,   456,  -277,   582,  1172,  1723,  1691,  1752,  -277,  -277,
    -277,   262,  -277,   233,  -277,  1684,  1684,  -277,   277,  -277,
    -277,  -277,  -277,   306,  -277,  -277,   698,   702,   169,   169,
    -277,   456,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  1341,  1341,
    1341,  1341,  1341,  1341,    46,    46,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   225,  -277,   187,   187,  -277,  -277,  -277,
    -277,  -277,  -277,  1341,   291,  -277,  -277,  1493,  -277,  1493,
    -277,  -277,  -277,  -277,   456,  -277,  -277,  -277,   470,   470,
     470,  -277,   470,   470,   470,   -27,   -27,  -277,  -277,  -277,
    -277,  1525,   169,  -277,  -277,  -277,  -277,  -277,   470,   291,
    -277,  -277,  1525,  -277,  1525,  -277,    20,  -277,  -277,  -277,
    -277,    52,  1493,   169,  -277,    52,  1493,  -277,  -277,   280,
    -277,   456,   -24,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  1493,  -277,   267,  -277,   456,
    -277,  1172,  1723,  1691,  1752,   456,   278,  -277,  -277,  -277,
    -277,  -277,  -277,   655,  -277,  -277,  -277,  -277,   218,   265,
    -277,  -277,  -277,  -277,  -277,   872,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,     2,    69,   894,  -277,   999,  -277,
    1031,  -277,  -277,   324,  -277,   456,  -277,  -277,  -277,  -277,
     198,  -277,  -277,   290,  -277,  -277,  1684,  -277,   698,  1493,
     377,  -277,  -277,   456,   342,   342,  1341,  1341,  -277,  -277,
    -277,  -277,  -277,   243,   243,  -277,  -277,  -277,  -277,  -277,
     235,   235,   470,   470,  -277,  -277,  -277,  -277,   243,   243,
    -277,  -277,  -277,  -277,  1493,  1493,  -277,  -277,  -277,  -277,
    -277,    76,  1493,  -277,  -277,  1161,  -277,  -277,  -277,  -277,
     306,  -277,  -277,   456,  -277,  -277,  -277,  -277,  -277,  1493,
    -277,   377,  -277,  -277,  -277,  1493,  -277,  -277,  -277,  -277,
    -277,  -277,   320,   193,   169,  -277,  -277,   193,  -277,    59,
    -277,  -277,  -277,    19,  -277,  -277,   169,  -277,  -277,   169,
     169,   169,   377,  -277,   277,   169,  -277,   169,  -277,   290,
    -277,  -277,   377,  -277
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -277,   163,   928,   259,  -277,  -177,   957,    65,  -277,   381,
     594,   754,   822,  -277,  -277,  -277,  -277,  -277,  -140,  -277,
       5,   123,    43,   -18,  -171,    87,  -277,  -277,  -277,  -277,
     182,    -8,   -20,  -174,  -277,    36,    83,  -277,  -277,    -1,
    -277,  -277,     4,  -277,    70,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,   -48,  -183,   -22,   -25,  -277,  -277,
      17,  -277,   -26,  -277,   366,    -6,  -277,   -40,  -277,  -277,
     376,  -277,    29,    82,  -277,  -277,  -152,  -277,   135,  -277,
     140,  -277,  -277,  -134,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -179,  -277,  -277,
     137,  -277,  -277,  -277,  -277,  -277,  -276,  -277,   127,   -12,
      -5,   -15,  -277,  -266,   315,  -277,  -277,    31,   134,   -96,
    -277,  -277,   157,  -204,  -263,   178,  -277,  -277,  -277,   398,
    -277,     6,    11,  -247,   401,  -277,  -277,   514,     7,  -277,
     114,   312,  -277,   -21,  -277,   -11,  -113,   840,   886,  -277,
    -277,  -277,   947,  -277,  -277,   498,  -277,  -277,  -277,   -72,
      40,   286,   302,   420,   488
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -338
static const yytype_int16 yytable[] =
{
     103,   133,   114,    51,   125,    62,   134,   123,   128,   350,
      57,   221,   473,   457,   124,    59,   276,    79,   338,   471,
     471,   373,    80,   138,   116,   330,   126,   167,   167,   459,
     461,   198,   385,   353,   392,   337,   199,   396,   247,   398,
     380,   351,   186,   207,    97,   288,   208,    53,  -229,   228,
     352,   181,    97,    85,   242,   104,   242,   241,   345,   245,
     381,   256,   390,   228,   249,   249,   134,   516,   252,   254,
     433,    85,   456,   298,   169,   184,   243,   209,   243,   389,
     517,   399,  -229,   213,   238,   178,   251,   251,   518,   182,
     346,    32,   152,  -229,    54,    97,    22,   125,    46,    39,
      91,   222,   223,   303,   215,   230,   120,   310,   131,    97,
      97,    97,    97,   551,   208,   207,   537,    32,   138,   126,
     230,    85,   139,    36,   306,    37,   312,   170,   185,   307,
     259,   117,   168,    23,    45,    41,   214,   237,   299,   260,
     301,   301,   140,   274,   264,   301,   393,    98,  -229,   397,
     167,   224,   231,   232,   350,    98,   240,   106,   244,   519,
     457,   304,   308,   346,   262,   224,   355,   207,   255,   208,
     101,   199,   423,   333,   552,   105,   459,   461,   101,   199,
     199,   199,   114,   199,   490,   199,   199,   238,   199,   423,
     423,   312,   385,   488,   504,   114,   246,   335,    98,   267,
     209,   489,   238,   514,   116,   258,   119,   409,   305,   309,
     544,   334,    98,    98,    98,    98,   230,   116,    25,   114,
     114,   101,   230,   114,   130,    27,   481,   482,   279,   313,
     287,   238,   228,    28,   403,   101,   101,   101,   101,   404,
     237,   116,   116,  -337,   289,   116,   275,   314,   246,   258,
     336,   231,   232,   125,   332,   237,   114,   246,  -297,   357,
     368,   370,   315,   402,  -104,   375,   377,    25,   379,   277,
     470,   470,   208,   468,   468,   126,   405,   480,   116,   478,
     469,   469,   134,   293,   237,   304,   114,   308,    25,    29,
     394,   130,   243,   243,   141,    29,   142,    24,   579,   421,
     505,   141,   380,   462,   418,   413,   265,   290,   116,   145,
     428,   463,   428,   146,   350,   266,   421,   421,   280,   474,
     527,   523,   381,   531,   148,   305,   309,   385,    94,   291,
     331,   139,   537,   292,   224,    30,   135,   538,   140,   114,
     150,    32,   189,   199,   199,   199,   280,   199,   199,   199,
     540,   246,   281,   238,   345,   267,   199,   429,    38,   429,
     346,   116,   568,   199,   515,   246,   258,   199,   354,   199,
     525,    23,   466,   466,   387,   388,   529,    61,    24,   229,
     423,   282,   153,   477,   479,   130,   114,    64,   437,   416,
     437,    24,   412,   248,   250,   253,   257,   427,    42,   427,
     582,   155,   422,   156,   114,   419,   237,   157,   116,    78,
     114,  -286,    81,   472,  -286,   263,    30,   563,   311,   422,
     422,   317,   327,   329,   300,   424,   116,   273,     0,    30,
     340,   342,   116,   344,     0,    32,     0,     0,  -287,    38,
       0,  -287,   424,   424,   507,  -291,     0,   511,  -291,   513,
     114,     0,    38,   445,   458,   460,     0,   428,     0,   428,
     547,   242,   105,     0,   543,   199,  -286,     0,   114,   306,
      24,   205,   116,   141,   307,   142,     0,     0,   130,    42,
       0,    26,   570,   243,    24,     0,     0,   199,   199,  -286,
     116,     0,    42,  -287,   574,   187,   106,   575,   576,   577,
    -291,     0,     0,   580,   429,   581,   429,   421,    30,   188,
     125,     0,     0,   560,   562,   573,  -287,     0,   114,   559,
     561,   566,    30,  -291,     0,     0,   199,     0,    32,     0,
       0,    38,   126,     0,     0,   437,     0,   437,   554,   206,
     116,     0,     0,     0,   427,    38,   427,     0,     0,   204,
       0,   572,   578,   305,     0,   522,   105,   199,     0,   526,
     347,   349,   583,   542,    24,   545,     0,   199,     0,     0,
     569,    42,   154,     0,   571,    26,     0,     0,   530,     0,
       0,     0,   324,   324,   324,    42,   382,   384,  -279,     0,
     106,   324,   324,   246,   324,     0,  -279,     0,    25,     0,
       0,   107,    30,   492,     0,    27,   496,  -279,   498,     0,
     422,     0,   556,    28,   365,   365,   365,     0,   205,     0,
     365,   365,  -279,   365,     0,    38,    29,     0,     0,     0,
       0,     0,     0,   424,  -279,     0,     0,     0,     0,     0,
       0,     0,   546,     0,     0,   194,     0,     0,     0,     0,
     325,   325,   325,     0,     0,     0,   108,  -279,     0,   325,
     325,  -274,   325,     0,     0,    42,     0,     0,     0,  -274,
     411,     0,   411,     0,     0,     0,     0,   549,   550,     0,
    -274,   417,   366,   366,   366,   555,   206,     0,   366,   366,
       0,   366,   204,   204,   204,  -274,   204,  -279,   204,   204,
       0,   204,   565,     0,     0,    23,   487,  -274,   567,    23,
     130,   371,    24,   143,     0,     0,    24,     0,    85,     0,
       0,     0,    85,    26,   386,     0,     0,    26,     0,     0,
    -274,     0,     0,     0,     0,     0,     0,     0,   484,   484,
     484,   484,   484,   484,     0,     0,   502,   503,   406,   407,
      30,     0,   408,     0,    30,     0,   318,   318,   318,     0,
      32,     0,     0,   484,   493,   318,   318,   324,   318,   324,
    -274,     0,     0,    38,     0,     0,     0,    38,   500,   500,
     500,     0,   500,   500,   500,   425,     0,     0,   358,   358,
     358,   205,   194,     0,   358,   358,     0,   358,   500,   508,
       0,     0,   365,     0,   365,   195,   485,   485,   485,   485,
     485,   485,     0,    42,     0,   483,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,   494,     0,     0,   325,    23,   325,   119,     0,
       0,     0,     0,    24,     0,     0,   501,   501,   501,    25,
     501,   501,   501,     0,    26,     0,   204,   204,   204,   206,
     204,   204,   204,     0,     0,     0,   501,   509,   499,   204,
     366,     0,   366,   196,     0,   487,   204,    29,  -275,     0,
     204,    30,   204,     0,     0,     0,  -275,     0,     0,   502,
     503,   200,     0,     0,     0,     0,     0,  -275,     0,     0,
    -276,     0,     0,     0,    38,     0,   484,   484,  -276,     0,
       0,     0,  -275,     0,     0,   528,   319,   319,   319,  -276,
       0,     0,   500,   500,  -275,   319,   319,     0,   319,     0,
       0,     0,     0,   533,  -276,     0,     0,   201,   318,   536,
       0,   318,     0,   318,    42,     0,  -276,  -275,   359,   359,
     359,     0,   195,     0,   359,   359,     0,   359,     0,     0,
       0,     0,     0,     0,     0,   194,     0,     0,     0,  -276,
       0,     0,     0,   358,   485,   485,   358,     0,   358,   539,
       0,     0,     0,     0,   320,   320,   320,  -275,     0,     0,
     501,   501,     0,   320,   320,     0,   320,   548,   203,     0,
     204,   204,   321,   321,   321,  -277,     0,     0,    23,  -276,
     119,   321,   321,  -277,   321,    24,   360,   360,   360,     0,
     196,    25,   360,   360,  -277,   360,    26,     0,     0,     0,
       0,     0,     0,     0,   362,   362,   362,  -278,   200,  -277,
     362,   362,     0,   362,     0,  -278,     0,   564,   322,   322,
     322,  -277,     0,    30,     0,     0,  -278,   322,   322,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -278,     0,     0,  -277,     0,    38,     0,     0,     0,
     363,   363,   363,  -278,   201,     0,   363,   363,     0,   363,
     316,   326,   328,     0,     0,     0,     0,     0,   319,   339,
     341,   319,   343,   319,     0,     0,  -278,     0,     0,   323,
     323,   323,     0,     0,  -277,     0,    42,     0,   323,   323,
       0,   323,     0,     0,     0,   195,     0,     0,     0,     0,
       0,     0,     0,   359,     0,     0,   359,     0,   359,     1,
       0,   364,   364,   364,     2,   203,  -278,   364,   364,     0,
     364,   356,   367,   369,     0,     0,     0,   374,   376,     0,
     378,     0,     0,     0,     0,     0,   320,     3,    23,   320,
     119,   320,     0,     4,     5,    24,     0,     0,     0,     0,
       0,    25,     0,     0,   321,     0,    26,   321,     0,   321,
       0,     0,    25,   196,     0,     0,     0,     0,     6,    27,
       0,   360,     0,     0,   360,     0,   360,  -270,     0,    29,
       0,   200,   106,    30,     0,     0,     0,     0,     0,   362,
      29,     0,   362,    33,   362,    31,     0,     0,     0,     0,
     322,     0,     7,   322,     0,   322,    38,     0,     8,     0,
       0,     0,   426,     0,    36,    23,   316,   326,   328,   339,
     341,   343,    24,     0,     0,     0,     0,   201,    85,     0,
       0,     0,    40,    26,     0,   363,     0,     0,   363,     0,
     363,   491,     0,     0,     0,   495,    42,   497,     0,     0,
       0,     0,     0,     0,    86,     0,     0,     0,    87,     0,
      30,   323,     0,     0,   323,     0,   323,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,   356,   367,   369,   203,   374,
     376,   378,     0,    89,     0,     0,   364,     0,     0,   364,
       0,   364,   141,     0,   142,   506,    23,     0,     0,   510,
     143,   512,     0,    24,   141,   144,   142,   145,    23,    85,
       0,   146,   143,    42,   147,    24,     0,     0,     0,     0,
       0,    85,   148,     0,     0,     0,   147,     0,   149,     0,
       0,     0,     0,     0,     0,   141,     0,   142,   150,    23,
     149,   151,     0,   143,     0,     0,    24,     0,     0,     0,
     145,   289,    85,   151,   146,     0,     0,   147,     0,   152,
       0,     0,     0,     0,    38,   148,    39,     0,     0,     0,
       0,   149,     0,     0,   495,   497,    38,     0,     0,     0,
     153,   150,     0,     0,   151,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,   155,
       0,   156,    41,   154,    42,   157,     0,    38,     0,     0,
       0,     0,     0,   141,   290,   142,    42,     0,   130,   510,
     512,     0,     0,   153,    24,     0,     0,     0,   145,     0,
       0,     0,   146,     0,   154,   187,   291,     0,     0,     0,
     292,     0,   155,   148,   156,     0,     0,    42,   157,   188,
       0,     0,     0,     0,     0,     0,   141,     0,   142,   150,
      23,     0,    30,     0,   143,     0,     0,    24,    32,   189,
       0,   145,     0,    85,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,    38,   148,     0,   141,     0,
     142,     0,   149,   130,     0,    24,     0,     0,     0,    24,
       0,   153,   150,   145,     0,   151,    26,   146,     0,     0,
     187,     0,   154,     0,     0,     0,     0,     0,   148,     0,
     155,     0,   156,     0,   188,    42,   157,    86,    38,    29,
       0,    87,     0,    30,   150,     0,     0,    30,     0,     0,
       0,     0,    88,    32,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,    38,    23,     0,     0,
      38,     0,     0,   155,    24,   156,    89,     0,    42,   157,
      25,     0,     0,     0,     0,    26,   153,    27,     0,     0,
       0,     0,     0,     0,     0,    28,     0,   154,     0,     0,
       0,     0,    23,   130,     0,   155,    42,   156,    29,    24,
      42,   157,    30,    31,     0,    85,     0,     0,    32,     0,
      26,     0,    33,     0,     0,     0,     0,     0,    34,     0,
      35,     0,    36,     0,    37,    38,     0,    39,     0,     0,
       0,    86,     0,     0,    23,    87,   119,    30,     0,     0,
      40,    24,     0,    32,     0,     0,    88,    25,     0,     0,
       0,    23,    26,   119,     0,     0,     0,     0,    24,     0,
      38,     0,     0,    41,    25,    42,     0,     0,     0,    26,
      89,   454,     0,    86,     0,    29,     0,    87,    27,    30,
       0,     0,   262,     0,     0,     0,    28,     0,    88,     0,
      86,   106,     0,     0,    87,     0,    30,     0,     0,    29,
      42,     0,    38,   438,    31,    88,     0,     0,     0,     0,
    -271,     0,    89,    33,   262,     0,     0,     0,    28,    38,
       0,   455,     0,    36,   440,    37,     0,     0,     0,    89,
       0,  -271,   438,     0,     0,     0,     0,     0,     0,  -273,
       0,    40,    42,   262,     0,    33,     0,    28,     0,     0,
       0,     0,   441,   439,     0,     0,   440,    37,     0,    42,
    -273,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,   439,     0,   441,   440,    37,     0,     0,     0,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   442
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-277)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      15,    21,    17,    11,    19,    11,    21,    19,    19,   180,
      11,    59,   288,   276,    19,    11,   112,    11,   170,   285,
     286,   198,    11,    21,    17,   165,    19,    45,    46,   276,
     277,    51,   206,   185,   217,   169,    51,   220,    78,    63,
      67,   181,    50,    24,    13,   117,    26,    11,     6,    64,
     184,    46,    21,    20,    69,    15,    71,    69,    12,    71,
      87,    81,   214,    78,    79,    80,    81,    15,    79,    80,
     274,    20,   276,   121,    45,    46,    69,    57,    71,   213,
      28,   105,    40,    54,    67,    45,    79,    80,    36,    46,
     117,    58,    70,    51,    11,    64,     0,   112,    11,    77,
      13,    61,    62,   124,    32,    29,    19,   128,    21,    78,
      79,    80,    81,    37,    26,    24,   114,    58,    21,   112,
      29,    20,    53,    72,   125,    74,   134,    45,    46,   125,
      90,    17,    45,     7,    11,   113,    54,    67,   121,    55,
     123,   124,    73,   112,   104,   128,   218,    13,   106,   221,
     168,    64,    64,    65,   325,    21,    69,    40,    71,   107,
     423,   125,   126,   117,    31,    78,   186,    24,    81,    26,
      13,   186,   268,   168,    98,     6,   423,   424,    21,   194,
     195,   196,   197,   198,   336,   200,   201,   170,   203,   285,
     286,   199,   366,   333,   371,   210,    73,   168,    64,   112,
      57,   335,   185,   386,   197,    82,     9,   247,   125,   126,
     476,   168,    78,    79,    80,    81,    29,   210,    20,   234,
     235,    64,    29,   238,     8,    27,   298,   299,   114,    17,
     116,   214,   247,    35,   228,    78,    79,    80,    81,   228,
     170,   234,   235,    20,    19,   238,   112,    34,   125,   126,
     168,    64,    65,   268,   167,   185,   271,   134,    20,   194,
     195,   196,    34,   223,     0,   200,   201,    20,   203,   112,
     285,   286,    26,   285,   286,   268,    65,   297,   271,   297,
     285,   286,   297,   120,   214,   249,   301,   251,    20,    48,
     220,     8,   285,   286,     3,    48,     5,    14,   574,   268,
     372,     3,    67,    41,   264,    78,    31,    82,   301,    18,
     274,    78,   276,    22,   485,    40,   285,   286,    41,    13,
      40,   393,    87,    56,    33,   242,   243,   501,    13,   104,
     167,    53,   114,   108,   247,    52,    21,    13,    73,   354,
      49,    58,    59,   358,   359,   360,    41,   362,   363,   364,
      60,   228,    47,   336,    12,   268,   371,   274,    75,   276,
     117,   354,    42,   378,   386,   242,   243,   382,   186,   384,
     395,     7,   285,   286,   211,   212,   402,    11,    14,    64,
     476,    76,    91,   296,   297,     8,   401,    11,   274,   254,
     276,    14,   252,    78,    79,    80,    81,   274,   115,   276,
     579,   110,   268,   112,   419,   268,   336,   116,   401,    11,
     425,     0,    11,   286,     3,   103,    52,   530,   132,   285,
     286,   162,   163,   164,   122,   268,   419,   112,    -1,    52,
     171,   172,   425,   174,    -1,    58,    -1,    -1,     0,    75,
      -1,     3,   285,   286,   379,     0,    -1,   382,     3,   384,
     465,    -1,    75,   275,   276,   277,    -1,   421,    -1,   423,
     480,   476,     6,    -1,   476,   480,    55,    -1,   483,   470,
      14,    51,   465,     3,   470,     5,    -1,    -1,     8,   115,
      -1,    25,   554,   476,    14,    -1,    -1,   502,   503,    78,
     483,    -1,   115,    55,   566,    25,    40,   569,   570,   571,
      55,    -1,    -1,   575,   421,   577,   423,   476,    52,    39,
     525,    -1,    -1,   525,   525,   563,    78,    -1,   533,   525,
     525,   541,    52,    78,    -1,    -1,   541,    -1,    58,    -1,
      -1,    75,   525,    -1,    -1,   421,    -1,   423,   521,    51,
     533,    -1,    -1,    -1,   421,    75,   423,    -1,    -1,    51,
      -1,   559,   572,   470,    -1,   392,     6,   572,    -1,   396,
     179,   180,   582,   476,    14,   478,    -1,   582,    -1,    -1,
     553,   115,   102,    -1,   557,    25,    -1,    -1,   415,    -1,
      -1,    -1,   162,   163,   164,   115,   205,   206,     6,    -1,
      40,   171,   172,   470,   174,    -1,    14,    -1,    20,    -1,
      -1,    51,    52,   344,    -1,    27,   347,    25,   349,    -1,
     476,    -1,   525,    35,   194,   195,   196,    -1,   198,    -1,
     200,   201,    40,   203,    -1,    75,    48,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,    51,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,   106,    75,    -1,   171,
     172,     6,   174,    -1,    -1,   115,    -1,    -1,    -1,    14,
     250,    -1,   252,    -1,    -1,    -1,    -1,   514,   515,    -1,
      25,   261,   194,   195,   196,   522,   198,    -1,   200,   201,
      -1,   203,   194,   195,   196,    40,   198,   115,   200,   201,
      -1,   203,   539,    -1,    -1,     7,   325,    52,   545,     7,
       8,   197,    14,    11,    -1,    -1,    14,    -1,    20,    -1,
      -1,    -1,    20,    25,   210,    -1,    -1,    25,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,
     320,   321,   322,   323,    -1,    -1,   365,   366,   234,   235,
      52,    -1,   238,    -1,    52,    -1,   162,   163,   164,    -1,
      58,    -1,    -1,   343,   344,   171,   172,   347,   174,   349,
     115,    -1,    -1,    75,    -1,    -1,    -1,    75,   358,   359,
     360,    -1,   362,   363,   364,   271,    -1,    -1,   194,   195,
     196,   371,   198,    -1,   200,   201,    -1,   203,   378,   379,
      -1,    -1,   382,    -1,   384,    51,   318,   319,   320,   321,
     322,   323,    -1,   115,    -1,   301,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,   344,    -1,    -1,   347,     7,   349,     9,    -1,
      -1,    -1,    -1,    14,    -1,    -1,   358,   359,   360,    20,
     362,   363,   364,    -1,    25,    -1,   358,   359,   360,   371,
     362,   363,   364,    -1,    -1,    -1,   378,   379,   354,   371,
     382,    -1,   384,    51,    -1,   494,   378,    48,     6,    -1,
     382,    52,   384,    -1,    -1,    -1,    14,    -1,    -1,   508,
     509,    51,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
       6,    -1,    -1,    -1,    75,    -1,   486,   487,    14,    -1,
      -1,    -1,    40,    -1,    -1,   401,   162,   163,   164,    25,
      -1,    -1,   502,   503,    52,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,   419,    40,    -1,    -1,    51,   344,   425,
      -1,   347,    -1,   349,   115,    -1,    52,    75,   194,   195,
     196,    -1,   198,    -1,   200,   201,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    75,
      -1,    -1,    -1,   379,   486,   487,   382,    -1,   384,   465,
      -1,    -1,    -1,    -1,   162,   163,   164,   115,    -1,    -1,
     502,   503,    -1,   171,   172,    -1,   174,   483,    51,    -1,
     502,   503,   162,   163,   164,     6,    -1,    -1,     7,   115,
       9,   171,   172,    14,   174,    14,   194,   195,   196,    -1,
     198,    20,   200,   201,    25,   203,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,   196,     6,   198,    40,
     200,   201,    -1,   203,    -1,    14,    -1,   533,   162,   163,
     164,    52,    -1,    52,    -1,    -1,    25,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    75,    -1,    75,    -1,    -1,    -1,
     194,   195,   196,    52,   198,    -1,   200,   201,    -1,   203,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,   344,   171,
     172,   347,   174,   349,    -1,    -1,    75,    -1,    -1,   162,
     163,   164,    -1,    -1,   115,    -1,   115,    -1,   171,   172,
      -1,   174,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   379,    -1,    -1,   382,    -1,   384,    10,
      -1,   194,   195,   196,    15,   198,   115,   200,   201,    -1,
     203,   194,   195,   196,    -1,    -1,    -1,   200,   201,    -1,
     203,    -1,    -1,    -1,    -1,    -1,   344,    38,     7,   347,
       9,   349,    -1,    44,    45,    14,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,   344,    -1,    25,   347,    -1,   349,
      -1,    -1,    20,   371,    -1,    -1,    -1,    -1,    69,    27,
      -1,   379,    -1,    -1,   382,    -1,   384,    35,    -1,    48,
      -1,   371,    40,    52,    -1,    -1,    -1,    -1,    -1,   379,
      48,    -1,   382,    62,   384,    53,    -1,    -1,    -1,    -1,
     344,    -1,   103,   347,    -1,   349,    75,    -1,   109,    -1,
      -1,    -1,    70,    -1,    72,     7,   318,   319,   320,   321,
     322,   323,    14,    -1,    -1,    -1,    -1,   371,    20,    -1,
      -1,    -1,    90,    25,    -1,   379,    -1,    -1,   382,    -1,
     384,   343,    -1,    -1,    -1,   347,   115,   349,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,
      52,   344,    -1,    -1,   347,    -1,   349,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,   358,   359,   360,   371,   362,
     363,   364,    -1,    85,    -1,    -1,   379,    -1,    -1,   382,
      -1,   384,     3,    -1,     5,   378,     7,    -1,    -1,   382,
      11,   384,    -1,    14,     3,    16,     5,    18,     7,    20,
      -1,    22,    11,   115,    25,    14,    -1,    -1,    -1,    -1,
      -1,    20,    33,    -1,    -1,    -1,    25,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    49,     7,
      39,    52,    -1,    11,    -1,    -1,    14,    -1,    -1,    -1,
      18,    19,    20,    52,    22,    -1,    -1,    25,    -1,    70,
      -1,    -1,    -1,    -1,    75,    33,    77,    -1,    -1,    -1,
      -1,    39,    -1,    -1,   486,   487,    75,    -1,    -1,    -1,
      91,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,   113,   102,   115,   116,    -1,    75,    -1,    -1,
      -1,    -1,    -1,     3,    82,     5,   115,    -1,     8,   502,
     503,    -1,    -1,    91,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    -1,   102,    25,   104,    -1,    -1,    -1,
     108,    -1,   110,    33,   112,    -1,    -1,   115,   116,    39,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    49,
       7,    -1,    52,    -1,    11,    -1,    -1,    14,    58,    59,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    33,    -1,     3,    -1,
       5,    -1,    39,     8,    -1,    14,    -1,    -1,    -1,    14,
      -1,    91,    49,    18,    -1,    52,    25,    22,    -1,    -1,
      25,    -1,   102,    -1,    -1,    -1,    -1,    -1,    33,    -1,
     110,    -1,   112,    -1,    39,   115,   116,    46,    75,    48,
      -1,    50,    -1,    52,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    61,    58,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    75,     7,    -1,    -1,
      75,    -1,    -1,   110,    14,   112,    85,    -1,   115,   116,
      20,    -1,    -1,    -1,    -1,    25,    91,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,   102,    -1,    -1,
      -1,    -1,     7,     8,    -1,   110,   115,   112,    48,    14,
     115,   116,    52,    53,    -1,    20,    -1,    -1,    58,    -1,
      25,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    74,    75,    -1,    77,    -1,    -1,
      -1,    46,    -1,    -1,     7,    50,     9,    52,    -1,    -1,
      90,    14,    -1,    58,    -1,    -1,    61,    20,    -1,    -1,
      -1,     7,    25,     9,    -1,    -1,    -1,    -1,    14,    -1,
      75,    -1,    -1,   113,    20,   115,    -1,    -1,    -1,    25,
      85,    20,    -1,    46,    -1,    48,    -1,    50,    27,    52,
      -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    61,    -1,
      46,    40,    -1,    -1,    50,    -1,    52,    -1,    -1,    48,
     115,    -1,    75,    20,    53,    61,    -1,    -1,    -1,    -1,
      27,    -1,    85,    62,    31,    -1,    -1,    -1,    35,    75,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    85,
      -1,    48,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    90,   115,    31,    -1,    62,    -1,    35,    -1,    -1,
      -1,    -1,   101,    70,    -1,    -1,    73,    74,    -1,   115,
      48,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,   101,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,    15,    38,    44,    45,    69,   103,   109,   131,
     132,   133,   202,   203,   208,   209,   211,   212,   253,   254,
     274,   275,     0,     7,    14,    20,    25,    27,    35,    48,
      52,    53,    58,    62,    68,    70,    72,    74,    75,    77,
      90,   113,   115,   134,   135,   139,   143,   144,   145,   146,
     147,   149,   152,   153,   154,   155,   156,   157,   159,   160,
     179,   182,   183,   184,   188,   189,   190,   191,   192,   193,
     195,   199,   200,   229,   235,   236,   237,   240,   247,   249,
     250,   252,   256,   257,   278,    20,    46,    50,    61,    85,
     139,   143,   204,   207,   232,   233,   234,   235,   236,   238,
     239,   240,   210,   229,   278,     6,    40,    51,   106,   213,
     214,   216,   217,   219,   229,   255,   256,   258,   277,     9,
     143,   153,   154,   227,   228,   229,   256,   260,   263,   280,
       8,   143,   149,   150,   229,   232,   276,   279,    21,    53,
      73,     3,     5,    11,    16,    18,    22,    25,    33,    39,
      49,    52,    70,    91,   102,   110,   112,   116,   119,   120,
     121,   122,   128,   129,   130,   138,   140,   141,   143,   190,
     191,   265,   266,   268,   270,   271,   272,   273,   278,   281,
     282,   138,   140,   143,   190,   191,   149,    25,    39,    59,
     123,   124,   125,   126,   128,   129,   130,   148,   150,   229,
     265,   266,   269,   270,   273,   281,   282,    24,    26,    57,
     172,   173,   174,   190,   191,    32,   158,   166,   177,   161,
     165,   172,   278,   278,   143,   185,   186,   187,   229,   232,
      29,    64,    65,   162,   163,   178,   201,   162,   178,   194,
     143,   227,   229,   256,   143,   227,   139,   185,   232,   229,
     232,   256,   263,   232,   263,   143,   150,   232,   139,   278,
      55,   206,    31,   259,   278,    31,    40,   143,   218,   227,
     228,   230,   231,   232,   235,   236,   237,   240,   263,   258,
      41,    47,    76,   222,   223,   224,   225,   258,   277,    19,
      82,   104,   108,   119,   136,   137,   141,   267,   172,   178,
     280,   178,   261,   261,   153,   154,   157,   160,   153,   154,
     261,   279,   149,    17,    34,    34,   120,   121,   128,   129,
     130,   265,   266,   270,   281,   282,   120,   121,   120,   121,
     136,   119,   143,   138,   140,   190,   191,   201,   194,   120,
     121,   120,   121,   120,   121,    12,   117,   127,   142,   127,
     142,   136,   201,   194,   148,   150,   124,   125,   128,   129,
     130,   150,   265,   266,   270,   281,   282,   124,   125,   124,
     125,   255,   258,   123,   124,   125,   124,   125,   124,   125,
      67,    87,   127,   151,   127,   151,   255,   119,   119,   201,
     194,   168,   173,   277,   162,   167,   173,   277,    63,   105,
     180,   181,   278,   249,   250,    65,   255,   255,   255,   185,
     198,   281,   198,    78,   196,   197,   196,   281,   278,   218,
     232,   235,   236,   237,   240,   255,    70,   139,   153,   154,
     160,   182,   188,   241,   242,   250,   252,   258,    20,    70,
      73,   101,   111,   157,   183,   243,   244,   245,   246,   247,
     248,   249,   251,   259,    20,    70,   241,   242,   243,   251,
     243,   251,    41,    78,   220,   221,   143,   226,   227,   228,
     229,   231,   226,   224,    13,   262,   264,   143,   141,   143,
     150,   277,   277,   255,   281,   282,   127,   127,   136,   201,
     194,   120,   121,   281,   282,   120,   121,   120,   121,   255,
     281,   282,   127,   127,   123,   277,   124,   125,   281,   282,
     124,   125,   124,   125,   173,   174,    15,    28,    36,   107,
     164,   175,   119,   277,   169,   175,   119,    40,   255,   180,
     119,    56,   205,   255,   241,   243,   255,   114,    13,   255,
      60,   215,   143,   227,   231,   143,   119,   150,   255,   119,
     119,    37,    98,   176,   178,   119,   143,   170,   171,   183,
     227,   228,   263,   264,   255,   119,   150,   119,    42,   178,
     277,   178,   149,   172,   277,   277,   277,   277,   150,   224,
     277,   277,   215,   150
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 117 "lyparse.y"
    {
                      (yyval.length) = (yyvsp[(1) - (1)].length);
                    }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 120 "lyparse.y"
    {
                      (yyval.length) = (yyvsp[(1) - (1)].length);
                    }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 123 "lyparse.y"
    {
                      (yyval.length) = (yyvsp[(1) - (1)].length);
                    }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 129 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(1) - (2)].dval);
                      (yyval.length) = length;
                    }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 134 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(1) - (1)].dval);
                      (yyval.length) = length;                      
                    }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 139 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (double)(yyvsp[(1) - (2)].ival);
                      (yyval.length) = length;
                    }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 144 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (double)(yyvsp[(1) - (1)].ival);
                      (yyval.length) = length;                      
                    }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 149 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = 4;//generate random number here
                      (yyval.length) = length;                                            
                    }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 154 "lyparse.y"
    {
                      Length* length = newLength();
                      Length* ll = getLastLength();
                      length->length = ll->length;
                      (yyval.length) = length;
                    }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 161 "lyparse.y"
    {
                      //assert(existsLineSegmentLabel($2->pA.label, $2->pB.label));                      
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].lineSegment)->length;
                      (yyval.length) = length;
                    }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 168 "lyparse.y"
    {
                      //assert(existsLineSegmentLabel($1->pA.label, $1->pB.label));
                      Length* length = newLength();
                      length->length = (yyvsp[(1) - (1)].lineSegment)->length;
                      (yyval.length) = length;
                    }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 178 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = epsilon + (yyvsp[(2) - (2)].length)->length;
                      (yyval.length) = length;
                    }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 184 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = -epsilon + (yyvsp[(2) - (2)].length)->length;
                      (yyval.length) = length;                    }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 189 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 2;
                      (yyval.length) = length;
                    }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 195 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 3;
                      (yyval.length) = length;
                    }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 201 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(3) - (3)].length)->length * (yyvsp[(1) - (3)].dval);
                      (yyval.length) = length;
                    }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 207 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(3) - (3)].length)->length * (yyvsp[(1) - (3)].ival);
                      (yyval.length) = length;
                    }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 213 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 0.5;
                      (yyval.length) = length;
                    }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 219 "lyparse.y"
    {
                      double result = getResult((yyvsp[(1) - (3)].operation), (yyvsp[(2) - (3)].length)->length, (yyvsp[(3) - (3)].length)->length);
                      Length* length = newLength();
                      length->length = result;
                      (yyval.length) = length;
                    }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 229 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = epsilon + (yyvsp[(2) - (2)].length)->length;
                      (yyval.length) = length;
                    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 235 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = -epsilon + (yyvsp[(2) - (2)].length)->length;
                      (yyval.length) = length;                    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 240 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 2;
                      (yyval.length) = length;
                    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 246 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 3;
                      (yyval.length) = length;
                    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 252 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(3) - (3)].length)->length * (yyvsp[(1) - (3)].dval);
                      (yyval.length) = length;
                    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 258 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(3) - (3)].length)->length * (yyvsp[(1) - (3)].ival);
                      (yyval.length) = length;
                    }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 264 "lyparse.y"
    {
                      Length* length = newLength();
                      length->length = (yyvsp[(2) - (2)].length)->length * 0.5;
                      (yyval.length) = length;
                    }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 270 "lyparse.y"
    {
                      double result = getResult((yyvsp[(1) - (3)].operation), (yyvsp[(2) - (3)].length)->length, (yyvsp[(3) - (3)].length)->length);
                      Length* length = newLength();
                      length->length = result;
                      (yyval.length) = length;
                    }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 279 "lyparse.y"
    { (yyval.degree) = (yyvsp[(1) - (1)].degree); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 280 "lyparse.y"
    { (yyval.degree) = (yyvsp[(1) - (1)].degree); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 281 "lyparse.y"
    { (yyval.degree) = (yyvsp[(1) - (1)].degree); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 285 "lyparse.y"
    {
                      Degree *degree = newDegree();
                      degree->degree = (yyvsp[(1) - (2)].dval);
                      (yyval.degree) = degree;
                    }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 290 "lyparse.y"
    {
                      Degree *degree = newDegree();
                      degree->degree = (yyvsp[(1) - (1)].dval);
                      (yyval.degree) = degree;
                    }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 295 "lyparse.y"
    {
                      Degree *degree = newDegree();
                      degree->degree = (yyvsp[(1) - (1)].ival);
                      (yyval.degree) = degree;
                    }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 300 "lyparse.y"
    {
                      Degree *degree = newDegree();
                      degree->degree = (yyvsp[(1) - (2)].ival);
                      (yyval.degree) = degree;
                    }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 305 "lyparse.y"
    {
                      Degree *degree = newDegree();
                      degree->degree = 30;
                      (yyval.degree) = degree;
                    }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 310 "lyparse.y"
    {
                      assert(existsLastAngle());
                      Angle la = getLastAngle();
                      Degree *degree = newDegree();
                      degree->degree = la.degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 317 "lyparse.y"
    {
		      char name[3];
		      name[0] = (yyvsp[(1) - (1)].angle)->leftVertex.label;
		      name[1] = (yyvsp[(1) - (1)].angle)->vertex.label;
		      name[2] = (yyvsp[(1) - (1)].angle)->rightVertex.label;
		      assert(existsAngle(name));
                      Degree *degree = newDegree();
                      degree->degree = (yyvsp[(1) - (1)].angle)->degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 331 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = epsilon + (yyvsp[(2) - (2)].degree)->degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 337 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = -epsilon + (yyvsp[(2) - (2)].degree)->degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 343 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 2;
                      (yyval.degree) = degree;
                    }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 349 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 3;
                      (yyval.degree) = degree;
                    }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 355 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(3) - (3)].degree)->degree * (yyvsp[(1) - (3)].dval);
                      (yyval.degree) = degree;
                    }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 361 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(3) - (3)].degree)->degree * (yyvsp[(1) - (3)].ival);
                      (yyval.degree) = degree;
                    }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 367 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 0.5;
                      (yyval.degree) = degree;
                    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 373 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = getResult((yyvsp[(1) - (3)].operation), (yyvsp[(2) - (3)].degree)->degree, (yyvsp[(3) - (3)].degree)->degree);
                      (yyval.degree) = degree;
                    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 382 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = epsilon + (yyvsp[(2) - (2)].degree)->degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 388 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = -epsilon + (yyvsp[(2) - (2)].degree)->degree;
                      (yyval.degree) = degree;
                    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 394 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 2;
                      (yyval.degree) = degree;
                    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 400 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 3;
                      (yyval.degree) = degree;
                    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 406 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(3) - (3)].degree)->degree * (yyvsp[(1) - (3)].dval);
                      (yyval.degree) = degree;
                    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 412 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(3) - (3)].degree)->degree * (yyvsp[(1) - (3)].ival);
                      (yyval.degree) = degree;
                    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 418 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = (yyvsp[(2) - (2)].degree)->degree * 0.5;
                      (yyval.degree) = degree;
                    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 424 "lyparse.y"
    {
                      Degree* degree = newDegree();
                      degree->degree = getResult((yyvsp[(1) - (3)].operation), (yyvsp[(2) - (3)].degree)->degree, (yyvsp[(3) - (3)].degree)->degree);
                      (yyval.degree) = degree;
                    }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 432 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 436 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 440 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 444 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 448 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 449 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 450 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 451 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 452 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 453 "lyparse.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); executeCommand(*(yyvsp[(1) - (1)].command)); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 458 "lyparse.y"
    {
                        Command *command = newCommand();
                        command->plottables = *(yyvsp[(2) - (2)].plottables);
                        (yyval.command) = command;
                      }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 466 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 467 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 471 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 472 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 473 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 474 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 475 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 476 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 477 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 478 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 479 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 480 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 481 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 482 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables);  }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 487 "lyparse.y"
    {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = (yyvsp[(4) - (4)].condition)->ls;
        LineSegment thisLineSegment = *(yyvsp[(2) - (4)].lineSegment);
        if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){
          spitError("line segment not same");
        }
        
        (yyvsp[(2) - (4)].lineSegment)->length = (yyvsp[(4) - (4)].condition)->length;
	if(!existsPoint((yyvsp[(2) - (4)].lineSegment)->pA)){
	  if(!existsPoint((yyvsp[(2) - (4)].lineSegment)->pB)){
	    //default position is (0,0)
	    (yyvsp[(2) - (4)].lineSegment)->pA.x = (yyvsp[(2) - (4)].lineSegment)->pA.y = 0.0;
	    (yyvsp[(2) - (4)].lineSegment)->pB.x = (yyvsp[(2) - (4)].lineSegment)->length;
	    (yyvsp[(2) - (4)].lineSegment)->pB.y = 0.0;
	  } else {
	    (yyvsp[(2) - (4)].lineSegment)->pA.x = (yyvsp[(2) - (4)].lineSegment)->pB.x - (yyvsp[(2) - (4)].lineSegment)->length;
	    (yyvsp[(2) - (4)].lineSegment)->pA.y = (yyvsp[(2) - (4)].lineSegment)->pB.y;
	  }
	} else {
	  if(!existsPoint((yyvsp[(2) - (4)].lineSegment)->pB)){
	    (yyvsp[(2) - (4)].lineSegment)->pB.x = (yyvsp[(2) - (4)].lineSegment)->pA.x + (yyvsp[(2) - (4)].lineSegment)->length;
	    (yyvsp[(2) - (4)].lineSegment)->pB.y = (yyvsp[(2) - (4)].lineSegment)->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *(yyvsp[(2) - (4)].lineSegment));
        (yyval.plottables) = p;
      }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 516 "lyparse.y"
    {
        Plottables *p = newPlottables(); 
        (yyvsp[(2) - (3)].lineSegment)->length = (yyvsp[(3) - (3)].length)->length;
        
	if(!existsPoint((yyvsp[(2) - (3)].lineSegment)->pA)){
	  if(!existsPoint((yyvsp[(2) - (3)].lineSegment)->pB)){
	    //default position is (0,0)
	    (yyvsp[(2) - (3)].lineSegment)->pA.x = (yyvsp[(2) - (3)].lineSegment)->pA.y = 0.0;
	    (yyvsp[(2) - (3)].lineSegment)->pB.x = (yyvsp[(2) - (3)].lineSegment)->length;
	    (yyvsp[(2) - (3)].lineSegment)->pB.y = 0.0;
	  } else {
	    (yyvsp[(2) - (3)].lineSegment)->pA.x = (yyvsp[(2) - (3)].lineSegment)->pB.x - (yyvsp[(2) - (3)].lineSegment)->length;
	    (yyvsp[(2) - (3)].lineSegment)->pA.y = (yyvsp[(2) - (3)].lineSegment)->pB.y;
	  }
	} else {
	  if(!existsPoint((yyvsp[(2) - (3)].lineSegment)->pB)){
	    (yyvsp[(2) - (3)].lineSegment)->pB.x = (yyvsp[(2) - (3)].lineSegment)->pA.x + (yyvsp[(2) - (3)].lineSegment)->length;
	    (yyvsp[(2) - (3)].lineSegment)->pB.y = (yyvsp[(2) - (3)].lineSegment)->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *(yyvsp[(2) - (3)].lineSegment));
        (yyval.plottables) = p;
      }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 540 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 546 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 552 "lyparse.y"
    {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = (yyvsp[(3) - (3)].condition)->ls;
        /* LineSegment thisLineSegment = *$2; */
        /* if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){ */
        /*   spitError("line segment not same"); */
        /* } */
        
	LineSegment *thisLineSegment = newLineSegment();
	thisLineSegment->length = (yyvsp[(3) - (3)].condition)->length;
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
        (yyval.plottables) = p;
      }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 585 "lyparse.y"
    {
        Plottables *p = newPlottables(); 
	LineSegment *thisLineSegment = newLineSegment();
        thisLineSegment->length = (yyvsp[(2) - (2)].length)->length;
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
        (yyval.plottables) = p;
      }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 613 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 619 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 625 "lyparse.y"
    {
        Plottables *p = newPlottables();
        LineSegment addressedLineSegment = (yyvsp[(3) - (3)].condition)->ls;
        LineSegment thisLineSegment = *(yyvsp[(1) - (3)].lineSegment);
        if(!areSameLineSegment(addressedLineSegment, thisLineSegment)){
          spitError("line segment not same");
        }
        
        (yyvsp[(1) - (3)].lineSegment)->length = (yyvsp[(3) - (3)].condition)->length;
	if(!existsPoint((yyvsp[(1) - (3)].lineSegment)->pA)){
	  if(!existsPoint((yyvsp[(1) - (3)].lineSegment)->pB)){
	    //default position is (0,0)
	    (yyvsp[(1) - (3)].lineSegment)->pA.x = (yyvsp[(1) - (3)].lineSegment)->pA.y = 0.0;
	    (yyvsp[(1) - (3)].lineSegment)->pB.x = (yyvsp[(1) - (3)].lineSegment)->length;
	    (yyvsp[(1) - (3)].lineSegment)->pB.y = 0.0;
	  } else {
	    (yyvsp[(1) - (3)].lineSegment)->pA.x = (yyvsp[(1) - (3)].lineSegment)->pB.x - (yyvsp[(1) - (3)].lineSegment)->length;
	    (yyvsp[(1) - (3)].lineSegment)->pA.y = (yyvsp[(1) - (3)].lineSegment)->pB.y;
	  }
	} else {
	  if(!existsPoint((yyvsp[(1) - (3)].lineSegment)->pB)){
	    (yyvsp[(1) - (3)].lineSegment)->pB.x = (yyvsp[(1) - (3)].lineSegment)->pA.x + (yyvsp[(1) - (3)].lineSegment)->length;
	    (yyvsp[(1) - (3)].lineSegment)->pB.y = (yyvsp[(1) - (3)].lineSegment)->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *(yyvsp[(1) - (3)].lineSegment));
        (yyval.plottables) = p;
      }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 654 "lyparse.y"
    {
        Plottables *p = newPlottables(); 
        (yyvsp[(1) - (2)].lineSegment)->length = (yyvsp[(2) - (2)].length)->length;
        
	if(!existsPoint((yyvsp[(1) - (2)].lineSegment)->pA)){
	  if(!existsPoint((yyvsp[(1) - (2)].lineSegment)->pB)){
	    //default position is (0,0)
	    (yyvsp[(1) - (2)].lineSegment)->pA.x = (yyvsp[(1) - (2)].lineSegment)->pA.y = 0.0;
	    (yyvsp[(1) - (2)].lineSegment)->pB.x = (yyvsp[(1) - (2)].lineSegment)->length;
	    (yyvsp[(1) - (2)].lineSegment)->pB.y = 0.0;
	  } else {
	    (yyvsp[(1) - (2)].lineSegment)->pA.x = (yyvsp[(1) - (2)].lineSegment)->pB.x - (yyvsp[(1) - (2)].lineSegment)->length;
	    (yyvsp[(1) - (2)].lineSegment)->pA.y = (yyvsp[(1) - (2)].lineSegment)->pB.y;
	  }
	} else {
	  if(!existsPoint((yyvsp[(1) - (2)].lineSegment)->pB)){
	    (yyvsp[(1) - (2)].lineSegment)->pB.x = (yyvsp[(1) - (2)].lineSegment)->pA.x + (yyvsp[(1) - (2)].lineSegment)->length;
	    (yyvsp[(1) - (2)].lineSegment)->pB.y = (yyvsp[(1) - (2)].lineSegment)->pA.y;
	  }	  
	}
        updatePlottablesLineSegment(p, *(yyvsp[(1) - (2)].lineSegment));
        (yyval.plottables) = p;
      }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 678 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 684 "lyparse.y"
    {
        Plottables *p = newPlottables();
        //not implemented now
        (yyval.plottables) = p;
      }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 693 "lyparse.y"
    { (yyval.condition) = (yyvsp[(1) - (1)].condition);  }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 698 "lyparse.y"
    {
        Condition *c = newCondition();
        setLineSegment(c, *(yyvsp[(3) - (4)].lineSegment));
        c->length = (yyvsp[(4) - (4)].length)->length;
      }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 704 "lyparse.y"
    {
        Condition *c = newCondition();
	setLineSegment(c, *(yyvsp[(2) - (3)].lineSegment));
	c->length = (yyvsp[(3) - (3)].length)->length;
      }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 710 "lyparse.y"
    {
        Condition *c = newCondition();
	if((yyvsp[(2) - (3)].angle)->degree != 0) {
	  c->angle = *(yyvsp[(3) - (3)].angle);
	  c->degree = (yyvsp[(2) - (3)].angle)->degree;
	} else {
	  c->angle = *(yyvsp[(2) - (3)].angle);
	  c->degree = (yyvsp[(3) - (3)].angle)->degree;
	}
      }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 723 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 724 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 728 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 732 "lyparse.y"
    { (yyval.length) = (yyvsp[(2) - (2)].length);  }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 733 "lyparse.y"
    { (yyval.length) = (yyvsp[(1) - (1)].length);  }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 737 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 741 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 746 "lyparse.y"
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
		(yyval.lineSegment) = ls;
      }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 772 "lyparse.y"
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
        (yyval.lineSegment) = ls;
      }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 798 "lyparse.y"
    {
        assert(existsLastLineSegment());
        LineSegment ls = getLastLineSegment();
        //TODO: $$ = the last segment present in the context
        LineSegment *l = newLineSegment();
	// Copies attributes from ls to *l
	LineSegmentCopy(ls, l);
        (yyval.lineSegment) = l;
      }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 808 "lyparse.y"
    {
        //assert(existsLastLineSegment());
        //LineSegment ls = getLastLineSegment();
        //TODO: $$ = the last segment present in the context
        LineSegment *l = newLineSegment();
	//LineSegmentCopy(ls, l);
	//This does not mean the last drawn line segment
        (yyval.lineSegment) = l;
      }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 820 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 821 "lyparse.y"
    { (yyval.plottables) = (yyvsp[(1) - (1)].plottables); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 826 "lyparse.y"
    {
        Plottables *p = newPlottables();

        char c1 = reserveNextPointLabel();
        char c2 = reserveNextPointLabel();

	assert(!existsPoint(*(yyvsp[(3) - (4)].point)));
	Angle* angle = newAngle();
	angle->vertex = *(yyvsp[(3) - (4)].point);
	angle->leftVertex.label = c1;
	angle->rightVertex.label = c2;
	angle->degree = (yyvsp[(4) - (4)].degree)->degree;

	//command is like "construct angle O of 34 degrees"
	//default position is origin
	angle->vertex.x = angle->vertex.y = 0.0;
	angle->rightVertex.x = 0.0 + DEFAULT_ANGLE_ARM_LENGTH;
	angle->rightVertex.y = 0.0;

	angle->leftVertex.x = DEFAULT_ANGLE_ARM_LENGTH*cos((angle->degree)*DEGREES_TO_RADIANS);
	angle->rightVertex.y = DEFAULT_ANGLE_ARM_LENGTH*sin((angle->degree)*DEGREES_TO_RADIANS);

	updatePlottablesAngle(p, *angle);
        (yyval.plottables) = p;
      
      }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 854 "lyparse.y"
    {
        Plottables *p = newPlottables();
	//e.g. angle ABC

	if(!existsPoint((yyvsp[(2) - (3)].angle)->vertex)){
	  //default place is origin
	  (yyvsp[(2) - (3)].angle)->vertex.x = (yyvsp[(2) - (3)].angle)->vertex.y = 0.0;
	}

	(yyvsp[(2) - (3)].angle)->degree = (yyvsp[(3) - (3)].degree)->degree;
	if(!existsPoint((yyvsp[(2) - (3)].angle)->leftVertex) && existsPoint((yyvsp[(2) - (3)].angle)->rightVertex)){
	  //A doesn't exist but C exists
	  double deltax = (yyvsp[(2) - (3)].angle)->rightVertex.x - (yyvsp[(2) - (3)].angle)->vertex.x;
	  double deltay = (yyvsp[(2) - (3)].angle)->rightVertex.y - (yyvsp[(2) - (3)].angle)->vertex.y;
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

	  double this_slope = base_slope + ((yyvsp[(2) - (3)].angle)->degree) * DEGREES_TO_RADIANS ;
	  (yyvsp[(2) - (3)].angle)->rightVertex.x = (yyvsp[(2) - (3)].angle)->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  (yyvsp[(2) - (3)].angle)->rightVertex.y = (yyvsp[(2) - (3)].angle)->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);
	}else if(existsPoint((yyvsp[(2) - (3)].angle)->leftVertex) && !existsPoint((yyvsp[(2) - (3)].angle)->rightVertex)){
	  //C doesn't exist but A exists
	  double deltax = (yyvsp[(2) - (3)].angle)->leftVertex.x - (yyvsp[(2) - (3)].angle)->vertex.x;
	  double deltay = (yyvsp[(2) - (3)].angle)->leftVertex.y - (yyvsp[(2) - (3)].angle)->vertex.y;
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

	  double this_slope = base_slope - ((yyvsp[(2) - (3)].angle)->degree) * DEGREES_TO_RADIANS ;
	  (yyvsp[(2) - (3)].angle)->rightVertex.x = (yyvsp[(2) - (3)].angle)->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  (yyvsp[(2) - (3)].angle)->rightVertex.y = (yyvsp[(2) - (3)].angle)->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);

	}else if(!existsPoint((yyvsp[(2) - (3)].angle)->leftVertex) && !existsPoint((yyvsp[(2) - (3)].angle)->rightVertex)){
	  //Both A and C don't exist
	  double base_slope = 0.0 * DEGREES_TO_RADIANS;//angle subtended by BA on X-axis
	  (yyvsp[(2) - (3)].angle)->rightVertex.x = (yyvsp[(2) - (3)].angle)->vertex.x + DEFAULT_ANGLE_ARM_LENGTH;
	  (yyvsp[(2) - (3)].angle)->rightVertex.y = (yyvsp[(2) - (3)].angle)->vertex.y;

	  double this_slope = base_slope + ((yyvsp[(2) - (3)].angle)->degree) * DEGREES_TO_RADIANS ;
	  (yyvsp[(2) - (3)].angle)->leftVertex.x = (yyvsp[(2) - (3)].angle)->vertex.x + DEFAULT_ANGLE_ARM_LENGTH * cos(this_slope);
	  (yyvsp[(2) - (3)].angle)->leftVertex.y = (yyvsp[(2) - (3)].angle)->vertex.y + DEFAULT_ANGLE_ARM_LENGTH * sin(this_slope);
	}else{
	  //all vertices exist, may be fishy
	}

	updatePlottablesAngle(p, *(yyvsp[(2) - (3)].angle));
        (yyval.plottables) = p;
      }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 918 "lyparse.y"
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
	angle->degree = (yyvsp[(2) - (2)].degree)->degree;

	//command is like "construct angle of 34 degrees"
	//default position is origin
	angle->vertex.x = angle->vertex.y = 0.0;
	angle->rightVertex.x = 0.0 + DEFAULT_ANGLE_ARM_LENGTH;
	angle->rightVertex.y = 0.0;

	angle->leftVertex.x = DEFAULT_ANGLE_ARM_LENGTH*cos((angle->degree)*DEGREES_TO_RADIANS);
	angle->rightVertex.y = DEFAULT_ANGLE_ARM_LENGTH*sin((angle->degree)*DEGREES_TO_RADIANS);

	updatePlottablesAngle(p, *angle);
        (yyval.plottables) = p;
      
      }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 950 "lyparse.y"
    {
	Plottables *p = newPlottables();

	Angle *a = newAngle();
	a->vertex = *(yyvsp[(4) - (4)].point);
	a->vertex.x = a->vertex.y = 0.0;
	a->leftVertex.x = 0.0;
	a->leftVertex.y = DEFAULT_ANGLE_ARM_LENGTH;
	a->rightVertex.x = DEFAULT_ANGLE_ARM_LENGTH;
	a->rightVertex.y = 0.0;
	a->leftVertex.label = reserveNextPointLabel();
	a->rightVertex.label = reserveNextPointLabel();
	a->degree = 90.0;

	updatePlottablesAngle(p, *a);

        (yyval.plottables) = p;
      }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 969 "lyparse.y"
    {
	Plottables *p = newPlottables();
	
	bool existsLeftVertex = existsPoint((yyvsp[(3) - (3)].angle)->leftVertex),
	  existsRightVertex = existsPoint((yyvsp[(3) - (3)].angle)->rightVertex);

	(yyvsp[(3) - (3)].angle)->degree = 90.0;
	if(!existsPoint((yyvsp[(3) - (3)].angle)->vertex)){
	  (yyvsp[(3) - (3)].angle)->vertex.x = (yyvsp[(3) - (3)].angle)->vertex.y = 0.0;
	} else {
	  (yyvsp[(3) - (3)].angle)->vertex = getPoint((yyvsp[(3) - (3)].angle)->vertex.label);
	}

	if(!existsLeftVertex && !existsRightVertex){
	  (yyvsp[(3) - (3)].angle)->rightVertex.x = (yyvsp[(3) - (3)].angle)->vertex.x + DEFAULT_ANGLE_ARM_LENGTH;
	  (yyvsp[(3) - (3)].angle)->rightVertex.y = (yyvsp[(3) - (3)].angle)->vertex.y;
	  existsRightVertex = true;
	}

	if(existsLeftVertex && !existsRightVertex){
	  double ldeltax = (yyvsp[(3) - (3)].angle)->leftVertex.x - (yyvsp[(3) - (3)].angle)->vertex.x,
	    ldeltay = (yyvsp[(3) - (3)].angle)->leftVertex.y - (yyvsp[(3) - (3)].angle)->vertex.y;
	  double lvslope;
	  if(abs(ldeltax) <= FLOAT_EPSILON){
	    if(ldeltay >= FLOAT_EPSILON) lvslope = 90.0;
	    else lvslope = -90.0;
	  } else {
	    lvslope = atan2(ldeltay, ldeltax) * RADIANS_TO_DEGREES;
	  }

	  double rvslope = lvslope - 90.0;

	  (yyvsp[(3) - (3)].angle)->rightVertex.x = (yyvsp[(3) - (3)].angle)->vertex.x
	    + DEFAULT_ANGLE_ARM_LENGTH*cos(rvslope * DEGREES_TO_RADIANS);
	  (yyvsp[(3) - (3)].angle)->rightVertex.y = (yyvsp[(3) - (3)].angle)->vertex.y
	    + DEFAULT_ANGLE_ARM_LENGTH*sin(rvslope * DEGREES_TO_RADIANS);

	} else if(!existsLeftVertex && existsRightVertex){
	  double rdeltax = (yyvsp[(3) - (3)].angle)->rightVertex.x - (yyvsp[(3) - (3)].angle)->vertex.x,
	    rdeltay = (yyvsp[(3) - (3)].angle)->rightVertex.y - (yyvsp[(3) - (3)].angle)->vertex.y;
	  double rvslope;
	  if(abs(rdeltax) <= FLOAT_EPSILON){
	    if(rdeltay >= FLOAT_EPSILON) rvslope = 90.0;
	    else rvslope = -90.0;
	  } else {
	    rvslope = atan2(rdeltay, rdeltax) * RADIANS_TO_DEGREES;
	  }

	  double lvslope = rvslope + 90.0;

	  (yyvsp[(3) - (3)].angle)->leftVertex.x = (yyvsp[(3) - (3)].angle)->vertex.x
	    + DEFAULT_ANGLE_ARM_LENGTH*cos(lvslope * DEGREES_TO_RADIANS);
	  (yyvsp[(3) - (3)].angle)->leftVertex.y = (yyvsp[(3) - (3)].angle)->vertex.y
	    + DEFAULT_ANGLE_ARM_LENGTH*sin(lvslope * DEGREES_TO_RADIANS);
	  
	} else {
	  //both points exist, may be fishy
	}
	
	updatePlottablesAngle(p, *(yyvsp[(3) - (3)].angle));
	(yyval.plottables) = p;

      }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1035 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1039 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1043 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1048 "lyparse.y"
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

        (yyval.angle) = na;
      }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 1101 "lyparse.y"
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

        (yyval.angle) = na;
      }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1154 "lyparse.y"
    {
       if(!existsLastAngle()){
         spitError("No previous angle");
       }
       Angle *a = newAngle();
       *a = getLastAngle();
       (yyval.angle) = a;
      }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1165 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 1166 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1171 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Circle c;
	c.center = *(yyvsp[(3) - (5)].point);
	if(!existsPoint(c.center)){
	  c.center.x = c.center.y = 0.0;
	}
	c.radius = (yyvsp[(5) - (5)].length)->length;
	updatePlottablesCircle(p, c);

        (yyval.plottables) = p;
      }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1184 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Circle c;
	c.center = *(yyvsp[(3) - (5)].point);
	if(!existsPoint(c.center)){
	  c.center.x = c.center.y = 0.0;
	}
	c.radius = 0.5 * ((yyvsp[(5) - (5)].length)->length);
	updatePlottablesCircle(p, c);

        (yyval.plottables) = p;	
      }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1197 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Circle c;
	c.center.label = reserveNextPointLabel();
	c.center.x = c.center.y = 0.0;
	c.radius = ((yyvsp[(3) - (3)].length)->length);
	updatePlottablesCircle(p, c);

        (yyval.plottables) = p;	
      }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1208 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Circle c;
	c.center.label = reserveNextPointLabel();
	c.center.x = c.center.y = 0.0;
	c.radius = 0.5 * ((yyvsp[(3) - (3)].length)->length);
	updatePlottablesCircle(p, c);

        (yyval.plottables) = p;	
      }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1221 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1225 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1230 "lyparse.y"
    {
        (yyval.plottables) = newPlottables();
      }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1234 "lyparse.y"
    {
        (yyval.plottables) = newPlottables();
      }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1238 "lyparse.y"
    {
        (yyval.plottables) = newPlottables();
      }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1245 "lyparse.y"
    {
      (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1256 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Arc a,b;
	
	a.center = (yyvsp[(1) - (3)]. vecPoints )->points[0];
	a.radius = (yyvsp[(2) - (3)].vecLengths)->lengths[0].length;

	updatePlottablesArc(p, a);
  printf("%lf %lf\n", a.center.x, a.center.y);
	b.center = (yyvsp[(1) - (3)]. vecPoints )->points[1];
	b.radius = (yyvsp[(2) - (3)].vecLengths)->lengths[1].length;
  printf("%lf %lf\n", b.center.x, b.center.y);
	updatePlottablesArc(p, b);

	Point pA = getArcArcIntersection(a,b,true);
  printf("%lf %lf\n", pA.x, pA.y);
	pA.label = (yyvsp[(3) - (3)]. vecPoints )->points[0].label;
	updatePlottablesPoint(p, pA);
	if((yyvsp[(3) - (3)]. vecPoints )->n >= 2){
	  //if both the intersection points are to be marked
	  Point pB = getArcArcIntersection(a,b,false);
	  pB.label = (yyvsp[(3) - (3)]. vecPoints )->points[1].label;
	  updatePlottablesPoint(p, pB);
	}

	(yyval.plottables) = p;
      }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1284 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Arc a,b;
	
	a.center = (yyvsp[(1) - (2)]. vecPoints )->points[0];
	a.radius = (yyvsp[(2) - (2)].vecLengths)->lengths[0].length;

	updatePlottablesArc(p, a);
  printf("%lf %lf\n", a.center.x, a.center.y);
	b.center = (yyvsp[(1) - (2)]. vecPoints )->points[1];
	b.radius = (yyvsp[(2) - (2)].vecLengths)->lengths[1].length;
  printf("%lf %lf\n", b.center.x, b.center.y);
	updatePlottablesArc(p, b);

	(yyval.plottables) = p;
      }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1305 "lyparse.y"
    {
        (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
      }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1312 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1317 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *(yyvsp[(1) - (3)].point);
	a.radius = (yyvsp[(2) - (3)].length)->length;
	updatePlottablesArc(p, a);
	Point in = getArcIntersectableIntersection(a, *(yyvsp[(3) - (3)].intersection), true);
	in.label = (yyvsp[(3) - (3)].intersection)->p1->label;
	updatePlottablesPoint(p, in);

	if((yyvsp[(3) - (3)].intersection)->p2 != NULL){
	  //the other intersection point is also to be marked
	  Point in2 = getArcIntersectableIntersection(a, *(yyvsp[(3) - (3)].intersection), false);
	  in2.label = (yyvsp[(3) - (3)].intersection)->p2->label;
	  updatePlottablesPoint(p, in2);
	}

	(yyval.plottables) = p;
      }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1337 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *(yyvsp[(1) - (2)].point);
	a.radius = (yyvsp[(2) - (2)].length)->length;
	updatePlottablesArc(p, a);
	(yyval.plottables) = p;
      }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1346 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Arc a;
	a.center = *(yyvsp[(1) - (2)].point);
	a.radius = getDistance(*(yyvsp[(1) - (2)].point), *(yyvsp[(2) - (2)].point));
	updatePlottablesArc(p, a);
	(yyval.plottables) = p;
      }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1358 "lyparse.y"
    {
	(yyval.point) = (yyvsp[(2) - (2)].point);
      }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1364 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1365 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1370 "lyparse.y"
    {
	assert(!existsPointLabel((yyvsp[(4) - (5)].sval)[0]));
	assert(!existsPointLabel((yyvsp[(5) - (5)].sval)[0]));
	VecPoints *vec = newVectorPoints();

	Point a,b;
	a.label = (yyvsp[(4) - (5)].sval)[0];
	b.label = (yyvsp[(5) - (5)].sval)[0];
	vec->points[vec->n++] = a;
	vec->points[vec->n++] = b;
	
	(yyval. vecPoints ) = vec;
      }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1384 "lyparse.y"
    {
	assert(!existsPointLabel((yyvsp[(3) - (4)].sval)[0]));
	assert(!existsPointLabel((yyvsp[(4) - (4)].sval)[0]));
	VecPoints *vec = newVectorPoints();

	Point a,b;
	a.label = (yyvsp[(3) - (4)].sval)[0];
	b.label = (yyvsp[(4) - (4)].sval)[0];
	vec->points[vec->n++] = a;
	vec->points[vec->n++] = b;
	
	(yyval. vecPoints ) = vec;
      }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1398 "lyparse.y"
    {
	assert(!existsPointLabel((yyvsp[(4) - (4)].sval)[0]));

	VecPoints *vec = newVectorPoints();
	Point a;
	a.label = (yyvsp[(4) - (4)].sval)[0];
	vec->points[vec->n++] = a;
	(yyval. vecPoints ) = vec;
      }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1408 "lyparse.y"
    {
	assert(!existsPointLabel((yyvsp[(3) - (3)].sval)[0]));

	VecPoints *vec = newVectorPoints();
	Point a;
	a.label = (yyvsp[(3) - (3)].sval)[0];
	vec->points[vec->n++] = a;
	(yyval. vecPoints ) = vec;
      }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1421 "lyparse.y"
    {
	Point *p = newPoint();
	p->label = (yyvsp[(2) - (2)].sval)[0];
	if(existsPointLabel(p->label)){
	  *p = getPoint(p->label);
	} else {
	  p->x = p->y = 0.0;
	}
	(yyval.point) = p;
      }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1435 "lyparse.y"
    {
	VecPoints *vec = newVectorPoints();
	Point a,b;
	a.label = (yyvsp[(2) - (3)].sval)[0];
	if(existsPoint(a)){
	  a = getPoint(a.label);
	} else {
	  printf("Point %c does not exist\n", a.label);
	  spitError("No such point(s) exist(s)\n");
	}

	b.label = (yyvsp[(3) - (3)].sval)[0];
	if(existsPoint(b)){
	  b = getPoint(b.label);
	} else {
	  printf("Point %c does not exist\n", a.label);
	  spitError("No such point(s) exist(s)\n");
	}

	vec->points[vec->n++]= a;
	vec->points[vec->n++]= b;
        (yyval. vecPoints ) = vec;
      }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1462 "lyparse.y"
    {
	(yyval.length) = (yyvsp[(2) - (2)].length);
      }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1469 "lyparse.y"
    {
	VecLengths *vec = newVectorLengths();
	
	vec->lengths[vec->n] = *(yyvsp[(2) - (3)].length);
	vec->n++;
	vec->lengths[vec->n] = *(yyvsp[(3) - (3)].length);
	vec->n++;

	(yyval.vecLengths) = vec;
      }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1483 "lyparse.y"
    {
	Point *pA = newPoint(),
	  *pB = newPoint();
	pA->label = (yyvsp[(4) - (5)].sval)[0];
	pB->label = (yyvsp[(5) - (5)].sval)[0];
	(yyvsp[(2) - (5)].intersection)->p1 = pA;
	(yyvsp[(2) - (5)].intersection)->p2 = pB;
	(yyval.intersection) = (yyvsp[(2) - (5)].intersection);
      }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1493 "lyparse.y"
    {
	Point *pA = newPoint();
	pA->label = (yyvsp[(4) - (4)].sval)[0];
	(yyvsp[(2) - (4)].intersection)->p1 = pA;
	(yyval.intersection) = (yyvsp[(2) - (4)].intersection);
      }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1503 "lyparse.y"
    {      
	Intersection *i = newIntersection();
	i->ls1 = (yyvsp[(1) - (1)].lineSegment);
	(yyval.intersection) = i;
      }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1509 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->l1 = (yyvsp[(1) - (1)].line);
	(yyval.intersection) = i;
      }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1515 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->a1 = &((yyvsp[(1) - (1)].vecArcs)->arcs[0]);
	if((yyvsp[(1) - (1)].vecArcs)->n >=2){
	  i->a2 = &((yyvsp[(1) - (1)].vecArcs)->arcs[1]);
	}
	(yyval.intersection) = i;
      }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1524 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->c1 = (yyvsp[(1) - (1)].circle);
	(yyval.intersection) = i;
      }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1530 "lyparse.y"
    {
	Intersection *i = newIntersection();
	//i->r1 = $1;
	(yyval.intersection) = i;
      }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1539 "lyparse.y"
    {
	(yyval.angle) = (yyvsp[(3) - (3)].angle);
      }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1545 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1549 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1553 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1557 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1558 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1559 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1560 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1564 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1565 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1569 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1573 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1578 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1582 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1586 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1590 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1597 "lyparse.y"
    {
	(yyval.point) = newPoint();
      }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1603 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1604 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1608 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1612 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1617 "lyparse.y"
    {
	Plottables *p = newPlottables();
	LineSegment ls = (yyvsp[(2) - (2)]. vecLineSegments )->lineSegments[0];
	LineSegment pb = getPerpendicularBisector(ls);
  printPoint(pb.pA);
  printPoint(pb.pB);
	updatePlottablesLineSegment(p, pb);
	(yyval.plottables) = p;
      }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1627 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1631 "lyparse.y"
    {
 resolvePlottables((yyvsp[(2) - (2)].plottables));
	Plottables *p = newPlottables();
	LineSegment pb = getPerpendicularBisectorPlottable(*(yyvsp[(2) - (2)].plottables));
	updatePlottablesLineSegment(p, pb);
	(yyval.plottables) = p;
      }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1639 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1646 "lyparse.y"
    {
	VecLineSegments *vec =  newVectorLineSegments();
	vec->lineSegments[0] = *(yyvsp[(1) - (1)].lineSegment);
	vec->n++;
	(yyval. vecLineSegments ) = vec;
      }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1653 "lyparse.y"
    {
	(yyval. vecLineSegments ) = newVectorLineSegments();
    }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1657 "lyparse.y"
    {
	(yyval. vecLineSegments ) = (yyvsp[(1) - (1)]. vecLineSegments );
    }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1664 "lyparse.y"
    {
	(yyval.lineSegment) = newLineSegment();
      }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1671 "lyparse.y"
    {
	(yyval. vecLineSegments ) = newVectorLineSegments();
      }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1677 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1682 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1686 "lyparse.y"
    {
	Plottables *p = newPlottables();
	LineSegment ab = getAngleBisector(*(yyvsp[(2) - (2)].angle));
	updatePlottablesLineSegment(p, ab);
	(yyval.plottables) = p;
      }
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1693 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Angle a = getLastAngle();
	LineSegment ab = getAngleBisector(a);
	updatePlottablesLineSegment(p, ab);
	(yyval.plottables) = p;
      }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1704 "lyparse.y"
    {
	Parallelization *par =  newParallelization();
	par->ls = (yyvsp[(2) - (2)].lineSegment);
	(yyval.parallelization) = par;
      }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1710 "lyparse.y"
    {
	Parallelization *par =  newParallelization();
	par->l = (yyvsp[(2) - (2)].line);
	(yyval.parallelization) = par;
      }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1719 "lyparse.y"
    {
	Perpendicularization *per = newPerpendicularization();
	per->ls = (yyvsp[(2) - (2)].lineSegment);
	(yyval.perpendicularization) = per;
      }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1725 "lyparse.y"
    {
	Perpendicularization *per = newPerpendicularization();
	per->l = (yyvsp[(2) - (2)].line);
        (yyval.perpendicularization) = per;
      }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1734 "lyparse.y"
    {
	LineSegment ls;
	Plottables *p = newPlottables();

	if((yyvsp[(2) - (2)].perpendicularization)->passingThroughPoint != NULL){
	  ls = getPerpendicularPassingThrough(*((yyvsp[(1) - (2)].perpendicularization)->ls), *((yyvsp[(2) - (2)].perpendicularization)->passingThroughPoint));
	} else {
	  ls = getPerpendicularAt(*((yyvsp[(1) - (2)].perpendicularization)->ls), *((yyvsp[(2) - (2)].perpendicularization)->atPoint));
	}

	updatePlottablesLineSegment(p, ls);

        (yyval.plottables) = p;
      }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1751 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1752 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1757 "lyparse.y"
    {
	Perpendicularization *per = newPerpendicularization();
	per->atPoint = (yyvsp[(2) - (2)].point);
	(yyval.perpendicularization) = per;
      }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1763 "lyparse.y"
    {
	Perpendicularization *per = newPerpendicularization();
	per->passingThroughPoint = (yyvsp[(1) - (1)].point);
	(yyval.perpendicularization) = per;
      }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1772 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1776 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1780 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();  
      }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1784 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();  
      }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1788 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();  
      }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1792 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();  
      }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1799 "lyparse.y"
    {	
	(yyval.length) = (yyvsp[(2) - (4)].length);
      }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1805 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1809 "lyparse.y"
    { (yyval.ival) = yylval.ival; }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1813 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1818 "lyparse.y"
    {
		LineSegment ls;
		Plottables *p = newPlottables();

		if((yyvsp[(2) - (2)].parallelization)->passingThroughPoint != NULL){
		  ls = getParallelPassingThrough(*((yyvsp[(1) - (2)].parallelization)->ls), *((yyvsp[(2) - (2)].parallelization)->passingThroughPoint));
		} else {
		  assert(0);
		}
		
		updatePlottablesLineSegment(p, ls);

		(yyval.plottables) = p;
      }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1836 "lyparse.y"
    {
		Parallelization *par =  newParallelization();
		par->passingThroughPoint = (yyvsp[(2) - (2)].point);
		(yyval.parallelization) = par;
	}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1842 "lyparse.y"
    {
		Parallelization *par =  newParallelization();
		par->passingThroughPoint = (yyvsp[(1) - (1)].point);
		(yyval.parallelization) = par;
      }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1852 "lyparse.y"
    {
	Command *command = newCommand();
	command->plottables = *(yyvsp[(2) - (2)].plottables);
	(yyval.command) = command;
      }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1860 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1865 "lyparse.y"
    {
	// $$ = newPlottables();
	LineSegment lS = *(yyvsp[(1) - (4)].lineSegment);
	Plottables *p = newPlottables();
	int number = (yyvsp[(3) - (4)].ival);
	double slope = getSlope(lS.pA, lS.pB);
	double distance = getDistance(lS.pA, lS.pB);
	int i;
	for(i=0;i<number;i++) {
	  Point P1 = locatePoint(lS.pA, slope, (distance*(i+1))/number);
	  P1.label = reserveNextPointLabel();
	  updatePlottablesPoint(p, P1);
	}
	(yyval.plottables)=p;
      }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1883 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1887 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1892 "lyparse.y"
    {
	// $$ = newLineSegment();
	(yyval.lineSegment) = (yyvsp[(1) - (1)].lineSegment);
      }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1897 "lyparse.y"
    {
	(yyval.lineSegment) = newLineSegment();
	//Jeetesh
      }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1905 "lyparse.y"
    {
	Command *c = newCommand();
	Plottables *p = newPlottables();

	int i;
	for(i = 0; i < (yyvsp[(2) - (2)].vecStrings)->n; i++){
	  char* pp = (yyvsp[(2) - (2)].vecStrings)->strings[i];
	  LineSegment ls;
	  ls.pA = getPoint(pp[0]);
	  ls.pB = getPoint(pp[1]);
	  updatePlottablesLineSegment(p, ls);
	}

	c->plottables = *p;
	(yyval.command) = c;
      }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1924 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1929 "lyparse.y"
    {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = (yyvsp[(1) - (1)].sval);
	(yyval.vecStrings) = vec;
      }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1935 "lyparse.y"
    {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = (yyvsp[(1) - (2)].sval);
	vec->strings[vec->n++] = (yyvsp[(2) - (2)].sval);
	(yyval.vecStrings) = vec;
      }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1942 "lyparse.y"
    {
	VecStrings *vec = newVectorStrings();
	vec->strings[vec->n++] = (yyvsp[(1) - (3)].sval);
	vec->strings[vec->n++] = (yyvsp[(2) - (3)].sval);
	vec->strings[vec->n++] = (yyvsp[(3) - (3)].sval);
	(yyval.vecStrings) = vec;
      }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1950 "lyparse.y"
    {
	VecStrings *vec = newVectorStrings();
	int num = getNumberOfPoints();
	char* arr = (char*)malloc(sizeof(char)*3);
	arr[0] = getPointAtPosition(num-1).label;
	arr[1] = getPointAtPosition(num-2).label;
	arr[2] = '\0';
	vec->strings[vec->n++] = arr;
	(yyval.vecStrings) = vec;
      }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1964 "lyparse.y"
    {
	Command *c = newCommand();
	c->plottables = *(yyvsp[(2) - (2)].plottables);
	(yyval.command) = c;
      }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1972 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1973 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1974 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1979 "lyparse.y"
    {
	(yyval.plottables) = (yyvsp[(1) - (1)].plottables);
      }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1983 "lyparse.y"
    {
	(yyval.plottables) = (yyvsp[(1) - (1)].plottables);
      }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1987 "lyparse.y"
    {
	(yyval.plottables) = (yyvsp[(1) - (1)].plottables);
      }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1994 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 2000 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 2005 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Point p1 = getIntersectableIntersectableIntersection(*(yyvsp[(2) - (5)].intersection), *(yyvsp[(3) - (5)].intersection), true);
	p1.label = (yyvsp[(4) - (5)].point)->label;
	Point p2 = getIntersectableIntersectableIntersection(*(yyvsp[(2) - (5)].intersection), *(yyvsp[(3) - (5)].intersection), false);
	p2.label = (yyvsp[(5) - (5)].point)->label;
	updatePlottablesPoint(p, p1);
	updatePlottablesPoint(p, p2);
	(yyval.plottables) = p;
      }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 2016 "lyparse.y"
    {
	Plottables *p = newPlottables();
	printf("Interection 1\n");
	printIntersection(*(yyvsp[(2) - (4)].intersection));
	printf("Interection 2\n");
	printIntersection(*(yyvsp[(3) - (4)].intersection));
	Point p1 = getIntersectableIntersectableIntersection(*(yyvsp[(2) - (4)].intersection), *(yyvsp[(3) - (4)].intersection), true);
	p1.label = (yyvsp[(4) - (4)].point)->label;
	updatePlottablesPoint(p, p1);
  printf("%c %lf %lf\n", p->points[0].label, p->points[0].x, p->points[0].y);
	(yyval.plottables) = p;
      }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 2029 "lyparse.y"
    {    
 resolvePlottables((yyvsp[(2) - (4)].plottables));
	Intersection *l = getIntersectionFromPlottables(*(yyvsp[(2) - (4)].plottables));
	Point p1 = getIntersectableIntersection(*l, true);
	Point p2 = getIntersectableIntersection(*l, false);	
 Plottables *p = newPlottables();
	p1.label = (yyvsp[(3) - (4)].point)->label;
	updatePlottablesPoint(p, p1);
	p2.label = (yyvsp[(4) - (4)].point)->label;
	updatePlottablesPoint(p, p2);
	(yyval.plottables) = p;
      }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 2042 "lyparse.y"
    {    
 resolvePlottables((yyvsp[(2) - (3)].plottables));
	Intersection *l = getIntersectionFromPlottables(*(yyvsp[(2) - (3)].plottables));
	Point p1 = getIntersectableIntersection(*l, false);
	p1.label = (yyvsp[(3) - (3)].point)->label;
 Plottables *p = newPlottables();
	updatePlottablesPoint(p, p1);
	(yyval.plottables) = p;
      }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 2054 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 2055 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 2056 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 2057 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 2062 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->a1 = &((yyvsp[(1) - (1)].vecArcs)->arcs[0]);
	(yyval.intersection) = i;
      }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 2068 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->c1 = (yyvsp[(1) - (1)].circle);
	(yyval.intersection) = i;
      }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 2074 "lyparse.y"
    {
	(yyval.intersection) = newIntersection();
      }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 2078 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->ls1 = (yyvsp[(1) - (1)].lineSegment);
	(yyval.intersection) = i;
      }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 2084 "lyparse.y"
    {
 (yyvsp[(1) - (1)].plottables)->class = INTERSECTABLE_D;
 resolvePlottables((yyvsp[(1) - (1)].plottables));
	(yyval.intersection) = getIntersectionFromPlottables(*(yyvsp[(1) - (1)].plottables));
      }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 2093 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Point pt = getPointNotOnLabelable(*(yyvsp[(2) - (2)].intersection), NULL);
	pt.label = (yyvsp[(1) - (2)].point)->label;
	updatePlottablesPoint(p, pt);
	(yyval.plottables) = p;
      }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 2101 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Point pt = getPointOnLabelable(*(yyvsp[(2) - (3)].intersection), (yyvsp[(3) - (3)].location));
	pt.label = (yyvsp[(1) - (3)].point)->label;
	updatePlottablesPoint(p, pt);
	(yyval.plottables) = p;
      }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 2109 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Point pt = getPointOnLabelable(*(yyvsp[(2) - (2)].intersection), NULL);
	pt.label = (yyvsp[(1) - (2)].point)->label;
	updatePlottablesPoint(p, pt);
	(yyval.plottables) = p;
      }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 2117 "lyparse.y"
    {
     Plottables *p = newPlottables();
     (yyvsp[(1) - (1)].point)->x = (rand() % DEFAULT_LINE_SEGMENT_LENGTH)
      -(DEFAULT_LINE_SEGMENT_LENGTH/2);
     (yyvsp[(1) - (1)].point)->y = (rand() % DEFAULT_LINE_SEGMENT_LENGTH)
      -(DEFAULT_LINE_SEGMENT_LENGTH/2);
     updatePlottablesPoint(p, *(yyvsp[(1) - (1)].point));
     (yyval.plottables) = p;
    
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 2131 "lyparse.y"
    {
	Location *l = newLocation();
	l->distance = (yyvsp[(3) - (3)].length)->length;
	l->fromPoint = *(yyvsp[(2) - (3)].point);
	(yyval.location) = l;
      }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 2140 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 2145 "lyparse.y"
    {
	(yyval.intersection) = (yyvsp[(2) - (2)].intersection);
      }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 2152 "lyparse.y"
    {
	(yyval.intersection) = (yyvsp[(2) - (2)].intersection);
      }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 2158 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 2162 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 2163 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 2168 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->ls1 = (yyvsp[(1) - (1)].lineSegment);
	(yyval.intersection) = i;
      }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 2174 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->a1 = &((yyvsp[(1) - (1)].vecArcs)->arcs[0]);
	(yyval.intersection) = i;
 
      }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 2181 "lyparse.y"
    {
	Intersection *i = newIntersection();
	i->l1 = (yyvsp[(1) - (1)].line);
	(yyval.intersection) = i;
      }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 2187 "lyparse.y"
    {
    (yyvsp[(1) - (1)].plottables)->class = LABELABLE_D;
    resolvePlottables((yyvsp[(1) - (1)].plottables));
    Intersection *i = getIntersectionFromPlottables(*(yyvsp[(1) - (1)].plottables));
    (yyval.intersection) = i;
      }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 2197 "lyparse.y"
    {
	Line *l = newLine();
	l->label = (yyvsp[(1) - (1)].sval)[0];
	(yyval.line) = l;
      }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 2203 "lyparse.y"
    {
	Line *l = newLine();
	l->label = (yyvsp[(2) - (2)].sval)[0];
	(yyval.line) = l;
      }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 2209 "lyparse.y"
    {
	Line *l = newLine();
	*l = getLastLine();
	(yyval.line) = l;
      }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 2215 "lyparse.y"
    {
	Line *l = newLine();
	l->label = reserveNextLineLabel();
	(yyval.line) = l;
      }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 2224 "lyparse.y"
    {
	VecArcs *vec = newVectorArcs();
	vec->arcs[vec->n++] = getLastArc();
	(yyval.vecArcs) = vec;
      }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 2230 "lyparse.y"
    {
	VecArcs *vec = newVectorArcs();
	int num = getNumberOfArcs();
	vec->arcs[vec->n++] = getArcAtPosition(num-1);
	vec->arcs[vec->n++] = getArcAtPosition(num-2);
	(yyval.vecArcs) = vec;
      }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 2248 "lyparse.y"
    {
    (yyvsp[(2) - (2)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 2253 "lyparse.y"
    {
    (yyvsp[(2) - (2)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 2258 "lyparse.y"
    {
    (yyvsp[(2) - (2)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 2263 "lyparse.y"
    {
    (yyvsp[(2) - (2)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 2268 "lyparse.y"
    {
    (yyvsp[(2) - (2)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 2273 "lyparse.y"
    {
    (yyvsp[(1) - (1)].plottables)->class = INTERSECTABLE_D;
    (yyval.plottables) = (yyvsp[(1) - (1)].plottables);
   }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 2281 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
   }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 2285 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
      }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 2289 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
      }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 2293 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
      }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 2297 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(2) - (2)].plottables);
      }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 2301 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(1) - (1)].plottables);
      }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 2308 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 2315 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 2322 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 2329 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 2336 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 2343 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 2350 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = INDEFINITE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 2359 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 2363 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 2367 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 2371 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 2375 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 2379 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 2383 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 2387 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 2392 "lyparse.y"
    {
    Plottables * p = newPlottables();
    p->type = LINE_SEGMENT_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 2399 "lyparse.y"
    {
    Plottables * p = newPlottables();
    p->type = LINE_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 2406 "lyparse.y"
    {
    Plottables * p = newPlottables();
    p->type = CIRCLE_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 2413 "lyparse.y"
    {
    Plottables * p = newPlottables();
    p->type = ARC_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 2420 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 2424 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 2428 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 2432 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 2439 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(1) - (1)].plottables);
   }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 2443 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = POINT_D;
    p->singleton = true;
    (yyval.plottables) = p;
   }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 2453 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = LINE_SEGMENT_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 2460 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = LINE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 2467 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = CIRCLE_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 2474 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = ARC_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 2481 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 2485 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 2489 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 2493 "lyparse.y"
    {
    (yyval.plottables) = newPlottables();
   }
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 2499 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 2503 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 2507 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 2511 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 2515 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 2519 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 2523 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 2528 "lyparse.y"
    {
    (yyval.plottables) = (yyvsp[(1) - (1)].plottables);
   }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 2532 "lyparse.y"
    {
    Plottables *p = newPlottables();
    p->type = POINT_D;
    p->singleton = false;
    (yyval.plottables) = p;
   }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 2541 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 2545 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 2550 "lyparse.y"
    {
	Command *c = newCommand();

	c->plottables = *(yyvsp[(2) - (2)].plottables);
	(yyval.command) = c;
      }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 2559 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 2564 "lyparse.y"
    {
	Point *p = newPoint();
	p->label = yylval.sval[0];
	if(existsPoint(*p)) *p = getPoint(p->label);
	(yyval.point) = p;
      }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 2571 "lyparse.y"
    {
	Point *p = newPoint();
	p->label = yylval.sval[0];
	if(existsPoint(*p)) *p = getPoint(p->label);
	(yyval.point) = p;
      }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 2578 "lyparse.y"
    {
	if(!existsLastPoint()){
	  spitError("No previous points exist\n");
	}
	Point *p = newPoint();
	*p = getLastPoint();
	(yyval.point) = p;
      }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 2587 "lyparse.y"
    {
	Point *p = newPoint();
	p->label = reserveNextPointLabel();
	(yyval.point) = p;
      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 2595 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 2599 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 2603 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 2607 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 2612 "lyparse.y"
    {
	Plottables *p = newPlottables();
	LineSegment cutting = *(yyvsp[(1) - (3)].lineSegment);
	LineSegment cuttingFrom = *((yyvsp[(3) - (3)].cut)->ls);
	
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
	Point res = locatePoint(src, slope, (yyvsp[(2) - (3)].length)->length);

	updatePlottablesPoint(p, res);
	(yyval.plottables) = p;
      }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 2644 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 2648 "lyparse.y"
    {
	(yyval.plottables) = newPlottables();
      }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2652 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Intersection *i = newIntersection();
	i->a1 = &((yyvsp[(1) - (2)].vecArcs)->arcs[0]);

	Point p1 = getPointOnLabelable(*i, NULL);
	p1.label = (yyvsp[(2) - (2)].cut)->p1->label;
	updatePlottablesPoint(p, p1);

	if((yyvsp[(2) - (2)].cut)->p2 != NULL){
	  Point p2 = getPointOnLabelable(*i, NULL);
	  p2.label = (yyvsp[(2) - (2)].cut)->p2->label;
	  updatePlottablesPoint(p, p2);
	}

	(yyval.plottables) = p;
      }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2670 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Intersection *i = newIntersection();
	i->c1 = (yyvsp[(1) - (2)].circle);

	Point p1 = getPointOnLabelable(*i, NULL);
	p1.label = (yyvsp[(2) - (2)].cut)->p1->label;
	updatePlottablesPoint(p, p1);

	if((yyvsp[(2) - (2)].cut)->p2 != NULL){
	  Point p2 = getPointOnLabelable(*i, NULL);
	  p2.label = (yyvsp[(2) - (2)].cut)->p2->label;
	  updatePlottablesPoint(p, p2);
	}

	(yyval.plottables) = p;
      }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 2691 "lyparse.y"
    {
	Cut *c = newCut();
	c->p1 = (yyvsp[(2) - (2)].point);
	(yyval.cut) = c;
      }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2697 "lyparse.y"
    {
	Cut *c = newCut();
	c->p1 = (yyvsp[(2) - (3)].point);
	c->p2 = (yyvsp[(3) - (3)].point);
	(yyval.cut) = c;
      }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2707 "lyparse.y"
    {
	Cut *c = newCut();
	c->ls = (yyvsp[(2) - (2)].lineSegment);
	(yyval.cut) = c;	
      }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2713 "lyparse.y"
    {
	(yyval.cut) = newCut();
      }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 2717 "lyparse.y"
    {
	(yyval.cut) = newCut();
      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 2724 "lyparse.y"
    {
	Circle *c = newCircle();
	c->center.label = (yyvsp[(3) - (3)].sval)[0];
	(yyval.circle) = c;
      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 2730 "lyparse.y"
    {
	Circle *c = newCircle();
	c->center.label = (yyvsp[(3) - (3)].sval)[0];
	(yyval.circle) = c;
      }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 2736 "lyparse.y"
    {
	Circle *c = newCircle();
	*c = getLastCircle();
	(yyval.circle) = c;
      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 2742 "lyparse.y"
    {
	Circle *c = newCircle();
	c->center.label = reserveNextPointLabel();
	c->radius = 2.0; //generate random radius here
	(yyval.circle) = c;
      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 2751 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 2755 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 2759 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 2763 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 2764 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 2765 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 2766 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 2770 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 2771 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 2775 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 2780 "lyparse.y"
    {
	Operation *o = newOperation();
	o->label = '-';
	(yyval.operation) = o;
      }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 2786 "lyparse.y"
    {
	Operation *o = newOperation();
	o->label = '+';
	(yyval.operation) = o;
      }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 2794 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 2795 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 2799 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 2803 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 2804 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 2809 "lyparse.y"
    {
	Command *c = newCommand();
	c->plottables = *(yyvsp[(2) - (2)].plottables);
	(yyval.command) = c;
      }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2817 "lyparse.y"
    { (yyval.voidPtr) = NULL;  }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2822 "lyparse.y"
    {
	Plottables *p = newPlottables();
	Point md = getMidPoint((yyvsp[(1) - (1)].lineSegment)->pA, (yyvsp[(1) - (1)].lineSegment)->pB);
	updatePlottablesPoint(p, md);
	(yyval.plottables) = p;
      }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 2829 "lyparse.y"
    {
	Plottables *p = newPlottables();
	LineSegment ls = getAngleBisector(*(yyvsp[(1) - (1)].angle));
	updatePlottablesLineSegment(p, ls);
	(yyval.plottables) = p;
      }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 2836 "lyparse.y"
    {
    (yyvsp[(1) - (1)].plottables)->class = BISECTABLE_D;
    resolvePlottables((yyvsp[(1) - (1)].plottables));
    (yyval.plottables) = (yyvsp[(1) - (1)].plottables);
   }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2845 "lyparse.y"
    {
	(yyval.sval) = newString(yylval.sval);
      }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2852 "lyparse.y"
    {
	(yyval.sval) = newString(yylval.sval);
      }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2859 "lyparse.y"
    {
	(yyval.sval) = newString(yylval.sval);
      }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2866 "lyparse.y"
    {
	(yyval.sval) = newString(yylval.sval);
      }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2873 "lyparse.y"
    {
	(yyval.ival) = yylval.ival;
      }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2880 "lyparse.y"
    {
	(yyval.dval) = yylval.dval;
      }
    break;


/* Line 1787 of yacc.c  */
#line 6426 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 2885 "lyparse.y"

int main()
{
  srand(time(NULL));
  readContext();
  readHistory();
  yyparse();
  return 0;
}
