#pragma once
#include "Producto.h"

///(I.V) = Isaias Velazquez
///(M.B) = Matias Barrientos
///(B.F) = Bruno Fondati

class ArchivoProducto
{
private:
    char _nombreArchivo[50];

public:
    ///CONSTRUCTORES
    ArchivoProducto();
    ArchivoProducto(const char* nombreArchivo);
    ArchivoProducto(bool backUp);
    ///GUARDAR
    bool Guardar(Producto producto);
    bool Guardar(Producto producto, int posicion);
    ///BUSCAR
    int Buscar(int IDProducto);
    ///LEER
    Producto Leer(int posicion);
    ///CONTAR REGISTROS
    int CantidadRegistros();
    ///?
    void Leer(int cantidadRegistros, Producto *vector);
    ///LISTADO (I.V)
    void Listar();
    ///MODIFICAR REGISTRO
    bool ModificarRegistro(const Producto& producto, int posicion);

    bool BackUp();
    ///DESTRUCTOR
    virtual ~ArchivoProducto();

protected:

};


