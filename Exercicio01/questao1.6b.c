#include <stdio.h>
// No é uma estrutura que representa um nó de uma lista encadeada
typedef struct no {
    int item; // campo que armazena o valor do nó
    struct no *prox;  // ponteiro que aponta para o próximo nó na lista, permite que os nós sejam encadeados
} No;

int main (void){

    // Alocação Encadeada Estática
    // Encadeada: aponta para o próximo nó, tendo sempre o endereço do atual
    // Estática: o tamanho da lista é fixo e definido em tempo de compilação
    // No v[4] tem um tamanho fixo de 4 nós

    // inicializa vetor de 4 nós
    No v[4] = {{3, v+2}, {1, v+3}, {4, NULL}, {2, v+0}}; 

    // v[0]: armazena o valor 3 e aponta para v[2] 
    // v[1]: armazena o valor 1 e aponta para v[3]
    // v[2]: armazena o valor 4 e aponta para NULL (indica o final da lista)
    // v[3]: armazena o valor 2 e aponta para v[0] (faz um ciclo de volta ao primeiro nó)

    // um ponteiro p é inicializado para apontar para o segundo nó (v[1])
    // o loop for continua enquanto p for diferente de NULL
    // o loop imprime o valor do item do nó atual (p->item) e atualiza p para apontar para o próximo nó (p = p->prox)
    for (No *p = v+1; p != NULL; p = p->prox){
        printf("%d\n", p->item);
    }
    return 0;
}