#include "ArchivoVendedor.h"
#include <cstring>
#include <iostream>
using namespace std;



ArchivoVendedor::ArchivoVendedor()
{
    strcpy(_nombreArchivo,"ArchivoVendedor.dat");
}
ArchivoVendedor::ArchivoVendedor(const char* nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}

bool ArchivoVendedor::Guardar(const Vendedor& vendedor)
{

    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr)
    {
        return false;
    }
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo)==1;
    fclose(pArchivo);
    return ok;
}
bool ArchivoVendedor::ModificarRegistro(const Vendedor& vendedor, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo)==1;
    fclose(pArchivo);
    return ok;
}
bool ArchivoVendedor::BajaRegistro()
{
    int IDVendedor;
    Vendedor vendedor;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        return false;
    }
    cout<<"Ingrese el número de ID del Vendedor: ";
    cin>>IDVendedor;
    int pos=Buscar(IDVendedor);
    if(pos==-1)
    {
        cout<<"No hay vendedor con esa ID.";
        fclose(pArchivo);
        return false;
    }
    vendedor=Leer(pos);
    vendedor.setEstado(false);
    bool resultado=ModificarRegistro(vendedor,pos);
    fclose(pArchivo);
    if(resultado)
    {
        cout<<"El vendedor fue dado de Baja";
    }
    else
    {
        cout << "Error al modificar el registro del cliente." << endl;
    }
    return resultado;
}
int ArchivoVendedor::Buscar(int IDVendedor)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return -1;
    }
    Vendedor vendedor;
    int i = 0;
    while(fread(&vendedor, sizeof(Vendedor), 1, pArchivo)==1)
    {
        if(vendedor.getIdVendedor() == IDVendedor)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}
Vendedor ArchivoVendedor::Leer(int posicion)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return Vendedor();
    }
    Vendedor vendedor;
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    fread(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return vendedor;
}
int ArchivoVendedor::CantidadRegistros()
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Vendedor);
    fclose(pArchivo);
    return cantidadRegistros;
}
void ArchivoVendedor::Leer(int cantidadRegistros, Vendedor *vector)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Vendedor), 1, pArchivo);
    }
    fclose(pArchivo);
}




ArchivoVendedor::~ArchivoVendedor()
{
    //dtor
}
