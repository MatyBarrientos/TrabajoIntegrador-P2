#pragma once
#include <cstring>
#include <iostream>

using namespace std;
///DECLARACION

class Producto
{
    private: ///ATRIBUTOS

        int _IdProducto;
        char _detalle[50];
        int _IdMarca;
        int _Idcategoria;
        float _precio;
        int  _stock;
        bool _estado;

    public: ///METODOS
        Producto();
        Producto(int nProducto,const char* detalle, int IDmarca, int IDCategoria, float precio,int stock,bool estado);

        ///AYUDAS

        void cargarProducto();
        void mostrarProducto();

        ///SETTERS

        void setIdProducto(int idProducto);
        void setDetalle(const char* descripcion);
        void setIdMarca(int marca);
        void setIdCategoria(int categoria);
        void setPrecioVenta(float precioVenta);
        void setStock(int stock);
        void setEstado(bool estado);

        ///GETTERS

        int getIdProducto();
        char* getDetalle();
        int getIdMarca();
        int getIdCategoria();
        float getPrecioVenta();
        int getStock();
        bool getEstado();

        ///DESTRUCTOR
        virtual ~Producto();

};

