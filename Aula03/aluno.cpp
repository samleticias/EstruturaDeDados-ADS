#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct aluno {
    int matricula;
    string nome;
} Aluno;

Aluno turma[30];
int contador_alunos = 0;

void limparTela() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}

void exibeMenu() {
    cout << "\n========= menu de opçoes =========\n";
    cout << "> 1 - inserir aluno\n";
    cout << "> 2 - consultar aluno por matrícula\n";
    cout << "> 3 - remover aluno\n";
    cout << "> 4 - mostrar lista de alunos\n";
    cout << "> 0 - sair\n";
    cout << "===================================\n";
    cout << "escolha uma opção: ";
}

void mostrarListaAlunos() {
    cout << "\nlista de alunos:\n";
    for (int i = 0; i < contador_alunos; i++) {
        printf("\n> matrícula: %d - nome: %s\n", turma[i].matricula, turma[i].nome.c_str()); 
    }
}

bool procuraAlunoPorMatricula(int matriculaProcurada) {
    for (int i = 0; i < contador_alunos; i++) {
        if (turma[i].matricula == matriculaProcurada) {
            return true;
        }
    }
    return false;
}

void mostraAluno(int matriculaProcurada) {
    bool encontrado = false;
    for (int i = 0; i < contador_alunos; i++) {
        if (turma[i].matricula == matriculaProcurada) {
            printf("\n> matrícula: %d - nome: %s\n", turma[i].matricula, turma[i].nome.c_str());
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("\n> aluno de matrícula %d não encontrado!\n", matriculaProcurada);
    }
}

void consultarMatricula() {
    int matriculaProcurada;
    printf("\nconsultar aluno por matrícula\n\n");
    printf("matrícula do aluno: ");
    scanf("%d", &matriculaProcurada);

    if (procuraAlunoPorMatricula(matriculaProcurada)) {
        mostraAluno(matriculaProcurada);
    } else {
        printf("\nnúmero de matrícula incorreto!\n");
    }
}

void remover() {
    int matriculaProcurada, opcao;
    printf("\nremover aluno\n\n");
    printf("matrícula do aluno: ");
    scanf("%d", &matriculaProcurada);

    for (int i = 0; i < contador_alunos; i++) {
        if (turma[i].matricula == matriculaProcurada) {
            printf("\n> aluno de matrícula %d - nome: %s\n", turma[i].matricula, turma[i].nome.c_str());
            printf("\ndeseja remover o aluno (1-sim/2-não)? ");
            scanf("%d", &opcao);

            if (opcao == 1) {
                // remover o aluno deslocando os elementos do array
                for (int j = i; j < contador_alunos - 1; j++) {
                    turma[j] = turma[j + 1];
                }
                contador_alunos--; // atualiza o número de alunos
                printf("\naluno removido com sucesso!\n");
            } else {
                printf("\naluno não foi removido!\n");
            }
            return;
        }
    }
    printf("\nnúmero de matrícula incorreto!\n");
}

void inserir() {
    int opcao = 1;
    int qtd_maxima = sizeof(turma) / sizeof(turma[0]);
    printf("\n>>> inserir novo aluno <<<\n");

    while (opcao == 1 && contador_alunos < qtd_maxima) {
        printf("\nmatrícula do aluno: ");
        scanf("%d", &turma[contador_alunos].matricula);
        printf("nome: ");
        cin.ignore();
        getline(cin, turma[contador_alunos].nome);
        contador_alunos++;
        printf("\naluno inserido com sucesso!\n");

        if (contador_alunos < qtd_maxima) {
            printf("\ndeseja inserir outro aluno (1-sim/0-não)? ");
            scanf("%d", &opcao);
        } else {
            printf("\nturma cheia! não é possível inserir mais alunos\n");
        }
    }
}

int main() {
    int opcao = -1;
    while (opcao != 0) {
        exibeMenu();
        cin >> opcao;

        if (opcao == 1) inserir();
        else if (opcao == 2) consultarMatricula();
        else if (opcao == 3) remover();
        else if (opcao == 4) mostrarListaAlunos();
        else if (opcao == 0) printf("\nsaindo ...\n\n");
        else printf("\nopçao inválida!\n\n");
    }

    return 0;
}
