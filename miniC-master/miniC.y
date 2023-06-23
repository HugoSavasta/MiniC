%{
#include <stdio.h> 
#include <stdlib.h>
#include "parsingMini.h"

extern int chars;
void yyerror (char *s);
%}

%union{
	int val;
	char* id;
	noeud *noeud;
	liste_noeud *liste_noeud;
}


%token VOID INT 
%token PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ

%left MUL DIV
%left PLUS MOINS

%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE

%left REL
%start programme

%token <id> WHILE FOR IF NOT IDENTIFICATEUR CONSTANTE BREAK RETURN DEFAULT CASE SWITCH EXTERN
%type <id>  binary_comp 
%type <noeud> condition selection saut iteration programme instruction bloc appel affectation expression fonction declaration declarateur type variable parm
%type <liste_noeud> liste_fonctions liste_instructions liste_parms liste_expressions liste_declarations liste_declarateurs
%%

programme	:	
		liste_declarations liste_fonctions  {$$= creerNoeud("PROGRAMME");
		    								liste_error* listeError = NULL;
											noeud* declaration = creerNoeud("BLOC");
											declaration->type = GLOBAL;
											declaration->tableSymbole->fonction->declaration = $1;
											noeud* fonction = creerNoeud("FONCTIONS");
											fonction=addAllChild(fonction,$2);
											$$=appendChild2($$,declaration,fonction);
											afficherArbre($$->fils[0]);
											listeError=verifierDeclarationFonction($$->fils[1],listeError);
											listeError=checkInBlock($$,$$,listeError);
											if(afficherErrors(listeError)){
												exit(1);
											}
											generateDotFile($2);}
;
liste_declarations	:	
		liste_declarations declaration  {$$=addNoeud($1,$2);}		
	|				{$$=NULL;}
;
liste_fonctions	:	
		liste_fonctions fonction      {$$ = addNoeud($1,$2);} 
|      			fonction			{$$= creerListeNoeud($1);}
;
declaration	:	
		type liste_declarateurs ';' {if(strcmp($1->val,"int")==0){
										$$ = creerNoeud("DECLARATION");
										$$ = addAllChild($$,$2);
									} else{
										yyerror("Error : Declaration of a non-handled type.");
									}}
;
liste_declarateurs	:
		liste_declarateurs ',' declarateur {$$= addNoeud($1,$3);}
	|	declarateur  {$$ = creerListeNoeud($1);}
;
declarateur	:	
		IDENTIFICATEUR   {$$ = newVariable($1,yylineno);}
	|	declarateur '[' CONSTANTE ']'  {$$=appendChild1($1,creerNoeud($3));}  
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' bloc {char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"%s, %s",$2,$1->val);
																								$$= creerNoeud(funcname);
																								$$->type = FONCTION;
																								$$=newFunction($$,$2,$1,$4,yylineno);
																								$$ = appendChild1($$,$6);
																								}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"EXTERN %s, %s",$3,$2->val);
																								$$= creerNoeud(funcname);
																								$$->type = EXTERNE;
																								$$=newFunction($$,$3,$2,$5,yylineno);
																								}
;
type	:	
		VOID {$$ = creerNoeud("void");}
	|	INT {$$ = creerNoeud("int");}
;

liste_parms	:	
		liste_parms ',' parm {$$=addNoeud($1,$3);}
	|	parm {liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
			$$ = f;
			$$=addNoeud($$,$1);}
	|	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		$$ = f;}
;

parm	:	 
		INT IDENTIFICATEUR  {$$ = creerNoeud($2);
							$$->tableSymbole->typeu=INTEGER;}
;

liste_instructions :	
		liste_instructions instruction {if ($2!=NULL) {$$=addNoeud($1,$2);}}
	|	{$$=NULL;}
;
instruction	:	
		iteration {$$=$1;}
	|	selection {$$=$1;}
	|	saut {$$=$1;}
	|	affectation ';' {$$=$1;}
	|	bloc {$$=$1;}
	|	appel {$$=$1;}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction 	{$$= creerNoeud("FOR");
																			if (strcmp($9->val,"BLOC")==0 && $9->nb_fils < 2){
																				$$ = appendChild3($$,$3,$5,$7);
																				for(int i = 0; i < $9->nb_fils; i++){
																					$$ = appendChild1($$,$9->fils[i]);
																				}
																				
																			} else {
																				$$ = appendChild4($$,$3,$5,$7,$9);
																			}}
	|	WHILE '(' condition ')' instruction {$$= creerNoeud("WHILE");
											$$ = appendChild2($$,$3,$5);}
	|   error '\n' {yyerror("reenter last");
                        yyerrok; };
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {$$= creerNoeud("IF");
													$$->type = IF;
													$$ = appendChild2($$,$3,$5);}
	|	IF '(' condition ')' instruction ELSE instruction {$$= creerNoeud("IF");
															$$ = appendChild3($$,$3,$5,$7);}
	|	SWITCH '(' expression ')' instruction {$$= creerNoeud("SWITCH");
												$$->tableSymbole->line = yylineno;
												$5->tableSymbole->line = yylineno;
												$$->type = SWITCHE;
												makeSwitchPretty($5);
												if (strcmp($5->val,"BLOC")==1){
													$$ = appendChild2($$,$3,$5);
												}
												else {
													$$ = appendChild1($$,$3);
													for(int i = 0; i < $5->nb_fils; i++){
														$$ = appendChild1($$,$5->fils[i]);
													}
												}}
	|	CASE CONSTANTE ':' instruction {$$= creerNoeud("CASE");
										$$->tableSymbole->line = yylineno;
										noeud* constante = creerNoeud($2);
										$$ = appendChild2($$,constante,$4);}
	|	DEFAULT ':' instruction {$$= creerNoeud("DEFAULT");
								$$ = appendChild1($$,$3);}
