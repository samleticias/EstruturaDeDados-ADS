#include <stdio.h>
#include <stdlib.h>
int main (void){

    // Alocação dinâmica sequencial

    // - Dinâmica: A memória é alocada durante a execução do programa, utilizando a função malloc, em vez de definir tamanho fixo para o vetor
    // - Sequencial: Os elementos são armazenados em um único bloco contíguo de memória, ou seja, o vetor
    // os elementos são armazenados em endereços adjacentes, um após o outro

    // int i é uma variável inteira que será usada como índice em um loop
    // *v é um ponteiro para um inteiro que será usado para armazenar o endereço de um bloco de memória alocado dinamicamente
    // aloca espaço para 4 inteiros na memória
    // 4 * sizeof(int) aloca 16 bytes (para um inteiro geralmente é 4 bytes)
    // malloc retorna um ponteiro para o primeiro byte do bloco de memória alocado
    int i, *v = malloc(4*sizeof(int));

    // o loop for itera sobre os índices de 0 a 3 do vetor e inicializa cada elemento do vetor v com valores de 1 a 4
    for (i = 0; i < 4; i++) v[i] = i+1;

    // exibe cada elemento por índice no vetor, de v[0] a v[3]
    for (i = 0; i < 4; i++) printf("%d\n", v[i]);

    return 0;
}