/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220128

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "miniC.y"
#include <stdio.h> 
#include <stdlib.h>
#include "parsingMini.h"

extern int chars;
void yyerror (char *s);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 10 "miniC.y"
typedef union YYSTYPE{
	int val;
	char* id;
	noeud *noeud;
	liste_noeud *liste_noeud;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define VOID 257
#define INT 258
#define PLUS 259
#define MOINS 260
#define MUL 261
#define DIV 262
#define LSHIFT 263
#define RSHIFT 264
#define BAND 265
#define BOR 266
#define LAND 267
#define LOR 268
#define LT 269
#define GT 270
#define GEQ 271
#define LEQ 272
#define EQ 273
#define NEQ 274
#define THEN 275
#define ELSE 276
#define REL 277
#define WHILE 278
#define FOR 279
#define IF 280
#define NOT 281
#define IDENTIFICATEUR 282
#define CONSTANTE 283
#define BREAK 284
#define RETURN 285
#define DEFAULT 286
#define CASE 287
#define SWITCH 288
#define EXTERN 289
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   21,   21,   17,   17,   12,   22,   22,   13,   13,
   11,   11,   14,   14,   19,   19,   19,   16,   18,   18,
    6,    6,    6,    6,    6,    6,    5,    5,    5,    3,
    3,    3,    3,    3,    4,    4,    4,    9,    7,    8,
   15,   15,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   20,   20,   20,    2,    2,
    2,    2,    2,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    2,    1,    3,    3,    1,    1,    4,
    6,    7,    1,    1,    3,    1,    0,    2,    2,    0,
    1,    1,    1,    2,    1,    1,    9,    5,    2,    5,
    7,    5,    4,    3,    2,    2,    3,    3,    4,    5,
    1,    4,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    1,    1,    4,    3,    1,    0,    4,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   13,   14,    0,    5,    2,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    6,    0,
    0,    0,    0,   16,    0,    0,    9,    0,    0,   18,
    0,    0,   10,    0,   15,    3,   11,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   39,   22,   23,   21,   19,   25,   26,    0,    0,
   29,    0,    0,    0,    0,   35,    0,    0,   53,   36,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   37,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   64,   65,   66,   67,   68,   69,    0,    0,    0,
    0,    0,    0,   43,    0,    0,    0,    0,    0,    0,
   50,   51,   33,    0,   42,    0,   62,   60,   61,   28,
    0,    0,    0,    0,   40,   55,   32,   59,    0,    0,
    0,   31,    0,   27,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  291,  312,  257,  258,  289,  302,  303,  305,  308,  305,
  282,  304,  313,  302,  305,  282,   40,   91,   59,   44,
  282,   40,  258,  307,  310,  283,  282,  304,  310,  282,
   44,   41,   93,   41,  307,  123,  298,   59,  312,  305,
  309,  256,  278,  279,  280,  282,  284,  285,  286,  287,
  288,  125,  294,  295,  296,  297,  298,  299,  300,  306,
   10,   40,   40,   40,   40,   59,  260,  282,  283,   59,
   40,  301,  306,   58,  283,   40,   59,   91,   61,  281,
   40,  293,  301,  282,  300,  293,  301,  311,  301,   40,
  301,  259,  260,  261,  262,  263,  264,  265,  266,   59,
  297,   58,  301,  301,  301,   40,  293,  301,  267,  268,
   41,  269,  270,  271,  272,  273,  274,  292,   59,   41,
   44,   41,  311,   41,  301,  301,  301,  301,  301,  301,
  301,  301,  297,   41,   93,  293,   41,  293,  293,  297,
  301,  293,  297,  301,   59,   41,  297,   41,   59,  276,
  300,  297,   41,  297,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
  118,   82,   53,   54,   55,   56,   57,   58,   59,   83,
    6,    7,   12,    8,   73,   24,    9,   41,   25,   88,
    2,   13,
};
static const YYINT yysindex[] = {                         0,
    0, -241,    0,    0, -234,    0,    0, -278, -241, -254,
   -4,  -50,  -19,    0, -252,   11, -212, -215,    0, -208,
   -4, -212, -206,    0,   18,   -1,    0,  -50,   23,    0,
 -212,  -45,    0,   35,    0,    0,    0,    0, -234, -208,
 -110,   90,   56,   68,   72,   76,   51,  -40,   59, -163,
   81,    0,    0,    0,    0,    0,    0,    0,   64,  -54,
    0,  -37, -158,  -37,  -35,    0,  -35,   85,    0,    0,
  -35,  -47,   37,  196,   84,  -35,    0,  -35,  -35,  103,
  -37,    4,  147,    0,   67,   20,  -60,   28, -209,  -35,
  130,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,    0,
    0,  196,  138,  -79,  -60,  -37,   36,   86,  -37,  -37,
  196,    0,    0,    0,    0,    0,    0,  -35,  -37,  196,
  -35,   71,   29,    0, -209, -209, -126, -126, -180, -180,
    0,    0,    0,  196,    0,   50,    0,    0,    0,    0,
  -60,  -58, -128,  -60,    0,    0,    0,    0, -158,  196,
  108,    0,  196,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  150,    0,
  -38,  -17,    0,    0,    0,    0,   43,    0,    0,    0,
    0,   43,    0,    0,    0,    0,    0,  -15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -90,    0,
    0,    0,    0,    0,    0,  -52,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,    0,    0,  -33,    0,    0,
    0,    0,  -10,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   61,    0,   38,   60,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   54,   70,  100,  114,    6,   22,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   34,    0,  210,   65,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,   26,    0,    0,    0,  303,  119,    0,  -61,  437,
  143,    0,  133,   13,  -31,  123,    0,    0,  134,   74,
  121,    0,
};
#define YYTABLESIZE 558
static const YYINT yytable[] = {                         71,
  149,   85,   81,   11,   71,    9,   79,   41,   41,   60,
   41,  100,   36,  135,   52,    3,    4,   10,   70,   38,
    9,   15,    3,    4,   20,   41,    8,   16,    7,   21,
   54,   60,   20,   54,   20,   17,   78,   38,   41,   19,
   18,    8,   60,    7,  111,   23,   48,    5,   54,   48,
   22,   40,    9,   96,   97,   98,   99,   41,   32,   41,
  120,   31,   49,   34,   48,   49,   31,   26,  122,  146,
   60,  121,  121,   27,   63,   30,  137,   36,   52,   60,
   49,   52,   54,   17,   98,   99,   17,  151,   60,   86,
  148,   33,   63,   38,   44,   62,   52,   44,   48,   61,
   58,   57,   60,   58,   57,   56,  107,   63,   56,   66,
   45,   64,   44,   45,   49,   65,   74,   60,   60,   75,
   76,   60,   77,   84,   90,  119,  124,   78,   45,  145,
   52,  136,   92,   93,  138,  139,   96,   97,   98,   99,
   46,  102,  106,   46,  142,   42,   44,  150,  153,    1,
   37,   14,   28,   35,   47,   29,   39,   47,   46,    0,
    0,    0,   45,  123,    0,   20,    0,   43,   44,   45,
  124,   46,   47,   47,   48,   49,   50,   51,  134,   92,
   93,   94,   95,   96,   97,   98,   99,   20,   20,   20,
    0,   20,   46,   20,   20,   20,   20,   20,   92,   93,
   94,   95,   96,   97,   98,   99,   47,    0,  109,  110,
    0,   92,   93,   94,   95,   96,   97,   98,   99,   67,
    0,    0,   67,    0,   67,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   68,   69,   80,   68,   69,   68,   69,   54,   54,
   54,   54,   54,   54,   54,   54,   54,   54,   54,   54,
   54,   54,   54,   54,   48,   48,   48,   48,   48,   48,
  109,  110,   48,   48,   48,   48,   48,   48,   48,   48,
   49,   49,   49,   49,   49,   49,  109,  110,   49,   49,
   49,   49,   49,   49,   49,   49,   52,   52,   52,   52,
   63,   63,  109,  110,   52,   52,   52,   52,   52,   52,
   52,   52,   44,   44,   44,   44,  109,  110,   36,    0,
   44,   44,   44,   44,   44,   44,   44,   44,   45,   45,
   45,   45,   30,    0,   30,    0,   45,   45,   45,   45,
   45,   45,   45,   45,   92,   93,   94,   95,   96,   97,
   98,   99,    0,    0,  112,  113,  114,  115,  116,  117,
   46,   46,    0,    0,    0,    0,   46,   46,   46,   46,
   46,   46,   46,   46,   47,   47,  101,    0,    0,    0,
   47,   47,   47,   47,   47,   47,   47,   47,   92,   93,
   94,   95,   96,   97,   98,   99,   92,   93,   94,   95,
   96,   97,   98,   99,  133,   92,   93,   94,   95,   96,
   97,   98,   99,  140,    0,  112,  113,  114,  115,  116,
  117,    0,  143,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  147,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   42,  152,    0,    0,  154,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,    0,    0,   43,   44,   45,    0,   46,    0,   47,
   48,   49,   50,   51,   72,    0,    0,   30,   30,   30,
    0,   30,    0,   30,   30,   30,   30,   30,    0,    0,
    0,   87,    0,   89,    0,    0,    0,   91,    0,    0,
    0,    0,  103,    0,  104,  105,    0,  108,    0,    0,
    0,    0,    0,    0,    0,    0,   87,    0,  125,  126,
  127,  128,  129,  130,  131,  132,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,    0,    0,  144,
};
static const YYINT yycheck[] = {                         40,
   59,   63,   40,  282,   40,   44,   61,   41,   61,   41,
   44,   59,  123,   93,  125,  257,  258,    5,   59,   41,
   59,    9,  257,  258,   44,   59,   44,  282,   44,  282,
   41,   63,  123,   44,  125,   40,   91,   59,   91,   59,
   91,   59,   74,   59,   41,  258,   41,  289,   59,   44,
   40,   39,   91,  263,  264,  265,  266,   91,   41,   93,
   41,   44,   41,   41,   59,   44,   44,  283,   41,   41,
  102,   44,   44,  282,   41,  282,   41,  123,   41,  111,
   59,   44,   93,   41,  265,  266,   44,  149,  120,   64,
   41,   93,   59,   59,   41,   40,   59,   44,   93,   10,
   41,   41,  134,   44,   44,   41,   81,   40,   44,   59,
   41,   40,   59,   44,   93,   40,   58,  149,  150,  283,
   40,  153,   59,  282,   40,   59,   41,   91,   59,   59,
   93,  106,  259,  260,  109,  110,  263,  264,  265,  266,
   41,   58,   40,   44,  119,  256,   93,  276,   41,    0,
   32,    9,   20,   31,   41,   22,   36,   44,   59,   -1,
   -1,   -1,   93,   90,   -1,  256,   -1,  278,  279,  280,
   41,  282,   59,  284,  285,  286,  287,  288,   41,  259,
  260,  261,  262,  263,  264,  265,  266,  278,  279,  280,
   -1,  282,   93,  284,  285,  286,  287,  288,  259,  260,
  261,  262,  263,  264,  265,  266,   93,   -1,  267,  268,
   -1,  259,  260,  261,  262,  263,  264,  265,  266,  260,
   -1,   -1,  260,   -1,  260,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  282,  283,  281,  282,  283,  282,  283,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  259,  260,  261,  262,  263,  264,
  267,  268,  267,  268,  269,  270,  271,  272,  273,  274,
  259,  260,  261,  262,  263,  264,  267,  268,  267,  268,
  269,  270,  271,  272,  273,  274,  259,  260,  261,  262,
  267,  268,  267,  268,  267,  268,  269,  270,  271,  272,
  273,  274,  259,  260,  261,  262,  267,  268,  123,   -1,
  267,  268,  269,  270,  271,  272,  273,  274,  259,  260,
  261,  262,  123,   -1,  125,   -1,  267,  268,  269,  270,
  271,  272,  273,  274,  259,  260,  261,  262,  263,  264,
  265,  266,   -1,   -1,  269,  270,  271,  272,  273,  274,
  261,  262,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,  273,  274,  261,  262,   74,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,  273,  274,  259,  260,
  261,  262,  263,  264,  265,  266,  259,  260,  261,  262,
  263,  264,  265,  266,  102,  259,  260,  261,  262,  263,
  264,  265,  266,  111,   -1,  269,  270,  271,  272,  273,
  274,   -1,  120,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  134,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  256,  150,   -1,   -1,  153,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  278,  279,  280,   -1,  282,   -1,  284,
  285,  286,  287,  288,   48,   -1,   -1,  278,  279,  280,
   -1,  282,   -1,  284,  285,  286,  287,  288,   -1,   -1,
   -1,   65,   -1,   67,   -1,   -1,   -1,   71,   -1,   -1,
   -1,   -1,   76,   -1,   78,   79,   -1,   81,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   -1,   92,   93,
   94,   95,   96,   97,   98,   99,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  118,   -1,   -1,  121,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#define YYUNDFTOKEN 314
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"error","VOID","INT","PLUS","MOINS","MUL","DIV","LSHIFT","RSHIFT","BAND",
"BOR","LAND","LOR","LT","GT","GEQ","LEQ","EQ","NEQ","THEN","ELSE","REL","WHILE",
"FOR","IF","NOT","IDENTIFICATEUR","CONSTANTE","BREAK","RETURN","DEFAULT","CASE",
"SWITCH","EXTERN","$accept","programme","binary_comp","condition","selection",
"saut","iteration","instruction","bloc","appel","affectation","expression",
"fonction","declaration","declarateur","type","variable","parm",
"liste_fonctions","liste_instructions","liste_parms","liste_expressions",
"liste_declarations","liste_declarateurs","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programme",
"programme : liste_declarations liste_fonctions",
"liste_declarations : liste_declarations declaration",
"liste_declarations :",
"liste_fonctions : liste_fonctions fonction",
"liste_fonctions : fonction",
"declaration : type liste_declarateurs ';'",
"liste_declarateurs : liste_declarateurs ',' declarateur",
"liste_declarateurs : declarateur",
"declarateur : IDENTIFICATEUR",
"declarateur : declarateur '[' CONSTANTE ']'",
"fonction : type IDENTIFICATEUR '(' liste_parms ')' bloc",
"fonction : EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'",
"type : VOID",
"type : INT",
"liste_parms : liste_parms ',' parm",
"liste_parms : parm",
"liste_parms :",
"parm : INT IDENTIFICATEUR",
"liste_instructions : liste_instructions instruction",
"liste_instructions :",
"instruction : iteration",
"instruction : selection",
"instruction : saut",
"instruction : affectation ';'",
"instruction : bloc",
"instruction : appel",
"iteration : FOR '(' affectation ';' condition ';' affectation ')' instruction",
"iteration : WHILE '(' condition ')' instruction",
"iteration : error '\\n'",
"selection : IF '(' condition ')' instruction",
"selection : IF '(' condition ')' instruction ELSE instruction",
"selection : SWITCH '(' expression ')' instruction",
"selection : CASE CONSTANTE ':' instruction",
"selection : DEFAULT ':' instruction",
"saut : BREAK ';'",
"saut : RETURN ';'",
"saut : RETURN expression ';'",
"affectation : variable '=' expression",
"bloc : '{' liste_declarations liste_instructions '}'",
"appel : IDENTIFICATEUR '(' liste_expressions ')' ';'",
"variable : IDENTIFICATEUR",
"variable : variable '[' expression ']'",
"expression : '(' expression ')'",
"expression : expression PLUS expression",
"expression : expression MOINS expression",
"expression : expression MUL expression",
"expression : expression DIV expression",
"expression : expression LSHIFT expression",
"expression : expression RSHIFT expression",
"expression : expression BAND expression",
"expression : expression BOR expression",
"expression : MOINS expression",
"expression : CONSTANTE",
"expression : variable",
"expression : IDENTIFICATEUR '(' liste_expressions ')'",
"liste_expressions : liste_expressions ',' expression",
"liste_expressions : expression",
"liste_expressions :",
"condition : NOT '(' condition ')'",
"condition : condition LAND condition",
"condition : condition LOR condition",
"condition : '(' condition ')'",
"condition : expression binary_comp expression",
"binary_comp : LT",
"binary_comp : GT",
"binary_comp : GEQ",
"binary_comp : LEQ",
"binary_comp : EQ",
"binary_comp : NEQ",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 331 "miniC.y"
extern int yylineno;

void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	clearFile();
	while(yyparse());
}
#line 660 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 41 "miniC.y"
	{yyval.noeud= creerNoeud("PROGRAMME");
		    								liste_error* listeError = NULL;
											noeud* declaration = creerNoeud("BLOC");
											declaration->type = GLOBAL;
											declaration->tableSymbole->fonction->declaration = yystack.l_mark[-1].liste_noeud;
											noeud* fonction = creerNoeud("FONCTIONS");
											fonction=addAllChild(fonction,yystack.l_mark[0].liste_noeud);
											yyval.noeud=appendChild2(yyval.noeud,declaration,fonction);
											afficherArbre(yyval.noeud->fils[0]);
											listeError=verifierDeclarationFonction(yyval.noeud->fils[1],listeError);
											listeError=checkInBlock(yyval.noeud,yyval.noeud,listeError);
											if(afficherErrors(listeError)){
												exit(1);
											}
											generateDotFile(yystack.l_mark[0].liste_noeud);}
