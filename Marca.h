#pragma once


class Marca
{
private:
    int _IdMarca;
    char _nombre[20];
    char _PaisOrigen[20]; //revisar clase pais
    bool _estado;
public:
    Marca();
    Marca(int idMarca, const char* nombreMarca,const char* origenP, bool estado);
    virtual ~Marca();

    void cargar();
    void mostrar();

    ///getters
    int getIdMarca();
    char* getNombre();
    char* getPaisOrigen();
    bool getEstado();

    ///setters

    void setIdMarca(int idMarca);
    void setNombre(const char* nombreMarca);
    void setPaisOrigen(const char* nombrePais);
    void setEstado(bool estado);

    int proxIDproducto ();



protected:

};

