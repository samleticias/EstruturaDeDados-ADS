#include <stdio.h>
#include <stdlib.h>

typedef int itemf;

typedef struct fila {
    int max;
    int total;
    int inicio;
    int final;
    itemf *item;
} *Fila;

Fila fila(int max){
    Fila f = (Fila)malloc(sizeof(struct fila));
    f->max = max;
    f->total = 0;
    f->inicio = 0;
    f->final = 0;
    f->item = (itemf*)malloc(max*sizeof(itemf));
    return f;
}

int estaVazia(Fila f){
    return f->total == 0;
}

int estaCheia(Fila f){
    return f->total == f->max;
}

void enfileira(itemf item, Fila f){
    if(estaCheia(f)){
        abort();
    }
    f->item[f->final] = item;
    f->final = (f->final + 1) % f->max;
    f->total++;
}

itemf desenfileira(Fila f){
    if(estaVazia(f)){
        abort();
    }
    itemf item = f->item[f->inicio];
    f->inicio = (f->inicio + 1) % f->max;
    f->total--;
    return item;
}