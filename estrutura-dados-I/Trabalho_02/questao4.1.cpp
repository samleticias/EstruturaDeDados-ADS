#include <iostream>
#include <cstring>

using namespace std;

class No {
    public:
        int mat;
        char nome[23];
        No *prox;
        No *ant;
        No(int m, char n[23]) {
            mat = m;
            strcpy(nome, n);
            prox = NULL;
            ant = NULL;
        }
};

class Lista {
    private:
        No *inicio;
        No *fim;

    public:
        Lista() {
            inicio = NULL;
            fim = NULL;
        }

        void inserirOrdenado(int mat, char nome[23]) {
            No *novo = new No(mat, nome);
            if (!inicio) {
                inicio = fim = novo;
            } else if (mat < inicio->mat) {
                novo->prox = inicio;
                inicio->ant = novo;
                inicio = novo;
            } else { 
                No *atual = inicio;
                while (atual->prox && atual->prox->mat < mat) {
                    atual = atual->prox;
                }

                if (!atual->prox) {
                    atual->prox = novo;
                    novo->ant = atual;
                    fim = novo;
                } else {
                    novo->prox = atual->prox;
                    novo->ant = atual;
                    atual->prox->ant = novo;
                    atual->prox = novo;
                }
            }
        }

        void mostrarInicioAoFim() {
            No *atual = inicio;
            while (atual) {
                cout << "Matricula: " << atual->mat << ", Nome: " << atual->nome << endl;
                atual = atual->prox;
            }
        }

        void removerUltimo() {
            if (!fim) {
                cout << "Lista vazia, nada a remover!" << endl;
                return;
            }

            No *removido = fim;

            if (inicio == fim) { 
                inicio = fim = NULL;
            } else {
                fim = fim->ant;
                fim->prox = NULL;
            }

            delete removido;
            cout << "Último elemento removido com sucesso." << endl;
        }

        void removerPrimeiro() {
            if (!inicio) {
                cout << "Lista vazia, nada a remover!" << endl;
                return;
            }

            No *removido = inicio;

            if (inicio == fim) {
                inicio = fim = NULL;
            } else {
                inicio = inicio->prox;
                inicio->ant = NULL;
            }

            delete removido;
            cout << "Primeiro elemento removido com sucesso." << endl;
        }
};

int main() {
    Lista lista;
    char nome1[23] = "Elanne";
    char nome2[23] = "Emanoel";
    char nome3[23] = "Marcio";
    char nome4[23] = "Pedro";

    lista.inserirOrdenado(2, nome2);
    lista.inserirOrdenado(1, nome1);
    lista.inserirOrdenado(4, nome4);
    lista.inserirOrdenado(3, nome3);

    cout << "Lista após inserção ordenada:" << endl;
    lista.mostrarInicioAoFim();

    cout << "\nRemovendo o último elemento..." << endl;
    lista.removerUltimo();
    lista.mostrarInicioAoFim();

    cout << "\nRemovendo o primeiro elemento..." << endl;
    lista.removerPrimeiro();
    lista.mostrarInicioAoFim();

    return 0;
}
