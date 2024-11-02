#include <iostream>
using namespace std;

struct Node2 {
    int id;

    Node2(){
        id = 0;
    }

    void setNode2(int i){
        id = i;
    }

    int getNode2(){
        return id;
    }
};

main(){
    // Exemplo 1
    struct Node2 y1;
    struct Node2 y2;
    y1.setNode2(3); // y1 = 3
    y2 = y1; // y2 = 3
    y2.setNode2(4); // y2 = 4
    cout<<"(VALUE)y1.getNode2():"<<y1.getNode2()<<endl; // Saída: 3
    cout<<"(VALUE)y2.getNode2():"<<y2.getNode2()<<endl; // Saída: 4
    cout<<"---------------"<<endl;

    // Exemplo 2 
    struct Node2 *x = new Node2();
    struct Node2 *x2 = new Node2();
    x2 = x; // x2 vai apontar agora para o endereco do ponteiro x
    cout << "x2->getNode2():" << x2->getNode2() << endl; // id de x2 = 0
    x2->setNode2(4); // id de x2 = 4

    // os dois ponteiros estão apontando para o endereco de x e vao exibir o mesmo valor
    cout << "x2->getNode2():" << x2->getNode2() << endl; // Saída: 4
    cout << "x->getNode2():" << x->getNode2() << endl;  // Saída: 4
    cout << "---------------" << endl;

}