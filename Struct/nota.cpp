#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float nota1;
    float nota2;
    float nota3;

    cout << "Digite a primeira nota: ";
    cin >> nota1;
    cout << "Digite a segunda nota: ";
    cin >> nota2;
    cout << "Digite a terceira nota: ";
    cin >> nota3;

    float mediaNotas = (nota1 + nota2 + nota3) / 3.0;
    cout << fixed << setprecision(2) << "Média = " << mediaNotas << endl;
    
    return 0;
}