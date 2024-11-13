#pragma once
#include "Fecha.h"
#include "DetalleVenta.h"
class Factura
{
private:
    int _nroFactura;
    int _IdCliente;
    int _IdVendedor;
    int _cantidadDetalles;         // Número de detalles para esta factura
    int _posicionDetalleInicio;    // Posición en DetalleVenta.dat donde inician los detalles de esta factura la idea era que los registros tengan el mismo tamaño
    float _total;                   // tratamos de evitar los vectores dínamicos a toda costa
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
    void setIdCliente(int IDcliente);
    void setIdVendedor(int IDvendedor);
    void setCantidadDetalles(int cantidad);        // Configura la cantidad de detalles
    void setPosicionDetalleInicio(int posicion);   // Configura la posición inicial
    void setTotal(float total);
    void setEstado(bool estado);
    void setFechaCompra(Fecha fechaCompra);

    ///GETTERS
    int  getNroFactura();
    int  getIdCliente();
    int  getIdVendedor();
    int getCantidadDetalles();
    int getPosicionDetalleInicio();
    float getTotal();
    bool  getEstado();
    Fecha getFechaCompra();

    ///
    float calcularTotal();
    void agregarDetalle(const DetalleVenta& detalle);
    int proxID ();



protected:

};
