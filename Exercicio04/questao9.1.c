#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(3, no(1, no(5, NULL)));
    exibe_inv(l);
    return 0;
}

// Saída:
// 5
// 1
// 3