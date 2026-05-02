#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    Persona(string n, int e) : nombre(n), edad(e) {}

    bool operator>(const Persona& p) const { return edad > p.edad; }
    bool operator<(const Persona& p) const { return edad < p.edad; }
    bool operator<=(const Persona& p) const { return edad <= p.edad; }
};

class OrdenadorIndirecto {
public:
    void burbuja(vector<Persona*>& p) {
        int n = p.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (*p[j] > *p[j + 1])
                    swap(p[j], p[j + 1]);
    }

    void mergeSort(vector<Persona*>& p, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(p, l, m);
            mergeSort(p, m + 1, r);
            merge(p, l, m, r);
        }
    }

    void quickSort(vector<Persona*>& p, int low, int high) {
        if (low < high) {
            int pi = partition(p, low, high);
            quickSort(p, low, pi - 1);
            quickSort(p, pi + 1, high);
        }
    }

private:
    void merge(vector<Persona*>& p, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<Persona*> L, R;

        for (int i = 0; i < n1; i++) L.push_back(p[l + i]);
        for (int j = 0; j < n2; j++) R.push_back(p[m + 1 + j]);

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
            p[k++] = (*L[i] <= *R[j]) ? L[i++] : R[j++];

        while (i < n1) p[k++] = L[i++];
        while (j < n2) p[k++] = R[j++];
    }

    int partition(vector<Persona*>& p, int low, int high) {
        Persona* pivot = p[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (*p[j] < *pivot) {
                i++;
                swap(p[i], p[j]);
            }
        }

        swap(p[i + 1], p[high]);
        return i + 1;
    }
};

void imprimirLista(const string& titulo, const vector<Persona*>& lista) {
    cout << "--- " << titulo << " ---" << endl;

    for (size_t i = 0; i < lista.size(); i++) {
        cout << lista[i]->nombre << " (" << lista[i]->edad << ")" << endl;
    }

    cout << endl;
}

int main() {
    Persona a("Adan", 20), b("Alex", 30), c("Polo", 100), d("Emilio", 40), e("Coach", 15);

    OrdenadorIndirecto ordenador;

    vector<Persona*> listaBurbuja;
    listaBurbuja.push_back(&a);
    listaBurbuja.push_back(&b);
    listaBurbuja.push_back(&c);
    listaBurbuja.push_back(&d);
    listaBurbuja.push_back(&e);

    ordenador.burbuja(listaBurbuja);
    imprimirLista("Ordenado con Burbuja", listaBurbuja);

    vector<Persona*> listaMerge;
    listaMerge.push_back(&a);
    listaMerge.push_back(&b);
    listaMerge.push_back(&c);
    listaMerge.push_back(&d);
    listaMerge.push_back(&e);

    ordenador.mergeSort(listaMerge, 0, listaMerge.size() - 1);
    imprimirLista("Ordenado con MergeSort", listaMerge);

    vector<Persona*> listaQuick;
    listaQuick.push_back(&a);
    listaQuick.push_back(&b);
    listaQuick.push_back(&c);
    listaQuick.push_back(&d);
    listaQuick.push_back(&e);

    ordenador.quickSort(listaQuick, 0, listaQuick.size() - 1);
    imprimirLista("Ordenado con QuickSort", listaQuick);

    return 0;
}
