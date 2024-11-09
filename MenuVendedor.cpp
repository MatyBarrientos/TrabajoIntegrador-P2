#include "MenuVendedor.h"
#include "MenuSalida.h"
#include "Persona.h"
#include "Vendedor.h"
#include "Cliente.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"

#include <iostream>
using namespace std;
MenuVendedor::MenuVendedor() {
    //ctor
}
bool MenuVendedor::agregarVendedor() {
    int DNI;
    ArchivoVendedor archivoVendedor;
    ArchivoCliente archivoCliente;
    fflush(stdin);

    cout<<"DNI: ";
    cin>>DNI;
    int posicionV=archivoVendedor.BuscarDNI(DNI);
    int posicionC=archivoCliente.Buscar(DNI);
    if(posicionV == -1 || posicionV == -2) {
        if(posicionC == -1 || posicionC == -2) {
            Persona persona;
            Vendedor vendedor(persona);
            vendedor.cargar(DNI);
            fflush(stdin);
            archivoVendedor.Guardar(vendedor);
            return true;
        } else {
            cout<<"Vendedor ya existente."<<endl;
            fflush(stdin);
            return false;
        }

    } else {
        cout<<"Vendedor ya existente."<<endl;
        fflush(stdin);
        return false;
    }
}
///baja lógica
bool MenuVendedor::bajaVendedor() {
    fflush(stdin);
    ArchivoVendedor archivoVendedor;
    return archivoVendedor.BajaRegistro();
}
bool MenuVendedor::altaVendedor() {
    fflush(stdin);
    ArchivoVendedor archivoVendedor;
    return archivoVendedor.AltaRegistro();
}
bool MenuVendedor::cambiarEstadoVendedor() {
    fflush(stdin);
    ArchivoVendedor archivoVendedor;
    return archivoVendedor.CambiarEstadoRegistro();
}

///////////////////
///sub opcion 1
void MenuVendedor::OpcionUno() {
    bool bandera;
    system("cls");
    cout << "Agregar Vendedor." << endl;
    bandera=agregarVendedor();
    if(bandera) {
        cout<<"Vendedor agregado"<<endl;
    }
    system("pause");
    system("cls");
}
void MenuVendedor::OpcionDos() {
    system("cls");
    cout << "Estado del vendedor." << endl;
    cambiarEstadoVendedor();
    system("pause");
    fflush(stdin);
}
void MenuVendedor::OpcionTres() {

    cout << "Buscar Vendedor." << endl;
    system("cls");
    int ID,posicion;
    fflush(stdin);
    cout<<"Ingrese el ID del vendedor a buscar: ";
    cin>>ID;
    fflush(stdin);
    ArchivoVendedor archivoVendedor;
    posicion=archivoVendedor.Buscar(ID);
    if(posicion==-1 || posicion==-2 ) {
        cout<<"Vendedor no encontrado"<<endl;
    } else {
        archivoVendedor.Leer(posicion).mostrar();
        system("pause");
    }

}
void  MenuVendedor::OpcionCuatro() {
    system("cls");
    cout << "Modificar Vendedor." << endl;
    int ID,posicion,opc=-1;
    MenuSalida ms;
    fflush(stdin);
    cout<<"Ingrese el ID del vendedor a modificar: ";
    cin>>ID;
    fflush(stdin);
    ArchivoVendedor archivoVendedor;
    posicion=archivoVendedor.Buscar(ID);
    if(posicion==-1 || posicion==-2 ) {
        cout<<"Cliente no encontrado"<<endl;
        system("pause");
    } else {
        Vendedor vendedor = archivoVendedor.Leer(posicion);
        while(opc != 0) {
            ms.mostrarSubMenuDosTres();
            cin >> opc;
            system("cls");
            switch(opc) {
            case 1:
                system("cls");
                vendedor.modificarNombre();
                break;
            case 2:
                vendedor.modificarApellido();
                system("cls");
                break;
            case 3:
                vendedor.modificarNivel();
                system("cls");
                break;
            case 4:
                vendedor.cargarVendedor();
                fflush(stdin);
                system("cls");
                break;
            case 0:
                cout << "Saliendo al menu principal..." << endl;
                system("pause");

                break;
            default:
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            archivoVendedor.ModificarRegistro(vendedor, posicion);
        }
    }
}
void MenuVendedor::OpcionCinco() {
    system("cls");
    cout << "Listar Vendedores." << endl;
    ArchivoVendedor archivoVendedor;
    archivoVendedor.Listar();
}




MenuVendedor::~MenuVendedor() {
    //dtor
}
