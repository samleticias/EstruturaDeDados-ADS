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
    Fila f = (Fila)malloc(max * sizeof(struct fila));
    f->max = max;
    f->inicio = 0;
    f->total = 0;
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
    if (estaCheia(f)){
        printf("\nA fila está cheia!\n");
        abort();
    }
    // inserções são feitas ao final da lista
    f->item[f->final] = item;
    f->final = (f->final + 1) % f->max;
    f->total++;
}

void desenfileira(Fila f){
    if (estaVazia(f)){
        abort();
    }
    // remoções são feitas no início da lista
    f->inicio = (f->inicio + 1) % f->max;
    f->total--;
}

void mostra(Fila f){
    if (estaVazia(f)){
        printf("\nA fila está vazia!\n");
    } else {
        printf("\n>> Fila <<\n");
        for (int i = 0; i < f->total; i++){
            int index = (f->inicio + i) % f->max;
            printf("item: %d\n", f->item[index]);
        }
    }
}

int main(){
    Fila f = fila(10);
    enfileira(12, f);
    enfileira(5, f);
    enfileira(9, f);
    mostra(f);

    desenfileira(f);
    mostra(f);
}