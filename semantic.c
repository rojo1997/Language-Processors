#include "semantic.h"

/* Lista de funciones y procedimientos para manejo de la TS */
// Devuelve si el atributo es array o no
int isArray (attributes e) {
    //return (e.nDim != 0) ;
}    
/* Fin de funciones y procedimientos para manejo de la TS */

void TS_InsertMark(){

    inTS input;

    input.entrada = mark ;
    input.nombre = "{" ;
    input.tipoDato = not_assigned ;
    input.parametros = 0 ;
    input.dimensiones = 0 ;
    input.TamDimen1 = 0 ;
    input.TamDimen2 = 0 ;

    tsAddIn(input);

    if(Subprog == 1){

		int j = TOPE - 2, mark = 0, function = 0 ;

		while(j > 0 && TS[j].entrada == formal_parameter){

			if(TS[j].entrada == formal_parameter) {
				inTS newIn ;
				newIn.entrada = TS[j].entrada ;
				newIn.nombre = TS[j].nombre ;
				newIn.tipoDato = TS[j].tipoDato ;
				newIn.parametros = TS[j].parametros ;
				newIn.dimensiones = TS[j].dimensiones ;
				newIn.TamDimen1 = TS[j].TamDimen1 ;
				newIn.TamDimen2 = TS[j].TamDimen2 ;
				tsAddIn(newIn) ;
			}
			j-- ;
		}
	}
}

void TS_CleanIn () {
    while(TS[TOPE-1].entrada != mark && TOPE > 0) TOPE-- ;
	if (TS[TOPE-1].entrada == mark) TOPE-- ;
    if (TS[TOPE-1].entrada == formal_parameter) {
        while(TS[TOPE-1].entrada != function && TOPE > 0) TOPE-- ;
        TOPE--;
    }
}

void TS_InsertSUBPROG (attributes e) {
inTSinTS newIn;
    newIn.entrada = function;
    newIn.nombre = e.lexema ;
    newIn.tipoDato = not_assigned ;
    newIn.parametros = 0 ;
    newIn.dimensiones = e.dims ;
    newIn.TamDimen1 = e.tDim1 ;
    newIn.TamDimen2 = e.tDim2 ;
    tsAddIn(newIn) ;
}

void TS_InsertPARAMF (attributes e) {
    int j = TOPE - 1, found = 0 ;
	while((j != currentFunction)  && (!found)) {
		if(strcmp(TS[j].entrada, e.lexema) != 0) j-- ;
		else {
			found = 1;
			printf("Semantic Error(%d): Exist param: %s\n", line, e.lexema) ;
        }
	}
	if(!found) {
		inTS newIn;
		newIn.entrada = formal_parameter;
		newIn.nombre = e.lexema ;
		newIn.tipoDato = not_assigned ;
		newIn.parametros = 0 ;
		newIn.dimensiones = e.dims ;
		newIn.TamDimen1 = e.tDim1 ;
		newIn.TamDimen2 = e.tDim2 ;
		tsAddIn(newIn) ;
    }
}

void TS_InsertIDENT (attributes e) {
	int j = TOPE-1, found = 0 ;
	if (j >= 0 && decVar == 1){
		// Se obtiene la posición de la mark del bloque
		while ((TS[j].entrada != mark) && (j >= 0) && !found){
			if (strcmp(TS[j].nombre, e.lexema) != 0) j-- ;
			else {
				found = 1 ;
				printf("Semantic Error(%d): Exist ident: %s\n", line, e.lexema) ;
	 		}
		}
		// Si no se ha encontrado significa que no existe, por lo que se añade
        // a la pila
		if(!found) {
			inTS newIn ;
			newIn.entrada = variable ;
			newIn.nombre = e.lexema ;
			newIn.tipoDato = not_assigned ;
			newIn.parametros = 0 ;
			newIn.dimensiones = e.dims ;
			newIn.TamDimen1 = e.tDim1 ;
			newIn.TamDimen2 = e.tDim2 ;
			tsAddIn(newIn) ;
		}
    }
}

int tsAddIn (inTS in) {
    if (TOPE < MAX_TS) {
        TS[TOPE].entrada = in.entrada ;
		TS[TOPE].nombre = in.nombre ;
		TS[TOPE].tipoDato = in.tipoDato ;
		TS[TOPE].parametros = in.parametros ;
		TS[TOPE].dimensiones = in.dimensiones ;
		TS[TOPE].TamDimen1 = in.TamDimen1 ;
		TS[TOPE].TamDimen2 = in.TamDimen2 ;
        TOPE++ ;
        return (1) ;
    } else {
        printf("Semantic Error(%d): Stack overflow", line) ;
        return (0) ;
    }
}