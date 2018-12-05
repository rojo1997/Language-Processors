OBJ=obj
SRC=src
INCLUDE=include
BIN=bin
.SUFFIXES:

all: clean lex.yy.c y.tab.c y.tab.o main.o prueba

prueba: main.o y.tab.o semantic.o
	gcc -o $(BIN)/prueba $(OBJ)/main.o $(OBJ)/y.tab.o $(OBJ)/semantic.o

y.tab.o: $(SRC)/y.tab.c $(INCLUDE)/semantic.h
	gcc -c -o $(OBJ)/y.tab.o $(SRC)/y.tab.c -I$(INCLUDE)

main.o: $(SRC)/main.c $(SRC)/y.tab.h
	gcc -c -o $(OBJ)/main.o $(SRC)/main.c -I$(SRC)

y.tab.c: $(SRC)/sintactico.y $(SRC)/lex.yy.c
	bison -v -d -o $(SRC)/y.tab.c $(SRC)/sintactico.y

lex.yy.c: $(SRC)/lex.c
	flex -o $(SRC)/lex.yy.c $(SRC)/lex.c

semantic.o: $(SRC)/semantic.c $(INCLUDE)/semantic.h
	gcc -c -o $(OBJ)/semantic.o $(SRC)/semantic.c -I$(INCLUDE)

clean:
	-rm -f $(BIN)/*
	-rm -f $(OBJ)/*.o
	-rm -f $(SRC)/y.tab.c
	-rm -f $(SRC)/y.output
	-rm -f $(SRC)/y.tab.h
	-rm -f $(SRC)/lex.yy.c