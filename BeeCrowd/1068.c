#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificaBalancoParenteses(char *);

void main()
{
    char expressao[1100];

    while(scanf(" %s", expressao) != EOF){

        if(verificaBalancoParenteses(expressao))
			printf("correct\n");
		else
			printf("incorrect\n");
    }
}

bool verificaBalancoParenteses(char *str){

    short qtsP = 0;

    // se a expressao começar com uma parentese que fecha, já não está balanceada
    if (*str == ')'){
        return false;
    }

	// enquanto a string nao acabar ou o balanço for irrecuperável
    while((*str) && (qtsP >= 0)){

        if (*str == '('){
            qtsP++;
        }

        if (*str == ')'){
            qtsP--;
        }

        str++;
    }

    if (qtsP == 0)
		return true;
	else
		return false;
}