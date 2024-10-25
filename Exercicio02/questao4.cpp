#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct {
    char valor[10];
} Str;

main(){
    char valor[3] = {"um"};
    Str v = {"123"};
    int i = 0;

    while (i <= strlen(v.valor)){
        cout << i << "--" << v.valor[i] << endl;
        i++;
    }

    cout << "---------";
    int j = 0;

    while (valor[j]!='\0'){
        cout << "j =" << j << "- " << valor[j] << endl;
        j++;
    }

    cout << "valor de j: " << j << endl;
    cout << "valor de i: " << i << endl;
}

// 4.1 Considerando o código acima, qual o valor de i e j ao final do
// programa?
// Saída:
// 0--1
// 1--2
// 2--3
// 3--
// ---------j =0- u
// j =1- m
// valor de j: 2
// valor de i: 4