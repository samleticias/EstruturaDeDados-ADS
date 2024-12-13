#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(3, no(1, no(1, no(9, NULL))));
    substitui(1, 7, l);
    exibe(l);
    return 0;
}

// Substitui toda ocorrencia do item 1 pelo item 7 na lista
// Saída:
// 3
// 7
// 7
// 9
