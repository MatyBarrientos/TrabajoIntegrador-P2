#include "Factura.h"
#include "ArchivoFactura.h"
#include "DetalleVenta.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

/// NO OLVIDAR EL AUTOINCREMENTAL
/// SOBRE EL ID

///CONSTRUCTOR
Factura::Factura() {
    _nroFactura=0;
    _IdCliente=0;
    _IdVendedor=0;
    _cantidadDetalles=0;         // Número de detalles para esta factura
    _posicionDetalleInicio=0;    // Posición en DetalleVenta.dat donde inician los detalles de esta factura la idea era que los registros tengan el mismo tamaño
    _total=0;                   // tratamos de evitar los vectores dínamicos a toda costa
    Fecha _fechaVenta;
    _estado=true;
}

///SETTERS
void Factura::setNroFactura(int nFactura) {
    _nroFactura=nFactura;
}

void Factura::setIdCliente(int IDcliente) {
    _IdCliente=IDcliente;
}
void Factura::setIdVendedor(int IDvendedor) {
    _IdVendedor=IDvendedor;
}

void Factura::setEstado(bool estado) {
    _estado=estado;
}
void Factura::setCantidadDetalles(int cantidad) {
    _cantidadDetalles=cantidad;
}
void Factura::setPosicionDetalleInicio(int posicion) {
    _posicionDetalleInicio=posicion;
}

void Factura::setFechaCompra(Fecha fechaCompra) {
    _fechaVenta=fechaCompra;
}

void Factura::setTotal(float total) {
    _total=total;
}


///GETTERS
int  Factura::getNroFactura() {
    return _nroFactura;
}
int  Factura::getPosicionDetalleInicio() {
    return _posicionDetalleInicio;
}

int  Factura::getIdCliente() {
    return _IdCliente;
}
int  Factura::getIdVendedor() {
    return _IdVendedor;
}
int Factura::getCantidadDetalles() {
    return _cantidadDetalles;
}
float Factura::getTotal() {
    return _total;
}
bool  Factura::getEstado() {
    return _estado;
}
Fecha Factura::getFechaCompra() {
    return _fechaVenta;
}
///////////////

int Factura::proxID () {
    ArchivoFactura archivoFactura;
    int pos, nuevoID;
    pos=archivoFactura.CantidadRegistros();
    if(pos==0) {
        cout<<"Ingresar el primer ID de Factura: ";
        cin>>nuevoID;
        fflush(stdin);

        return nuevoID;
    } else {
        Factura aux;
        aux=archivoFactura.Leer(pos-1);
        nuevoID=aux.getNroFactura();
        nuevoID++;
        return nuevoID;
    }
}


Factura::~Factura() {
    //dtor
}
