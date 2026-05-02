#include <iostream>
#include <list>
using namespace std;

class Lista {
private:
    list<int> lista;

public:
    void insertar(int val) {
        lista.push_back(val);
    }

    void mostrar() {
        list<int>::iterator it;
        for (it = lista.begin(); it != lista.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    Lista l;
    l.insertar(100);
    l.insertar(200);
    l.insertar(300);
    l.mostrar();
}
