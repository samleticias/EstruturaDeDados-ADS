#include <stdio.h>
int percorrerCadeiaCaracteres(char *str) {
    int contador = 0;
    while (*str) {
        contador++;
        str++;
    }
    return contador;
}
int main() {
    char str[] = "Hello World";
    int w = percorrerCadeiaCaracteres(str);
    printf("%d\n", w);
    return 0;
}

// 9.1. O que será impresso ao final do programa?
// Saída: 11

// 9.2. O que a função X está fazendo?
// Está percorrendo o array de caracteres e retornando a quantidade de caracteres, que é a variável contador.