void testScanner();

<<<<<<< HEAD
typedef enum Token{ID, BUG, CTE, END} Token;
typedef enum Columna{COLLETRA=0, COLNUMERO, COLESPACIO, COLERROR, COLFIN} Columna;
Token reconocerToken(FILE*);
=======
typedef enum Token{ID, BUG, CTE, FDT} Token;
Token scanner(FILE*);
>>>>>>> 8fd9259b46c42d0fcb5d87d50c64f897b5685efc
