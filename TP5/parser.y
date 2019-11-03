%code top{
#include <stdio.h>
#include "scanner.h"
#include "sematic.h"
}
%code provides{

typedef enum yytokentype TOKEN;

struct REG_EXPRESION {  // Registro semántico
    TOKEN token;        // Token de Bison
    char nombre[32];
    int valor;
};

struct YYSTYPE {        // Tipo Bison
    char * lexema;
    struct REG_EXPRESION regExp;
};

void yyerror(const char*);
extern int yylexerrs;
extern int yysemerrs;
extern int yynerrs;
extern char yyerrorBuffer[255];
}
%defines "parser.h"
%output "parser.c"
%token IDENTIFICADOR CONSTANTE ASIGNACION PROGRAMA DEFINIR CODIGO LEER ESCRIBIR FIN
%define api.value.type { struct YYSTYPE }
%define parse.error verbose

%left '-' '+'
%left '/' '*'
%precedence NEG

%%

programa            : PROGRAMA { comenzar(); } listaDeclaraciones CODIGO listaSentencias FIN { terminar(); if (yynerrs || yylexerrs || yysemerrs) YYABORT;}
listaDeclaraciones  : listaDeclaraciones declaracion
                    | %empty
                    ;
declaracion         : DEFINIR IDENTIFICADOR ';' { strcpy(bufferLexemas, yylval.lexema); if(definir()) YYERROR; }
                    | error ';'
                    ;
listaSentencias     : listaSentencias sentencia
                    | sentencia
                    ;
sentencia           : ident ASIGNACION expresion ';'         { asignar($1.regExp, $3.regExp); }
                    | LEER '(' listaIdentificadores ')' ';'  
                    | ESCRIBIR '(' listaExpresiones ')' ';'  
                    | error ';'
                    ;
listaIdentificadores: listaIdentificadores ',' ident        { leer($3.regExp); }
                    | ident                                 { leer($1.regExp); }
                    ;
listaExpresiones    : listaExpresiones ',' expresion        { escribir($3.regExp); }
                    | expresion                             { escribir($1.regExp); }
                    ;
expresion           : expresion '+' expresion   { $$.regExp = genInfijo($1.regExp, '+', $3.regExp); }
                    | expresion '-' expresion   { $$.regExp = genInfijo($1.regExp, '-', $3.regExp); }
                    | expresion '*' expresion   { $$.regExp = genInfijo($1.regExp, '*', $3.regExp); }
                    | expresion '/' expresion   { $$.regExp = genInfijo($1.regExp, '/', $3.regExp); }
                    | '-' valor %prec NEG       { struct REG_EXPRESION r = { IDENTIFICADOR, "", 0 }; $$.regExp = genInfijo($2.regExp, NEG, r); }
                    | valor
                    ;
valor               : ident
                    | CONSTANTE                 { strcpy(bufferLexemas, yylval.lexema); $$.regExp = procesarCte(); }
                    | '(' expresion ')'         { $$.regExp = $2.regExp; }
                    ;
ident               : IDENTIFICADOR             { strcpy(bufferLexemas, yylval.lexema); $$.regExp = procesarId(); if($$.regExp.valor) YYERROR; }
%%

int yylexerrs = 0;
int yysemerrs = 0;
char yyerrorBuffer[255];

void yyerror(const char* s){

	printf("Línea #%d: %s\n", yylineno, s);
	return;
}