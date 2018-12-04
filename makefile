OBJ: obj
SRC: src
INCLUDE: include
BIN: bin
.SUFFIXES:

all: clean y.tab.c lex.yy.c prueba

prueba: $(OBJ)/main.o $(OBJ)/y.tab.o $(OBJ)/semantic.o
	gcc -o $(BIN)/prueba $(OBJ)/main.o $(OBJ)/y.tab.o

y.tab.o: $(SRC)/y.tab.c
	gcc -c $(SRC)/y.tab.c

main.o: $(SRC)/main.c
	gcc -c $(SRC)/main.c

y.tab.c: $(SRC)/sintactico.y $(SRC)/lex.yy.c
	bison -v -d -o $(SRC)/y.tab.c $(SRC)/sintactico.y

#lex.yy.h: lex.yy.c
#	gcc lex.yy.c -ly -lfl

lex.yy.c: $(SRC)/lex.c
	flex $(SRC)/lex.c

semantic.o: $(SRC)/semantic.c $(INCLUDE)/semantic.h
	gcc -c $(SRC)/semantic.c -I/semantic.h

clean:
	-rm -f $(BIN)/prueba $(OBJ)/main.o $(OBJ)/y.tab.o $(SRC)/y.tab.c $(SRC)/lex.yy.c $(OBJ)/semantic.o
