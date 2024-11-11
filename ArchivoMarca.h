#pragma once
#include "Marca.h"


class ArchivoMarca {
public:
    ArchivoMarca();
    ArchivoMarca(const char *nombreArchivo);
    ArchivoMarca(bool backUp);
    bool Guardar(const Marca& marca);
    bool ModificarRegistro(const Marca& marca, int posicion);
    bool BajaRegistro();
    bool AltaRegistro();
    bool CambiarEstadoRegistro();
    int Buscar(int IDMarca);
    Marca Leer(int posicion);
    int CantidadRegistros();
    void Listar();
    bool BackUp();

    int CargaMarcaID();
    void mostrarCargaMarca();
    int ingresoMarca();
    void mostrarMarcas();
    void mostrarMarcasPorCategoria(int idCategoria);
    virtual ~ArchivoMarca();

protected:

private:
    char _nombreArchivo[50];
};

