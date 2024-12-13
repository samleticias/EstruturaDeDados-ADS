#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* p = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (p->next != NULL) {
        p= p->next;
    }
    p->next = new_node;
    return;
}

void appendInicio(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = *head_ref;
    new_node->data = new_data;
    *head_ref = new_node;
}

// Função para imprimir a lista
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    puts("\n");
}

int main() {
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printf("Lista encadeada adicionando no final:\n");
    printList(head);

    printf("Lista encadeada adicionando no inicio:\n");
    appendInicio(&head, 0);
    appendInicio(&head, -1);
    printList(head);
    return 0;
}

// 10.1. O que será impresso ao final do programa?
// Saída: Lista encadeada:  1  2  3  4 
// Inclui cada elemento no final da lista

// 10.2. Se o algoritmo está incluindo no final da lista, faça uma função que inclua no início da lista.
// função appendInicio criada.