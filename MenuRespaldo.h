#pragma once

class MenuRespaldo
{
    public:
        ///CONSTRUCTOR
        MenuRespaldo();

        ///OPCIONES DE CLIENTE
        void OpcionCliente();///EXPORTAR A .DAT Y .CSV

        ///OPCIONES DE VENDEDOR
        void OpcionVendedor();///EXPORTAR A .DAT Y .CSV

        ///OPCIONES DE PRODUCTO
        void OpcionProducto();///EXPORTAR MARCA Y CATEGORIA A .DAT Y .CSV

        ///DESTRUCTOR
        virtual ~MenuRespaldo();
    protected:

    private:
};
