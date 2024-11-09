#include "Vendedor.h"
#pragma once


class ArchivoVendedor
{
private:
    char _nombreArchivo[50];

public:
    ArchivoVendedor();
    ArchivoVendedor(const char* nombreArchivo);
    ArchivoVendedor(bool backUp);
    bool Guardar(const Vendedor& vendedor);
    bool ModificarRegistro(const Vendedor& vendedor, int posicion);
    bool BajaRegistro();
    bool AltaRegistro();
    bool CambiarEstadoRegistro();
    int Buscar(int IDCliente);
    int BuscarDNI(int DNI);
    Vendedor Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Vendedor *vector);
    void Listar();
    bool BackUp();
    bool modificarNombreCliente(Vendedor& vendedor,int pos);
    virtual ~ArchivoVendedor();

protected:
};
