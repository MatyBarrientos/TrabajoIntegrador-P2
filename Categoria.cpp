#include "Categoria.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>

///CONSTRUCTORES
Categoria::Categoria(){
    strcpy(_nombre,"Sin nombre");
    _IdCategoria=-1;
    strcpy(_descripcion,"Sin descripcion");
    _estado=false;
}
Categoria::Categoria(const char* nombre, int idCateg, const char* descripcion, bool estado){
    strcpy(_nombre,nombre);
    _IdCategoria=idCateg;
    strcpy(_descripcion,descripcion);
    _estado=true;
}
///SETTERS
void Categoria::setNombreCat(const char* nombreCat){strcpy(_nombre,nombreCat);}
void Categoria::setIdCat(int idCategoria){_IdCategoria=idCategoria;}
void Categoria::setDescripcionCat(const char* descripcionCat){strcpy(_descripcion,descripcionCat);}
void Categoria::setEstadoCat(bool estadoCat){_estado=estadoCat;}






Categoria::~Categoria()
{
    //dtor
}
