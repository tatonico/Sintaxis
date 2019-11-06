/*
    TP5 - 2019
    "Compilador completo del lenguaje micro"

    Grupo 11
    Integrantes:
     .Israeski  Martin  - 1682611
     .Mandarino Gonzalo - 1678929
     .Pawlow    Manuel  - 1681280
     .Rickert   Nicolás - 1673944

*/

#include <stdio.h>
#include "parser.h"

int main(void) {
    switch (yyparse()) {
        case 1:
            printf("Errores de compilación\n");
            break;
        case 2:
            printf("Error de memoria");
            break;
        case 0:
            printf("Compilación realizada con éxito\n");
            break;
    }
    printf("Errores sintácticos: %d  -  Errores léxicos: %d - Errores semánticos: %d\n", yynerrs, yylexerrs, yysemerrs);
    return 0;
}