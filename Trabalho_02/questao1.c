#include <stdio.h>
#include "fila.h"

int main() {
    Fila fila = criaFila(10);

    enfileira(1, fila);
    enfileira(2, fila);
    enfileira(3, fila);

    printf("Após enfileirar 1, 2 e 3:\n");
    mostrarFila(fila);

    desenfileira(fila);
    printf("Após desenfileirar 1 elemento:\n");
    mostrarFila(fila);

    enfileira(4, fila);
    printf("Após enfileirar 4:\n");
    mostrarFila(fila);

    destruirFila(&fila);

    return 0;
}