#line 1347 "y.tab.c"
break;
case 2:
#line 58 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}
#line 1352 "y.tab.c"
break;
case 3:
#line 59 "miniC.y"
	{yyval.liste_noeud=NULL;}
#line 1357 "y.tab.c"
break;
case 4:
#line 62 "miniC.y"
	{yyval.liste_noeud = addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}
#line 1362 "y.tab.c"
break;
case 5:
#line 63 "miniC.y"
	{yyval.liste_noeud= creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1367 "y.tab.c"
break;
case 6:
#line 66 "miniC.y"
	{if(strcmp(yystack.l_mark[-2].noeud->val,"int")==0){
										yyval.noeud = creerNoeud("DECLARATION");
										yyval.noeud = addAllChild(yyval.noeud,yystack.l_mark[-1].liste_noeud);
									} else{
										yyerror("Error : Declaration of a non-handled type.");
									}}
#line 1377 "y.tab.c"
break;
case 7:
#line 74 "miniC.y"
	{yyval.liste_noeud= addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1382 "y.tab.c"
break;
case 8:
#line 75 "miniC.y"
	{yyval.liste_noeud = creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1387 "y.tab.c"
break;
case 9:
#line 78 "miniC.y"
	{yyval.noeud = newVariable(yystack.l_mark[0].id,yylineno);}
#line 1392 "y.tab.c"
break;
case 10:
#line 79 "miniC.y"
	{yyval.noeud=appendChild1(yystack.l_mark[-3].noeud,creerNoeud(yystack.l_mark[-1].id));}
#line 1397 "y.tab.c"
break;
case 11:
#line 82 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"%s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = FONCTION;
																								yyval.noeud=newFunction(yyval.noeud,yystack.l_mark[-4].id,yystack.l_mark[-5].noeud,yystack.l_mark[-2].liste_noeud,yylineno);
																								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);
																								}
#line 1408 "y.tab.c"
break;
case 12:
#line 89 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"EXTERN %s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = EXTERNE;
																								yyval.noeud=newFunction(yyval.noeud,yystack.l_mark[-4].id,yystack.l_mark[-5].noeud,yystack.l_mark[-2].liste_noeud,yylineno);
																								}
