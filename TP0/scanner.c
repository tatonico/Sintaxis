#include "scanner.h"

typedef enum Columna{COLLETRA,
                    COLNUMERO,
                    COLESPACIO,
                    COLERROR,
                    COLFIN} Columna;

typedef enum Estado{EFINTEXTO = 12,
                    EFINALID = 10,
                    EFINALCTE = 11,
                    EFINERROR = 20,
                    EINICIAL = 0,
                    EMEDIOID = 1,
                    EMEDIOCTE = 2,
                    EMEDIOERROR = 3} Estado;

const int INICIAL = 0;

int T[4][5] = {     // ColLetras(0)-ColNros(1)-ColEspacios(2)-ColErrores(3)-ColFDT(4)
                    /*0*/{EMEDIOID , EMEDIOCTE, EINICIAL , EMEDIOERROR, EFINTEXTO},
                    /*1*/{EMEDIOID , EMEDIOID , EFINALID , EFINALID   , EFINALID },
                    /*2*/{EFINALCTE, EMEDIOCTE, EFINALCTE, EFINALCTE  , EFINALCTE},
                    /*3*/{EFINERROR, EFINERROR, EFINERROR, EMEDIOERROR, EFINERROR}
              };


// Funciones estados
int deboParar(int pEstado) {
    return pEstado >= 10;
}

int estadoConCentinela(int pEstado) {
    return pEstado != EFINTEXTO;
}

Token tokenSegunEstado(int pEstado) {
    switch (pEstado) {
        case EFINALID:
            return ID;
        case EFINALCTE:
            return CTE;
        case EFINTEXTO:
            return FDT;
        default:
            return ERR;
    }
}

// Funciones caracteres

int leerCaracter(char c) {
    int col;
    if (isalpha(c))
        col = COLLETRA;
    else if (isdigit(c))
        col = COLNUMERO;
    else if (isspace(c))
        col = COLESPACIO;
    else if (c == EOF)
        col = COLFIN;
    else
        col = COLERROR;
    return col;
}

// Funcion principal
Token scanner(){
   Token tok;
   int estado = INICIAL;
   int colCaracter;
   char caracter;

   while (!deboParar(estado)) {
       caracter = getchar();
       colCaracter = leerCaracter(caracter);
       estado = T[estado][colCaracter];
   }

   if (estadoConCentinela(estado))
        ungetc(caracter, stdin);

   tok = tokenSegunEstado(estado);

   return tok;
}
