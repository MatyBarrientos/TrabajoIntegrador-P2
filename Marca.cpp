#include "Marca.h"
#include "ArchivoMarca.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

///CONSTRUCTORES
Marca::Marca() {
    _IdMarca=1;
    strcpy(_nombre,"Generico");
    _estado=true;
}

Marca::Marca(int idMarca, const char* nombreMarca,const char* origenP, bool estado) {
    _IdMarca=idMarca;
    strcpy(_nombre,nombreMarca);
    strcpy(_PaisOrigen,origenP);
}
///CARGAR Y MOSTRAR
void Marca::cargar() {

    _IdMarca=proxID();
    cout<<"Nombre de la marca: ";
    cargarCadena(_nombre,19);
    cout<<"Pais de origen: ";
    cargarCadena(_PaisOrigen,19);
}
void Marca::mostrar() {
    cout<<"ID de la Marca: "<<_IdMarca<<endl;
    cout<<"Nombre de la marca: "<<_nombre<<endl;
    cout<<"Pais de origen: "<<_PaisOrigen<<endl;
    cout<<"Estado: "<<_estado<<endl;
}
/*void Marca::mostrarCargaMarca() {
    int contador = 0, ID, cantidad;
    char nombre[20];
    ArchivoMarca archivo;
    Marca marca;

    cantidad = archivo.CantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay marcas aún ingresadas" << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        marca = archivo.Leer(i);
        if (marca.getEstado()) {
            ID = marca.getIdMarca();
            strcpy(nombre, marca.getNombre());
            if (contador > 0) cout << " || ";
            cout << "ID " << ID << " -> " << nombre;
            contador++;
        }
    }
    cout << endl; // Añadir un salto de línea al final de la lista.
}*/
/*
int Marca::CargaMarcaID() {
    int ID, opc, cantidad;
    ArchivoMarca archivo;
    bool bandera = true;
    cantidad = archivo.CantidadRegistros();

    if (cantidad == 0) {
        cout << "Desea ingresar una nueva marca o seleccionar un ID existente? (1-SI || 2-NO): ";
        cin >> opc;
        if (opc == 1) {
            cargar();  // Método que pide datos y guarda una nueva marca.
            archivo.Guardar(*this);
            return this->_IdMarca;
        }
        else {
            while (bandera) {
                cout << "Ingrese el ID de marca: ";
                cin >> ID;
                int pos = archivo.Buscar(ID);
                if (pos != -1 && pos != -2) {
                    bandera = false;
                    return ID;
                }
                else {
                    cout << "ID no encontrado. Intente nuevamente." << endl;
                }
            }
        }
    }
    else {
        while (bandera) {
            cout << "Ingrese el ID de marca: ";
            cin >> ID;
            int pos = archivo.Buscar(ID);
            if (pos != -1 && pos != -2) {
                bandera = false;
                return ID;
            }
            else {
                cout << "ID no encontrado. Intente nuevamente." << endl;
            }
        }
    }
    return -1; // En caso de que no se encuentre o el usuario salga.
}*/


///GETTERS
int   Marca::getIdMarca() {
    return _IdMarca;
}
char* Marca::getNombre() {
    return _nombre;
}
char* Marca::getPaisOrigen() {
    return _PaisOrigen;
}
bool  Marca::getEstado() {
    return _estado;
}

///SETTERS
void Marca::setIdMarca(int idMarca) {
    _IdMarca=idMarca;
}
void Marca::setNombre(const char* nombreMarca) {
    strcpy(_nombre,nombreMarca);
}
void Marca::setPaisOrigen(const char* nombrePais) {
    strcpy(_PaisOrigen,nombrePais);
}
void Marca::setEstado(bool estado) {
    _estado=estado;
}


int Marca::proxID () {
    ArchivoMarca archivoM;
    int pos, nuevoID;
    pos=archivoM.CantidadRegistros();
    if(pos==0) {
        cout<<"Ingresar el primer IDMarca: ";
        cin>>nuevoID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nuevoID;
    } else {
        Marca aux;
        aux=archivoM.Leer(pos-1);
        nuevoID=aux.getIdMarca();
        nuevoID++;
        return nuevoID;
    }
}
Marca::~Marca() {
    //dtor
}
