#include "Cliente.h"
#include <iostream>
#include <cstring>
#include "Funciones.h"
#include <limits>
using namespace std;

Cliente::Cliente() {}



Cliente::Cliente(const Persona& persona):Persona(persona)
{
    _telefono=0;
    strcpy(_Email,"vacio");
    strcpy(_Direccion,"vacio");

}

void Cliente::mostrar()
{
    Persona::mostrar();
    cout<<"Telefono: "<< _telefono<<endl;
    cout<<"Correo electronico: "<< _Email<<endl;
    cout<<"Domicilio: "<< _Direccion<<endl;
}

void Cliente::cargar()
{
    Persona::cargar();
    cout<<"Telefono: ";
    cin>>_telefono;
    fflush(stdin);
    cout<<"Correo electronico: ";
    cin>>_Email;
    fflush(stdin);
    cout<<"Domicilio: ";
    cin>>_Direccion;
    fflush(stdin);
}
void Cliente::cargar(int dni)
{
    Persona::cargar(dni);
    cout<<"Telefono: ";
    cin>>_telefono;
    fflush(stdin);
    cout<<"Correo electronico: ";
    cin>>_Email;
    fflush(stdin);
    cout<<"Domicilio: ";
    cin>>_Direccion;
    fflush(stdin);
}

//getters
char* Cliente::getDomicilio()
{
    return _Direccion;
}
char* Cliente::getNombre()
{
    return Persona::getNombre();
}
char* Cliente::getApellido()
{
    return Persona::getApellido();
}
int Cliente::getTelefono ()
{
    return _telefono;
}
int Cliente::getIdCliente ()
{
    return Persona::getDNI();
}
bool Cliente::getEstado ()
{
    return Persona::getEstado();
}
char* Cliente::getEmail()
{
    return _Email;
}

//setters
void Cliente::setDomicilio(const char* domicilio)
{
    strcpy(_Direccion, domicilio);
}
void Cliente::setTelefono (int telefono)
{
    _telefono=telefono;
}
void Cliente::setEmail(const char* mail)
{
    strcpy(_Email,mail);
}
void Cliente::setEstado (bool estado)
{
    Persona::setEstado(estado);
}
void Cliente::setNombre (const char nombre[30])
{
    Persona::setNombre(nombre);
}
void Cliente::setApellido (const char apellido[30])
{
    Persona::setApellido(apellido);
}

void Cliente::modificarNombre()
{
    char aux[50];
    system("cls");
    fflush(stdin);
    cout<<"Nombre actual: "<<Persona::getNombre()<<endl;
    cout<<"Ingrese el nuevo Nombre:";
    cargarCadena(aux,49);
    Persona::setNombre(aux);
    cout<<"Cambios realizados"<<endl;
}

void Cliente::modificarApellido()
{
    char aux[50];
    system("cls");
    fflush(stdin);
    cout<<"Apellido actual: "<<Persona::getApellido()<<endl;
    cout<<"Ingrese el nuevo Apellido:";
    cargarCadena(aux,49);
    Persona::setApellido(aux);
    cout<<"Cambios realizados"<<endl;
}

void Cliente::modificarDireccion()
{
    char aux[50];
    system("cls");
    fflush(stdin);
    cout<<"Direccion actual: "<<getDomicilio()<<endl;
    cout<<"Ingrese la nueva direccion:";
    cargarCadena(aux,49);
    strcpy(_Direccion,aux);
    cout<<"Cambios realizados"<<endl;
}
void Cliente::modificarMail()
{
    char aux[50];
    system("cls");
    fflush(stdin);
    cout<<"e-mail actual: "<<getEmail()<<endl;
    cout<<"Ingrese la nueva direccion:";
    cargarCadena(aux,49);
    strcpy(_Email,aux);
    cout<<"Cambios realizados"<<endl;
}

void Cliente::modificarTelefono()
{
    system("cls");
    fflush(stdin);
    cout<<"Telefono actual: "<<getTelefono()<<endl;
    cout<<"Ingrese el nuevo numero:";
    cin>>_telefono;
    cout<<"Cambios realizados"<<endl;
}






Cliente::~Cliente()
{
    //dtor
}
