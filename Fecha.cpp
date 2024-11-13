#include "Fecha.h"
#include <sstream>
#include <string>
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
    while(d< 1 || d>31){
        cout<<"ingrese un dia valido: ";
        cin>>d;
        fflush(stdin);
    }
    _dia=d;
}
void Fecha::setMes(int m)
{
    while(m< 1 || m>12){
        cout<<"ingrese un mes valido: ";
        cin>>m;
        fflush(stdin);
    }
    _mes=m;
}
void Fecha::setAnio(int a)
{
    while(a< 1900 || a>2025){
        cout<<"ingrese un anio valido: ";
        cin>>a;
        fflush(stdin);
    }
    _anio=a;
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
void Fecha::operator = (Fecha aux){
    _dia=aux.getDia();
    _mes=aux.getMes();
    _anio=aux.getAnio();

}

string Fecha::getFechaCompleta() {
    std::stringstream ss;
    ss << (getDia() < 10 ? "0" : "") << getDia() << "/"
       << (getMes() < 10 ? "0" : "") << getMes() << "/"
       << getAnio();
    return ss.str();
}

void Fecha::mostrarFecha()
{
    cout<<this->_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

void Fecha::cargarFecha()
{
    int dia, mes, anio;
    cout<<"Ingrese dia: ";
    cin>>dia;
    setDia(dia);
    fflush(stdin);
    cout<<"Ingrese mes: ";
    cin>>mes;
    setMes(mes);
    fflush(stdin);
    cout<<"Ingrese anio: ";
    cin>>anio;
    setAnio(anio);
    fflush(stdin);
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
