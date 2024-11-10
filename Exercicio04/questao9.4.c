#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(7, no(9, no(2, NULL)));
    exibe(inversa(l));
    return 0;
}

// Saída: 
// 2
// 9
// 7
