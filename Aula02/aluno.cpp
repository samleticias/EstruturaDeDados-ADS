#include <iostream>
#include <string.h>
#include <iomanip>  
using namespace std;

struct Aluno {
    int matricula;
    char nome[30];
    float nota;
};

int main() {
    Aluno aluno1;

    strcpy(aluno1.nome, "Sammya");
    aluno1.matricula = 123;
    aluno1.nota = 8.5;

    cout << "\n>>>>> Aluno <<<<<\n";
    cout << "-----------------" << endl;
    cout << "Nome: " << aluno1.nome << endl;
    cout << "Matrícula: " << aluno1.matricula << endl;
    cout << "Nota: " << fixed << setprecision(2) << aluno1.nota << endl;
    cout << "-----------------\n";

    Aluno *a1; 
    a1 = &aluno1; // a1 recebe/aponta para o endereço de aluno1

    cout << "\nUsando ponteiro\n";
    cout << "-----------------" << endl;
    cout << "Nome: " << a1->nome << endl;
    cout << "Matrícula: " << a1->matricula << endl;
    cout << "Nota: " << fixed << setprecision(2) << a1->nota << endl;
    cout << "-----------------";

    return 0;
}
