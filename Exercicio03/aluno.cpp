// Atividade
// Faça usando o modelo da opção 2 (usando classes):
// 1. Escreve o método para inserir no inicio da lista.
// 2. Escreva o método consultar, aonde será pesquisado um aluno
// através do número de matrícula. Se o aluno for encontrado uma
// mensagem com matrícula e nome deve ser impressa na tela do
// computador, se o aluno não for encontrado, a mensagem deve
// informar que o aluno não existe.
// 3. Escreva o método remover, aonde será retirado um elemento da
// lista.
// 4. Escreva o método listar, aonde serão listados todos os elementos
// da lista.
// 5. Criar uma nova lista que seja o inverso da primeira já criada.
// 6. Inverter a própria lista.

#include <string>
#include <iostream>
using namespace std;

class No {
    public:
    int matricula;
    string nome;
    No *proximo;
    No(int matricula, string nome) {
        this->matricula = matricula;
        this->nome = nome;
        proximo = NULL;
    }
};

class Lista{
    public:
    No *inicio;
    No *fim;
    Lista(){
        inicio = NULL;
        fim = NULL;
    }

    void inserir(int matricula, string nome){
        No *novo = new No(matricula, nome);
        novo->proximo = inicio;
        inicio = novo;
        if (fim = NULL){
            fim = novo;
        }
    }

    void consultar(int matriculaProcurada){
        No *atual = inicio;
        while(atual != NULL){
            if (atual->matricula == matriculaProcurada){
                printf("\nmatricula   nome\n");
                printf("---------------------------------------\n");
                printf("%9d   %-20s\n", atual->matricula, atual->nome);
                printf("---------------------------------------\n");
                atual = atual->proximo;
            } else {
                cout << "\naluno nao encontrado!\n\n";
                return;
            }
        }
    }

    void remover(int matricula) {
        if (inicio == NULL) {
            cout << "\nlista vazia!\n\n" << endl;
            return;
        }

        if (inicio->matricula == matricula){
            inicio = inicio->proximo;
            if (inicio == NULL) fim = NULL;
            cout << "\naluno removido!\n\n" << endl;
            return;
        }

        No *atual = inicio;
        while (atual->proximo != NULL && atual->proximo->matricula != matricula) {
            atual = atual->proximo;
        }

        if (atual->proximo == NULL) {
            cout << "\naluno nao encontrado!\n\n" << endl;
            return;
        } else {
            atual->proximo = atual->proximo->proximo;
            if (atual->proximo == NULL) fim = atual;
            cout << "\naluno removido!\n\n" << endl;
            return;
        }
    }

    void listar(){
        No *atual = inicio;
        if (atual == NULL){
            cout << "\nlista vazia!\n\n";
            return;
        } else {
            int contador = 0;
            printf("matricula   nome\n");
            printf("---------------------------------------\n");
            while(atual != NULL){
                printf("%d          %s\n", atual->matricula, atual->nome.c_str());
                atual = atual->proximo;
                contador++;
            }
            printf("---------------------------------------\n");
            printf("> quantidade de alunos = %d\n\n", contador);
        }
    }

    Lista* criarListaInvertida(){
        Lista *listaInvertida = new Lista();
        No *atual = inicio;
        while(atual != NULL){
            listaInvertida->inserir(atual->matricula, atual->nome);
            atual = atual->proximo;
        }
        return listaInvertida;
    }

    void inverter(){
        No *anterior = NULL;
        No *atual = inicio;
        No *posterior = NULL;
        fim = inicio;

        while(atual != NULL){
            posterior = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = posterior;
        }
        inicio = anterior;
    }
};

main(){
    Lista lista;
    lista.inserir(1, "jose");
    lista.inserir(2, "sammya");
    lista.inserir(3, "joao");

    lista.remover(3);

    lista.listar();
    
    Lista *listaInvertida = lista.criarListaInvertida();
    listaInvertida->listar();

    lista.inverter();
    lista.listar();
}

