%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void yyerror(const char *msg) ;
int yylex(void) ;

%}

%error-verbose


%left 	AT
%left	OR
%left	AND
%left	EQUALITYOPER
%left 	RELATIONOPER
%left	ADDSUB
%left 	MULTOPER
%right 	UNARYOPER
%left 	DECREMENT
%left 	INCREMENT
%left 	ATT
%left	LISTLEFTRIGHT
%left	DOLLAR

%token	IDENT
%token 	DATATYPE
%token	LISTNAME
%token	LOGICVALUE
%token	INTVALUE
%token	DOUBLEVALUE
%token	CHARVALUE
%token	STRINGVALUE
%token	CONDITIONIF
%token	CONDITIONELSE
%token	LOOP
%token	OPTION
%token	CASE
%token	PARENTSTART
%token	PARENTEND
%token	SQBRASTART
%token	SQBRAEND
%token	INPUT
%token	OUTPUT
%token	ENDCASE
%token	DEFAULTCASE
%token	SEMICOLON
%token	COLON
%token 	ASSIGNATION
%token 	DECLARE
%token	MAINP
%token TWOPOINTS
%token RETURN
%token MULTOPER

%start Program

%%

Program: Program_head block;

Program_head : DATATYPE MAINP PARENTSTART PARENTEND
	| error ;

block :	Block_init { TS_InsertMark(); } Local_var_declaration Subprogs_declaration Sentences Block_end { TS_CleanIn(); };

Block_init : SQBRASTART;

Local_var_declaration :	init_mark_var_declaration local_variables end_mark_var_declaration
	| ;

Subprogs_declaration : Subprogs_declaration Subprog_declaration
	| ;

Sentences :	Sentences Sentence
	| ;

Block_end :	SQBRAEND
	| error ;

init_mark_var_declaration :	DECLARE SQBRASTART ;

local_variables : local_variables Var_body_declaration
	| Var_body_declaration ;

end_mark_var_declaration: SQBRAEND ;

Subprog_declaration : Subprog_head {subProg = 1;} block {subProg = 0;};

Sentence : block
	| assignment_sentence
	| if_sentence
	| while_sentence
	| switch_sentence
	| input_sentence
	| output_sentence
	| return_sentence
	| list_operations ;

Var_body_declaration : types { setType($1); } list_of_ident SEMICOLON
	| error ;

Subprog_head : types IDENT { TS_InsertSUBPROG($2); } PARENTSTART arg_func PARENTEND;

arg_func : arg_func COLON types IDENT {TS_InsertPARAMF($4);}
	| types IDENT {TS_InsertPARAMF($2);}
	| error
	| ;

assignment_sentence : IDENT ASSIGNATION expression SEMICOLON ;

if_sentence: CONDITIONIF PARENTSTART expression PARENTEND Sentence
	| CONDITIONIF PARENTSTART expression PARENTEND Sentence CONDITIONELSE Sentence ;

while_sentence : LOOP PARENTSTART expression PARENTEND Sentence ;

switch_sentence : OPTION PARENTSTART IDENT PARENTEND SQBRASTART cases SQBRAEND ;

input_sentence : INPUT PARENTSTART expression COLON list_of_ident PARENTEND SEMICOLON ;

output_sentence : OUTPUT PARENTSTART expression PARENTEND SEMICOLON ;

return_sentence : RETURN expression SEMICOLON ;

list_operations : IDENT LISTLEFTRIGHT SEMICOLON
	| DOLLAR IDENT SEMICOLON ;

expression : UNARYOPER expression
	| INCREMENT expression
	| DECREMENT expression
	| ADDSUB expression %prec UNARYOPER
	| expression ADDSUB expression
	| expression OR expression
	| expression AND expression
	| expression EQUALITYOPER expression
	| expression RELATIONOPER expression
	| expression DECREMENT expression
	| expression INCREMENT expression ATT expression
	| expression AT expression
	| expression MULTOPER expression
	| PARENTSTART expression PARENTEND
	| IDENT
	| constants
	| function
	| error ;

cases :	CASE const TWOPOINTS Sentences ENDCASE SEMICOLON cases
	| CASE const TWOPOINTS Sentences SEMICOLON cases
	| DEFAULTCASE TWOPOINTS Sentences ENDCASE SEMICOLON cases
	| DEFAULTCASE TWOPOINTS Sentences SEMICOLON cases
	| ;

const : INTVALUE
	| CHARVALUE ;

function : IDENT PARENTSTART expression_list PARENTEND
	| IDENT PARENTSTART PARENTEND ;

expression_list : expression_list COLON expression
	| expression ;

types:	DATATYPE
	| LISTNAME DATATYPE ;

list_of_ident:	list_of_ident COLON IDENT {TS_InsertIDENT($3);}
	| IDENT {TS_InsertIDENT($1);};

constants:	INTVALUE
	| DOUBLEVALUE
	| LOGICVALUE
	| CHARVALUE
	| STRINGVALUE
	| c_lists ;

c_lists:	c_int_list
	| c_double_list
	| c_boolean_list
	| c_character_list ;

c_int_list : SQBRASTART int_list SQBRAEND ;

c_double_list :	SQBRASTART double_list SQBRAEND ;

c_boolean_list : SQBRASTART boolean_list SQBRAEND ;

c_character_list : SQBRASTART character_list SQBRAEND ;

int_list : int_list COLON INTVALUE
	| INTVALUE ;

double_list:	double_list COLON DOUBLEVALUE
	| DOUBLEVALUE ;

boolean_list:	boolean_list COLON LOGICVALUE
	| LOGICVALUE ;

character_list:	character_list COLON CHARVALUE
	| CHARVALUE ;

%%

#include "lex.yy.c"

void yyerror (const char *msg) {
	fprintf(stderr, "Linea %d: %s \n", line, msg);
}

//export line ;