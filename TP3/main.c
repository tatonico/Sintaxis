/*
    TP3 - 2019
    "Escaner del lenguaje mini con flex"

    Grupo 11
    Integrantes:
     .Israeski  Martin  - 1682611
     .Mandarino Gonzalo - 1678929
     .Pawlow    Manuel  - 1681280
     .Rickert   Nicolás - 1673944

*/

#include <stdio.h>
#include "tokens.h"
#include "scanner.h"

extern char* yytext;

void escribirToken(TOKEN);

int main(void) {
    TOKEN token;

	do {
		token = yylex();
        escribirToken(token);
	} while (token != FDT);
}

void escribirToken(TOKEN token) {
    switch(token) {
        case FDT:
            printf("Token: Fin de archivo\n");
            break;
        case IDENTIFICADOR:
            printf("Token: Identificador\t\tLexema: %s\n", yytext);
            break;
        case CONSTANTE:
            printf("Token: Constante    \t\tLexema: %s\n", yytext);
            break;
        case ASIGNACION:
            printf("Token: Asignación\n");
            break;
        case PROGRAMA:
            printf("Token: Programa\n");
            break;
        case DEFINIR:
            printf("Token: Definir\n");
            break;
        case CODIGO:
            printf("Token: Código\n");
            break;
        case LEER:
            printf("Token: Leer\n");
            break;
        case ESCRIBIR:
            printf("Token: Escribir\n");
            break;
        case FIN:
            printf("Token: Fin\n");
            break;
        default:
            printf("Token: '%c'\n", token);
    }
}