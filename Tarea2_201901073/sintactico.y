%{
	#include <iostream>
	#include "nodo.h"

	extern int yylex(void);
	extern Nodo *com;

	int yyerror(const char*mens){
		std::cout<<mens<<std::endl;
		return 0;
	}
%}

%union{
	char text[400];
	class Nodo *script;
}

%start inicio;

%token <text>NUMERO
%token <text>MKDISK
%token <text>REP
%token <text>ID
%token <text>RUTA

%type<script> ins;
%type<script> in;
%type<script> inicio;


%%
inicio : ins 			{com = $$;};

ins : ins in            {$$ = $2;};
    | in                {$$ = $1;};

in : REP				{$$->reporte();};
    | MKDISK			{$$->mkdisk();};

%%
