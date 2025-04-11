#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(3, no(1, no(5, no(4, NULL))));
    printf("%d", soma(l)); // Saída: 13
    return 0;
}
