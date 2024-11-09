#pragma once
#include "Producto.h"


class ArchivoProducto
{
private:
    char _nombreArchivo[50];

public:
    ArchivoProducto(const char* nombreArchivo);
    ArchivoProducto();
    bool Guardar(const Producto& producto);
    bool ModificarRegistro(const Producto& producto, int posicion);
    bool BajaRegistro();
    int Buscar(int IDProducto);
    Producto Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Producto *vector);
    virtual ~ArchivoProducto();

protected:

};


