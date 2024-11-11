#include "Producto.h"
#include "Marca.h"
#include "ArchivoMarca.h"
#include "ArchivoCategoria.h"
#include "Categoria.h"
#include "ArchivoProducto.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>
#include <limits>


///CONSTRUCTORES
Producto::Producto() {
    _IdProducto=_IdMarca=_Idcategoria=_stock=-1;
    strcpy(_detalle,"sin detalle");
    _precio=-1;
    _estado=0;
    ///LES PUSE -1 A LOS VALORES DEL CONSTRUCTOR QUE NO RECIBE PARAMETROS
}
Producto::Producto(int idArt, const char* detalle, int idMarca, int idCat, float precio,int stock,bool estado) {
    _IdProducto=idArt;
    strcpy(_detalle,detalle);
    _IdMarca=idMarca;
    _Idcategoria=idCat;
    _precio=precio;
    _stock=stock;
    _estado=estado;
}
///CARGAR Y MOSTRAR
void Producto::cargarProducto(int nuevoID) {
    ArchivoMarca Amarca;
    ArchivoCategoria Acategoria;
    _IdProducto=nuevoID;
    cout<<endl;
    cout<<"Ingresar: "<<endl;
    cout<<"ID del producto: "<<_IdProducto<<endl;
    cout<<"Detalle del producto: ";
    cargarCadena(_detalle,49);
    Amarca.mostrarCargaMarca();
    _IdMarca=Amarca.CargaMarcaID();
    cout<<"ID de la Marca: "<<_IdMarca<<endl;
    Acategoria.mostrarCargaCategoria();
    _Idcategoria=Acategoria.CargaCategoriaID();
    cout<<"ID del producto: "<<_Idcategoria<<endl;
    cout<<"Precio: $";
    cin>>_precio;
    fflush(stdin);
    cout<<"Stock: ";
    fflush(stdin);
    cin>>_stock;
    _estado=true;
}
void Producto::mostrarProducto () {
    cout<<"ID del articulo: "<<_IdProducto<<endl;
    cout<<"Detalle del producto: "<<_detalle<<endl;
    cout<<"ID de marca: "<<_IdMarca<<endl;
    cout<<"ID de categoria: "<<_Idcategoria<<endl;
    cout<<"Precio: $"<<_precio<<endl;
    cout<<"stock: "<<_stock<<endl;
    cout<<"Estado: "<<_estado<<endl;

}
void Producto::modificarProducto() { ///(OPC 5)
    cout<<endl;
    cout<<"Modificar: "<<endl;
    cout<<"ID del producto: "<<_IdProducto<<endl;
    cout<<"Detalle del producto: ";
    cargarCadena(_detalle,49);
    cout<<"ID de la marca: "<<endl;
    cout<<"1-PEDIGREE. / "<<"2-PROPLAN. / "<<"3-RAZA."<<endl;
    cout<<"4-ROYAL CANIN. / "<<"5-WHISKAS. /"<<"6-KONGO."<<endl;
    cin>>_IdMarca;
    cout<<"ID de la categoria: "<<endl;
    cout<<"1-ALIMENTO PARA PERROS. / "<<"2-ALIMENTO PARA GATOS."<<endl;
    cout<<"3-PRODUCTOS DE LIMPIEZA. / "<<"4-ALIMENTOS. /"<<endl;
    cin>>_Idcategoria;
    cout<<"Precio: $";
    cin>>_precio;
    fflush(stdin);
    cout<<"Stock: ";
    cin>>_stock;
    fflush(stdin);
}

void Producto::mostrarProductoVenta(int IDMarca, int IDCategoria) {
    cout<<"ID Articulo-> "<<getIdProducto()<<" | Producto-> "<<getDetalle()<<" | Precio -> "<<getPrecioVenta()<<" |Stock-> "<<getStock()<<endl;
}
///Fue el original, se re utilizó para ventas IDVendedores.
int Producto::proxIDproducto () { ///RECIBE EL ARCHIVO PRODUCTO
    ArchivoProducto archivoP;
    int pos, nuevoID;
    pos=archivoP.CantidadRegistros(); ///OBTENEMOS CUANTO REGISTROS TIENE EL ARCHIVO
    if(pos==0) { /// PREGUNTAMOS SI NO HAY REGISTROS EN EL ARCHIVO
        cout<<"Ingresar el primer ID de productos: ";
        cin>>nuevoID;
        fflush(stdin);
        return nuevoID; ///RETORNAMOS EL 1ER ID INGRESADO POR TECLADO
    } else {
        Producto aux; ///OBJ PRODUCTO AUXILIAR
        aux=archivoP.Leer(pos-1); /// OBTENEMOS EL ULTIMO REGISTRO
        nuevoID=aux.getIdProducto(); /// OBTENEMOS EL ULTIMO ID UTILIZADO
        nuevoID++; ///LO INCREMENTAMOS
        return nuevoID; ///RETORNAMOS EL SIGUIENTE ID
    }
}

///SETTERS
void Producto::setIdProducto(int idProducto) {
    _IdProducto=idProducto;
}
void Producto::setDetalle(const char* descripcion) {
    strcpy(_detalle,descripcion);
}
void Producto::setIdMarca(int marca) {
    _IdMarca=marca;
}
void Producto::setIdCategoria(int categoria) {
    _Idcategoria=categoria;
}
void Producto::setPrecioVenta(float precioVenta) {
    _precio=precioVenta;
}
void Producto::setStock(int stock) {
    _stock=stock;
}
void Producto::setEstado(bool estado) {
    _estado=estado;
}

///GETTERS
int   Producto::getIdProducto() {
    return _IdProducto;
}
char* Producto::getDetalle() {
    return _detalle;
}
int   Producto::getIdMarca() {
    return _IdMarca;
}
int   Producto::getIdCategoria() {
    return _Idcategoria;
}
float Producto::getPrecioVenta() {
    return _precio;
}
int   Producto::getStock() {
    return _stock;
}
bool  Producto::getEstado() {
    return _estado;
}


///DESTRUCTOR
Producto::~Producto() {
}


