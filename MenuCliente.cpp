#include "MenuCliente.h"
#include "MenuSalida.h"
#include "Persona.h"
#include "Vendedor.h"
#include "ArchivoVendedor.h"


MenuCliente::MenuCliente() {
    //ctor
}
bool MenuCliente::agregarCliente() {
    int DNI;
    ArchivoCliente archivoCliente;

    cout<<"DNI: ";
    cin>>DNI;
    fflush(stdin);
    int posicion=archivoCliente.Buscar(DNI);
    if(posicion==-2 || posicion==-1) {
        Persona persona;
        Cliente cliente(persona);
        cliente.cargar(DNI);

        archivoCliente.Guardar(cliente);
        return true;
    } else {
        cout<<"Cliente ya existente."<<endl;

        return false;
    }
}
///baja lógica
bool MenuCliente::bajaCliente() {

    ArchivoCliente archivoCliente;
    return archivoCliente.BajaRegistro();
}
bool MenuCliente::altaCliente() {

    ArchivoCliente archivoCliente;
    return archivoCliente.AltaRegistro();
}
bool MenuCliente::cambiarEstadoCliente() {

    ArchivoCliente archivoCliente;
    return archivoCliente.CambiarEstadoRegistro();
}

///////////////////////
//Sub Opcion 1
void MenuCliente::OpcionUno() {
    bool bandera;
    system("cls");
    cout << "Agregar Cliente." << endl;
    bandera=agregarCliente();
    if(bandera) {
        cout<<"Cliente agregado"<<endl;
    }
    system("pause");
    system("cls");
}

void MenuCliente::OpcionDos() {
    system("cls");
    cout << "Estado del Cliente." << endl;
    cambiarEstadoCliente();
    system("pause");

    //fflush(stdin);
}

void MenuCliente::OpcionTres() {

    cout << "Buscar Cliente." << endl;
    system("cls");
    int DNI,posicion;
    //fflush(stdin);
    cout<<"Ingrese el DNI del cliente a buscar: ";
    cin>>DNI;
    fflush(stdin);
    ArchivoCliente archivoCliente;
    posicion=archivoCliente.Buscar(DNI);
    if(posicion==-1 || posicion==-2 ) {
        cout<<"Cliente no encontrado"<<endl;
    } else {
        archivoCliente.Leer(posicion).mostrar();
        system("pause");
    }

}

void  MenuCliente::OpcionCuatro() {
    system("cls");
    cout << "Modificar Cliente." << endl;
    int DNI,posicion,opc=-1;
    MenuSalida ms;
    //fflush(stdin);
    cout<<"Ingrese el DNI del cliente a modificar: ";
    cin>>DNI;
    fflush(stdin);
    ArchivoCliente archivoCliente;
    posicion=archivoCliente.Buscar(DNI);
    if(posicion==-1 || posicion==-2 ) {
        cout<<"Cliente no encontrado"<<endl;
        system("pause");
    } else {
        Cliente cliente = archivoCliente.Leer(posicion);
        while(opc != 0) {
            ms.mostrarSubMenuUnoTres();
            cin >> opc;
            fflush(stdin);
            switch(opc) {
            case 1:
                system("cls");
                cliente.modificarNombre();
                break;
            case 2:
                cliente.modificarApellido();
                system("cls");
                break;
            case 3:
                cliente.modificarDireccion();
                system("cls");
                break;
            case 4:
                cliente.modificarTelefono();
                system("cls");
                break;
            case 5:
                cliente.modificarMail();
                system("cls");
                break;
            case 6:
                cliente.cargar(cliente.getIdCliente());

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
            archivoCliente.ModificarRegistro(cliente, posicion);
        }
    }
}

void MenuCliente::OpcionCinco() {
    system("cls");
    cout << "Listar Clientes." << endl;
    ArchivoCliente archivoCliente;
    archivoCliente.Listar();
    system("pause");
}



MenuCliente::~MenuCliente() {
    //dtor
}
