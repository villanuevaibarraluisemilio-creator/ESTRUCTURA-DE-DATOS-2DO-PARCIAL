#include <iostream>

using namespace std;

const int MAX = 5;
int cola[MAX];
int frente = 0;
int final = -1;
int contador = 0; 

// Función para insertar (Enqueue)
void enqueue(int valor) {
    if (contador == MAX) {
        cout << "Error: La cola esta llena." << endl;
    } else {
        final++;
        cola[final] = valor;
        contador++;
        cout << "Insertado en la cola: " << valor << endl;
    }
}

// Función para eliminar (Dequeue)
void dequeue() {
    if (contador == 0) {
        cout << "Error: La cola esta vacia." << endl;
    } else {
        cout << "Atendido/Eliminado: " << cola[frente] << endl;
        frente++;
        contador--;
    }
}

void mostrarCola() {
    if (contador == 0) {
        cout << "Cola vacia." << endl;
    } else {
        cout << "Elementos en la cola: ";
        for (int i = frente; i <= final; i++) {
            cout << "[" << cola[i] << "] ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    mostrarCola();

    dequeue(); 
    
    mostrarCola();

    return 0;
}
