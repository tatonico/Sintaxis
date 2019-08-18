void testScanner();

typedef enum Token{ID, BUG, CTE, END} Token;
Token reconocerToken(FILE*);
