#include <stdio.h>
#include <stdlib.h>

typedef int Itemp;

typedef struct pilha {
    int max;
    int top;
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

void empilha(Itemp value, Pilha pilha) {
    if (fullp(pilha)) {
        printf("A pilha está cheia\n");
        abort();
    }
    pilha->item[++pilha->top] = value;
}

Itemp desempilha(Pilha pilha) {
    if (emptyp(pilha)) {
        printf("A pilha está vazia\n");
        abort();
    }
    return pilha->item[pilha->top--];
}

void destruir(Pilha *pilha) {
    free((*pilha)->item);
    free(*pilha);
    *pilha = NULL;
}

// estrutura da fila usando duas pilhas
typedef struct fila {
    Pilha pilha1; // para empilhar novos elementos
    Pilha pilha2; // para desempilhar na ordem correta
} *Fila;

Fila criaFila(int max) {
    Fila fila = malloc(sizeof(struct fila));
    if (!fila) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    fila->pilha1 = criaPilha(max);
    fila->pilha2 = criaPilha(max);
    if (!fila->pilha1 || !fila->pilha2) {
        printf("Erro ao criar as pilhas da fila\n");
        free(fila);
        return NULL;
    }
    return fila;
}

void enfileira(Itemp value, Fila fila) {
    empilha(value, fila->pilha1);
}

Itemp desenfileira(Fila fila) {
    // se pilha2 está vazia, transfere todos os elementos de `pilha1 para pilha2
    if (emptyp(fila->pilha2)) {
        while (!emptyp(fila->pilha1)) {
            empilha(desempilha(fila->pilha1), fila->pilha2);
        }
    }
    // desempilha de pilha2
    if (emptyp(fila->pilha2)) {
        printf("A fila está vazia\n");
        abort();
    }
    return desempilha(fila->pilha2);
}

void destruirFila(Fila *fila) {
    destruir(&(*fila)->pilha1);
    destruir(&(*fila)->pilha2);
    free(*fila);
    *fila = NULL;
}

void mostrarFila(Fila fila) {
    if (emptyp(fila->pilha1) && emptyp(fila->pilha2)) {
        printf("A fila está vazia\n");
        return;
    }

    Pilha pilhaTemp = criaPilha(fila->pilha1->max);

    while (!emptyp(fila->pilha2)) {
        empilha(desempilha(fila->pilha2), pilhaTemp);
    }

    while (!emptyp(fila->pilha1)) {
        empilha(desempilha(fila->pilha1), pilhaTemp);
    }

    printf("Itens na fila: ");
    while (!emptyp(pilhaTemp)) {
        Itemp item = desempilha(pilhaTemp);
        printf("%d ", item);

        if (emptyp(fila->pilha2)) {
            empilha(item, fila->pilha2); 
        } else {
            empilha(item, fila->pilha1); 
        }
    }
    printf("\n");

    destruir(&pilhaTemp); 
}
