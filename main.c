/*
    TP0 - 2019
    "Un escaner elemental"

    Grupo 11
    Integrantes:
     .Israeski  Martin  - 1682611
     .Mandarino Gonzalo - 1678929
     .Pawlow    Manuel  - 1681280
     .Rickert   Nicolás - 1673944

*/

#include "scanner.h"

#define ARCHIVO "prueba.txt"

int cntIds = 0;
int cntErrs = 0;
int cntCtes = 0;

void escribirToken(Token tok) {
    switch(tok) {
        case ID:
            printf("Identificador\n");
            cntIds++;
            break;
        case ERR:
            printf("Error\n");
            cntErrs++;
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
    Token tok;

    // Reemplazo el stdin por ARCHIVO, definido arriba
    freopen(ARCHIVO, "r", stdin);

    do {
        tok = scanner(stdin);
        escribirToken(tok);
    } while (tok != FDT);

    printf("-----------\n\n");
    printf("Totales:\n");
    printf("Identificadores: %i\n", cntIds);
    printf("Constantes: %i\n", cntCtes);
    printf("Errores: %i\n", cntErrs);
    return 0;
}
