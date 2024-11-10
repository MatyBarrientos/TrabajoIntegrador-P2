#include "MenuSalida.h"
#include "MenuOpciones.h"
#include "MenuCliente.h"
#include "MenuVendedor.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include <iostream>
using namespace std;

MenuOpciones::MenuOpciones() {
    //ctor
}

void MenuOpciones::ingresoSistema() {
    if(auth.ingresarSistema()) {

        opcion();
    }
}

void MenuOpciones::opcion() {
    MenuSalida ms;
    int opc1=-1;
    while(opc1!=0) {
        ms.mostrarMenuPrincipal(auth.nivelAcceso());
        cin>>opc1;
        system("cls");
        if(auth.nivelAcceso()) {
            switch(opc1) {
            case 1:
                opcionSubMenuUno();
                break;
            case 2:
                opcionSubMenuDos();
                break;
            case 3:
                opcionSubMenuTres();
                break;
            case 4:
                ms.mostrarSubMenuCuatro();
                break;
            case 5:
                ms.mostrarSubMenuCinco();
                break;
            case 0: {
                cout<<"Saliendo del sistema"<<endl;
                //system("pause"); // Pausa para que el usuario vea el mensaje antes de limpiar
                system("cls");
            }
            break;
            default: {
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                system("cls");
            }
            break;
            }
        } else {
            switch(opc1) {
            case 1:
                opcionSubMenuUno();
                break;
            case 2:
                opcionSubMenuDos();
                break;
            case 3:
                opcionSubMenuTres();

                break;
            case 4:
                ms.mostrarSubMenuCuatro();
                break;
            case 0: {
                cout<<"Saliendo del sistema"<<endl;
                //system("pause"); // Pausa para que el usuario vea el mensaje antes de limpiar
                system("cls");
            }
            break;
            default: {
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                system("cls");
            }
            break;
            }
        }
    }

}
///////Clientes
void MenuOpciones::opcionSubMenuUno() {
    int opc = -1;
    MenuSalida ms;
    MenuCliente mCliente;
    while(opc != 0) {
        ms.mostrarSubMenuUno(auth.nivelAcceso(),"Clientes","Cliente");
        cin >> opc;
        if(auth.nivelAcceso()) {
            switch(opc) {
            case 1:
                mCliente.OpcionUno();
                break;
            case 2:
                mCliente.OpcionDos();
                break;
            case 3:
                mCliente.OpcionTres();
                break;
            case 4:
                mCliente.OpcionCuatro();
                break;
            case 5:
                mCliente.OpcionCinco();
                break;

            case 0:
                cout << "Saliendo al menu principal..." << endl;
                system("pause");
                system("cls");

                break;

            default:
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                system("cls");
                break;
            }
            system("cls");
        } else {
            switch(opc) {
            case 1:
                mCliente.OpcionTres();
                break;
            case 2:
                mCliente.OpcionCinco();
                break;
            case 0:
                cout << "Saliendo al menu principal..." << endl;

                break;

            default:
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            system("cls");
        }
    }
}
////////Vendedores
void MenuOpciones::opcionSubMenuDos() {
    int opc = -1;
    MenuSalida ms;
    MenuVendedor mVendedor;
    while(opc != 0) {
        ms.mostrarSubMenuUno(auth.nivelAcceso(),"Vendedores","Vendedores");
        cin >> opc;
        if(auth.nivelAcceso()) {
            switch(opc) {
            case 1:
                mVendedor.OpcionUno();
                break;
            case 2:
                mVendedor.OpcionDos();
                break;
            case 3:
                mVendedor.OpcionTres();
                break;
            case 4:
                mVendedor.OpcionCuatro();
                break;
            case 5:
                mVendedor.OpcionCinco();
                system("pause");
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
            system("cls");
        } else {
            switch(opc) {
            case 1:
                mVendedor.OpcionTres();
                break;
            case 2:
                mVendedor.OpcionCinco();
                system("pause");
                break;
            case 0:
                cout << "Saliendo al menu principal..." << endl;

                break;

            default:
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            system("cls");
        }
    }
}

////producto
void MenuOpciones::opcionSubMenuTres() {
    int opc = -1;
    MenuSalida ms;
    MenuCliente mCliente;
    while(opc != 0) {
        ms.mostrarSubMenuUno(auth.nivelAcceso(),"Productos","Producto");
        cin >> opc;
        if(auth.nivelAcceso()) {
            switch(opc) {
            case 1:
                mCliente.OpcionUno();
                break;
            case 2:
                mCliente.OpcionDos();
                break;
            case 3:
                mCliente.OpcionTres();
                break;
            case 4:
                mCliente.OpcionCuatro();
                break;
            case 5:

                mCliente.OpcionCinco();

                system("pause");

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
            system("cls");
        } else {
            switch(opc) {
            case 1:
                mCliente.OpcionTres();
                break;
            case 2:
                mCliente.OpcionCinco();
                break;
            case 0:
                cout << "Saliendo al menu principal..." << endl;

                break;

            default:
                cout << "Ingrese una opcion correcta." << endl;
                system("pause");
                break;
            }
            system("cls");
        }
    }
}

MenuOpciones::~MenuOpciones() {
    //dtor
}
