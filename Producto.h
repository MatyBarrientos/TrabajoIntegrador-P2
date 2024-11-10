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

    ///METODOS CARGAR/MOSTRAR
    void cargarProducto(int nuevoID);
    void mostrarProducto();
    ///MODIFICAR
    void modificarProducto(); ///(OPC 5)
    ///GENERAR ID UNICO
    //int proximoID (Producto producto,ArchivoProducto archivoP);

    ///SETTERS
    void setIdProducto(int idProducto);
    void setDetalle(const char* descripcion);
    void setIdMarca(int marca);
    void setIdCategoria(int categoria);
    void setPrecioVenta(float precioVenta);
    void setStock(int stock);
    void setEstado(bool estado);

    ///GETTERS
    int   getIdProducto();
    char* getDetalle();
    int   getIdMarca();
    int   getIdCategoria();
    float getPrecioVenta();
    int   getStock();
    bool  getEstado();

    /////
    int proxIDproducto ();

    ///DESTRUCTOR
    virtual ~Producto();

};

