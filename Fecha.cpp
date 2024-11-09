#include "Fecha.h"
#include <iostream>
using namespace std;


Fecha::Fecha()
{
    _dia=1;
    _mes=1;
    _anio=2023;
}
Fecha::Fecha(int dia,int mes,int anio)
{
    bool check=fechaValida(dia,mes,anio);
    if(check)
    {
        _dia=dia;
        _mes=mes;
        _anio=anio;
    }
    else
    {
        _dia=1;
        _mes=1;
        _anio=2023;
    }
}
///setters
void Fecha::setDia(int d)
{
    _dia=(d>= 1 && d<=31)? d : 1;
}
void Fecha::setMes(int m)
{
    _mes=(m>= 1 && m<=12)? m : 1;
}
void Fecha::setAnio(int a)
{
    _anio=(a>=0)? a : 2023;
}

///getters

int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

void Fecha::mostrarFecha()
{
    cout<<this->_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

void Fecha::cargarFecha()
{
    cout<<"Ingrese dia: ";
    cin>>_dia;
    cout<<"Ingrese mes: ";
    cin>>_mes;
    cout<<"Ingrese anio: ";
    cin>>_anio;
}

///Funciones de ayuda

bool Fecha::esBiciesto(int anio)
{
    bool biciesto=(anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    return biciesto;
}
bool Fecha::fechaValida(int d,int m,int a)
{
    bool biciesto(a);
    int diaMes[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m==2 && biciesto)
    {
        diaMes[1]=29;
    }
    bool diaCheck=(d>=1 && d<=diaMes[m-1]);
    return((diaCheck) && (m>=1 && m<=12) && (a>0));
}
///
void Fecha::AgregarDia()
{
    bool biciesto=esBiciesto(_anio);
    int diaMes[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ( biciesto)
    {
        diaMes[1]=29;
    }
    /////////////////
    if((_dia==diaMes[_mes-1]) && (_mes<12))
    {
        _dia=1;
        _mes+=1;

    }
    else if((_dia==diaMes[_mes-1]) && (_mes==12))
    {
        _dia=1;
        _mes=1;
        _anio+=1;
    }
    else
    {
        _dia+=1;
    }
}
void Fecha::RestarDia()
{
    bool biciesto=esBiciesto(_anio);
    int diaMes[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ( biciesto)
    {
        diaMes[1]=29;
    }
    /////////////////
    if((_dia==1) && (_mes==1))
    {
        _dia=31;
        _mes=12;
        _anio-=1;

    }
    else if((_dia==1) && (_mes!=1))
    {
        _dia=diaMes[_mes-2];
        _mes-=1;
    }
    else
    {
        _dia-=1;
    }
}

Fecha::~Fecha()
{
    //dtor
}
