#pragma once
#include "Persona.h"

class Vendedor : private Persona
{
private:
    int _nivelAcceso;
    int _IdVendedor;
    char _password[20];
public:
    Vendedor();
    Vendedor(Persona persona);
    Vendedor(Persona persona, int nivelAcceso, int IDvendedor);
    virtual ~Vendedor();


    void cargar(int DNI);
    void cargar();
    void cargarVendedor();
    void mostrar();

    //setters

    void setNivelUsuario (int nivelUsuario);
    void setIdVendedor (int IDvendedor);
    void setEstado(bool estado);
    void setPassword(char* pass);
    ///Id
    int IdVendedor();

    //getters
    int getIdUsuario();
    char* getNombre ();
    char* getApellido ();
    int getNivelUsuario ();
    int getIdVendedor ();
    bool getEstado();
    char* getPassword();
    string getFecha();

    ////modificadores
    void modificarApellido();
    void modificarNombre();
    void modificarNivel();
    void modificarVendedor();




protected:

};
