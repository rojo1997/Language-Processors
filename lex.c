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
"true" {  yylval.atrib = 0;
          return LOGICVALUE;
       }
"false" {  yylval.atrib = 1;
          return LOGICVALUE;
        }
"int" {  yylval.atrib = 1;
         yyval.type = INT;
          return DATATYPE;
      }
"double" {  yylval.atrib = 2;
            yyval.type = DOUBLE;
          return DATATYPE;
      }
"char" {  yylval.atrib = 3;
          yyval.type = CHARACTER;
          return DATATYPE;
      }
"bool" {  yylval.atrib = 4;
          yyval.type = BOOLEAN;
          return DATATYPE;
      }
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
"+" { yylval.atrib = 0;
      return ADDSUB;
    }
"-" { yylval.atrib = 1;
      return ADDSUB;
    }
"*" { yylval.atrib = 0;
      return MULTOPER;
    }
"/" { yylval.atrib = 1;
      return MULTOPER;
    }
"==" {  yylval.atrib = 0;
        return EQUALITYOPER;
      }
"!=" {  yylval.atrib = 1;
        return EQUALITYOPER;
      }
"<" {
      yylval.atrib = 0;
      return RELATIONOPER;
    }
">" {
      yylval.atrib = 1;
      return RELATIONOPER;
    }
">=" {
      yylval.atrib = 2;
      return RELATIONOPER;
    }
"<=" {
      yylval.atrib = 3;
      return RELATIONOPER;
    }
"%" { yylval.atrib = 2;
      return MULTOPER;
    }
"**" { yylval.atrib = 3;
      return MULTOPER;
    }
"&&" return AND;
"\|\|" return OR;
"@" return AT;
"!" { yylval.atrib = 0;
      return UNARYOPER;
    }
"#" { yylval.atrib = 1;
      return UNARYOPER;
    }
"|" { yylval.atrib = 2;
      return UNARYOPER;
    }
"?" { yylval.atrib = 3;
      return UNARYOPER;
    }
"<<" { yylval.atrib = 0;
       return LISTLEFTRIGHT;
      }
">>" { yylval.atrib = 1;
       return LISTLEFTRIGHT;
      }
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
{letter}{alphanum}* { yylval.lexema = strdup(yytext);
                      return IDENT;
                    }
                      

{digit}+  { yylval.atrib = 
            return INTVALUE;
          }
{caracter}  return CHARVALUE;
{ascii} return STRINGVALUE;
{nothing}* ;
{digit}*{real}{digit}* return DOUBLEVALUE;
{salto} line = line+1;
. {printf("\nError lexico en linea %d lexema: %s \n", line, yytext);}
%%

