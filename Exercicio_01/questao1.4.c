#include <stdio.h>
// declara estrutura Str com campo valor, que é um array de char, pois não existe string em C
typedef struct { char valor[10]; } Str;

int main (void){
    // x é uma instancia do struct Str
    Str x = { "um" };

    // y é uma instancia do struct Str
    Str y = { "dois" };

    // exibe campo valor de x
    puts(x.valor); // Saída : um

    // campo valor de x recebe o valor de y, antes x.valor era "um" e agora vai ser "dois"
    x = y;

    // exibe novo valor atribuido ao campo valor da instancia x
    puts(x.valor); // Saída : dois

    return 0;
}