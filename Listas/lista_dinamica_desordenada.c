#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[20];
    float nota;
    struct aluno *prox;  
} TAluno;

TAluno *inicio = NULL;
TAluno *fim = NULL;
int qtd = 0; 

void listar() {
    TAluno *noAtual = inicio;
    printf("\n>>> listagem de alunos <<<\n\n");
    if (qtd != 0) {
        printf("matricula   nome\n");
        printf("---------------------------------------\n");
        while (noAtual != NULL) {
            printf("%d          %s\n", noAtual->matricula, noAtual->nome);
            noAtual = noAtual->prox;
        }
        printf("---------------------------------------\n");
        printf("> quantidade de alunos = %d\n\n", qtd);
    } else {
        printf("\nnenhum aluno cadastrado!\n");
    }
}

void adicionarAluno(int matricula, const char *nome, float nota) {
    TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
    if (novo == NULL) {
        printf("erro ao alocar memoria ...\n");
        return;
    }
    
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
    qtd++;
}

void consultarAluno(int matriculaProcurada) {
    TAluno *noAtual = inicio;
    int achou = 0;
    while (noAtual != NULL) {
        if (noAtual->matricula == matriculaProcurada) {
            achou = 1;
            printf("\nmatricula   nome\n");
            printf("---------------------------------------\n");
            printf("%9d   %-20s\n", noAtual->matricula, noAtual->nome);
            printf("---------------------------------------\n");
            break;
        }
        noAtual = noAtual->prox;
    }
    if (achou == 0) {
        printf("\naluno nao encontrado!\n");
    }
}

int main() {
    adicionarAluno(5, "joao", 8.0);
    adicionarAluno(8, "sammya", 9.0);
    adicionarAluno(3, "jose", 7.0);

    int matriculaProcurada, continuar;
    do {
        printf("\nconsulta aluno pelo numero de matricula\n");
        printf("\n> matricula: ");
        scanf("%d", &matriculaProcurada);

        consultarAluno(matriculaProcurada);
        
        printf("\ndeseja continuar consultando? (1-sim/0-nao) ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    listar();

    return 0;
}
