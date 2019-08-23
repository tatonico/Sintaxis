void testScanner();

typedef enum Token{ID, BUG, CTE, END} Token;
typedef enum Columna{COLLETRA=0, COLNUMERO, COLESPACIO, COLERROR, COLFIN} Columna;
Token reconocerToken(FILE*);
