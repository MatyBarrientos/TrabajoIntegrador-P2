#include <iostream>
#include "MenuSalida.h"
#include "Funciones.h"
#include "MenuCliente.h"

using namespace std;

MenuSalida::MenuSalida() {}



void MenuSalida::mostrarMenuPrincipal(bool administrador) {
    if(administrador) {
        cout << " ***Sistema de Gestion*** "<<endl;
        cout << " 'Lo de brunillo' "<<endl;
        cout << "1 - Clientes "<<endl;
        cout << "2 - Vendedores "<<endl;
        cout << "3 - Productos "<<endl;
        cout << "4 - Ventas "<<endl;
        cout << "5 - Respaldos "<<endl;
        cout << "0 - Salir "<<endl;
        cout << " Seleccione una opcion: ";
    } else {
        cout << " ***Sistema de Gestion*** "<<endl;
        cout << " 'Lo de brunillo' "<<endl;
        cout << "1 - Clientes "<<endl;
        cout << "2 - Vendedores "<<endl;
        cout << "3 - Productos "<<endl;
        cout << "4 - Ventas "<<endl;
        cout << "0 - Salir "<<endl;
        cout << " Seleccione una opcion: ";
    }

}


///Salida de Cliente, Vendedor y Producto están todas en un método
void MenuSalida::mostrarSubMenuUno(bool administrador, const char titulo[10],const char tipo[10]) {
    if(administrador) {
        cout << " ***"<<titulo<<"*** "<<endl;
        cout << "1 - Agregar "<<tipo<< "."<<endl;
        cout << "2 - Estado "<<tipo<<". "<<endl;
        cout << "3 - Buscar "<<tipo<<". " <<endl;
        cout << "4 - Modificar "<<tipo<<". " <<endl;
        cout << "5 - Listar "<<tipo<<". " <<endl;
        cout << "0 - Volver al menú anterior "<<endl;
        cout << " Seleccione una opcion: ";
    } else {
        cout << " ***"<<titulo<<"*** "<<endl;
        cout << "1 - Buscar "<<tipo<<". " <<endl;
        cout << "2 - Mostrar listado "<<tipo<<". " <<endl;
        cout << "0 - Volver al menú anterior "<<endl;
        cout << " Seleccione una opcion: ";
    }
}

void MenuSalida::mostrarSubMenuCuatro() {
    cout << " ***Ventas*** "<<endl;
    cout << "1 - Realizar Venta "<<endl;
    cout << "2 - Buscar Venta "<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
void MenuSalida::mostrarSubMenuCinco() {
    cout << " ***Respaldos*** "<<endl;
    cout << "1 - Clientes "<<endl;
    cout << "2 - Vendedores "<<endl;
    cout << "3 - Productos "<<endl;
    cout << "4 - Ventas "<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
void MenuSalida::mostrarSubMenuCincoUno() {
    cout << " ***Respaldos*** "<<endl;
    cout << "1 - Exportar Archivo de Clientes a .dat"<<endl;
    cout << "2 - Exportar Archivo de Clientes a .csv"<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
void MenuSalida::mostrarSubMenuCincoDos() {
    cout << " ***Respaldos*** "<<endl;
    cout << "1 - Exportar Archivo de Vendedores a .dat"<<endl;
    cout << "2 - Exportar Archivo de Vendedores a .csv"<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
void MenuSalida::mostrarSubMenuCincoTres() {
    cout << " ***Respaldos*** "<<endl;
    cout << "1 - Exportar Archivo de Producto a .dat"<<endl;
    cout << "4 - Exportar Archivo de Producto a .csv"<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}

void MenuSalida::mostrarSubMenuUnoTres() {

    cout << " ***Modificar datos cliente*** "<<endl;
    cout << "1 - Modificar Nombre "<<endl;
    cout << "2 - Modificar Apellido "<<endl;
    cout << "3 - Modificar Dirección "<<endl;
    cout << "4 - Modificar Telefono "<<endl;
    cout << "5 - Modificar e-mail "<<endl;
    cout << "5 - Modificar Todo "<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
void MenuSalida::mostrarSubMenuDosTres() {

    cout << " ***Modificar datos Vendedor*** "<<endl;
    cout << "1 - Modificar Nombre "<<endl;
    cout << "2 - Modificar Apellido "<<endl;
    cout << "3 - Modificar Nivel de Acceso "<<endl;
    cout << "4 - Modificar Todo "<<endl;
    cout << "0 - Volver al menú anterior "<<endl;
    cout << " Seleccione una opcion: ";
}
///MENU PRODUCTOS -> OPC 5 LISTADOS
void MenuSalida::SubMenuListadoProducto(){
    system("cls");
    cout<<"***Listar Productos por:***"<<endl;
    cout<<"1 - Estado ACTIVO " <<endl;
    cout<<"2 - Estado BAJA " <<endl;
    cout<<"3 - CATEGORIA y MARCA " <<endl;
    cout<<"0 - Volver al menu anterior "<<endl;
    cout<<" Seleccione una opcion: ";
}



MenuSalida::~MenuSalida() {
    //dtor
}
