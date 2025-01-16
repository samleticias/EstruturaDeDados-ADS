#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;

typedef struct pilha {
    int max;
    int top;    // indica a posição do topo
    Itemp *item;
} *Pilha;

Pilha criaPilha(int max) {
    Pilha pilha = malloc(sizeof(struct pilha));
    if (pilha) {
        pilha->top = -1;
        pilha->max = max;
        pilha->item = malloc(max * sizeof(Itemp));
        return pilha;
    }
    printf("Erro ao alocar memória");
}

int emptyp(Pilha pilha) {
    return pilha->top == -1;
}

int fullp(Pilha pilha) {
    return pilha->top == pilha->max - 1;
}

// empilhar
void empilha(Itemp value, Pilha pilha) {
    if (fullp(pilha)) {
        printf("A pilha está cheia");
        abort();
    }
    pilha->top++;
    pilha->item[pilha->top] = value;
}

// desempilhar
Itemp desempilha(Pilha pilha) {
    if (emptyp(pilha)) {
        printf("A pilha está vazia");
        abort();
    }
    Itemp ultimoItem = pilha->item[pilha->top];
    pilha->top--;
    return ultimoItem;
}

void destruir(Pilha *pilha) {
    free((*pilha)->item);
    free(*pilha);
    *pilha = NULL;
}

Itemp topo(Pilha pilha){
    if (emptyp(pilha)) {
        printf("A pilha está vazia");
        abort();
    }
    return pilha->item[pilha->top];
}