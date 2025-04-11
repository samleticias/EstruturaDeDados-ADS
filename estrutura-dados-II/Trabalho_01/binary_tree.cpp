#include "binary_tree.hpp"

// Cria um nó comum de arvore e o retorna
BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree));
    newNode->left = left;
    newNode->right = right;
    newNode->item = item;

    return newNode;
}

// Questao 13.2
// Devolve o total de nós da árvore binária
int nodeCount(BinaryTree tree){
    if (tree == NULL) return 0;

    return 1 + nodeCount(tree->left) + nodeCount(tree->right);
}

// Questao 13.3
// Devolve o total de folhas da árvore binária
int leafCount(BinaryTree tree){
    if (tree == NULL) return 0;

    if (tree->left == NULL && tree->right == NULL) return 1;
    return leafCount(tree->left) + leafCount(tree->right);
}

// Questao 13.4
// Devolve a altura da árvore binária
int treeHeight(BinaryTree tree){
    if (tree == NULL) return 0;

    int leftCount = 1 + treeHeight(tree->left);
    int rightCount = 1 + treeHeight(tree->right);

    if (leftCount > rightCount) return leftCount;

    return rightCount;
}

// Questao 13.5
// Informa se a árvore binária tem o item passado na função
int treeHas(int item, BinaryTree tree){
    if (tree == NULL) return 0;

    if (item == tree->item) return 1;
    else if (item < tree->item) return treeHas(item, tree->left);
    else return treeHas(item, tree->right);
}

// Questao 13.6
// Informa se a árvore é estritamente binária
// Se cada nó na árvore é uma folha ou tem dois filhos
int treeIsStrictlyBinary(BinaryTree tree){
    // If a node is a leaf
    // Se o nó é uma folha
    if (tree->left == NULL && tree->right == NULL) return 1;

    // If there are two "sons" in a node
    // Se o nó tem dois filhos, a função chama a si mesma recursivamente para verificar se os subárvores 
    // esquerda e direita também são estritamente binárias.
    if (tree->left != NULL && tree->right != NULL){
        return treeIsStrictlyBinary(tree->left) & treeIsStrictlyBinary(tree->right);
    }

    // If it's neither a leaf or it has not two sons
    // Se o nó não é uma folha e não tem dois filhos (ou seja, tem só um filho), 
    // então a árvore não é estritamente binária, e a função retorna 0.
    return 0;
}


// Questao 13.7
// verifica se uma árvore é igual à outra
int treeEquals(BinaryTree tree1, BinaryTree tree2){
    if (tree1 == NULL && tree2 == NULL) return 1; // são iguais, vazias
    if (tree1 == NULL || tree2 == NULL) return 0;
    if (tree1->item != tree2->item) return 0;

    return 1 && treeEquals(tree1->left, tree2->left) && treeEquals(tree1->right, tree2->right);
}

// Questao 13.8
void printWeOrder(BinaryTree tree){
    if (tree == NULL) return;
    printWeOrder(tree->right);
    printf("%d\n", tree->item);
    printWeOrder(tree->left);
}

// esq raiz dir
void printTreeInOrder(BinaryTree tree){
    if (tree == NULL) return;
    printTreeInOrder(tree->left);
    printf("%d\n", tree->item);
    printTreeInOrder(tree->right);
}

// raiz esq dir
void printTreePreOrder(BinaryTree tree){
    if (tree == NULL) return;
    printf("%d\n", tree->item);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
}

// esq dir raiz
void printTreePostOrder(BinaryTree tree){
    if (tree == NULL) return;
    printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);
    printf("%d\n", tree->item);
}

// Destrói a árvore, liberando memória
void destroyTree(BinaryTree *treePtr){
    if (*treePtr == NULL) return;
    destroyTree(&(*treePtr)->left);
    destroyTree(&(*treePtr)->right);
    free(*treePtr);
    *treePtr = NULL;
}

// Insere os nós em uma árvore, de modo que ela seja uma arvore de busca binaria
void insertTreeNode(int item, BinaryTree *treePtr){
    if (*treePtr == NULL){
        *treePtr = createTreeNode(item, NULL, NULL);
    } else if (item <= (*treePtr)->item){
        insertTreeNode(item, &(*treePtr)->left);
    } else {
        insertTreeNode(item, &(*treePtr)->right);
    }
}