#line 1418 "y.tab.c"
break;
case 13:
#line 97 "miniC.y"
	{yyval.noeud = creerNoeud("void");}
#line 1423 "y.tab.c"
break;
case 14:
#line 98 "miniC.y"
	{yyval.noeud = creerNoeud("int");}
#line 1428 "y.tab.c"
break;
case 15:
#line 102 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1433 "y.tab.c"
break;
case 16:
#line 103 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
			yyval.liste_noeud = f;
			yyval.liste_noeud=addNoeud(yyval.liste_noeud,yystack.l_mark[0].noeud);}
#line 1441 "y.tab.c"
break;
case 17:
#line 107 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1448 "y.tab.c"
break;
case 18:
#line 113 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id);
							yyval.noeud->tableSymbole->typeu=INTEGER;}
#line 1454 "y.tab.c"
break;
case 19:
#line 118 "miniC.y"
	{if (yystack.l_mark[0].noeud!=NULL) {yyval.liste_noeud=addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}}
#line 1459 "y.tab.c"
break;
case 20:
#line 119 "miniC.y"
	{yyval.liste_noeud=NULL;}
#line 1464 "y.tab.c"
break;
case 21:
#line 122 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1469 "y.tab.c"
break;
case 22:
#line 123 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1474 "y.tab.c"
break;
case 23:
#line 124 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1479 "y.tab.c"
break;
case 24:
#line 125 "miniC.y"
	{yyval.noeud=yystack.l_mark[-1].noeud;}
