#include <stdio.h>
void x(char *str1, char *str2) {
    while (*str1) {
        str1++;
    }

    while (*str2) {
        // ponteiro de str1 aponta para o endereço de str2
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}
int main() {
    char str1[100] = "Hello ";
    char str2[] = "World!";
    x(str1, str2);
    printf(" %s\n", str1);
    return 0;
}

// 8.1. O que será impresso ao final do programa?
// Hello World!

// 8.2. O que a função X está fazendo?
// Está concatenando os caracteres da string2 na string1, ou seja, a string 1 está mantendo os caracteres que já tem e recebendo os caracteres das string2.