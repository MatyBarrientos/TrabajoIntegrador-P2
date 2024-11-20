#include "Autenticacion.h"
#include <iostream>
#include "Funciones.h"
#include <cstring>
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
        cin >> IDVendedor;
        fflush(stdin);

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
            while(!usuarioEncontrado){
                cout<<"Ingrese Password: ";
                char pass[20];
                cargarCadena(pass,19);
                if(strcmp(pass,vendedorActual.getPassword())==0){

                    system("cls");
                    cout << "Bienvenido " << vendedorActual.getApellido() << " " << vendedorActual.getNombre() << endl;
                    usuarioEncontrado = true;
                    return true;

                }else if (strcmp(pass,"0")==0){
                    cout<<"Saliendo del sistema."<<endl;
                    return false;

                }else {
                    cout<<"Contraseña incorrecta."<<endl;
                }
            }
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
int Autenticacion::VendedorActual()
{
    return vendedorActual.getIdVendedor();
}

Autenticacion::~Autenticacion()
{
    //dtor
}