#line 1484 "y.tab.c"
break;
case 25:
#line 126 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1489 "y.tab.c"
break;
case 26:
#line 127 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1494 "y.tab.c"
break;
case 27:
#line 130 "miniC.y"
	{yyval.noeud= creerNoeud("FOR");
																			if (strcmp(yystack.l_mark[0].noeud->val,"BLOC")==0 && yystack.l_mark[0].noeud->nb_fils < 2){
																				yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-6].noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud);
																				for(int i = 0; i < yystack.l_mark[0].noeud->nb_fils; i++){
																					yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud->fils[i]);
																				}
																				
																			} else {
																				yyval.noeud = appendChild4(yyval.noeud,yystack.l_mark[-6].noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
																			}}
#line 1508 "y.tab.c"
break;
case 28:
#line 140 "miniC.y"
	{yyval.noeud= creerNoeud("WHILE");
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1514 "y.tab.c"
break;
case 29:
#line 142 "miniC.y"
	{yyerror("reenter last");
                        yyerrok; }
#line 1520 "y.tab.c"
break;
case 30:
#line 146 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
													yyval.noeud->type = IF;
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1527 "y.tab.c"
break;
case 31:
#line 149 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
															yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1533 "y.tab.c"
break;
case 32:
#line 151 "miniC.y"
	{yyval.noeud= creerNoeud("SWITCH");
												yyval.noeud->tableSymbole->line = yylineno;
												yystack.l_mark[0].noeud->tableSymbole->line = yylineno;
												yyval.noeud->type = SWITCHE;
												makeSwitchPretty(yystack.l_mark[0].noeud);
												if (strcmp(yystack.l_mark[0].noeud->val,"BLOC")==1){
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
												}
												else {
													yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].noeud);
													for(int i = 0; i < yystack.l_mark[0].noeud->nb_fils; i++){
														yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud->fils[i]);
													}
												}}
