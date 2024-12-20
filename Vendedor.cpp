#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include "Funciones.h"
#include <iostream>
#include <cstring>
using namespace std;

Vendedor::Vendedor() {
    //ctor
}

Vendedor::~Vendedor() {
    _nivelAcceso=1;
    _IdVendedor=0;
    strcpy(_password,"vacio");
}

Vendedor::Vendedor(Persona persona, int nivelAcceso, int IDvendedor):Persona(persona) {
    _nivelAcceso=nivelAcceso;
    _IdVendedor=IDvendedor;
}
Vendedor::Vendedor(Persona persona):Persona(persona) {
}


void Vendedor::mostrar() {
    Persona::mostrar();
    cout<<"Nivel de acceso: "<< _nivelAcceso<<endl;
    cout<<"ID Vendedor: "<< _IdVendedor<<endl;
}

void Vendedor::cargar(int DNI) {
    Persona::cargar(DNI);
    _IdVendedor=IdVendedor();
    cout<<"Nivel de acceso: ";
    cin>>_nivelAcceso;
    fflush(stdin);
    cout<<"Password: ";
    cargarCadena(_password,19);
}
void Vendedor::cargar() {
    Persona::cargar();
    cout<<"Nivel de acceso: ";
    cin>>_nivelAcceso;
    fflush(stdin);
    _IdVendedor=IdVendedor();
    cout<<"Password: ";
    cargarCadena(_password,19);
}
void Vendedor::cargarVendedor() {
    Persona::cargar();
    _IdVendedor=IdVendedor();
    cout<<"Nivel de acceso: ";
    cin>>_nivelAcceso;
    fflush(stdin);
    cout<<"Password: ";
    cargarCadena(_password,19);
}

void Vendedor::modificarVendedor() {
    cout<<"ID vendedor: "<<_IdVendedor<<endl;
    Persona::cargar();
    cout<<"Nivel de acceso: ";
    cin>>_nivelAcceso;
    fflush(stdin);
}
//getters

char* Vendedor::getNombre () {
    return Persona::getNombre();
}
char* Vendedor::getApellido () {
    return Persona::getApellido();
}
int Vendedor::getNivelUsuario () {
    return _nivelAcceso;
}
int Vendedor::getIdVendedor () {
    return _IdVendedor;
}
int Vendedor::getIdUsuario () {
    return Persona::getDNI();
}
bool Vendedor::getEstado() {
    return Persona::getEstado();
}
char* Vendedor::getPassword(){
    return _password;
}
string Vendedor::getFecha(){
return Persona::getFecha().getFechaCompleta();}

//setters


void Vendedor::setNivelUsuario(int nivelUsuario) {
    _nivelAcceso=nivelUsuario;
}
void Vendedor::setIdVendedor(int IDvendedor) {
    _IdVendedor=IDvendedor;
}
void Vendedor::setEstado(bool estado) {
    Persona::setEstado(estado);
}
void Vendedor::setPassword(char* pass){
    strcpy(_password,pass);
}
///////////////
void Vendedor::modificarNombre() {
    char aux[50];
    system("cls");

    cout<<"Nombre actual: "<<Persona::getNombre()<<endl;
    cout<<"Ingrese el nuevo Nombre:";
    cargarCadena(aux,49);
    Persona::setNombre(aux);
    cout<<"Cambios realizados"<<endl;
}

void Vendedor::modificarApellido() {
    char aux[50];
    system("cls");

    cout<<"Apellido actual: "<<Persona::getApellido()<<endl;
    cout<<"Ingrese el nuevo Apellido:";
    cargarCadena(aux,49);
    Persona::setApellido(aux);

    cout<<"Cambios realizados"<<endl;
}
void Vendedor::modificarNivel() {
    int opc;
    int aNivel=getNivelUsuario();
    if (aNivel==2) {
        cout<<"El nivel de acceso es Administrador "<<aNivel<<endl;
        cout<<"Desea cambiarlo a No Adminitrador? (SI-1 || NO-2)"<<endl;
        cin>>opc;
        fflush(stdin);
        if(opc==1) {
            setNivelUsuario(1);
            cout<<"Acceso administrador quitado."<<endl;
        } else {
            cout<<"Registro sin modificar."<<endl;
        }
    } else {
        cout<<"Su nivel de acceso es: "<<aNivel<<endl;
        cout<<"Desea cambiarlo a Adminitrador? (SI-1 || NO-2):"<<endl;
        cin>>opc;
        fflush(stdin);
        if(opc==1) {
            setNivelUsuario(2);
            cout<<"Acceso administrador concedido."<<endl;
        } else {
            cout<<"Registro sin modificar."<<endl;
        }
    }
}

////
int Vendedor::IdVendedor () {
    ArchivoVendedor aVendedor;
    int pos, nuevoID;
    pos=aVendedor.CantidadRegistros(); ///OBTENEMOS CUANTO REGISTROS TIENE EL ARCHIVO
    if(pos==0) { /// PREGUNTAMOS SI NO HAY REGISTROS EN EL ARCHIVO
        cout<<"Ingresar el primer ID: ";
        cin>>nuevoID;
        fflush(stdin);
        return nuevoID; ///RETORNAMOS EL 1ER ID INGRESADO POR TECLADO
    } else {
        Vendedor aux; ///OBJ PRODUCTO AUXILIAR
        aux=aVendedor.Leer(pos-1); /// OBTENEMOS EL ULTIMO REGISTRO
        nuevoID=aux.getIdVendedor(); /// OBTENEMOS EL ULTIMO ID UTILIZADO
        nuevoID++; ///LO INCREMENTAMOS
        return nuevoID; ///RETORNAMOS EL SIGUIENTE ID
    }
}
