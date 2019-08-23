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
        case FDT:
            printf("\nFin del archivo\n");
    }
}

int main() {
    char strvar[100];
    fgets (strvar, 100, stdin);
    while(strvar[0] != '0'){

    freopen(strvar, "r", stdin);

    char caracter;
    Token tok;
    do {
        tok = scanner(stdin);
        escribirToken(tok);
    } while (tok != FDT);

    printf("-----------\n\n");
    printf("Totales:\n");
    printf("Identificadores: %i\n", cntIds);
    printf("Constantes: %i\n", cntCtes);
    printf("Errores: %i\n", cntBugs);

    cntBugs = cntCtes = cntIds = 0;
    fgets (strvar, 100, stdin);
    }
    return 0;
}
