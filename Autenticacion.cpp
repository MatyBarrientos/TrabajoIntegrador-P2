#include "Autenticacion.h"
#include <iostream>
using namespace std;

Autenticacion::Autenticacion()
{
    //ctor
}
bool Autenticacion::ingresarSistema()
{
    int IDVendedor;
    ArchivoVendedor archivoVendedor("ArchivoVendedor.dat");

    while (true)
    {
        cout << "Ingrese su IDVendedor: ";
        fflush(stdin);
        cin >> IDVendedor;

        if (IDVendedor == 0)
        {
            cout << "Ingreso cancelado."<<endl;
            return false;
        }

        int pos = archivoVendedor.Buscar(IDVendedor);
        if( IDVendedor==9999)
        {
            cout << "Bienvenido al modo de Prueba Administrador"  << endl;
            usuarioEncontrado = true;
            adminEncontrado = true;
            return true;

        }
        if( IDVendedor==8888)
        {
            cout << "Bienvenido al modo de Prueba"  << endl;
            usuarioEncontrado = true;
            return true;

        }
        else if (pos != -1)
        {
            vendedorActual = archivoVendedor.Leer(pos);
            cout << "Bienvenido " << vendedorActual.getApellido() << " " << vendedorActual.getNombre() << endl;
            usuarioEncontrado = true;
            return true;
        }
        else
        {
            cout << "Usuario no encontrado. "<<endl;
            cout << "Por favor Intente nuevamente. "<<endl;
            system("pause");
            system("cls");
        }
    }
}

bool Autenticacion::nivelAcceso()
{
    if (usuarioEncontrado && (vendedorActual.getNivelUsuario()==2 || adminEncontrado))
    {
        return true;
    }
    else if (usuarioEncontrado)//no es admin
    {
        return false;
    }
    else
    {
        return false;
    }
}

Autenticacion::~Autenticacion()
{
    //dtor
}
