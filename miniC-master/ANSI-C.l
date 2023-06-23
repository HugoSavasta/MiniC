%option noyywrap
D                       [0-9]
L                       [a-zA-Z_]

%{
#include <stdio.h>
#include "parsingMini.h"
#include "y.tab.h"
%}

%%
"break"                 { return BREAK; }
"case"                  { return CASE; }
"default"               { return DEFAULT; }
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"switch"                { return SWITCH; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

{L}({L}|{D})*           {yylval.id = strdup(yytext); return IDENTIFICATEUR;}
{D}+                    {yylval.id = strdup(yytext); return CONSTANTE;}

"&"                     {return BAND;}
"|"                     {return BOR;}
">>"                    {return RSHIFT;}
"<<"                    {return LSHIFT;}
"&&"                    {return LAND;}
"||"                    {return LOR;}
"<="                    {return LEQ;}
">="                    {return GEQ;}
"=="                    {return EQ;}
"!="                    {return NEQ;}
">"                     {return GT;}
"<"                     {return LT;}
"!"                     {return NOT;}

"+"                     {return PLUS;}
"-"                     {return MOINS;}
"*"                     {return MUL;}
"/"                     {return DIV;}

"{"|"}"|"("|")"|"["|"]" {return yytext[0]; }
";"|":"|","|"="         {return yytext[0]; } 

(\/\/.*)|(\/\*)(.|\r|\n)*?(\*\/)  {int counter = 0;
                                    for (int i=0; i<strlen(yytext); i++){
                                        if (yytext[i] == '\n'){
                                        counter += 1;
                                        }
                                    }
                                    yylineno+=counter;
                                    }

\n                        {  yylineno++;}
[ \t\v\f]                {  }
.                       {printf("Not allowed character (%s) line : %d\n",yytext,yylineno); exit(1);}
%%
