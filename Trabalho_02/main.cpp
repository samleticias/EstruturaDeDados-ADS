#include <iostream>
#include <stack>
using namespace std;

// Versão usando stl das questões:
// Questão 1. Desenvolva os procedimentos de entrar e sair de uma fila a partir dos procedimentos empilhar, desempilhar de uma pilha. 
// Utilize 2 (duas) pilhas.

int main() {
    int max;
    
    // obter quantidade de elementos
    cout << "> quantidade de elementos: ";
    cin >> max;

    // cria pilhas
    stack <char> s1;
    stack <char> s2;

    // insere letras
    for (int i = 0; i < max; i++) {
        cout << (i+1) << " letra: ";
        char current;
        cin >> current;
        s1.push(current);
    }

    // move letras da pilha 1 para a pilha 2
    for (int i = 0; i < max; i++) {
        s2.push(s1.top()); // adiciona na pilha 2 o elemento do topo da pilha 1
        s1.pop(); // remove elemento do topo da pilha 1
    }

    // desempilha
    for (int i = 0; i < max; i++) {
        cout << "\n> desempilha: " << s2.top();
        s2.pop();
    }
}