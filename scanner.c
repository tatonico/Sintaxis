#include <stdio.h>
#include <stdlib.h>
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
    if (isalpha(c))
        col = 0;
    else if (isdigit(c))
        col = 1;
    else if (isspace(c))
        col = 2;
    else if (c == EOF)
        col = 4;
    else
        col = 3;
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
