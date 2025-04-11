#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;

typedef struct pilha {
    int max;
    int topo;    // indica a posição do topo
    Itemp *item;
} *Pilha;

Pilha criaPilha(int max) {
    Pilha pilha = malloc(sizeof(struct pilha));
    if (pilha) {
        pilha->topo = -1;
        pilha->max = max;
        pilha->item = malloc(max * sizeof(Itemp));
        return pilha;
    }
    printf("Falha ao alocar memória");
}

int emptyp(Pilha pilha) {
    return pilha->topo == -1;
}

int fullp(Pilha pilha) {
    return pilha->topo == pilha->max - 1;
}

// empilhar
void empilha(Itemp value, Pilha pilha) {
    if (fullp(pilha)) {
        printf("A pilha está cheia");
        abort();
    }
    pilha->topo++;
    pilha->item[pilha->topo] = value;
}

// desempilhar
Itemp desempilha(Pilha pilha) {
    if (emptyp(pilha)) {
        printf("A pilha está vazia");
        abort();
    }
    Itemp ultimoItem = pilha->item[pilha->topo];
    pilha->topo--;
    return ultimoItem;
}

void destroi(Pilha *pilha) {
    free((*pilha)->item);
    free(*pilha);
    *pilha = NULL;
}

Itemp topo(Pilha pilha){
    if (emptyp(pilha)) {
        printf("A pilha está vazia");
        abort();
    }
    return pilha->item[pilha->topo];
}