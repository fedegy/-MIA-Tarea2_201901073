%{
    #include <iostream>
    #include "parser.h"
    Nodo *com;
%}

%option case-insensitive
%option noyywrap

DIGITO              [0-9]
NUMERO              {DIGITO}+
ID                  [a-zA-Z][a-zA-Z0-9_]*
RUTA                \/.[^" "]+|{ID}"."{ID}

%%
{NUMERO}            {strcpy(yylval.text, yytext); return(NUMERO);}
"mkdisk"            {strdup(yytext); return(MKDISK);}
"rep"               {strdup(yytext); return(REP);}
{ID}                {strcpy(yylval.text, yytext); return(ID);}
{RUTA}              {strcpy(yylval.text, yytext); return(RUTA);}
[\t\r\f\n]            {}
.                   {std::cout<<yytext<<" Error Lexico "<<std::endl;}
%%