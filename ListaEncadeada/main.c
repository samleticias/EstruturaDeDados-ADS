#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// inserir no inicio da lista
void inserirNoInicio(No **lista, int num){
    No *novo = malloc(sizeof(No)); // aloca memoria para novo nó
    if (novo){
        novo->valor = num;
        novo->proximo = *lista; // novo nó aponta para inicio da lista
        *lista = novo; // atualiza inicio da lista que aponta para o novo nó
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

// inserir no final da lista
void inserirNoFinal(No **lista, int num){
    No *atual, *novo = malloc(sizeof(No)); // aloca memoria para novo nó
    if (novo){
        novo->valor = num;
        novo->proximo = NULL;
        // se a lista está vazia, o novo nó se torna o primeiro nó
        if (*lista == NULL){
            *lista = novo;
        } else {
            // ponteiro atual aponta para o inicio da lista
            atual = *lista;
            
            // loop percorre toda a lista até que o proximo aponte para null para encontrar o final da lista
            while (atual->proximo != NULL){
                // a cada volta, atualiza o atual para ser o proximo, percorrendo todos os elementos da lista
                atual = atual->proximo; 
            }
            // loop para quando o proximo apontar para null e atualiza o atual para ser o novo, encadeando/inserindo elemento ao final
            // da lista
            atual->proximo = novo;
        }
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

// inserir no meio da lista
void inserirNoMeio(No **lista, int num, int ant){
    No *atual, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = num;
        // se a lista está vazia, o novo nó se torna o primeiro nó
        if (*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            // variavel auxiliar para armazenar inicio da lista
            atual = *lista;
            // loop ocorre enquanto o valor do atual for diferente do valor anterior (valor de referencia) e proximo nao for null
            while(atual->valor != ant && atual->proximo != NULL){
                atual = atual->proximo; // atualiza variavel auxiliar para apontar para o proximo elemento da lista
            }
            // ex: inserir 2 entre os valores 1 e 3
            // proximo de 2 (novo elemento) para apontar para o proximo de 1 (que é 3) 
            // 2->proximo = 1->proximo (que é 3)
            novo->proximo = atual->proximo;
            // ponteiro proximo do atual vai apontar para o novo elemento a ser inserido no meio
            // 1-> proximo = 2 (que é o novo)
            atual->proximo = novo;
        }
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

void inserirOrdenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = num;
        // se a lista está vazia
        if (*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        // novo elemento é o menor
        } else if (novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        } else {
            aux = *lista;
            // encerra quando proximo é nulo ou o novo valor nao é maior que o valor do proximo nó
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

// imprimir lista encadeada na tela
void imprimir(No **lista){
    No *no = *lista; 
    printf("\nlista encadeada: ");
    while(no != NULL){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){
    int opcao, valor, anterior;
    No *lista = NULL;

    do {
        printf("\n\t1 - inserir no inicio\n\t2 - inserir no final\n\t3 - inserir no meio\n\t4 - imprimir lista\n\t5 - inserir ordenado\n\t0 - sair\n\t> ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("\ndigite um valor: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("\ndigite um valor: ");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
                break;
            case 3:
                printf("\ndigite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &anterior);
                inserirNoMeio(&lista, valor, anterior);
                break;
            case 4:
                imprimir(&lista);
                break;
            case 5:
                printf("\ndigite um valor: ");
                scanf("%d", &valor);
                inserirOrdenado(&lista, valor);
                break;
            default:
                if (opcao != 0){
                    printf("\nopcao invalida!\n\n");
                }
        }

    } while(opcao != 0);

    return 0;
}