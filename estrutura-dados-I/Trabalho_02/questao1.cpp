#include <iostream>
#include <stack>
using namespace std;

void entrarFila(stack<char> *s, char valor) {
    s->push(valor);
}

char sairFila(stack<char> *s) {
    if (s->empty()) {
        abort();
    }

    stack<char> aux;

    // move elementos da pilha 1 para a pilha auxiliar
    while (!s->empty()) {
        aux.push(s->top());
        s->pop();
    }

    // obter primeiro elemento da fila
    char resposta = aux.top();
    aux.pop();

    // move elementos da pilha auxiliar para a pilha 1
    while (!aux.empty()) {
        s->push(aux.top());
        aux.pop();
    }

    return resposta;
}

int main() {
    stack<char> s1;

    entrarFila(&s1, 'e');
    entrarFila(&s1, 'n');
    entrarFila(&s1, 'z');
    entrarFila(&s1, 'o');

    cout << sairFila(&s1) << endl;
    cout << sairFila(&s1) << endl;
    cout << sairFila(&s1) << endl;
    cout << sairFila(&s1) << endl;
}