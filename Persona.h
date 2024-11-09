#pragma once
#include "Fecha.h"



class Persona
{
private:
    char _nombre[50], _apellido[50];
    int _DNI;
    Fecha _fechaNacimiento;
    bool _estado=true;

public:
    Persona();

    Persona(const char* nombre,const char* apellido,int dni, Fecha nacimiento,bool estado);

    virtual void cargar();
    virtual void cargar(int dni);
    virtual void mostrar();

    ///Setters
    void setNombre(const char name[30]);
    void setApellido(const char lastName[30]);
    void setDni(int ID);
    void setEstado(bool estado);
    void setFecha(int d,int m,int a);

    ///getters
    char* getNombre();
    char* getApellido();
    int getDNI();
    bool getEstado();
    Fecha getFecha();


};
