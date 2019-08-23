#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
typedef enum Token{ID, BUG, CTE, END} Token;
typedef enum Columna{COLLETRA=0, COLNUMERO, COLESPACIO, COLERROR, COLFIN} Columna;
typedef enum Estado{ESTADOSINCENTINELA = 12} Estado;
const int INICIAL = 0;
int T[4][5] = {
                        {1, 2, 0, 3, 12},
                        {1, 1, 10, 10, 10},
                        {11, 2, 11, 11, 11},
                        {20, 20, 20, 3, 20}
                    };


void testScanner() {
    printf("Hello scanner!\n");
}
=======
#include <ctype.h>
#include "scanner.h"
>>>>>>> 8fd9259b46c42d0fcb5d87d50c64f897b5685efc

const int INICIAL = 0;
int T[4][5] =   {
                    {1, 2, 0, 3, 12},
                    {1, 1, 10, 10, 10},
                    {11, 2, 11, 11, 11},
                    {20, 20, 20, 3, 20}
                };

// Funciones estados
int deboParar(int pEstado) {
    return pEstado >= 10;
}

int estadoRechazador(int pEstado) {
    return pEstado >= 20;
}

int estadoAceptor(int pEstado) {
    return deboParar(pEstado) && !estadoRechazador(pEstado);
}

int estadoConCentinela(int pEstado) {
    return pEstado != 12;
}

Token tokenSegunEstado(int pEstado) {
    switch (pEstado) {
        case 10:
            return ID;
        case 11:
            return CTE;
        case 12:
            return FDT;
        case 20:
            return BUG;
    }
}

// Funciones caracteres

int leerCaracter(char c) {
    int col;
<<<<<<< HEAD
    if (esLetra(c))
        col = COLLETRA;
    else if (esNumero(c))
        col = COLNUMERO;
    else if (esEspacio(c))
        col = COLESPACIO;
=======
    if (isalpha(c))
        col = 0;
    else if (isdigit(c))
        col = 1;
    else if (isspace(c))
        col = 2;
>>>>>>> 8fd9259b46c42d0fcb5d87d50c64f897b5685efc
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
