%code top{
#include <stdio.h>
#include "scanner.h"
}
%code provides{
void yyerror(const char *);
extern int yylexerrs;
extern int yynerrs;
}
%defines "parser.h"
%output "parser.c"
%token IDENTIFICADOR CONSTANTE ASIGNACION PROGRAMA DEFINIR CODIGO LEER ESCRIBIR FIN
%define api.value.type {char *}
%define parse.error verbose

%left '-' '+'
%left '/' '*'
%precedence NEG

%%

programa            : PROGRAMA listaDeclaraciones CODIGO listaSentencias FIN { if (yynerrs || yylexerrs) YYABORT;}
listaDeclaraciones  : listaDeclaraciones declaracion
                    | %empty
                    ;
declaracion         : DEFINIR IDENTIFICADOR ';' { printf("definir %s\n", yylval); }
                    | error ';'
                    ;
listaSentencias     : listaSentencias sentencia
                    | sentencia
                    ;
sentencia           : IDENTIFICADOR ASIGNACION expresion ';' { printf("asignacion\n"); }
                    | LEER '(' listaIdentificadores ')' ';'  { printf("leer\n"); }
                    | ESCRIBIR '(' listaExpresiones ')' ';'  { printf("escribir\n"); }
                    | error ';'
                    ;
listaIdentificadores: listaIdentificadores ',' IDENTIFICADOR
                    | IDENTIFICADOR
                    ;
listaExpresiones    : listaExpresiones ',' expresion
                    | expresion
                    ;
expresion           : expresion '+' expresion   { printf("suma\n"); }
                    | expresion '-' expresion   { printf("resta\n"); }
                    | expresion '*' expresion   { printf("multiplicacion\n"); }
                    | expresion '/' expresion   { printf("division\n"); }
                    | '-' valor %prec NEG       { printf("inversion\n"); }
                    | valor
                    ;
valor               : IDENTIFICADOR
                    | CONSTANTE
                    | '(' expresion ')'         { printf("parentesis\n"); }
                    ;
%%

int yylexerrs = 0;
void yyerror(const char *s){

	printf("Línea #%d: %s\n", yylineno, s);
	return;
}