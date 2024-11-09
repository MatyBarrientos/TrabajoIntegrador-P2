#pragma once
#include "Cliente.h"
#include "ArchivoCliente.h"


class MenuCliente
{
public:
    MenuCliente();
    ////Funciones de Carga
    bool agregarCliente();
    bool bajaCliente();
    bool altaCliente();
    bool cambiarEstadoCliente();
    Cliente modificarCliente(int DNI, int posicion);
    bool modificarCliente(int DNI);
    void Listar();
    void OpcionUno();
    void OpcionDos();
    void OpcionTres();
    void OpcionCuatro();
    void OpcionCinco();
    //void OpcionSeies();
    /////////////////////
    void  modificarCliente();
    virtual ~MenuCliente();

protected:

private:
};

