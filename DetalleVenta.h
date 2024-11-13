#pragma once


class DetalleVenta
{
private:
    int _IdFactura;
    int _IdProducto;
    int _cantidad;
    float _precioUnitario;
    float _subTotal;
public:
    DetalleVenta();
    virtual ~DetalleVenta();
    ///CARGAR/MOSTRAR
    void cargar();
    void mostrar();

    ///GETTERS
    int getIdFactura();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getSubTotal();

    ///SETTERS
    void setIdFactura(int IDfactura);
    void setIdProducto(int IDproducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setSubTotal(float subTotal);

    ///SOBRECARGA DE OPERADORES
    void operator = (DetalleVenta aux);

    float calcularSubTotal();



protected:

};

