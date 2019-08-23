#include <stdio.h>
#include <stdlib.h>
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
            return END;
    }
}

// Funciones caracteres
int esLetra(char c){
   return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int esNumero(char c){
   return (c >= '0' && c <= '9');
}

int esEspacio(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int leerCaracter(char c) {
    int col;
    if (esLetra(c))
        col = COLLETRA;
    else if (esNumero(c))
        col = COLNUMERO;
    else if (esEspacio(c))
        col = COLESPACIO;
    else if (c == EOF)
        col = COLFIN;
    else
        col = COLERROR;
    return col;
}


// Funcion principal
Token reconocerToken(FILE* input){
   Token tok;
   int estado = INICIAL;
   char caracter;
   int colCaracter;
   while (!deboParar(estado)) {
       caracter = getc(input);
       colCaracter = leerCaracter(caracter);
       estado = T[estado][colCaracter];
   }
   if (estadoAceptor(estado)){
       if (estadoConCentinela(estado))
            ungetc(caracter, input);
       tok = tokenSegunEstado(estado);
   } else {
       tok = BUG;
   }
   return tok;
}
