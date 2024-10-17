#include <stdio.h>
#include <stdlib.h>

main(){
    int *p1 = (int*)malloc(sizeof(int)); // alocou espaço de memória
    *p1 = 20;
    printf("valor: %d\n", *p1);

    // é uma alocação sequencial porque acontece em um vetor 
    // -> vantagem: rapidez de acesso aos dados pelos índices
    // -> desvantagem: remover ou inserir elementos porque terá que percorrer todos os elementos

    // também é alocação estática porque quando escrita a linha de código, já aloca o espaço no vetor de acordo com o tamanho
    int v[9];
    int n = 3;

    // alocação dinâmica porque acontece no momento da execução do programa
    int *w = (int*)malloc(n*sizeof(int));

    w[0] = 9;
    printf("valor: %d", *w);

}