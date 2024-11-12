#pragma once
#include "Categoria.h"


class ArchivoCategoria
{
    public:
    ArchivoCategoria();
    ArchivoCategoria(const char *nombreArchivo);
    ArchivoCategoria(bool backUp);
    bool Guardar(const Categoria& categoria);
    bool ModificarRegistro(const Categoria& categoria, int posicion);
    bool BajaRegistro();
    bool AltaRegistro();
    bool CambiarEstadoRegistro();
    int Buscar(int IDCliente);
    Categoria Leer(int posicion);
    int CantidadRegistros();
    void Listar();
    bool BackUp();
    int CargaCategoriaID();
    void mostrarCargaCategoria();
    int ingresoCategoria();
    void mostrarCategorias();


    bool modificarNombreCategoria(Categoria& categoria,int pos);
        virtual ~ArchivoCategoria();

    protected:

    private:
           char _nombreArchivo[50];
};

