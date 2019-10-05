#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum Token{ID,
                   ERR,
                   CTE,
                   FDT} Token;
// Estados
int deboParar(int);
int estadoConCentinela(int);
Token tokenSegunEstado(int);

// Caracteres
int leerCaracter(char);

//Principal
Token scanner();

#endif
