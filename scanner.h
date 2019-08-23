void testScanner();



typedef enum Token{ID,
                   BUG,
                   CTE,
                   END} Token;

typedef enum Columna{COLLETRA=0,
                    COLNUMERO,
                    COLESPACIO,
                    COLERROR,
                    COLFIN} Columna;

typedef enum Estado{ESTADOFINTEXTO = 12,
                    ESTADOFINALID = 10,
                    ESTADOFINALCTE = 11,
                    ESTADOERROR = 20,
                    ESTADOINICIAL = 0,
                    ESTADOMEDIOID = 1,
                    ESTADOMEDIOCTE = 2,
                    ESTADOMEDIOERROR = 3} Estado;

Token reconocerToken(FILE*);
Token scanner(FILE*);

