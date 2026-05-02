#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* sig;

    Nodo(int d) {
        dato = d;
        sig = NULL;
    }
};

class ListaDinamica {
private:
    Nodo* cabeza;

public:
    ListaDinamica() { cabeza = NULL; }

    void insertar(int val) {
        Nodo* nuevo = new Nodo(val);
        nuevo->sig = cabeza;
        cabeza = nuevo;
    }

    void mostrar() {
        Nodo* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->sig;
        }
        cout << endl;
    }
};

int main() {
    ListaDinamica l;
    l.insertar(5);
    l.insertar(10);
    l.insertar(15);
    l.mostrar();
}
