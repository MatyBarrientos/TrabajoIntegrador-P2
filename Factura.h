#pragma once
#include "Fecha.h"
#include "DetalleVenta.h"
class Factura
{
private:
    int _nroFactura;
    char _tipoFactura;
    int _IdCliente;
    int _IdVendedor;
    DetalleVenta _detalle;
    float _total;
    int _metodoPago;
    Fecha _fechaVenta;
    bool _estado;
public:
    ///CONSTRUCOR Y DESTRUCTOR
    Factura();
    virtual ~Factura();

    ///CARGAR Y MOSTRAR
    void mostrar();
    void cargar();

    ///SETTERS
    void setNroFactura(int nFactura);
    void setTipoFactura(char tipoFactura);
    void setIdCliente(int IDcliente);
    void setIdVendedor(int IDvendedor);
    void setDetalleVenta(DetalleVenta detalle);
    void setTotal(float total);
    void setEstado(bool estado);
    void setMetodoPago(int metodoPago);
    void setFechaCompra(Fecha fechaCompra);

    ///GETTERS
    int  getNroFactura();
    char getTipoFactura();
    int  getIdCliente();
    int  getIdVendedor();
    DetalleVenta getDetalleVenta();
    float getTotal();
    bool  getEstado();
    int  getMetodoPago();
    Fecha getFechaCompra();



protected:

};

