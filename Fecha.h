#pragma once
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Fecha
{

    private:
        int _dia,_mes,_anio;
    public:
        Fecha();
        Fecha(int dia,int mes,int anio);

        void cargarFecha();
        void mostrarFecha();

        ///setters

        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        ///getters

        int getDia();
        int getMes();
        int getAnio();

        ///Metodos de ayuda
        bool esBiciesto(int anio);
        bool fechaValida(int d,int m,int a);
        ///
        void AgregarDia();
        void RestarDia();

        string getFechaCompleta();


        virtual ~Fecha();

    protected:
};
