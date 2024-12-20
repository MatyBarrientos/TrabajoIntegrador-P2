#include "MenuSalida.h"
#include "MenuOpciones.h"
#include "MenuCliente.h"
#include "MenuProducto.h"
#include "MenuVendedor.h"
#include "MenuRespaldo.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include <iostream>
#include "MenuVenta.h"
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
        fflush(stdin);
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
                opcionSubMenuCuatro();
                break;
            case 5:
                opcionSubMenuCinco();
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
        fflush(stdin);
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
        fflush(stdin);
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
    MenuProducto mProducto;
    while(opc != 0) {
        ms.mostrarSubMenuUno(auth.nivelAcceso(),"Productos","Producto");
        cin >> opc;
        fflush(stdin);
        if(auth.nivelAcceso()) {
            switch(opc) {
            case 1:///AGREGAR PRODUCTO (ID UNICO)
                mProducto.agregarProducto();
                break;
            case 2:///CAMBIAR EL ESTADO DEL PRODUCTO
                mProducto.cambiarEstadoProducto();
                break;
            case 3:///BUSCAR PRODUCTO POR ID
                mProducto.buscarProducto();
                break;
            case 4:///MODIFICAR PRODUCTO
                mProducto.modificarProducto();
                break;
            case 5:{///LISTAR PRODUCTOS(MUESTRA CANTIDAD REGISTROS)
                int opc2=-1;
                while(opc2!=0){
                ms.SubMenuListadoProducto();
                cin>>opc2;
                fflush(stdin);
                    switch(opc2){
                    case 1:
                        mProducto.listarProductoActivo();
                        break;
                    case 2:
                        mProducto.listarProductoBaja();
                        break;
                    case 3:
                        mProducto.listarProductoMarca();
                        break;
                    case 4:
                        mProducto.listarProductoCat();
                        break;
                    case 0:
                        cout << "Saliendo al menu anterior..." << endl;
                        system("pause");
                        break;
                    default:
                        cout << "Ingrese una opcion correcta." << endl;
                        system("pause");
                        break;
                    }
                }
            }
                break;
            case 6:///OPCION OCULTA
                mProducto.filtroVenta();
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
            case 1:///BUSCAR PRODUCTO POR ID
                mProducto.buscarProducto();
                break;
            case 2:///LISTAR PRODUCTOS(MUESTRA CANTIDAD REGISTROS)
                mProducto.listarProductoActivo();
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
///VENTAS
void MenuOpciones::opcionSubMenuCuatro() {
    int opc = -1;
    MenuSalida ms;
    MenuVenta mVenta;
    while(opc != 0) {
        ms.mostrarSubMenuCuatro();
        cin >> opc;
        fflush(stdin);
        switch(opc) {
        case 1:
            cout << "Realizar Venta." << endl;
            mVenta.realizarVenta(auth.VendedorActual());
            system("pause");
            break;
        case 2:
            cout << "Buscar Venta." << endl;
            mVenta.mostrarDetallesVenta();
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
    }
}

///MENU DE RESPALDOS
void MenuOpciones::opcionSubMenuCinco() {
    int opc = -1;
    MenuSalida ms;
    MenuRespaldo respaldo;

    while(opc != 0) {
        ms.mostrarSubMenuCinco();
        cin >> opc;
        fflush(stdin);
        switch(opc) {
        case 1:
            respaldo.OpcionCliente();
            break;
        case 2:
            respaldo.OpcionVendedor();
            break;
        case 3:
            respaldo.OpcionProducto();
            break;
        case 4:
            cout << "Respaldo Ventas." << endl;
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
    }
}

MenuOpciones::~MenuOpciones() {
    //dtor
}
