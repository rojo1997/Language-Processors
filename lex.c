%{
  #include <stdio.h>
  #include "y.tab.h"
  #include <stdlib.h>
  #include <string.h>

  int line = 1;
%}

%option yylineno
%option noyywrap

nothing [ \t]+
letter	[a-zA-Z]
digit	[0-9]
ascii	\"[^\"]+\"
caracter \'[^\']\'
alphanum	[a-zA-Z_0-9]
blanco	[ \t]
real [0-9.0-9]
salto [\n]

%%
"return" return RETURN;
"true" return LOGICVALUE;
"false" return LOGICVALUE;
"int" return DATATYPE;
"double" return DATATYPE;
"char" return DATATYPE;
"bool" return DATATYPE;
"if"  return CONDITIONIF;
"else"  return CONDITIONELSE;
"while" return LOOP;
"switch"  return OPTION;
"case"  return CASE;
"break" return ENDCASE;
"default" return DEFAULTCASE;
"list" return LISTNAME;
"--"  return DECREMENT;
"++"  return INCREMENT;
"\(" return PARENTSTART;
"\{" return SQBRASTART;
"\)" return PARENTEND;
"\}" return SQBRAEND;
"+" return ADDSUB;
"-" return ADDSUB;
"*" return MULTOPER;
"/" return MULTOPER;
"==" return EQUALITYOPER;
"!=" return EQUALITYOPER;
"<" return RELATIONOPER;
">" return RELATIONOPER;
">=" return RELATIONOPER;
"<=" return RELATIONOPER;
"%" return MULTOPER;
"**" return MULTOPER;
"&&" return AND;
"\|\|" return OR;
"@" return AT;
"!" return UNARYOPER;
"#" return UNARYOPER;
"|" return UNARYOPER;
"?" return UNARYOPER;
"<<" return LISTLEFTRIGHT;
">>" return LISTLEFTRIGHT;
"=" return ASSIGNATION;
"scanf" return INPUT;
"printf"  return OUTPUT;
"main" return MAINP;
";" return SEMICOLON;
"," return COLON;
"declare" return DECLARE;
":" return TWOPOINTS;
"$" return DOLLAR;
"@@" return ATT;
{letter}{alphanum}* return IDENT;
{digit}+  return INTVALUE;
{caracter}  return CHARVALUE;
{ascii} return STRINGVALUE;
{nothing}* ;
{digit}*{real}{digit}* return DOUBLEVALUE;
{salto} line = line+1;
. {printf("\nError lexico en linea %d lexema: %s \n", line, yytext);}
%%

