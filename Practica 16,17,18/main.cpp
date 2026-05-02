#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    Persona() : nombre(""), edad(0) {}
    Persona(string n, int e) : nombre(n), edad(e) {}

    bool operator>(const Persona& p) const { return edad > p.edad; }
    bool operator<(const Persona& p) const { return edad < p.edad; }
    bool operator<=(const Persona& p) const { return edad <= p.edad; }
};

class OrdenadorDirecto {
public:
    void burbuja(vector<Persona>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
    }

    void mergeSort(vector<Persona>& a, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    void quickSort(vector<Persona>& a, int low, int high) {
        if (low < high) {
            int pi = partition(a, low, high);
            quickSort(a, low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    }

private:
    void merge(vector<Persona>& a, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<Persona> L, R;

        for (int i = 0; i < n1; i++) L.push_back(a[l + i]);
        for (int j = 0; j < n2; j++) R.push_back(a[m + 1 + j]);

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
            a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

        while (i < n1) a[k++] = L[i++];
        while (j < n2) a[k++] = R[j++];
    }

    int partition(vector<Persona>& a, int low, int high) {
        Persona pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);
        return i + 1;
    }
};

void mostrar(const vector<Persona>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i].nombre << " - " << v[i].edad << endl;
    }
    cout << "\n\n\n";
}

int main() {
    vector<Persona> personas;
    personas.push_back(Persona("Adan", 100));
    personas.push_back(Persona("Santiago", 19));
    personas.push_back(Persona("Emilio", 30));
    personas.push_back(Persona("Carlos", 50));

    OrdenadorDirecto ord;

    cout << "Original:\n";
    mostrar(personas);

    ord.quickSort(personas, 0, personas.size() - 1);

    cout << "Ordenado por edad:\n";
    mostrar(personas);
    
    cout << "Se ocupan los metodos burbuja, quick sort y merge sort en el proyecto \n";

    return 0;
}
