#include <stdio.h>
#include "lista.h"

int main(void){
    Lista l = no(3, no(1, no(5, NULL)));
    printf("%d", ultimo(l)); // Saída: 5
    return 0;
}
