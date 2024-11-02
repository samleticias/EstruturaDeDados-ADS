#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Aluno {
    int matricula;
    char nome[20];
    struct Aluno *proximo;
} Aluno;

int main(){
    Aluno *aluno1;
    aluno1 = (Aluno*)malloc(sizeof(Aluno));
    aluno1->matricula = 2;
    strcpy(aluno1->nome, "maria");
    aluno1->proximo = NULL;

    Aluno *inicio;
    inicio = aluno1;
    Aluno *fim;
    fim = aluno1;

    Aluno *aluno2;
    aluno2 = (Aluno*)malloc(sizeof(Aluno));
    aluno2->matricula = 9;
    strcpy(aluno2->nome, "joao");
    aluno2->proximo = NULL;

    fim->proximo = aluno2;
    fim = fim->proximo;

    // incluir aluno no inicio da lista
    Aluno *aluno3;
    aluno3 = (Aluno*)malloc(sizeof(Aluno));
    aluno3->matricula = 5;
    strcpy(aluno3->nome, "sammya");
    inicio->proximo = aluno3;
    inicio = inicio->proximo;
    aluno3->proximo = aluno1;
    aluno1->proximo = aluno2;

    // incluir aluno no meio da lista
    Aluno *aluno4;
    aluno4 = (Aluno*)malloc(sizeof(Aluno));
    aluno4->matricula = 6;
    strcpy(aluno4->nome, "jose");
    aluno1->proximo = aluno4;
    aluno4->proximo = aluno2;

    Aluno *atual;
    atual = inicio;
    printf("\n>>> lista de alunos <<<\n\n");
    while (atual != NULL) {
        printf("> matricula: %d\n",atual->matricula);
        printf("> nome: %s\n\n",atual->nome);
        atual = atual->proximo;
    }

    return 0;
}