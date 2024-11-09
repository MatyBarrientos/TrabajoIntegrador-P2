#pragma once
#include "ArchivoVendedor.h"



class Autenticacion
{

public:
    Autenticacion();
    virtual ~Autenticacion();
    bool ingresarSistema();
    bool nivelAcceso();

private:
    Vendedor vendedorActual;
    bool usuarioEncontrado = false;
    bool adminEncontrado = false;
};

