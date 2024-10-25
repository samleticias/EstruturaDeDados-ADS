#include <iostream>
using namespace std;

// 6.2 Inclua os valores no vetor agora através da leitura do teclado.
// OBS: Leia o valor de um item através do teclado e inclua no vetor de
// maneira que o ponteiro prox deve apontar sempre para o proximo
// elemento do vetor.

typedef struct no {
    int item;
    struct no *prox;
} No;

void inserir(No v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "digite um número: ";
        cin >> v[i].item;
        if (i < tamanho - 1) {
            v[i].prox = &v[i + 1]; 
        } else {
            v[i].prox = NULL; 
        }
    }
}

int main() {
    const int TAMANHO = 4; 
    No v[TAMANHO];         
    
    inserir(v, TAMANHO);
    
    for (No *p = v; p != NULL; p = p->prox) {
        cout << p->item << endl;
    }

    return 0;
}

