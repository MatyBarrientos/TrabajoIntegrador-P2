#pragma once
#include "Vendedor.h"
#include "ArchivoVendedor.h"


class MenuVendedor
{
    public:
        MenuVendedor();
        virtual ~MenuVendedor();


            ////Funciones de Carga
    bool agregarVendedor();
    bool bajaVendedor();
    bool altaVendedor();
    bool cambiarEstadoVendedor();
    Vendedor modificarVendedor(int DNI, int posicion);
    bool modificarVendedor(int DNI);
    void Listar();
    void OpcionUno();
    void OpcionDos();
    void OpcionTres();
    void OpcionCuatro();
    void OpcionCinco();
    //void OpcionSeies();
    /////////////////////
    void  modificarVendedor();

    protected:

    private:
};

