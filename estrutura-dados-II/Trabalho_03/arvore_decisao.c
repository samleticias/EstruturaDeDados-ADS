#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @note Árvore de decisão aplicada à análise de crédito.
 * Cada nó representa uma pergunta sobre o perfil financeiro do cliente.
 * As respostas "sim" ou "não" direcionam para outras perguntas ou para uma decisão final.
 * 
 * @param Nó com filhos: representa uma pergunta.
 * @param Nó folha: representa uma decisão final (ex.: "Crédito aprovado").
 */

/** @brief Estrutura de um nó da árvore de decisão.
 *  @details Contém o texto da pergunta ou decisão, e os ponteiros para as respostas "sim" e "não". */
typedef struct No {
    char texto[100]; 
    struct No* sim;  
    struct No* nao;
} No;

/**
 * @brief Cria um novo nó da árvore de decisão.
 * 
 * @param texto Texto da pergunta ou decisão.
 * @return Ponteiro para o nó recém-criado.
 * 
 * @note A função utiliza malloc. É necessário liberar a memória posteriormente.
 */
No* criarNo(char texto[]) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->texto, texto);
    novo->sim = NULL;
    novo->nao = NULL;
    return novo;
}

/**
 * @brief Percorre a árvore de decisão conforme as respostas do usuário.
 * 
 * @param no Ponteiro para o nó atual.
 * 
 * @note A função faz perguntas até encontrar um nó folha, que contém a decisão final.
 */
void percorrerArvore(No* no) {
    if (no->sim == NULL && no->nao == NULL) {
        printf("Decisao: %s\n", no->texto);
        return;
    }

    char resposta;
    printf("%s (s/n): ", no->texto);
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        percorrerArvore(no->sim);
    } else {
        percorrerArvore(no->nao);
    }
}

/**
 * @brief Desenha a estrutura da árvore no terminal.
 * 
 * @param no Ponteiro para o nó atual.
 * @param nivel Nível de profundidade na árvore, usado para calcular a indentação.
 * 
 * @note A visualização ajuda a entender a estrutura lógica da árvore.
 */
void desenharArvore(No* no, int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("   ");  // Espaçamento proporcional ao nível.
    }
    printf("-> %s\n", no->texto);

    if (no->sim != NULL) {
        desenharArvore(no->sim, nivel + 1);
    }
    if (no->nao != NULL) {
        desenharArvore(no->nao, nivel + 1);
    }
}

/**
 * @note A função monta a árvore, desenha sua estrutura, executa a análise de crédito e libera a memória.
 */
int main() {
    // Decisões finais
    No* credito_aprovado = criarNo("Credito aprovado");
    No* credito_restrito = criarNo("Credito aprovado com restricoes");
    No* credito_negado = criarNo("Credito negado");

    // Sub-perguntas
    No* outros_emprestimos = criarNo("Possui outros emprestimos ativos?");
    outros_emprestimos->sim = credito_restrito;
    outros_emprestimos->nao = credito_aprovado;

    No* emprego_formal = criarNo("Possui emprego formal?");
    emprego_formal->sim = outros_emprestimos;
    emprego_formal->nao = credito_restrito;

    No* inadimplencia = criarNo("Tem historico de inadimplencia?");
    inadimplencia->sim = credito_negado;
    inadimplencia->nao = emprego_formal;

    No* renda = criarNo("Possui renda mensal superior a R$ 3.000?");
    renda->sim = inadimplencia;
    renda->nao = credito_negado;

    // Raiz da árvore
    No* analise_credito = renda;

    // Desenha a árvore
    printf("\n=== Estrutura da Arvore de Decisao ===\n");
    desenharArvore(analise_credito, 0);

    // Executa a análise de crédito
    printf("\n=== Sistema de Analise de Credito ===\n");
    percorrerArvore(analise_credito);

    // Libera a memória alocada
    free(credito_aprovado);
    free(credito_restrito);
    free(credito_negado);
    free(outros_emprestimos);
    free(emprego_formal);
    free(inadimplencia);
    free(renda);

    return 0;
}
