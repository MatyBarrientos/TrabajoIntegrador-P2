#pragma once
#include "DetalleVenta.h"


class ArchivoDetalleVenta {
public:
    ArchivoDetalleVenta();
    ArchivoDetalleVenta(const char *nombreArchivo);
    ArchivoDetalleVenta(bool backUp);

    //bool Guardar(const DetalleVenta& detalle);
    int Guardar(const DetalleVenta& detalle);
    bool ModificarRegistro(const DetalleVenta& detalle, int posicion);
    bool BajaRegistro();
    bool AltaRegistro();
    bool CambiarEstadoRegistro();
    int Buscar(int IDFactura);
    DetalleVenta Leer(int posicion);
    int CantidadRegistros();
    void Listar();
    bool BackUp();

    int cantidadDetalles(int IDVenta);

    virtual ~ArchivoDetalleVenta();
protected:

private:
    char _nombreArchivo[50];
};

