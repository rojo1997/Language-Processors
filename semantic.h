#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TS 500
#define YYSTYPE atributos
#define line 0

typedef enum {
    mark,             /* marca comienzo bloque */
    function,         /* si es subprograma */
    variable,         /* si es variable */
    formal_parameter, /* si es parametro formal */
} inType;

typedef enum {
    integer,
    real,
    character,
    boolean,
    list,
    unknow,
    not_assigned
} dtype ;

typedef struct {
    inType       entrada ;
    char         *nombre ;
    dtype        tipoDato ;
    unsigned int parametros ;
    unsigned int dimensiones ;
    int          TamDimen1;
    int          TamDimen2;
} inTS ;

typedef struct {
    int   atrib ;      /* Atributo del símbolo (si tiene) */
    char  *lexema ;    /* Nombre del lexema */
    dtype tipo ;       /* Tipo del símbolo */
    unsigned int dims ; /* DIMENSIÓN DE ESTA PUTA MIERDA */
    int tDim1 ;        /* MÁS TAMAÑOS DE MIERDA */
    int tDim2 ;        /* MÁS BASURA */
} attributes ;

unsigned int TOPE = 0 ; /* Tope de la pila */
unsigned int Subprog ;  /* Indicador de comienzo de bloque de un subprog */
inTS TS[MAX_TS] ;       /* Pila de la tabla de símbolos */

extern int currentFunction ;
extern int decVar ;

// Funciones
// Devuelve si el atributo es array o no
int isArray (attributes e) ;
// Devuelve si los dos posibles arrays que recibe tienen el mismo tamaño
int equalSize (attributes e1, attributes e2) ;
// Guarda el tipo de la variable
int setType (attributes value) ;

/**************************** TABLA DE SÍMBOLOS ***********************/
// Añade una marca de tope
void TS_InsertMark () ;

// Limpia las entradas de la TS hasta el primer inicio de bloque que encuentre
void TS_CleanIn () ;

void TS_InsertSUBPROG (attributes e) ;

void TS_InsertPARAMF (attributes e) ;

void TS_InsertIDENT (attributes e) ;

// Inserta una entrada en la tabla de símbolos
int tsAddIn (inTS in) ;

// Busca una entrada según el identificador
int tsSearchId (attributes e) ;

// Busca una entrada según el nombre
int tsSearchName (attributes e) ;

// Añade un identificador
void tsAddId (attributes e) ;