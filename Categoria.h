#pragma once


class Categoria
{

private:
    char _nombre[20];
    int _IdCategoria;
    char _descripcion[50];
    bool _estado;
public:
    Categoria();
    Categoria(const char* nombre, int idCateg, const char* descripcion, bool estado);


    void mostrar();
    void cargar();

    //getters
    char* getNombreCategoria();
    int getIdCategoria();
    char* getDescripcionCategoria();
    bool getEstadoCategoria();


    //setters

    void setNombreCat(const char* nombreCat);
    void setIdCat(int idCategoria);
    void setDescripcionCat(const char* descripcionCat);
    void setEstadoCat(bool estadoCat);

    virtual ~Categoria();
protected:

};
