#pragma once
#include "Autenticacion.h"


class MenuOpciones
{
public:
    MenuOpciones();
    virtual ~MenuOpciones();

    void ingresoSistema();

    /// Opciones de los Menu
    void opcion();
    void opcionSubMenuUno();
    void opcionSubMenuDos();
    void opcionSubMenuTres();
    void opcionSubMenuCuatro();
    void opcionSubMenuCinco();

    void opcionSubMenuUnoTres();


protected:

private:
    Autenticacion auth;
    bool admin;
};

