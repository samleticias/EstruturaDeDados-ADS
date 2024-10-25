// Leia dois nomes e compare se os nomes são iguais. Se forem iguais imprima “São Iguais!”, senão
// imprima “São Diferentes”.
// OBSERVAÇÃO: Faça usando:
// string nome1;
// string nome2;
#include <iostream>
#include <string>		
using namespace std;
int main (void){
    string nome1;
    string nome2;

    if (nome1 == nome2){
        cout << "são iguais" << endl;
    } else {
        cout << "são diferentes" << endl;
    }
}