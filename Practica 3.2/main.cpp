#include <iostream>

using namespace std;

const int MAX = 5;
int pila[MAX];
int tope = -1;

// INSERTAR
void push(int valor) {
    if (tope == MAX - 1) {
        cout << "Error: La pila esta llena." << endl;
    } else {
        tope++;            
        pila[tope] = valor; 
        cout << "Insertado: " << valor << endl;
    }
}

// ELIMINAR (AUTOMATICO)
void pop() {
    if (tope == -1) {
        cout << "Error: La pila esta vacia." << endl;
    } else {
        cout << "Eliminado: " << pila[tope] << endl;
        tope--;
    }
}

// MOSTRAR
void mostrarPila() {
    if (tope == -1) {
        cout << "Pila vacia." << endl;
    } else {
        cout << "Contenido de la pila: ";
        for (int i = 0; i <= tope; i++) {
            cout << "[" << pila[i] << "] ";
        }
        cout << "\nTope actual: " << tope << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    mostrarPila();

    pop();
    
    mostrarPila();

    return 0;
}
