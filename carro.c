#include <stdio.h>
#include <string.h>

typedef struct {
    char modelo[50];
    int ano;
    float preco;
} Carro;

void inicializarCarro(Carro *carro, const char *modelo, int ano, float preco) {
    strncpy(carro->modelo, modelo, sizeof(carro->modelo) - 1);
    carro->modelo[sizeof(carro->modelo) - 1] = '\0';
    carro->ano = ano;
    carro->preco = preco;
}

void exibirCarro(const Carro *carro) {
    printf(">>> Carro <<<\n");
    printf("> Modelo: %s\n", carro->modelo);
    printf("> Ano: %d\n", carro->ano);
    printf("> Preço: %.2f\n", carro->preco);
}

int main() {
    Carro c1;
    inicializarCarro(&c1, "Fusca", 1976, 15000.00);
    exibirCarro(&c1);
    
    return 0;
}
