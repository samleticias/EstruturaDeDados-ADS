#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Estrutura do paciente
struct Paciente {
    int id;
    char nome[100];
};

// Nó da árvore AVL
struct No {
    Paciente paciente;
    int altura;
    No *esq;
    No *dir;
};

// Funções auxiliares
int altura(No *n) {
    return (n == nullptr) ? 0 : n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

No* novo_no(int id, const char nome[]) {
    No* no = (No*) malloc(sizeof(No));
    no->paciente.id = id;
    strcpy(no->paciente.nome, nome);
    no->altura = 1;
    no->esq = nullptr;
    no->dir = nullptr;
    return no;
}

No* rotacao_direita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    return x;
}

No* rotacao_esquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    return y;
}

int fator_balanceamento(No* n) {
    return (n == nullptr) ? 0 : altura(n->esq) - altura(n->dir);
}

No* inserir(No* no, int id, const char nome[]) {
    // Caso base: arvore vazia
    if (no == nullptr)
        return novo_no(id, nome);

    // Inserção recursiva: se o id for menor, insere à esquerda
    if (id < no->paciente.id)
        no->esq = inserir(no->esq, id, nome);

    // Se o id for maior, insere à direita
    else if (id > no->paciente.id)
        no->dir = inserir(no->dir, id, nome);

    // id já existe, não insere
    else
        return no;

    // Atualiza a altura do nó atual após inserção
    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    // Calcula o fator de balanceamento (diferença entre alturas das subárvores)
    int fb = fator_balanceamento(no);

    // Verifica se a árvore ficou desbalanceada 

    // Caso Esquerda-Esquerda (inserido na esquerda da subárvore esquerda)
    if (fb > 1 && id < no->esq->paciente.id)
        return rotacao_direita(no);

    // Caso Direita-Direita (inserido na direita da subárvore direita)
    if (fb < -1 && id > no->dir->paciente.id)
        return rotacao_esquerda(no);

    // Caso Esquerda-Direita (inserido na direita da subárvore esquerda)
    if (fb > 1 && id > no->esq->paciente.id) {
        no->esq = rotacao_esquerda(no->esq);     // rotaciona à esquerda o filho esquerdo
        return rotacao_direita(no);              // rotaciona à direita o próprio nó
    }

    // Caso Direita-Esquerda (inserido na esquerda da subárvore direita)
    if (fb < -1 && id < no->dir->paciente.id) {
        no->dir = rotacao_direita(no->dir);      // rotaciona à direita o filho direito
        return rotacao_esquerda(no);             // rotaciona à esquerda o próprio nó
    }

    return no;
}

void listar_em_ordem(No *raiz) {
    if (raiz != nullptr) {
        listar_em_ordem(raiz->esq);
        cout << "ID: " << raiz->paciente.id << " | Nome: " << raiz->paciente.nome << endl;
        listar_em_ordem(raiz->dir);
    }
}

No* buscar(No* raiz, int id) {
    if (raiz == nullptr || raiz->paciente.id == id)
        return raiz;
    if (id < raiz->paciente.id)
        return buscar(raiz->esq, id);
    else
        return buscar(raiz->dir, id);
}

// Menu principal
int main() {
    No* raiz = nullptr;
    int opcao, id;
    char nome[100];

    do {
        system("cls"); 

        cout << "=== MENU ===\n";
        cout << "1 - Cadastrar paciente\n";
        cout << "2 - Listar pacientes\n";
        cout << "3 - Buscar paciente\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore(); 

        switch (opcao) {
            case 1:
                cout << "\nID do paciente: ";
                cin >> id;
                cin.ignore();
                cout << "\nNome do paciente: ";
                cin.getline(nome, sizeof(nome));
                raiz = inserir(raiz, id, nome);
                cout << "\nPaciente cadastrado com sucesso!\n";
                break;

            case 2:
                cout << "\nLista de pacientes (ordenada por ID):\n";
                listar_em_ordem(raiz);
                break;

            case 3: {
                cout << "Digite o ID a buscar: ";
                cin >> id;
                No* resultado = buscar(raiz, id);
                if (resultado)
                    cout << "\nPaciente encontrado: " << resultado->paciente.nome << "\n";
                else
                    cout << "\nPaciente não encontrado.\n";
                break;
            }

            case 0:
                cout << "Saindo do sistema...\n";
                break;

            default:
                cout << "Opção inválida.\n";
        }

        if (opcao != 0) {
            cout << "\nPressione ENTER para continuar...";
            cin.ignore(); 
            cin.get();
        }

    } while (opcao != 0);

    return 0;
}