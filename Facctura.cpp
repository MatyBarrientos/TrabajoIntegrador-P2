#include "Factura.h"
#include "DetalleVenta.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

///CONSTRUCTOR
Factura::Factura(){
    _nroFactura=_IdCliente=_IdVendedor=_metodoPago=-1;
    _tipoFactura='X';
    _total=-1;
    _estado=false;
}
///CARGAR/MOSTRAR
void Factura::cargar(){
    cout<<"************************************"<<endl;
    cout<<"Ingresar:"<<endl;
    cout<<"Nro de factura: ";
    cin>>_nroFactura;
    cout<<"Tipo de factura: ";
    cin>>_tipoFactura;
    cout<<"ID de cliente: ";
    cin>>_IdCliente;
    cout<<"ID de vendedor: ";
    cin>>_IdVendedor;
    cout<<"Detalle de la venta: "<<endl;
    _detalle.cargar();
    cout<<"Total de la compra: $";
    cin>>_total;
    cout<<"Metodo de pago (1,2 o 3): ";
    cin>>_metodoPago;
    cout<<"Fecha: ";
    _fechaVenta.cargarFecha();
    _estado=true;
}
void Factura::mostrar(){
    cout<<"******************************************"<<endl;
    cout<<"Nro de factura: "<<_nroFactura<<endl;;
    cout<<"Tipo de factura: "<<_tipoFactura<<endl;
    cout<<"ID de cliente: "<<_IdCliente<<endl;
    cout<<"ID de vendedor: "<<_IdVendedor<<endl;
    cout<<"Detalle de la venta: "<<endl;
    _detalle.mostrar();
    cout<<"Total de la compra: "<<_total<<endl;
    cout<<"Metodo de pago (1,2 o 3): "<<_metodoPago<<endl;
    cout<<"Fecha: "<<endl;
    _fechaVenta.mostrarFecha();
    cout<<"Estado: "<<_estado<<endl;
}

///SETTERS
void Factura::setNroFactura(int nFactura){_nroFactura=nFactura;}
void Factura::setTipoFactura(char tipoFactura){_nroFactura=tipoFactura;}
void Factura::setIdCliente(int IDcliente){_IdCliente=IDcliente;}
void Factura::setIdVendedor(int IDvendedor){_IdVendedor=IDvendedor;}
void Factura::setDetalleVenta(DetalleVenta detalle){_detalle=detalle;}
void Factura::setTotal(float total){_total=total;}
void Factura::setEstado(bool estado){_estado=estado;}
void Factura::setMetodoPago(int metodoPago){_metodoPago=metodoPago;}
void Factura::setFechaCompra(Fecha fechaCompra){_fechaVenta=fechaCompra;}

///GETTERS
int  Factura::getNroFactura(){return _nroFactura;}
char Factura::getTipoFactura(){return _tipoFactura;}
int  Factura::getIdCliente(){return _IdCliente;}
int  Factura::getIdVendedor(){return _IdVendedor;}
DetalleVenta Factura::getDetalleVenta(){return _detalle;}
float Factura::getTotal(){return _total;}
bool  Factura::getEstado(){return _estado;}
int  Factura::getMetodoPago(){return _metodoPago;}
Fecha Factura::getFechaCompra(){return _fechaVenta;}


Factura::~Factura()
{
    //dtor
}
