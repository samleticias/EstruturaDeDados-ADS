#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(1, no(2, no(1, no(4, no(1, NULL)))));
    printf("%d", ocorrencias(1, l)); // Saída: 3
    return 0;
}
