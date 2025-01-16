#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p){
    Lista n = (Lista)malloc(sizeof(struct no));  
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista l){
    while (l != NULL){
        printf("%d\n", l->item);
        l = l->prox;
    }
}

void anexa(Lista *A, Lista B){
    if (B == NULL) return;
    while (*A != NULL) A = &(*A)->prox;
    *A = B;
}

void destroi(Lista *l){
    while (*l != NULL){
        Lista n = *l;
        *l = n->prox;
        free(n);
    }
}

void exibe_inv(Lista l){
    if (l == NULL) return;
    exibe_inv(l->prox);
    printf("%d\n", l->item);
}

int ocorrencias(Item x, Lista l){
    int qtd = 0;
    while (l != NULL){
        if (l->item == x){
            qtd++;
        }
        l = l->prox;
    }
    return qtd;
}

Item ultimo(Lista l){
    while (l->prox != NULL){
        l = l->prox;
    }
    return l->item;
}

Lista inversa(Lista l){
    Lista inv = NULL;
    while (l != NULL){
        inv = no(l->item, inv);
        l = l->prox;
    }
    return inv;
}

int soma(Lista l){
    if (l == 0){
        return 0;
    } else {
        return l->item + soma(l->prox);
    }
}

void substitui(int x, int y, Lista l){
    if (l == NULL){
        return;
    }
    if (l->item == x){
        l->item = y;
    }
    substitui(x, y, l->prox);
}

int igual(Lista A, Lista B) {
    if (A == NULL && B == NULL) {
        return 1;  
    }
    if (A == NULL || B == NULL || A->item != B->item) {
        return 0; 
    }
    return igual(A->prox, B->prox); 
}

Item enesimo(int posicao, Lista l){
    if (l == NULL){
        printf("\nerro fatal: posicao invalida!\n\n");
        exit(1);
    }
    if (posicao == 1){
        return l->item;
    }
    return enesimo(posicao - 1, l->prox);
}
