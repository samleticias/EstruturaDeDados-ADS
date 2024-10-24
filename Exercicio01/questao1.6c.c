#include <stdio.h>
#include <stdlib.h>
// cada nó da lista contém um valor e um ponteiro para o próximo nó na lista
typedef struct no {
    int item;
    struct no *prox;
} *Lst; // Lst representa um ponteiro para um nó

// funcao para criar um novo nó na lista
Lst no (int x, Lst p){
    Lst n = malloc(sizeof(struct no)); // aloca dinamicamente memória suficiente para armazenar um novo nó (struct no)
    n->item = x;
    n->prox = p; // faz o campo prox do novo nó apontar para o próximo nó na lista, que é fornecido pelo argumento p
    return n;
}

// Lista encadeada dinâmica
// Encadeada: cada nó da lista armazena um valor e um ponteiro para o próximo nó
// Dinâmica: c função no cria nós dinamicamente, conectando-os em sequência
// o loop while percorre os nós da lista, imprimindo os valores na ordem em que foram encadeados (1, 2, 3, 4)

int main (void){
    Lst p = no(1, no(2, no(3, no(4, NULL))));
    while (p){
        printf("%d\n", p->item);
        p = p->prox;
    }
    return 0;
}