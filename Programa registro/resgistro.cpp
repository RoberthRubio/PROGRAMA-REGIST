#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    string nombre;
    int documento;
    Paciente* siguiente;
};

void agregarPaciente(Paciente* &inicio, Paciente* &fin, string nombre, int documento) {
    Paciente* nuevoPaciente = new Paciente;
    nuevoPaciente->nombre = nombre;
    nuevoPaciente->documento = documento;
    nuevoPaciente->siguiente = nullptr;

    if (inicio == nullptr) {
        inicio = nuevoPaciente;
        fin = nuevoPaciente;
    } else {
        fin->siguiente = nuevoPaciente;
        fin = nuevoPaciente;
    }
}

void mostrarPacientes(Paciente* inicio) {
    int i = 1;
    while (inicio != nullptr) {
        cout << i << ". Nombre: " << inicio->nombre << ", Documento: " << inicio->documento << endl;
        inicio = inicio->siguiente;
        i++;
    }
}

int main() {
    Paciente* inicio = nullptr;
    Paciente* fin = nullptr;

    int opcion = 1;
    while (opcion != 0) {
        string nombre;
        int documento;
        cout << "Ingrese el nombre del paciente (o 0 para terminar): ";
        getline(cin, nombre);
        if (nombre == "0") {
            opcion = 0;
            break;
        }
        cout << "Ingrese el numero de documento del paciente: ";
        cin >> documento;
        cin.ignore(); // Ignorar el salto de línea después de ingresar el número de documento
        agregarPaciente(inicio, fin, nombre, documento);
    }

    mostrarPacientes(inicio);

    // Liberar memoria de los nodos
    while (inicio != nullptr) {
        Paciente* nodoAEliminar = inicio;
        inicio = inicio->siguiente;
        delete nodoAEliminar;
    }

    return 0;
}
//Roberth Rubio, Jhonier Cortes.