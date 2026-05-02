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

class Cola {
private:
    Nodo* frente;
    Nodo* fin;

public:
    Cola() {
        frente = fin = NULL; 
    }

    void enqueue(int val) {
        Nodo* nuevo = new Nodo(val);
        if (!fin) {
            frente = fin = nuevo;
        } else {
            fin->sig = nuevo;
            fin = nuevo;
        }
    }

    void dequeue() {
        if (frente) {
            Nodo* temp = frente;
            frente = frente->sig;

            if (!frente) 
                fin = NULL;

            delete temp;
        }
    }

    void mostrar() {
        Nodo* temp = frente;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->sig;
        }
        cout << endl;
    }
};

int main() {
    Cola c;
    c.enqueue(300);
    c.enqueue(200);
    c.enqueue(100);
    c.mostrar();
}
