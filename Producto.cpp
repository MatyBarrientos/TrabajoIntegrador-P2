#include "Producto.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>


///CONSTRUCTORES
Producto::Producto(){
    _IdProducto=_IdMarca=_Idcategoria=_stock=-1;
    strcpy(_detalle,"sin detalle");
    _precio=-1;
    _estado=0;
    ///LES PUSE -1 A LOS VALORES DEL CONSTRUCTOR QUE NO RECIBE PARAMETROS
}
Producto::Producto(int idArt, const char* detalle, int idMarca, int idCat, float precio,int stock,bool estado){
    _IdProducto=idArt;
    strcpy(_detalle,detalle);
    _IdMarca=idMarca;
    _Idcategoria=idCat;
    _precio=precio;
    _stock=stock;
    _estado=estado;
}
///CARGAR Y MOSTRAR
void Producto::cargarProducto(){
    cout<<"Ingresar: "<<endl;
    cout<<"ID del producto: ";
    cin>>_IdProducto;
    cout<<"Detalle del producto: ";
    cargarCadena(_detalle,49);
    cout<<"ID de la marca: ";
    cin>>_IdMarca;
    cout<<"ID de la categoria: ";
    cin>>_Idcategoria;
    cout<<"Precio: $";
    cin>>_precio;
    cout<<"Stock: ";
    cin>>_stock;
    _estado=true;
}
void Producto::mostrarProducto (){
    cout<<"*******************************************"<<endl;
    cout<<"ID del articulo: "<<_IdProducto<<endl;
    cout<<"Detalle del producto: "<<_detalle<<endl;
    cout<<"ID de marca: "<<_IdMarca<<endl;
    cout<<"ID de categoria: "<<_Idcategoria<<endl;
    cout<<"Precio: $"<<_precio<<endl;
    cout<<"stock: "<<_stock<<endl;
    cout<<"Estado: "<<_estado<<endl;
}
///SETTERS
void Producto::setIdProducto(int idProducto){_IdProducto=idProducto;}
void Producto::setDetalle(const char* descripcion){strcpy(_detalle,descripcion);}
void Producto::setIdMarca(int marca){_IdMarca=marca;}
void Producto::setIdCategoria(int categoria){_Idcategoria=categoria;}
void Producto::setPrecioVenta(float precioVenta){_precio=precioVenta;}
void Producto::setStock(int stock){_stock=stock;}
void Producto::setEstado(bool estado){_estado=estado;}

///GETTERS
int   Producto::getIdProducto(){return _IdProducto;}
char* Producto::getDetalle(){return _detalle;}
int   Producto::getIdMarca(){return _IdMarca;}
int   Producto::getIdCategoria(){return _Idcategoria;}
float Producto::getPrecioVenta(){return _precio;}
int   Producto::getStock(){return _stock;}
bool  Producto::getEstado(){return _estado;}


///DESTRUCTOR
Producto::~Producto()
{
}


