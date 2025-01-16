// 2. Leia dois nomes e compare se os nomes são iguais. Se forem iguais imprima “São Iguais!”, senão
// imprima “São Diferentes”.
// OBSERVAÇÃO:
// Faça usando:
// char nome1[20];
// char nome2[20];
// UTILIZE O COMANDO DE REPETIÇÃO “FOR” PARA PERCORRER AS
// STRINGS CARACTERE A CARACTERE E FAZER A COMPARAÇÃO ENTRE
// ELAS.
#include <stdio.h>
#include <string.h>
int main (void){
    char nome1[6] = "sammya";
    char nome2[6] = "sammya";

    int tamanho1 = strlen(nome1);
    int contador = 0;

    for (int i = 0; i < tamanho1; i++){
        if (*(nome1+1) == *(nome2+1)) {
            contador += 1;
        }
    } 

    if (tamanho1 == contador){
        puts("são iguais");
    } else {
        puts("são diferentes");
    }
}
