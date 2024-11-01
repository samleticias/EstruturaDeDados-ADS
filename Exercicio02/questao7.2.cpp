// 7.2 Inclua os valores no vetor agora através da leitura do teclado.
// OBS: Leia o valor de item através do teclado e inclua na lista de
// maneira que o ponteiro prox deve apontar sempre para o proximo elemento da lista.

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct no {
    int item;
    struct no *proximo;
} *Lst;

Lst inserirNo(int valor, Lst lista){
    // Lista dinâmica encadeada
    // Aloca espaço na memória para variável do tipo struct no
    Lst novo = (struct no*)malloc(sizeof(struct no));
    novo->item = valor;
    novo->proximo = NULL;

    if (lista != NULL){
        return novo;
    } else {
        Lst atual = lista;
        while (atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    return lista;
}

void mostra(Lst no){
    cout << "\nvalores na lista:" << endl;
    cout << "-----------------" << endl;
    while (no){
        cout << "> " << no->item << endl;
        no = no->proximo;
    }
    cout << "-----------------\n" << endl;
}

int main() {
    Lst lista = NULL; 
    int valor;

    while (valor != 0) {
        cout << "digite um número: ";
        cin >> valor; 
        lista = inserirNo(valor, lista); 
    }

    mostra(lista);

    return 0;
}