#include <stdio.h>
#include <string.h>
int main (void){
    // arrays s e t são alocados em enedreços diferentes da memória
    char s[3] = "um";
    char t[3] = "um";    

    // condição s == t compara os endereços dos arrays de caracteres
    printf("comparando endereços:\n");
    if (s == t) puts("iguais");
    else puts("diferentes");

    // para comparar caracteres usa-se a funcao strcmp de string.h
    printf("\ncomparando caracteres:\n");
    if (strcmp(s, t) == 0){
        puts("caracteres iguais");
    } else {
        puts("caracteres diferentes");
    }
    return 0;
}

// s e t são dois arrays de caracteres que armazenam a sequencia "um". Porém, a comparação if (s == t) não compara o conteúdo das strings,
// mas sim os endereços de memória onde os arrays s e t estão armazenados. Como cada array é alocado em um local diferente da memória, 
// s e t terão endereços diferentes, então a condição s == t será falsa, exibindo a mensagem "diferentes" no terminal.