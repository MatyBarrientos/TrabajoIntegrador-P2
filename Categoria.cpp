#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
#include <limits>

///CONSTRUCTORES
Categoria::Categoria() {
    strcpy(_nombre,"Sin nombre");
    _IdCategoria=1;
    strcpy(_descripcion,"Sin descripcion");
    _estado=true;
}
Categoria::Categoria(const char* nombre, int idCateg, const char* descripcion, bool estado) {
    strcpy(_nombre,nombre);
    _IdCategoria=idCateg;
    strcpy(_descripcion,descripcion);
    _estado=true;
}
///SETTERS
void Categoria::setNombre(const char* nombreCat) {
    strcpy(_nombre,nombreCat);
}
void Categoria::cargar() {
    _IdCategoria=proxID();
    cout<<"ID de la Categoria: "<<_IdCategoria<<endl;
    cout<<"Nombre de la Categoria: ";
    cargarCadena(_nombre,49);
}
void Categoria::mostrar() {
    cout<<"ID de la Categoria: "<<_IdCategoria<<endl;
    cout<<"Nombre de la Categoria: "<<_nombre<<endl;
}
int Categoria::proxID () {
    ArchivoCategoria archivoC;
    int pos, nuevoID;
    pos=archivoC.CantidadRegistros();
    if(pos==0) {
        cout<<"Ingresar el primer ID de categoria: ";
        cin>>nuevoID;

        return nuevoID;
    } else {
        Categoria aux;
        aux=archivoC.Leer(pos-1);
        nuevoID=aux.getID();
        nuevoID++;
        return nuevoID;
    }
}
/*void Categoria::setGenerico() {
    strcpy(_nombre,"Generico");
    _IdCategoria=1;
    strcpy(_descripcion,"Sin descripcion");
    _estado=true;
}*/

void Categoria::setDescripcion(const char* descripcionCat) {
    strcpy(_descripcion,descripcionCat);
}
void Categoria::setEstado(bool estadoCat) {
    _estado=estadoCat;
}


///GETTERS
char* Categoria::getNombre() {
    return _nombre;
}
int Categoria::getID() {
    return _IdCategoria;
}
char* Categoria::getDescripcion() {
    return _descripcion;
}
bool Categoria::getEstado() {
    return _estado;
}



Categoria::~Categoria() {
    //dtor
}
