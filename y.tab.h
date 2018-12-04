/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define AT 258
#define OR 259
#define AND 260
#define EQUALITYOPER 261
#define RELATIONOPER 262
#define ADDSUB 263
#define MULTOPER 264
#define UNARYOPER 265
#define DECREMENT 266
#define INCREMENT 267
#define ATT 268
#define LISTLEFTRIGHT 269
#define DOLLAR 270
#define IDENT 271
#define DATATYPE 272
#define LISTNAME 273
#define LOGICVALUE 274
#define INTVALUE 275
#define DOUBLEVALUE 276
#define CHARVALUE 277
#define STRINGVALUE 278
#define CONDITIONIF 279
#define CONDITIONELSE 280
#define LOOP 281
#define OPTION 282
#define CASE 283
#define PARENTSTART 284
#define PARENTEND 285
#define SQBRASTART 286
#define SQBRAEND 287
#define INPUT 288
#define OUTPUT 289
#define ENDCASE 290
#define DEFAULTCASE 291
#define SEMICOLON 292
#define COLON 293
#define ASSIGNATION 294
#define DECLARE 295
#define MAINP 296
#define TWOPOINTS 297
#define RETURN 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

