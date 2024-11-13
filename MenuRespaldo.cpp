#include <iostream>
#include "MenuRespaldo.h"
#include "ArchivoCliente.h"
#include "ArchivosCSV.h"
#include "MenuSalida.h"
#include "ArchivoProducto.h"
#include "ArchivoVendedor.h"
#include "ArchivoMarca.h"

using namespace std;

///CONSTRUCTOR
MenuRespaldo::MenuRespaldo()
{
    //ctor
}

///CLIENTE
void MenuRespaldo::OpcionCliente()
{
    system("cls");

    int opc=-1;
    MenuSalida ms;
    ArchivoCliente cliente;

    while(opc != 0)
    {
        system("cls");
        ms.mostrarSubMenuCincoUno();
        cin >> opc;
        fflush(stdin);
        switch(opc)
            {
            case 1:{
                ///EXPORTAR ARCHIVO CLIENTE A .DAT
                system("cls");
                ArchivosCSV muestra("Respaldos/Cliente.dat",cliente.getEncabezados());
                muestra.escribirFilaCliente();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 2:{
                ///EXPORTAR ARCHIVO CLIENTE A .CSV
                system("cls");
                ArchivosCSV muestra("Respaldos/Cliente.csv",cliente.getEncabezados());
                muestra.escribirFilaCliente();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 0:{
                cout << "Saliendo al menu principal..." << endl;
                system("pause");
                break;
            }
            default:{
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            }
    }
}

///VENDEDOR
void MenuRespaldo::OpcionVendedor()
{
    system("cls");

    int opc=-1;
    MenuSalida ms;
    ArchivoVendedor vendedor;

    while(opc != 0)
    {
        system("cls");
        ms.mostrarSubMenuCincoDos();
        cin >> opc;
        fflush(stdin);
        switch(opc)
            {
            case 1:{
                ///EXPORTAR ARCHIVO VENDEDOR A .DAT
                system("cls");
                ArchivosCSV muestra("Respaldos/Vendedor.dat",vendedor.getEncabezados());
                muestra.escribirFilaVendedor();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 2:{
                ///EXPORTAR ARCHIVO VENDEDOR A .CSV
                system("cls");
                ArchivosCSV muestra("Respaldos/Vendedor.csv",vendedor.getEncabezados());
                muestra.escribirFilaVendedor();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 0:{
                cout << "Saliendo al menu principal..." << endl;
                system("pause");
                break;
            }
            default:{
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            }
    }
}

///PRODUCTO
void MenuRespaldo::OpcionProducto()
{
    system("cls");

    int opc=-1;
    MenuSalida ms;
    ArchivoProducto Producto;
    ArchivoMarca Marca;
    while(opc != 0)
    {
        system("cls");
        ms.mostrarSubMenuCincoTres();
        cin >> opc;
        fflush(stdin);
        switch(opc)
            {
            case 1:{
                ///EXPORTAR ARCHIVO PRODUCTO A .DAT
                system("cls");
                ArchivosCSV muestra("Respaldos/Producto.dat",Producto.getEncabezados());
                muestra.escribirFilaProducto();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 2:{
                ///EXPORTAR ARCHIVO PRODUCTO A .CSV
                system("cls");
                ArchivosCSV muestra("Respaldos/Producto.csv",Producto.getEncabezados());
                muestra.escribirFilaProducto();
                cout << "Archivo Exportado con Exito." << endl;
                system("pause");
                break;
            }
            case 0:{
                cout << "Saliendo al menu principal..." << endl;
                system("pause");
                break;
            }
            default:{
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            }
    }
}


///DESTRUCTOR
MenuRespaldo::~MenuRespaldo()
{
    //dtor
}
