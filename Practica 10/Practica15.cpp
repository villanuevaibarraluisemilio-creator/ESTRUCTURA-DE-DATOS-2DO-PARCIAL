#include <iostream>
#include <algorithm> 
using namespace std;

class Numeros {
private:
    int arr[5];

public:
    // Método para ingresar datos
    void ingresar() {
        cout << "Ingresa 5 numeros:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Método para suma
    int suma() {
        int s = 0;
        for (int i = 0; i < 5; i++) {
            s += arr[i];
        }
        return s;
    }

    // Método para promedio
    float promedio() {
        return (float)suma() / 5;
    }

    // Método para media (ordenando el arreglo)
    float media() {
        int temp[5];
        for (int i = 0; i < 5; i++) {
            temp[i] = arr[i];
        }

        sort(temp, temp + 5);

        // Como son 5 números, la media es el del centro
        return temp[2];
    }

    // Método para máximo
    int maximo() {
        int max = arr[0];
        for (int i = 1; i < 5; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Método para mínimo
    int minimo() {
        int min = arr[0];
        for (int i = 1; i < 5; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    // Método para mostrar resultados
    void mostrar() {
        cout << "\nResultados:\n";
        cout << "Suma: " << suma() << endl;
        cout << "Promedio: " << promedio() << endl;
        cout << "Media: " << media() << endl;
        cout << "Maximo: " << maximo() << endl;
        cout << "Minimo: " << minimo() << endl;
    }
};

int main() {
    Numeros obj;

    obj.ingresar();   // ingreso indirecto mediante método
    obj.mostrar();    // muestra todos los cálos

    return 0;
}