#line 1551 "y.tab.c"
break;
case 33:
#line 165 "miniC.y"
	{yyval.noeud= creerNoeud("CASE");
										yyval.noeud->tableSymbole->line = yylineno;
										noeud* constante = creerNoeud(yystack.l_mark[-2].id);
										yyval.noeud = appendChild2(yyval.noeud,constante,yystack.l_mark[0].noeud);}
#line 1559 "y.tab.c"
break;
case 34:
#line 169 "miniC.y"
	{yyval.noeud= creerNoeud("DEFAULT");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1565 "y.tab.c"
break;
case 35:
#line 173 "miniC.y"
	{yyval.noeud= creerNoeud("BREAK"); 
					yyval.noeud->type = BREAK;}
#line 1571 "y.tab.c"
break;
case 36:
#line 175 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
					yyval.noeud->type = RETURN;
					yyval.noeud->tableSymbole->line = yylineno;}
#line 1578 "y.tab.c"
break;
case 37:
#line 178 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
							yyval.noeud->type = RETURN;
							yyval.noeud->tableSymbole->line = yylineno;
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1586 "y.tab.c"
break;
case 38:
#line 184 "miniC.y"
	{yyval.noeud = creerNoeud(":=");
									yyval.noeud->type = AFFECTATION;
									yystack.l_mark[-2].noeud->tableSymbole->line = yylineno;
									yystack.l_mark[-2].noeud->tableSymbole->typeu = INTEGER;
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1595 "y.tab.c"
break;
case 39:
#line 191 "miniC.y"
	{yyval.noeud= creerNoeud("BLOC");
														yyval.noeud->tableSymbole->fonction->declaration=yystack.l_mark[-2].liste_noeud;
														if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															if (yystack.l_mark[-1].liste_noeud->liste_noeud[i]!=NULL){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
														}
														}
														}
}
#line 1609 "y.tab.c"
break;
case 40:
#line 203 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-4].id);
														yyval.noeud->tableSymbole->line = yylineno;
														yyval.noeud->tableSymbole->fonction->nbParametres = yystack.l_mark[-2].liste_noeud->nb_noeud;
														if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0){
															for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
																if (yystack.l_mark[-2].liste_noeud->liste_noeud[i]!=NULL){
																yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
																}
															}
														}
														yyval.noeud->type=APPELFONCTION;
													}
