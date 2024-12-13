#include "pilha.h"
#include <stdio.h>

// oi bom dia   // io mob aid

int main() {

    char frase[100];
    Pilha pilha1 = criaPilha(100);
    Pilha pilha2 = criaPilha(100);
    Pilha pilha3 = criaPilha(100);
    printf("\n> digite uma frase: ");
    gets(frase);

    // preenche a pilha 1 com a cadeia de caracteres
    for (int i = 0; frase[i] != '\0'; i++) {
        empilha(frase[i], pilha1);
    }

    while (!emptyp(pilha1)) {

        // desempilha da pilha 1 e empilha na pilha 2, até formar uma palavra
        while (!emptyp(pilha1) && topo(pilha1) != ' ') {
            empilha(desempilha(pilha1), pilha2);
        }

        // desempilha da pilha 2 e empilha na pilha 3 a palavra com as letras invertidas
        while (!emptyp(pilha2)) {
            empilha(desempilha(pilha2), pilha3);
        }

        // empilha o caracter de espaço que ficou na pilha 1 para a pilha 3, caso ainda tenha
        if (!emptyp(pilha1))
            empilha(desempilha(pilha1), pilha3);
    }

    //vem desempilhando a pilha 3, exibindo as palavras na mesma ordem, porém com as letras invertidas
    while (!emptyp(pilha3)){
        printf("%c", desempilha(pilha3));
    }

    // faz a liberação de memória
    destruir(&pilha1);
    destruir(&pilha2);
    destruir(&pilha3);

    return 0;
}