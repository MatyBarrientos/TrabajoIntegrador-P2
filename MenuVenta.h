#pragma once
#include "Cliente.h"

class MenuVenta
{
    public:
        MenuVenta();
        virtual ~MenuVenta();

        //void venta();
        Cliente ObtenerCliente();
        void realizarVenta(int IDVendedor);

        void mostrarDetallesVenta();

    protected:

    private:
};

