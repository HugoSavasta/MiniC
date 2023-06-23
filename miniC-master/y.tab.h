#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
	int val;
	char* id;
	noeud *noeud;
	liste_noeud *liste_noeud;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
