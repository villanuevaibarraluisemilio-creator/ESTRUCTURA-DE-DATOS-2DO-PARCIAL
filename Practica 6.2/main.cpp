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

class Pila {
private:
    Nodo* cima;

public:
    Pila() { cima = NULL; } 

    void push(int val) {
        Nodo* nuevo = new Nodo(val);
        nuevo->sig = cima;
        cima = nuevo;
    }

    void pop() {
        if (cima) {
            Nodo* temp = cima;
            cima = cima->sig;
            delete temp;
        }
    }

    void mostrar() {
        Nodo* temp = cima;
        while (temp) {
            cout << temp->dato << endl;
            temp = temp->sig;
        }
    }
};

int main() {
    Pila p;
    p.push(5);
    p.push(7);
    p.push(2);
    p.mostrar();
}
