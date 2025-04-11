#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct pessoa {
    int id;
    char nome[30];
    pessoa *proximo;
} Pessoa;

main(){

    // alocação de memória
    Pessoa *p1 =(Pessoa*)malloc(sizeof(Pessoa));

    p1->id = 3;
    strcpy(p1->nome, "sammya");
    p1->proximo = NULL;

    cout << p1->id << endl;
    cout << p1->nome << endl;

    // alocação de memória
    Pessoa *p2 =(Pessoa*)malloc(sizeof(Pessoa));

    p2->id = 6;
    strcpy(p2->nome, "joao");
    p2->proximo = NULL;

    // proximo vai apontar para p2, encadeando a lista
    p1->proximo = p2;

    Pessoa *percorre = p1;

    // acaba o laço de repetição quando percorre = NULL
    // while (percorre != NULL)
    while (percorre){
        cout << "id: " << percorre->id << endl;
        cout << "nome: " << percorre->nome << endl;
        cout << "proximo: " << percorre->proximo << endl;
        // atualizando o percorre no laço de repetição para apontar para o proximo
        percorre = percorre->proximo;
    }

    // lista encadeada:
    // -> sempre necessário ter o endereço do inicio quando for lista encadeada
    // -> vantagem: rapidez de inserção e remoção dos itens, não tem mais índice
    // -> desvantagem: se qusier acessar qualquer elemento, tem que percorrer todos, pois não existe índice
    // deve obrigatoriamente ter o endereço do primeiro para consultar os seguintes
    // o que garante o encadeamento é o ponteiro proximo que vai levar ao outro elemento

}
