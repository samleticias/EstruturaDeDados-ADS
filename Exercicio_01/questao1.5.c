#include <stdio.h>
int main (void){
    // declara variaveis do tipo inteiro a = 3 e b = 5
    int a = 3, b = 5;

    // ponteiro *p aponta para o endereço da variavel a
    // ponteiro *q aponta para o endereço da variavel b
    int *p = &a, *q = &b;

    // traz o que tá no endereço q ele recebeu
    // com o *, pega os valores
    printf("\nvalores:\n");
    printf("valor de a: %d\n", *p); // traz o valor da variavel a
    printf("valor de b: %d\n", *q); // traz o valor da variavel b

    // sem *, pega o endereço
    printf("\nendereços:\n");
    printf("endereço da variavel a: %d\n", p); // traz o endereco da variavel a
    printf("endereço da variavel b: %d\n", q); // traz o endereco da variavel b

    // *p = 3 e *q = 5 inicialmente
    *p = *p + *q; // 3 = 3 + 5 = 8 = *p
    *q = *p - *q; // 5 = 8 - 5 = 3 = *q
    *p = *p - *q; // 8 = 8 - 3 = 5 = *p
    printf("\n%d, %d\n", a, b); // Saída: 5, 3
    printf("\n%d, %d\n\n", *p, *q); // Saída: 5, 3

    return 0;
}