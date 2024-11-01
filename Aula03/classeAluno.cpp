#include <iostream>
#include <string.h>
using namespace std;

class Aluno {
    private:
        int matricula;
        string nome;
    public:
    Aluno(int amtricula, string nome){
        matricula = matricula;
        nome = nome;
    }
};

main(){
    // chama construtor da classe
    Aluno a1(1, "sammya"); 

    // cria uma alocacao de memoria e o endereco da alocacao é atribuido a um ponteiro
    Aluno *a2 = new Aluno(2, "joao");
}