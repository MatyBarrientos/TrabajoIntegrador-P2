#include "DetalleVenta.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

///CONSTRUCTORES
DetalleVenta::DetalleVenta(){
    _IdFactura=_IdProducto=_cantidad=-1;
    _precioUnitario=_subTotal=-1;
}
///CARGAR/MOSTRAR
void DetalleVenta::cargar(){
    cout<<"Ingresar:"<<endl;
    cout<<"ID de Factura (int): ";
    cin>>_IdFactura;
    cout<<"ID del producto: ";
    cin>>_IdProducto;
    cout<<"Cantidad: ";
    cin>>_cantidad;
    cout<<"Precio Unitario: $";
    cin>>_precioUnitario;
    cout<<"Subtotal: $";
    cin>>_subTotal;
}
void DetalleVenta::mostrar(){
    cout<<"----------------------------------------"<<endl;
    cout<<"ID de factura: "<<_IdFactura<<endl;
    cout<<"ID del producto: "<<_IdProducto<<endl;
    cout<<"Cantidad: "<<_cantidad<<endl;
    cout<<"Precio Unitario: "<<_precioUnitario<<endl;
    cout<<"Subtotal: "<<_subTotal<<endl;
    cout<<"----------------------------------------"<<endl;
}

///SETTERS
void DetalleVenta::setIdFactura(int IDfactura){_IdFactura=IDfactura;}
void DetalleVenta::setIdProducto(int IDproducto){_IdProducto=IDproducto;}
void DetalleVenta::setCantidad(int cantidad){_cantidad=cantidad;}
void DetalleVenta::setPrecioUnitario(float precioUnitario){_precioUnitario=precioUnitario;}
void DetalleVenta::setSubTotal(float subTotal){_subTotal=subTotal;}

///GETTERS
int   DetalleVenta::getIdFactura(){return _IdFactura;}
int   DetalleVenta::getIdProducto(){return _IdProducto;}
int   DetalleVenta::getCantidad(){return _cantidad;}
float DetalleVenta::getPrecioUnitario(){return _precioUnitario;}
float DetalleVenta::getSubTotal(){return _subTotal;}

///SOBRECARGA DE OPERADORES
void DetalleVenta::operator = (DetalleVenta aux){
    _IdFactura=aux.getIdFactura();
    _IdProducto=aux.getIdProducto();
    _cantidad=aux.getCantidad();
    _precioUnitario=aux.getPrecioUnitario();
    _subTotal=aux.getSubTotal();
}


DetalleVenta::~DetalleVenta()
{
}
