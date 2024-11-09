#include "Vendedor.h"
#include <iostream>
#include <cstring>
using namespace std;

Vendedor::Vendedor()
{
    //ctor
}

Vendedor::~Vendedor()
{
    _nivelAcceso=-1;
    _IdVendedor=-1;
}

Vendedor::Vendedor(Persona persona, int nivelAcceso, int IDvendedor):Persona(persona)
{
    _nivelAcceso=nivelAcceso;
    _IdVendedor=IDvendedor;
}


void Vendedor::mostrar()
{
    Persona::mostrar();
    cout<<"Nivel de acceso: "<< _nivelAcceso<<endl;
    cout<<"ID Vendedor: "<< _IdVendedor<<endl;
}

void Vendedor::cargar()
{
    Persona::cargar();
    cout<<"Nivel de acceso: ";
    cin>>_nivelAcceso;
    cout<<"ID Vendedor: ";
    cin>>_IdVendedor;
}

//getters

char* Vendedor::getNombre ()
{
    return Persona::getNombre();
}
char* Vendedor::getApellido ()
{
    return Persona::getApellido();
}
int Vendedor::getNivelUsuario ()
{
    return _nivelAcceso;
}
int Vendedor::getIdVendedor ()
{
    return _IdVendedor;
}
int Vendedor::getIdUsuario ()
{
    return Persona::getDNI();
}
bool Vendedor::getEstado()
{
    return Persona::getEstado();
}

//setters


void Vendedor::setNivelUsuario(int nivelUsuario)
{
    _nivelAcceso=nivelUsuario;
}
void Vendedor::setIdVendedor(int IDvendedor)
{
    _IdVendedor=IDvendedor;
}
void Vendedor::setEstado(bool estado)
{
    Persona::setEstado(estado);
}
