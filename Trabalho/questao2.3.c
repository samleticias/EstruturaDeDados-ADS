#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char caracter;
    struct no *proximo;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

int estaVazia(Pilha *pilha){
    return pilha->topo == NULL;
}

void empilhar(char letra, Pilha *pilha){
    No *novo = (No*)malloc(sizeof(struct no));
    if (novo){
        novo->caracter = letra;
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    } else {
        printf("erro ao alocar memória ...");
    }
}

char desempilhar(Pilha *pilha){
    if(!estaVazia(pilha)){
        No *remover = pilha->topo;
        char letra = remover->caracter;
        pilha->topo = remover->proximo;
        free(remover);
        return letra;
    }
    return '\0';
}

int main(){
    char frase[100];
    printf("Digite uma frase: "); // apenas um teste
    fgets(frase, sizeof(frase), stdin); 

    Pilha pilha;
    pilha.topo = NULL;

    for (int i = 0; i < strlen(frase); i++){
        if (frase[i] != ' ' && frase[i] != '\n'){
            empilhar(frase[i], &pilha);
        } else {
            while (!estaVazia(&pilha)){
                printf("%c", desempilhar(&pilha));
            }
            if (frase[i] == ' ') {
                printf(" "); 
            }
        }
    }

    if (!estaVazia(&pilha)){
        printf("%c", desempilhar(&pilha));
    }

    // Saída: sanepa mu etset

    return 0;
}