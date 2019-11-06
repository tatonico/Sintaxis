/*
    TP4 - 2019
    "Parser del lenguaje mini con Bison"

    Grupo 11
    Integrantes:
     .Israeski  Martin  - 1682611
     .Mandarino Gonzalo - 1678929
     .Pawlow    Manuel  - 1681280
     .Rickert   Nicolás - 1673944

*/

#include <stdio.h>
#include "scanner.h"
#include "parser.h"

int main(void) {

    if(yyparse()) {
        printf("Errores de compilación\n");
    } else {
        printf("Compilación realizada con éxito\n");
    }
    printf("Errores sintácticos: %d  -  Errores léxicos: %d\n", yynerrs, yylexerrs);
}