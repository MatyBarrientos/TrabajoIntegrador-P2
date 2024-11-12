#pragma once


class Categoria {

private:
    char _nombre[50];
    int _IdCategoria;
    char _descripcion[50];
    bool _estado;
public:
    Categoria();
    Categoria(const char* nombre, int idCateg, const char* descripcion, bool estado);


    void mostrar();
    void cargar();

    //getters
    char* getNombre();
    int getID();
    char* getDescripcion();
    bool getEstado();


    //setters

    void setNombre(const char* nombreCat);
    void setDescripcion(const char* descripcionCat);
    void setEstado(bool estadoCat);

     int proxID();
     void setGenerico();

    virtual ~Categoria();
protected:

};
