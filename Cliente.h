#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

class Cliente : private Persona
{
private:
    int _telefono;
    char _Email[30];
    char _Direccion[30];
public:

    Cliente();//a construir
    Cliente(const Persona& persona);
    virtual ~Cliente();

    void mostrar();
    void cargar();
    void cargar(int dni);


    //setters
    void setDomicilio(const char* domicilio);
    void setTelefono (int telefono);
    void setEmail(const char* mail);
    void setEstado (bool estado);
    void setNombre (const char nombre[30]);
    void setApellido (const char apellido[30]);

    //getters
    char* getDomicilio();
    char* getNombre();
    char* getApellido();
    int getTelefono ();
    int getIdCliente ();
    char* getEmail();
    bool getEstado ();

    ///modificadores

    void modificarNombre();
    void modificarApellido();
    void modificarDireccion();
    void modificarTelefono();
    void modificarMail();




};
