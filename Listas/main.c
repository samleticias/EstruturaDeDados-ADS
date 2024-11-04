#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void criarLista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

// inserir no inicio da lista
void inserirNoInicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No)); // aloca memoria para novo nó
    if (novo){
        novo->valor = num;
        novo->proximo = lista->inicio; // novo nó aponta para inicio da lista
        lista->inicio = novo; // atualiza inicio da lista que aponta para o novo nó
        lista->tam++; // incrementa tamanho da lista a cada novo elemento inserido
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

// inserir no final da lista
void inserirNoFinal(Lista *lista, int num){
    No *atual, *novo = malloc(sizeof(No)); // aloca memoria para novo nó
    if (novo){
        novo->valor = num;
        novo->proximo = NULL;
        // se a lista está vazia, o novo nó se torna o primeiro nó
        if (lista->inicio == NULL){
            lista->inicio = novo;
        } else {
            // ponteiro atual aponta para o inicio da lista
            atual = lista->inicio;
            
            // loop percorre toda a lista até que o proximo aponte para null para encontrar o final da lista
            while (atual->proximo != NULL){
                // a cada volta, atualiza o atual para ser o proximo, percorrendo todos os elementos da lista
                atual = atual->proximo; 
            }

            // loop para quando o proximo apontar para null e atualiza o atual para ser o novo, encadeando/inserindo elemento ao final
            // da lista
            atual->proximo = novo;
        }
        lista->tam++;
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

void inserirNoMeio(Lista *lista, int num, int ant){
    No *atual, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = num;

        // se a lista está vazia, o novo nó se torna o primeiro nó
        if (lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        } else {
            // variavel auxiliar para armazenar inicio da lista
            atual = lista->inicio;
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
        lista->tam++;
    } else {
        printf("\nerro ao alocar memoria!\n");
    }
}

void imprimir(Lista lista){
    // elemento struct usa ponto
    // ponteiro usa seta
    No *no = lista.inicio; // copia da lista
    printf("\nlista encadeada tam %d: ", lista.tam);
    while(no != NULL){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){
    int opcao, valor, anterior;
    // No *lista = NULL;
    Lista lista;

    criarLista(&lista);

    do {
        printf("\n\t1 - inserir no inicio\n\t2 - inserir no final\n\t3 - inserir no meio\n\t4 - imprimir lista\n\t0 - sair\n\t> ");
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
                imprimir(lista);
                break;
            default:
                if (opcao != 0){
                    printf("\nopcao invalida!\n\n");
                }
        }

    } while(opcao != 0);

    return 0;
    
}