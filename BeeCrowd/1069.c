#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int conta_diamantes(char *linha) {
    int i, diamantes = 0;
    int pilha = 0;  

    for (i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            pilha++;
        } else if (linha[i] == '>') {
            if (pilha > 0) {
                pilha--;
                diamantes++;
            }
        }
    }
    
    return diamantes;
}

int main() {
    int N, i;
    char linha[MAX_SIZE + 1];

    scanf("%d", &N);
    getchar();  

    for (i = 0; i < N; i++) {
        fgets(linha, MAX_SIZE + 1, stdin);

        linha[strcspn(linha, "\n")] = '\0';

        int resultado = conta_diamantes(linha);
        printf("%d\n", resultado);
    }

    return 0;
}
