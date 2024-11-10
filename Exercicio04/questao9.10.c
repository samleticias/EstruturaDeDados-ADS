#include "fila.h"

int main(){
    Fila f = fila(5);
    enfileira(1, f);
    enfileira(2, f);
    enfileira(3, f);
    enfileira(desinfileira(f), f);
    printf("%d\n", desinfileira(f));
    enfileira(desinfileira(f), f);
    printf("%d\n", desinfileira(f));
}