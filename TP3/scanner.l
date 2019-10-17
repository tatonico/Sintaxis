%top{
#include <stdio.h>
#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

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
{L}{LD}*            return IDENTIFICADOR;
{D}+                return CONSTANTE;
{O}+                printf("Error Léxico: Cadena desconocida: %s\n", yytext);
{L}{LDO}*           printf("Error Léxico: Identificador inválido: %s\n", yytext);
{D}{LD}*            printf("Error Léxico: Constante inválida: %s\n", yytext);
{S}+                /*ignorar espacios*/
#.*\n               /*ignorar comentario*/
.                   printf("Error Léxico: Cadena desconocida: %s\n", yytext);
