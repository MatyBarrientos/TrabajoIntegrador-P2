#include "ArchivoProducto.h"
#include <cstring>

ArchivoProducto::ArchivoProducto()
{
    strcpy(_nombreArchivo,"ArchivoProducto.dat");
}
ArchivoProducto::ArchivoProducto(const char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}

bool ArchivoProducto::Guardar(const Producto& producto)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr)
    {
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProducto::ModificarRegistro(const Producto& producto, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoProducto::BajaRegistro()
{
    int IDProducto;
    Producto producto;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        return false;
    }
    cout<<"Ingrese el número de ID del producto: ";
    cin>>IDProducto;
    int pos=Buscar(IDProducto);
    if(pos==-1)
    {
        cout<<"No hay Producto con esa ID.";
        fclose(pArchivo);
        return false;
    }
    producto=Leer(pos);
    producto.setEstado(false);
    bool resultado=ModificarRegistro(producto,pos);
    fclose(pArchivo);
    if(resultado)
    {
        cout<<"El producto fue dado de Baja";
    }
    else
    {
        cout << "Error al modificar el registro del Producto." << endl;
    }
    return resultado;
}

int ArchivoProducto::Buscar(int IDProducto)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo))
    {
        if(producto.getIdProducto() == IDProducto)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Producto ArchivoProducto::Leer(int posicion)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return Producto();
    }
    Producto producto;
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return producto;
}

int ArchivoProducto::CantidadRegistros()
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProducto::Leer(int cantidadRegistros, Producto *vector)
{
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Producto), 1, pArchivo);
    }
    fclose(pArchivo);
}



ArchivoProducto::~ArchivoProducto()
{
    //dtor
}
