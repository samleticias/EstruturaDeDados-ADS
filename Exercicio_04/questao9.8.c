#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(5, no(2, no(8, no(4, no(7, no(6, NULL))))));
    printf("%d\n", enesimo(5, l)); // Saída: 7
    return 0;
}