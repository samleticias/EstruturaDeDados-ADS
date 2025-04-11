#include <string>
#include <iostream>
using namespace std;
class No{
    public:
    int matricula;
    string nome;
    No *prox;
    No(int m,string n){
        matricula = m;
        nome = n;
        prox = NULL;
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
};