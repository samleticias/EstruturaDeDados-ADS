#include <stdlib.h>
#include <stdio.h>

typedef int itemp;

typedef struct pilha {
    int max;
    int topo;
    itemp *item;
} *Pilha;

Pilha pilha (int max){
    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    p->max = max;
    p->topo = -1;
    p->item = (itemp*)malloc(max*sizeof(itemp));
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
        abort();
    }
    p->topo++;
    p->item[p->topo] = item;
}

itemp desempilha(Pilha p){
    if (estaVazia(p)){
        abort();
    }
    itemp item = p->item[p->topo];
    p->topo--;
    return item;
}

itemp getTopo(Pilha p){
    if(estaVazia(p)){
        abort();
    }
    return p->item[p->topo];
}

int main(){
    Pilha p = pilha(100);
    empilha(10, p);
    while(getTopo(p) > 0){
        empilha(getTopo(p)/2, p);
    }
    while(!estaVazia(p)){
        printf("%d\n", desempilha(p));
    }
}

