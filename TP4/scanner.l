%top{
#include <stdio.h>
#include "parser.h"

void enviarErrorLexico(const char*);
char buffer[255];
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput
%option yylineno

L   [[:alpha:]]
D   [0-9]
LD  [[:alnum:]]
S   [[:space:]]
O   [[:^alnum:]]{-}[[:space:]]{-}[,;()+*/<=#-]
LDO [[:^space:]]{-}[,;()+*/<=#-]

%%
programa            return PROGRAMA;
definir             return DEFINIR;
codigo              return CODIGO;
leer                return LEER;
escribir            return ESCRIBIR;
fin                 return FIN;
\+                  return '+';
-                   return '-';
\*                  return '*';
"/"                 return '/';
"<="                return ASIGNACION;
"("                 return '(';
")"                 return ')';
","                 return ',';
";"                 return ';';
{L}{LD}*            { yylval = strdup(yytext); return IDENTIFICADOR; }
{D}+                { yylval = strdup(yytext); return CONSTANTE; }
{O}+                { yylexerrs++; enviarErrorLexico("Error Léxico: Cadena desconocida: "); }
{L}{LDO}*           { yylexerrs++; enviarErrorLexico("Error Léxico: Identificador inválido: "); }
{D}{LD}*            { yylexerrs++; enviarErrorLexico("Error Léxico: Constante inválida: "); }
{S}+                /*ignorar espacios*/
#.*\n               /*ignorar comentario*/
.                   { yylexerrs++; enviarErrorLexico("Error Léxico: Cadena desconocida: "); }
%%

void enviarErrorLexico(const char *s) {
    strcat(buffer, s);
    strcat(buffer, yytext);
    yyerror(buffer);
    memset(buffer, '\0', 255);  
}