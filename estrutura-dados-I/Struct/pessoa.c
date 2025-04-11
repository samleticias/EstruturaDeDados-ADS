#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
    char cpf[15];
} Pessoa;

void inicializaDados(Pessoa *pessoa, const char *nome, int idade, float altura, const char *cpf){
    strncpy(pessoa->nome, nome, sizeof(pessoa->nome) - 1);
    strncpy(pessoa->cpf, cpf, sizeof(pessoa->cpf) - 1);
    pessoa->cpf[sizeof(pessoa->cpf) - 1] = '\0';
    pessoa->nome[sizeof(pessoa->nome) - 1] = '\0';
    pessoa->altura = altura;
    pessoa->idade = idade;
}; 

void mostraDados(const Pessoa *pessoa){
    printf("-----------------------------\n");
    printf(">>> Dados <<<\n");
    printf("CPF: %s\n", pessoa->cpf);
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Altura: %.2f\n", pessoa->altura);
    printf("-----------------------------\n");
}

int main(){
    Pessoa p1;
    inicializaDados(&p1, "Maria", 18, 1.57, "123.456.789-00");
    mostraDados(&p1);

    return 0;
}