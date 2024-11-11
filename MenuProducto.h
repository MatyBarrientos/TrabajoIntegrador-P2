#pragma once
#include "Producto.h"
#include "ArchivoProducto.h"
///(I.V)
class MenuProducto{
    private:

    public:
        ///CONSTRUCTOR
        MenuProducto();
        ///METODOS
        void agregarProducto();       ///(OPC 1)
        void cambiarEstadoProducto(); ///(OPC 2)
        void buscarProducto();        ///(OPC 3)
        void modificarProducto();     ///(OPC 4)
        void listarProducto();        ///(OPC 5)


        void filtroVenta();
        ///DESTRUCTOR
        virtual ~MenuProducto();
};