;
saut	:	
		BREAK ';' {$$= creerNoeud("BREAK"); 
					$$->type = BREAK;}
	|	RETURN ';' {$$= creerNoeud("RETURN");
					$$->type = RETURN;
					$$->tableSymbole->line = yylineno;}
	|	RETURN expression ';' {$$= creerNoeud("RETURN");
							$$->type = RETURN;
							$$->tableSymbole->line = yylineno;
							$$ = appendChild1($$,$2);}
;
affectation	:	 
		variable '=' expression   {$$ = creerNoeud(":=");
									$$->type = AFFECTATION;
									$1->tableSymbole->line = yylineno;
									$1->tableSymbole->typeu = INTEGER;
									$$ = appendChild2($$,$1,$3);}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$= creerNoeud("BLOC");
														$$->tableSymbole->fonction->declaration=$2;
														if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															if ($3->liste_noeud[i]!=NULL){
															$$ = appendChild1($$,$3->liste_noeud[i]);
														}
														}
														}
}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$= creerNoeud($1);
														$$->tableSymbole->line = yylineno;
														$$->tableSymbole->fonction->nbParametres = $3->nb_noeud;
														if ($3->nb_noeud > 0){
															for(int i = 0; i < $3->nb_noeud; i++){
																if ($3->liste_noeud[i]!=NULL){
																$$ = appendChild1($$,$3->liste_noeud[i]);
																}
															}
														}
														$$->type=APPELFONCTION;
													}
;
variable	:	
		IDENTIFICATEUR  {$$ = creerNoeud($1);
						$$->tableSymbole->line = yylineno;
						$$->tableSymbole->typeu = INTEGER;}
	|	variable '[' expression ']' {
									if (strcmp($1->val,"TAB")==0){
										$$ = appendChild1($$,$3);}
									else{
										$$ = creerNoeud("TAB");
										$$ = appendChild2($$,$1,$3);}
									}
;
expression	:	
		'(' expression ')'	{$$ = $2;}                      
	|	expression PLUS expression	{$$= creerNoeud("+");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression MOINS expression	{$$= creerNoeud("-");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression MUL expression	{$$= creerNoeud("*");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression DIV expression	{$$= creerNoeud("/");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression LSHIFT expression	{$$= creerNoeud("<<");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression RSHIFT expression	{$$= creerNoeud(">>");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression BAND expression	{$$= creerNoeud("&");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	expression BOR expression	{$$= creerNoeud("|");
												$$->type=OPERATEUR;
												$$->tableSymbole->typeu=INTEGER;
												$$ = appendChild2($$,$1,$3);}
	|	MOINS expression	{if ($2->type==CONSTANTEE){
								char* temp = malloc(sizeof(char)*100);
								sprintf(temp,"-%s", $2->val);
								temp=realloc(temp,sizeof(char)*strlen(temp));
								$$ = creerNoeud(temp);
								$$->tableSymbole->typeu=INTEGER;
								$$->type=CONSTANTEE;
							}
							else{
								$$ = creerNoeud("-");
								$$ = appendChild1($$,$2);
							}
							}                                   
	|	CONSTANTE       {$$= creerNoeud($1); 
						$$->tableSymbole->typeu=INTEGER;
						$$->type=CONSTANTEE;}                                                  							
	|	variable	 {$$ = $1;}                                 
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = creerNoeud($1);
													$$->type = APPELFONCTION;
													$$->tableSymbole->line = yylineno;
													$$->tableSymbole->fonction->nbParametres = $3->nb_noeud;
													if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															$$ = appendChild1($$,$3->liste_noeud[i]);
															$$->tableSymbole->line = yylineno;

														}
													}
													}                                  
;

liste_expressions	:	
		liste_expressions ',' expression {$$=addNoeud($1,$3);}
	|	expression {$$=creerListeNoeud($1);}
	|   {liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		$$ = f;}
;

condition	:	
		NOT '(' condition ')' {$$ = creerNoeud("NOT");
								$$ = appendChild1($$,$3);}
	|	condition LAND condition %prec REL {
									$$ = creerNoeud("&&");
									$$->type = OPERATEUR;
									$$ = appendChild2($$,$1,$3);
	}
	|	condition LOR condition %prec REL {
									$$ = creerNoeud("||");
									$$->type = OPERATEUR;
									$$ = appendChild2($$,$1,$3);
	}
	|	'(' condition ')' {$$ = $2;}
	|	expression binary_comp expression {
										$$ = creerNoeud($2);
										$$->type = OPERATEUR;
										$$ = appendChild2($$,$1,$3);
	}
;
binary_comp	:	
		LT	{$$ = "<"; }
	|	GT	{$$ = ">"; }
	|	GEQ	{$$ = ">="; }
	|	LEQ	{$$ = "<="; }
	|	EQ	{$$ = "=="; }
	|	NEQ	{$$ = "!="; }
;

%%
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