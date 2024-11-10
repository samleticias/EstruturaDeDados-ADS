#include <stdio.h>
#include "lista.h"

int main(void){
    Lista i = no(1, no(2, no(3, NULL)));
    Lista j = no(1, no(2, no(3, NULL)));
    Lista k = no(1, no(3, no(2, NULL)));

    printf("%d\n", igual(i, j)); // Saída: 1
    printf("%d\n", igual(j, k)); // Saída: 0
    return 0;
}