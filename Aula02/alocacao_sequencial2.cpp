#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    int matricula;
    char nome[20];
} Aluno;

Aluno v[20]; 
int ultimo = 0;  

void inserir(Aluno novo) {
    if (ultimo < 20) {  
        v[ultimo] = novo;  
        ultimo += 1;  
    } else {
        printf("Lista cheia! Não é possível inserir mais alunos...\n");
    }
}

Aluno salvarDados(const char *nome, int matricula) {
    Aluno aluno;
    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    return aluno;
}

void remover(int matriculaProcurada) {
    if (ultimo > 0) {  
        bool encontrado = false;
        for (int i = 0; i < ultimo; i++) {
            if (v[i].matricula == matriculaProcurada) {
                encontrado = true;
                printf("Aluno com matrícula %d removido com sucesso!\n\n", matriculaProcurada);
                for (int j = i; j < ultimo - 1; j++) {
                    v[j] = v[j + 1];
                }
                ultimo--;  
                break;
            }
        }
        if (!encontrado) {
            printf("Aluno com matrícula %d não encontrado!\n", matriculaProcurada);
        }
    } else {
        printf("Lista vazia! Não há alunos para remover ...\n");
    }
}

void mostraListaAlunos() {
    if (ultimo == 0) {
        cout << "\nNenhum aluno cadastrado\n" << endl;
        return;
    }
    
    cout << "Lista de Alunos" << endl;
    for (int i = 0; i < ultimo; i++) {  
        cout << "| Aluno:" << endl;
        cout << "> Posição: " << i << endl;
        cout << "> Matrícula: " << v[i].matricula << endl;
        cout << "> Nome: " << v[i].nome << endl << endl;
    }
}

int main() {
    Aluno aluno1 = salvarDados("Sammya", 123);
    inserir(aluno1);

    Aluno aluno2 = salvarDados("Joao", 456);
    inserir(aluno2);

    mostraListaAlunos();
    
    remover(123);
    mostraListaAlunos();
    
    return 0;
}
