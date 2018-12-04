#include "semantic.h"

/* Lista de funciones y procedimientos para manejo de la TS */
// Devuelve si el atributo es array o no
int isArray (attributes e) {
    //return (e.nDim != 0) ;
}    
/* Fin de funciones y procedimientos para manejo de la TS */

void TS_InsertMark(){

    inTS input;

    input.entrada = mark;
    input.nombre = "{";
    input.tipoDato = not_assigned;
    input.parametros = 0;
    input.dimensiones = 0;
    input.TamDimen1 = 0;
    input.TamDimen2 = 0;

    tsAddIn(input);
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

}

void TS_InsertPARAMF (attributes e) {

}

void TS_InsertIDENT (attributes e) {
    // Para añadir un id a la pila no se puede haber llegado al tope,
    // el id no puede existir y se deben estar declarando variables
	int j = LIMIT-1;
	int found = 0;

	if(j >= 0 && decVar == 1){
		// Se obtiene la posición de la mark del bloque
		while((ts[j].in != MARK) && (j >= 0) && !found){

			if(strcmp(ts[j].lex, e.lex) != 0){

				j--;

			} else{

				found = 1;
				printf("Semantic Error(%d): Exist ident: %s\n", line, e.lex);

	 		}
		}
		// Si no se ha encontrado significa que no existe, por lo que se añade
        // a la pila
		if(!found) {
			inTS newIn;
			newIn.in = VAR;
			newIn.lex = e.lex;
			newIn.type = globalType;
			newIn.nParam = 0;
			newIn.nDim=e.nDim;
			newIn.tDim1=e.tDim1;
			newIn.tDim2=e.tDim2;
			tsAddIn(newIn);
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
    }
    else {
        printf("Semantic Error(%d): Stack overflow", line) ;
        return (0) ;
    }
}