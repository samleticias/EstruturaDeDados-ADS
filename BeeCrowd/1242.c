#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 

typedef struct {
    char items[MAX_SIZE];
    int top;
} Pilha;

void inicializa(Pilha* p) {
    p->top = -1;
}

int estaVazia(Pilha* p) {
    return p->top == -1;
}

void push(Pilha* p, char item) {
    if (p->top < MAX_SIZE - 1) {
        p->items[++(p->top)] = item;
    }
}

char pop(Pilha* p) {
    if (!estaVazia(p)) {
        return p->items[(p->top)--];
    }
    return '\0'; 
}

char top(Pilha* p) {
    if (!estaVazia(p)) {
        return p->items[p->top];
    }
    return '\0';
}

int main() {
    char fita[MAX_SIZE];
    
    while (scanf("%s", fita) != EOF) {
        char resp[MAX_SIZE];
        int cont = 0;
        Pilha pilha;
        
        inicializa(&pilha);

        for (int i = 0; i < strlen(fita); i++) {
            if (fita[i] == 'S')
                resp[i] = 'B';
            else if (fita[i] == 'B')
                resp[i] = 'S';
            else if (fita[i] == 'C')
                resp[i] = 'F';
            else if (fita[i] == 'F')
                resp[i] = 'C';
        }
        resp[strlen(fita)] = '\0'; 

        for (int i = 0; i < strlen(fita); i++) {
            if (estaVazia(&pilha) || top(&pilha) != resp[i]) {
                push(&pilha, fita[i]);
            } else {
                while (1) {
                    if (estaVazia(&pilha)) {
                        i--;
                        break;
                    } else if (resp[i] == top(&pilha)) {
                        cont++;
                        pop(&pilha);
                        i++;
                    } else {
                        i--;
                        break;
                    }

                    if (i >= strlen(resp)) {
                        i--;
                        break;
                    }
                }
            }
        }
        
        printf("%d\n", cont);
    }

    return 0;
}