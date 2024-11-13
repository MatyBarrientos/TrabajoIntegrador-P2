#include "DetalleVenta.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

///CONSTRUCTORES
DetalleVenta::DetalleVenta(){
    _IdFactura=0;
    _IdProducto=0;
    _cantidad=0;
    _precioUnitario=0;
    _subTotal=0;
}
///CARGAR/MOSTRAR

///SETTERS
void DetalleVenta::setIdFactura(int IDfactura) {
    _IdFactura=IDfactura;
}
void DetalleVenta::setIdProducto(int IDproducto) {
    _IdProducto=IDproducto;
}
void DetalleVenta::setCantidad(int cantidad) {
    _cantidad=cantidad;
}
void DetalleVenta::setPrecioUnitario(float precioUnitario) {
    _precioUnitario=precioUnitario;
}
void DetalleVenta::setSubTotal(float subTotal) {
    _subTotal=subTotal;
}

///GETTERS
int   DetalleVenta::getIdFactura() {
    return _IdFactura;
}
int   DetalleVenta::getIdProducto() {
    return _IdProducto;
}
int   DetalleVenta::getCantidad() {
    return _cantidad;
}
float DetalleVenta::getPrecioUnitario() {
    return _precioUnitario;
}
float DetalleVenta::getSubTotal() {
    return _subTotal;
}

///SOBRECARGA DE OPERADORES
void DetalleVenta::operator = (DetalleVenta aux) {
    _IdFactura=aux.getIdFactura();
    _IdProducto=aux.getIdProducto();
    _cantidad=aux.getCantidad();
    _precioUnitario=aux.getPrecioUnitario();
    _subTotal=aux.getSubTotal();
}

float DetalleVenta::calcularSubTotal() {
    return (getCantidad() * getPrecioUnitario());
}

DetalleVenta::~DetalleVenta()
{
}
