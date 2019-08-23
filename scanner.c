#include <stdio.h>
#include <stdlib.h>

typedef enum Token{ID,
                   BUG,
                   CTE,
                   END} Token;

typedef enum Columna{COLLETRA=0,
                    COLNUMERO,
                    COLESPACIO,
                    COLERROR,
                    COLFIN} Columna;

typedef enum Estado{ESTADOFINTEXTO = 12,
                    ESTADOFINALID = 10,
                    ESTADOFINALCTE = 11,
                    ESTADOERROR = 20,
                    ESTADOINICIAL = 0,
                    ESTADOMEDIOID = 1,
                    ESTADOMEDIOCTE = 2,
                    ESTADOMEDIOERROR = 3} Estado;

const int INICIAL = 0;

int T[4][5] = {        //ColLetras(0)-----ColNros(1)------ColEspacios(2)--ColErrores(3)-----ColFDT(4)
                    /*0*/{ESTADOMEDIOID,  ESTADOMEDIOCTE, ESTADOINICIAL,  ESTADOMEDIOERROR, ESTADOFINTEXTO},
                    /*1*/{ESTADOMEDIOID,  ESTADOMEDIOID,  ESTADOFINALID,  ESTADOFINALID,    ESTADOFINALID},
                    /*2*/{ESTADOFINALCTE, ESTADOMEDIOCTE, ESTADOFINALCTE, ESTADOFINALCTE,   ESTADOFINALCTE},
                    /*3*/{ESTADOERROR,    ESTADOERROR,    ESTADOERROR,    ESTADOMEDIOERROR, ESTADOERROR}
              };


void testScanner() {
    printf("Hello scanner!\n");
}

#include <ctype.h>
#include "scanner.h"


const int INICIAL = 0;
int T[4][5] =   {
                    {1, 2, 0, 3, 12},
                    {1, 1, 10, 10, 10},
                    {11, 2, 11, 11, 11},
                    {20, 20, 20, 3, 20}
                };

// Funciones estados
int deboParar(int pEstado) {
    return pEstado >= ESTADOFINALID;
}

int estadoRechazador(int pEstado) {
    return pEstado >= ESTADOERROR;
}

int estadoAceptor(int pEstado) {
    return deboParar(pEstado) && !estadoRechazador(pEstado);
}

int estadoConCentinela(int pEstado) {
    return pEstado != 12;
}

Token tokenSegunEstado(int pEstado) {
    switch (pEstado) {
        case ESTADOFINALID:
            return ID;
        case ESTADOFINALCTE:
            return CTE;
        case ESTADOFINTEXTO:
            return FDT;
        case ESTADOERROR:
            return BUG;
    }
}

// Funciones caracteres

int leerCaracter(char c) {
    int col;

    if (esLetra(c))
        col = COLLETRA;
    else if (esNumero(c))
        col = COLNUMERO;
    else if (esEspacio(c))
        col = COLESPACIO;

    if (isalpha(c))
        col = COLLETRA;
    else if (isdigit(c))
        col = COLNUMERO;
    else if (isspace(c))
        col = COLESPACIO;
    else if (c == EOF)
        col = COLFIN;
    else
        col = COLERROR;
    return col;
}

// Funcion principal
Token scanner(FILE* input){
   Token tok;
   int estado = INICIAL;
   char caracter;
   int colCaracter;
   while (!deboParar(estado)) {
       caracter = getc(input);
       colCaracter = leerCaracter(caracter);
       estado = T[estado][colCaracter];
   }
   if (estadoConCentinela(estado))
        ungetc(caracter, input);
   tok = tokenSegunEstado(estado);
   return tok;
}
