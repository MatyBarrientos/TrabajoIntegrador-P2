#pragma once
#include "Persona.h"

class Vendedor : private Persona
{
private:

    int _nivelAcceso;
    int _IdVendedor;

public:
    Vendedor();
    Vendedor(Persona persona, int nivelAcceso, int IDvendedor);
    virtual ~Vendedor();


    void cargar();
    void mostrar();

    //setters

    void setNivelUsuario (int nivelUsuario);
    void setIdVendedor (int IDvendedor);
    void setEstado(bool estado);

    //getters
    int getIdUsuario();
    char* getNombre ();
    char* getApellido ();
    int getNivelUsuario ();
    int getIdVendedor ();
    bool getEstado();


protected:

};
