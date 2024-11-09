#include <iostream>
#include <cstring>
using namespace std;
#include "Persona.h"
#include "Funciones.h"



Persona::Persona()
{
    strcpy(_nombre,"Joe");
    strcpy(_apellido,"Doe");
    _DNI=0;
    _estado=true;
    //_fechaNacimiento;
}
Persona::Persona(const char* nombre,const char* apellido,int dni, Fecha nacimiento,bool estado=true)
{
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    _DNI=dni;
    _estado=true;
    _fechaNacimiento.setDia(nacimiento.getDia());
    _fechaNacimiento.setMes(nacimiento.getMes());
    _fechaNacimiento.setAnio(nacimiento.getAnio());
}

void Persona::cargar()
{
    cout<<"Nombre: ";
    cargarCadena(_nombre,49);
    cout<<"Apellido: ";
    cargarCadena(_apellido,49);
    cout<<"DNI: ";
    cin>> _DNI;
    cout<<"Fecha de nacimiento: "<<endl;
    _fechaNacimiento.cargarFecha();
    //cout<<endl;
}
void Persona::cargar(int dni)
{
    setDni(dni);
    cout<<"Nombre: ";
    cargarCadena(_nombre,49);
    cout<<"Apellido: ";
    cargarCadena(_apellido,49);
    cout<<"Fecha de nacimiento: "<<endl;
    _fechaNacimiento.cargarFecha();
    //cout<<endl;
}
void Persona::mostrar()
{
    cout<<"Nombre: ";
    cout<< _nombre;
    cout<<endl;
    cout<<"Apellido: ";
    cout<< _apellido;
    cout<<endl;
    cout<<"DNI: ";
    /*cout<< _DNI;
    cout<<endl;*/
    cout<<"Fecha de nacimiento: ";
    _fechaNacimiento.mostrarFecha();

}



///Setters
void Persona::setNombre(const char name[30])
{
    strcpy(_nombre,name);
}
void Persona::setApellido(const char lastName[30])
{
    strcpy(_apellido,lastName);
}
void Persona::setDni(int ID)
{
    _DNI=ID;
}

void Persona::setEstado(bool estado)
{
    _estado=estado;
}

void Persona::setFecha(int d,int m,int a)
{
    _fechaNacimiento.setDia(d);

    _fechaNacimiento.setMes(m);

    _fechaNacimiento.setAnio(a);
}

///getters
char* Persona::getNombre()
{
    return _nombre;
}
char* Persona::getApellido()
{
    return _apellido;
}
int Persona::getDNI()
{
    return _DNI;
}
Fecha Persona::getFecha()
{
    return _fechaNacimiento;
}

bool Persona::getEstado()
{
    return _estado;
}
