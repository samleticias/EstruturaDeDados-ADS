#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct no {
    int item;
    struct no *prox;
} No;

main(){
    No v[4]={{3,v+2},{1,v+3},{4,NULL},{2,v+0}};
    for (No *p=v+1; p!=NULL; p=p->prox)
    cout << p->item << endl;
}

// 6.1 o que será impresso ao final da execucao do programa?
// Saída:
// 1
// 2
// 3
// 4

