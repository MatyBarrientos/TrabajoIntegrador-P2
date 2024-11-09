#include "Vendedor.h"
#pragma once


class ArchivoVendedor
{
private:
    char _nombreArchivo[50];

public:
    ArchivoVendedor();
    ArchivoVendedor(const char* nombreArchivo);
    bool Guardar(const Vendedor& vendedor);
    bool ModificarRegistro(const Vendedor& vendedor, int posicion);
    bool BajaRegistro();
    int Buscar(int IDVendedor);
    Vendedor Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Vendedor *vector);
    virtual ~ArchivoVendedor();

protected:
};