#line 1625 "y.tab.c"
break;
case 41:
#line 217 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id);
						yyval.noeud->tableSymbole->line = yylineno;
						yyval.noeud->tableSymbole->typeu = INTEGER;}
#line 1632 "y.tab.c"
break;
case 42:
#line 220 "miniC.y"
	{
									if (strcmp(yystack.l_mark[-3].noeud->val,"TAB")==0){
										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
									else{
										yyval.noeud = creerNoeud("TAB");
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-3].noeud,yystack.l_mark[-1].noeud);}
									}
#line 1643 "y.tab.c"
break;
case 43:
#line 229 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1648 "y.tab.c"
break;
case 44:
#line 230 "miniC.y"
	{yyval.noeud= creerNoeud("+");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1656 "y.tab.c"
break;
case 45:
#line 234 "miniC.y"
	{yyval.noeud= creerNoeud("-");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1664 "y.tab.c"
break;
case 46:
#line 238 "miniC.y"
	{yyval.noeud= creerNoeud("*");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1672 "y.tab.c"
break;
case 47:
#line 242 "miniC.y"
	{yyval.noeud= creerNoeud("/");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1680 "y.tab.c"
break;
case 48:
#line 246 "miniC.y"
	{yyval.noeud= creerNoeud("<<");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1688 "y.tab.c"
break;
case 49:
#line 250 "miniC.y"
	{yyval.noeud= creerNoeud(">>");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1696 "y.tab.c"
break;
case 50:
#line 254 "miniC.y"
	{yyval.noeud= creerNoeud("&");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1704 "y.tab.c"
break;
case 51:
#line 258 "miniC.y"
	{yyval.noeud= creerNoeud("|");
												yyval.noeud->type=OPERATEUR;
												yyval.noeud->tableSymbole->typeu=INTEGER;
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1712 "y.tab.c"
break;
case 52:
#line 262 "miniC.y"
	{if (yystack.l_mark[0].noeud->type==CONSTANTEE){
								char* temp = malloc(sizeof(char)*100);
								sprintf(temp,"-%s", yystack.l_mark[0].noeud->val);
								temp=realloc(temp,sizeof(char)*strlen(temp));
								yyval.noeud = creerNoeud(temp);
								yyval.noeud->tableSymbole->typeu=INTEGER;
								yyval.noeud->type=CONSTANTEE;
							}
							else{
								yyval.noeud = creerNoeud("-");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);
							}
							}
#line 1729 "y.tab.c"
break;
case 53:
#line 275 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[0].id); 
						yyval.noeud->tableSymbole->typeu=INTEGER;
						yyval.noeud->type=CONSTANTEE;}
#line 1736 "y.tab.c"
break;
case 54:
#line 278 "miniC.y"
	{yyval.noeud = yystack.l_mark[0].noeud;}
#line 1741 "y.tab.c"
break;
case 55:
#line 279 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[-3].id);
													yyval.noeud->type = APPELFONCTION;
													yyval.noeud->tableSymbole->line = yylineno;
													yyval.noeud->tableSymbole->fonction->nbParametres = yystack.l_mark[-1].liste_noeud->nb_noeud;
													if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
															yyval.noeud->tableSymbole->line = yylineno;

														}
													}
													}
#line 1757 "y.tab.c"
break;
case 56:
#line 294 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1762 "y.tab.c"
break;
case 57:
#line 295 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1767 "y.tab.c"
break;
case 58:
#line 296 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1774 "y.tab.c"
break;
case 59:
#line 302 "miniC.y"
	{yyval.noeud = creerNoeud("NOT");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1780 "y.tab.c"
break;
case 60:
#line 304 "miniC.y"
	{
									yyval.noeud = creerNoeud("&&");
									yyval.noeud->type = OPERATEUR;
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1789 "y.tab.c"
break;
case 61:
#line 309 "miniC.y"
	{
									yyval.noeud = creerNoeud("||");
									yyval.noeud->type = OPERATEUR;
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1798 "y.tab.c"
break;
case 62:
#line 314 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1803 "y.tab.c"
break;
case 63:
#line 315 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id);
										yyval.noeud->type = OPERATEUR;
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1812 "y.tab.c"
break;
case 64:
#line 322 "miniC.y"
	{yyval.id = "<"; }
#line 1817 "y.tab.c"
break;
case 65:
#line 323 "miniC.y"
	{yyval.id = ">"; }
#line 1822 "y.tab.c"
break;
case 66:
#line 324 "miniC.y"
	{yyval.id = ">="; }
#line 1827 "y.tab.c"
break;
case 67:
#line 325 "miniC.y"
	{yyval.id = "<="; }
#line 1832 "y.tab.c"
break;
case 68:
#line 326 "miniC.y"
	{yyval.id = "=="; }
#line 1837 "y.tab.c"
break;
case 69:
#line 327 "miniC.y"
	{yyval.id = "!="; }
#line 1842 "y.tab.c"
break;
#line 1844 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
