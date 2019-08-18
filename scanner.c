#include <stdio.h>
#include <stdlib.h>
typedef enum Token{ID, BUG, CTE, END} Token;
const int INICIAL = 0;
int T[4][5] = {
                        {1, 2, 0, 3},
                        {1, 1, 10, 10},
                        {11, 2, 11, 11},
                        {20, 20, 20, 3}
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

Token tokenSegunEstado(int pEstado) {
    switch (pEstado) {
        case 10:
            return ID;
        case 11:
            return CTE;
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
        col = 0;
    else if (esNumero(c))
        col = 1;
    else if (esEspacio(c))
        col = 2;
    else
        col = 3;
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
       if (caracter == EOF)     // VER SI SE PUEDE MEJORAR ESTO
            return END;
       colCaracter = leerCaracter(caracter);
       estado = T[estado][colCaracter];
   }
   ungetc(caracter, input); // Todos los estados paran con un valor centinela
   if (estadoAceptor(estado)){
       tok = tokenSegunEstado(estado);
   } else {
       tok = BUG;
   }
   return tok;
}
