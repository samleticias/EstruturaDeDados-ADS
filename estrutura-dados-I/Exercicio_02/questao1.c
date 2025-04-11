// Leia dois nomes e compare se os nomes são iguais. Se forem iguais imprima “São Iguais!”, senão
// imprima “São Diferentes”.
// OBSERVAÇÃO:
// Faça usando:
// char nome1[20];
// char nome2[20];
// USE A FUNÇÃO STRCMP () PARA COMPARAR AS STRINGS
#include <stdio.h>
#include <string.h>
int main (void){
    char nome1[10] = "sammya";
    char nome2[10] = "sammya";

    // compara os endereços
    if (nome1 == nome2){
        puts("são iguais");
    } else {
        puts("são diferentes");
    }

    // compara os caracteres
    if (strcmp(nome1, nome2) == 0){
        puts("são iguais");
    } else {
        puts("são diferentes");
    }
}