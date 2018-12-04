.SUFFIXES:

all: clean y.tab.c lex.yy.c prueba

prueba: main.o y.tab.o
	gcc -o prueba main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: sintactico.y lex.yy.c
	bison -v -d -o y.tab.c sintactico.y

#lex.yy.h: lex.yy.c
#	gcc lex.yy.c -ly -lfl

lex.yy.c: lex.c
	flex lex.c

clean:
	-rm -f prueba main.o y.tab.o y.tab.c lex.yy.c
