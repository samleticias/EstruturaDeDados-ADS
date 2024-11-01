#include <iostream>
using namespace std;

class Node3 {
    int id;
    public:
    Node3(){
        id=2;
    }
    
    void setNode3(int i){
        id = i;
    }

    int getNode3(){
        return id;
    }
};

main(){
    Node3 a1;
    a1.setNode3(4); // id de a1 = 4
    Node3 b1;
    b1 = a1; // id de b1 = 4
    b1.setNode3(5); // id de b1 = 5
    cout << "b1.getNode3() :" << b1.getNode3() << endl; // Saída: 5
    cout << "a1.getNode3():" << a1.getNode3() << endl; // Saída: 4
}