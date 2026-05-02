#include <iostream>
#include <string>

using namespace std;

const int TAM = 3; 

struct AutoStruct {
    float precio;
    int anio;
};

class PersonaClass {
private:
    string nombre, ap, am, genero;
    int edad;
public:
    void pedirDatos() {
        cout << "Nombre: "; cin >> nombre;
        cout << "Ap. Paterno: "; cin >> ap;
        cout << "Ap. Materno: "; cin >> am;
        cout << "Genero: "; cin >> genero;
        cout << "Edad: "; cin >> edad;
    }
    void mostrar() {
        cout << "Persona -> " << nombre << " " << ap << " " << am 
             << " (" << genero << ") " << edad << " anos" << endl;
    }
};

int main() {
   
    AutoStruct listaAutos[TAM];
    PersonaClass listaPersonas[TAM];


    PersonaClass *ptrPersonas = listaPersonas;

    cout << " CAPTURA DE " << TAM << " COCHES (STRUCTS) " << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "\nAuto #" << i + 1 << ":" << endl;
        cout << "Precio: "; cin >> listaAutos[i].precio;
        cout << "Ano: "; cin >> listaAutos[i].anio;
    }

    cout << "\n CAPTURA DE " << TAM << " PERSONAS (OBJETOS - INDIRECTO) " << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "\nPersona #" << i + 1 << ":" << endl;
        (ptrPersonas + i)->pedirDatos();  
    }

    cout << "\n\n LISTADO DE COCHES " << endl;
    for(int i = 0; i < TAM; i++) {
        cout << i + 1 << ". Precio: " << listaAutos[i].precio 
             << " | Ano: " << listaAutos[i].anio << endl;
    }

    cout << "\n LISTADO DE PERSONAS (INDIRECTO) " << endl;
    for(int i = 0; i < TAM; i++) {
        cout << i + 1 << ". ";
        (ptrPersonas + i)->mostrar();  
    }

    cout << "\n ANALISIS DE MEMORIA (ARREGLOS) " << endl;
    cout << "Tamano total del arreglo de Autos: " << sizeof(listaAutos) << " bytes" << endl;
    cout << "Tamano total del arreglo de Personas: " << sizeof(listaPersonas) << " bytes" << endl;

    return 0;
}
