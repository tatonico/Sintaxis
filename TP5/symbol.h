#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

struct datoTS {
    char            identificador[32];
    int             token;      // TOKEN DEL PARSER
    struct datoTS*  izq;
    struct datoTS*  der;
};

struct datoTS* buscarTS (struct datoTS*, char *);
struct datoTS* insertarTS (struct datoTS*, char *, int);
struct datoTS* nuevoDatoTS (char*, int);
struct datoTS* inicializarTS(void);
void           inorden (struct datoTS*);
#endif