#pragma once
#include "Factura.h"


class ArchivoFactura
{
    private:
        char _nombreArchivo[50];
    public:
        ///CONSTRUCTORES
        ArchivoFactura();
        ArchivoFactura(const char *nombreArchivo);
        ArchivoFactura(bool backUp);
        ///METODOS
        bool BackUp();
        bool Guardar(const Factura& factura);
        int Buscar(int IDFactura);
        bool ModificarRegistro(const Factura& factura, int posicion);
        bool BajaRegistro();
        bool AltaRegistro();
        Factura Leer(int posicion);
        int CantidadRegistros();
        void Listar();

        virtual ~ArchivoFactura(); //destructor
};


