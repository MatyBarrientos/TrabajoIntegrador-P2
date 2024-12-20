#pragma once
#include <string>
#include <cstring>
#include "Autenticacion.h"



class MenuSalida
{
public:
    MenuSalida();
    virtual ~MenuSalida();
    /// Salida por consola de los menu

    void mostrarMenuPrincipal(bool administrador);

    void mostrarSubMenuUno(bool administrador, const char titulo[10],const char tipo[10]);

    void mostrarSubMenuCuatro();

    ///MENU DE RESPALDOS
    void mostrarSubMenuCinco();///OPCION DE MENU RESPALDOS

    void mostrarSubMenuCincoUno();///OPCION UNO (CLIENTE)
    void mostrarSubMenuCincoDos();///OPCION DOS (VENDEDOR)
    void mostrarSubMenuCincoTres();///OPCION TRES (PRODUCTO)

    /// Opciones de los Menu
    void SubMenuListadoProducto();


    /////////////////////////////////
    void mostrarSubMenuUnoTres();
    void mostrarSubMenuDosTres();

    /// Opciones

protected:
    Autenticacion auth;
    bool admin;

private:

};


