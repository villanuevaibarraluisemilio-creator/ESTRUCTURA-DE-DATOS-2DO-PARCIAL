#include <iostream>
using namespace std;

class ListaEstatica {
private:
    int arr[100];
    int n;

public:
    ListaEstatica() { n = 0; }

    void insertar(int val) {
        arr[n++] = val;
    }

    void mostrar() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    ListaEstatica l;
    l.insertar(10);
    l.insertar(20);
    l.insertar(30);
    l.mostrar();
}
