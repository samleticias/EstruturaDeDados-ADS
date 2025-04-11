#include <stdio.h>
#include <stdlib.h>

typedef int itemp;

typedef struct pilha {
    int max;
    int topo;
    itemp *item;
} *Pilha;

Pilha pilha(int max){
    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    p->max = max;
    p->topo = -1;
    p->item = (itemp*)malloc(max * sizeof(itemp));
    return p;
}

int estaVazia(Pilha p){
    return p->topo == -1;
}

int estaCheia(Pilha p){
    return p->topo == p->max-1;
}

void empilha(itemp item, Pilha p){
    if (estaCheia(p)){
        printf("A pilha está cheia!\n");
        abort();
    }
    p->topo++;
    p->item[p->topo] = item;
}

void desempilha(Pilha p){
    if (estaVazia(p)){
        printf("A pilha está vazia!\n");
        abort();
    }
    p->topo--;
}

void mostra(Pilha p) {
    if (estaVazia(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("\n>> Pilha <<\n");
       for (int i = p->topo; i >= 0; i--){
        printf("item: %d\n", p->item[i]);
       }
    }
}

int main(){
    Pilha p = pilha(6);
    empilha(2, p);
    empilha(9, p);
    empilha(34, p);
    mostra(p);

    desempilha(p);
    mostra(p);

    free(p->item);
    free(p);
    
    return 0;
}