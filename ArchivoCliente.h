#pragma once
#include "Cliente.h"

class ArchivoCliente
{
private:
    char _nombreArchivo[50];

public:
    ArchivoCliente();
    ArchivoCliente(bool backUp);
    bool Guardar(const Cliente& cliente);
    bool ModificarRegistro(const Cliente& cliente, int posicion);
    bool BajaRegistro();
    bool AltaRegistro();
    bool CambiarEstadoRegistro();
    int Buscar(int IDCliente);
    Cliente Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Cliente *vector);
    void Listar();
    bool BackUp();
    bool modificarNombreCliente(Cliente& cliente,int pos);


    virtual ~ArchivoCliente();

protected:


};
