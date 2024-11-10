#include "Marca.h"
#include "ArchivoMarca.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

///CONSTRUCTORES
Marca::Marca()
{
    _IdMarca=1;
    strcpy(_nombre,"Generico");
}

Marca::Marca(int idMarca, const char* nombreMarca,const char* origenP, bool estado){
    _IdMarca=idMarca;
    strcpy(_nombre,nombreMarca);
    strcpy(_PaisOrigen,origenP);
}
///CARGAR Y MOSTRAR
void Marca::cargar(){

    _IdMarca=proxIDproducto();
    cout<<"Nombre de la marca: ";
    cargarCadena(_nombre,19);
    cout<<"Pais de origen: ";
    cargarCadena(_PaisOrigen,19);
    cout<<"Estado: ";
    cin>>_estado;
}
void Marca::mostrar(){
    cout<<"ID de la Marca: "<<_IdMarca<<endl;
    cout<<"Nombre de la marca: "<<_nombre<<endl;
    cout<<"Pais de origen: "<<_PaisOrigen<<endl;
    cout<<"Estado: "<<_estado<<endl;
}

///GETTERS
int   Marca::getIdMarca(){return _IdMarca;}
char* Marca::getNombre(){return _nombre;}
char* Marca::getPaisOrigen(){return _PaisOrigen;}
bool  Marca::getEstado(){return _estado;}

///SETTERS
void Marca::setIdMarca(int idMarca){_IdMarca=idMarca;}
void Marca::setNombre(const char* nombreMarca){strcpy(_nombre,nombreMarca);}
void Marca::setPaisOrigen(const char* nombrePais){strcpy(_PaisOrigen,nombrePais);}
void Marca::setEstado(bool estado){_estado=estado;}


int Marca::proxIDproducto (){
    ArchivoMarca archivoM;
    int pos, nuevoID;
    pos=archivoM.CantidadRegistros();
    if(pos==0){
        cout<<"Ingresar el primer ID de productos: ";
        cin>>nuevoID;
        return nuevoID;
    }else{
        Marca aux;
        aux=archivoM.Leer(pos-1);
        nuevoID=aux.getIdMarca();
        nuevoID++;
        return nuevoID;
    }
}
Marca::~Marca()
{
    //dtor
}
