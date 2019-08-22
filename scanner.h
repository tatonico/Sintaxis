void testScanner();

typedef enum Token{ID, BUG, CTE, FDT} Token;
Token scanner(FILE*);
