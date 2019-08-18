#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int cntIds = 0;
int cntBugs = 0;
int cntCtes = 0;

void escribirToken(Token tok) {
    switch(tok) {
        case ID:
            printf("Identificador\n");
            cntIds++;
            break;
        case BUG:
            printf("Error\n");
            cntBugs++;
            break;
        case CTE:
            printf("Constante entera\n");
            cntCtes++;
            break;
        case END:
            printf("Fin del archivo\n");
    }
}

int main(int argc, char **argv) {
    char caracter;
    Token tok;
    FILE *input = stdin;
    if (argc > 2){
        input = fopen(argv[2], "r");  // Abrir el parametro
    }
    while (!feof(input)) {
        tok = reconocerToken(input);
        escribirToken(tok);
    }
    printf("-----------\n\n");
    printf("Totales:\n");
    printf("Identificadores: %i\n", cntIds);
    printf("Constantes: %i\n", cntCtes);
    printf("Errores: %i\n", cntBugs);
    return 0;
}
