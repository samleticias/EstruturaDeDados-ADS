#include <stdio.h>

main(){
    int v[3] = {9, 6, 7};
    int *p = v; // ponteiro para um vetor
    printf("valor: %d\n", *(v)); // saida: 9 = v[0]
    printf("valor: %d\n", *(v + 1)); // saida: 6 = v[1]
    printf("valor: %d", *(v + 2)); // saida: 7 = v[2]

}