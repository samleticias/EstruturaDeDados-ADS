#include <iostream>
#include <string>
#include <sstream>

class No {
public:
    char caracter;
    No* proximo;

    No(char valor) : caracter(valor), proximo(nullptr) {}
};

class Pilha {
private:
    No* topo;

public:
    Pilha() : topo(nullptr) {}

    void empilhar(char valor) {
        No* novo = new No(valor);
        if (novo) {
            novo->proximo = topo;
            topo = novo;
        } else {
            std::cout << "\terro ao alocar memória ...\n";
        }
    }

    void desempilhar() {
        if (topo) {
            std::cout << topo->caracter;
            No* remover = topo;
            topo = remover->proximo;
            delete remover;
        } else {
            std::cout << "a pilha está vazia!\n";
        }
    }

    bool estaVazia() const {
        return topo == nullptr;
    }
};

int main() {
    std::string frase;
    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase);

    Pilha pilha;
    for (char c : frase) {
        if (c != ' ') {
            pilha.empilhar(c);
        } else {
            while (!pilha.estaVazia()) {
                pilha.desempilhar();
            }
            std::cout << ' ';
        }
    }
    while (!pilha.estaVazia()) {
        pilha.desempilhar();
    }
    return 0;
}