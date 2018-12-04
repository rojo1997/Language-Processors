/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AT = 258,
    OR = 259,
    AND = 260,
    EQUALITYOPER = 261,
    RELATIONOPER = 262,
    ADDSUB = 263,
    MULTOPER = 264,
    UNARYOPER = 265,
    DECREMENT = 266,
    INCREMENT = 267,
    ATT = 268,
    LISTLEFTRIGHT = 269,
    DOLLAR = 270,
    IDENT = 271,
    DATATYPE = 272,
    LISTNAME = 273,
    LOGICVALUE = 274,
    INTVALUE = 275,
    DOUBLEVALUE = 276,
    CHARVALUE = 277,
    STRINGVALUE = 278,
    CONDITIONIF = 279,
    CONDITIONELSE = 280,
    LOOP = 281,
    OPTION = 282,
    CASE = 283,
    PARENTSTART = 284,
    PARENTEND = 285,
    SQBRASTART = 286,
    SQBRAEND = 287,
    INPUT = 288,
    OUTPUT = 289,
    ENDCASE = 290,
    DEFAULTCASE = 291,
    SEMICOLON = 292,
    COLON = 293,
    ASSIGNATION = 294,
    DECLARE = 295,
    MAINP = 296,
    TWOPOINTS = 297,
    RETURN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
