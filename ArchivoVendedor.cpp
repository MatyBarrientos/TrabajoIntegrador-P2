#include "ArchivoVendedor.h"
#include <cstring>
#include <iostream>
using namespace std;



ArchivoVendedor::ArchivoVendedor() {
    strcpy(_nombreArchivo,"ArchivoVendedores.dat");
}
ArchivoVendedor::ArchivoVendedor(const char* nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoVendedor::ArchivoVendedor(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoVendedorBackUp.dat");
}
bool ArchivoVendedor::Guardar(const Vendedor& vendedor) {

    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo)==1;
    fclose(pArchivo);
    return ok;
}
bool ArchivoVendedor::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }

    // Abrir archivo de respaldo en modo escritura (crea el archivo si no existe)
    pArchivoBackUp = fopen("ArchivoVendedorBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }

    Vendedor vendedor;
    // Leer registros y respaldar aquellos con estado activo
    while (fread(&vendedor, sizeof(Vendedor), 1, pArchivo) == 1) {
        if (vendedor.getEstado()) {  // Verificar si el cliente está activo
            fwrite(&vendedor, sizeof(Vendedor), 1, pArchivoBackUp);
        }
    }

    fclose(pArchivo);
    fclose(pArchivoBackUp);

    cout << "Backup completado con éxito." << endl;
    return true;
}
bool ArchivoVendedor::ModificarRegistro(const Vendedor& vendedor, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoVendedor::BajaRegistro() {
    int IDVendedor;
    Vendedor vendedor;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de ID del Vendedor: ";
    cin>>IDVendedor;
    int pos=Buscar(IDVendedor);
    if(pos==-1||pos==-2) {
        cout<<"No hay vendedor con esa ID.";
        fclose(pArchivo);
        return false;
    }
    vendedor=Leer(pos);
    vendedor.setEstado(false);
    bool resultado=ModificarRegistro(vendedor,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"El vendedor fue dado de Baja";
    } else {
        cout << "Error al modificar el registro del vendedor." << endl;
    }
    return resultado;
}
bool ArchivoVendedor::AltaRegistro() {
    int IDVendedor;
    Vendedor vendedor;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de ID del Vendedor: ";
    cin>>IDVendedor;
    int pos=Buscar(IDVendedor);
    if(pos==-1||pos==-2) {
        cout<<"No hay vendedor con esa ID.";
        fclose(pArchivo);
        return false;
    }
    vendedor=Leer(pos);
    vendedor.setEstado(true);
    bool resultado=ModificarRegistro(vendedor,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"El vendedor fue dado de Baja";
    } else {
        cout << "Error al modificar el registro del vendedor." << endl;
    }
    return resultado;
}


int ArchivoVendedor::Buscar(int IDVendedor) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Vendedor vendedor;
    int i = 0;
    while(fread(&vendedor, sizeof(Vendedor), 1, pArchivo)==1) {
        if(vendedor.getIdVendedor() == IDVendedor) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}
int ArchivoVendedor::BuscarDNI(int DNI) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Vendedor vendedor;
    int i = 0;
    while(fread(&vendedor, sizeof(Vendedor), 1, pArchivo)==1) {
        if(vendedor.getIdUsuario() == DNI) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
bool ArchivoVendedor::CambiarEstadoRegistro() {
    int IDVendedor,opc;
    bool resultado=false;
    Vendedor vendedor;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de ID del Vendedor: ";
    cin>>IDVendedor;
    int pos=Buscar(IDVendedor);
    if(pos==-1||pos==-2) {
        cout<<"No hay Vendedor con es IDVendedor."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    vendedor=Leer(pos);
    if (vendedor.getEstado()) {
        cout<<"El Vendedor está dado de alta."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            vendedor.setEstado(false);
            cout<<"Estado cambiado a Baja."<<endl;
        } else {
            cout<<"El estado permanece en Alta."<<endl;
        }
        resultado=ModificarRegistro(vendedor,pos);
    } else {
        cout<<"El Vendedor está dado de Baja."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            vendedor.setEstado(true);
            cout<<"Estado cambiado a Alta."<<endl;
            resultado=ModificarRegistro(vendedor,pos);
        } else {
            cout<<"El estado permanece en Baja."<<endl;
        }
    }
    fclose(pArchivo);
    if(!resultado) {
        cout << "Error al modificar el registro del cliente." << endl;
        system("pause");
    }
    return resultado;
}


Vendedor ArchivoVendedor::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return Vendedor();
    }
    Vendedor vendedor;
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    fread(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return vendedor;
}
int ArchivoVendedor::CantidadRegistros() {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Vendedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoVendedor::Listar() {
    int cantidadRegistros=CantidadRegistros();
    FILE *pArchivo=nullptr;
    Vendedor vendedor;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&vendedor, sizeof(Vendedor), 1, pArchivo);
        if(vendedor.getEstado()==true) {
            vendedor.mostrar();
            cout<<"----------------------------------------------"<<endl;
        }
    }
    fclose(pArchivo);
}

vector<string> ArchivoVendedor::getEncabezados()
{
    return {"Nombre", "Apellido", "DNI","IDVendedor","Fecha Nacimiento", "Nivel Acceso" };
}

Vendedor* ArchivoVendedor::listarEnVectorD()
{
    Vendedor *vendedor=nullptr;
    int cantidadRegistros=CantidadRegistros();

    vendedor = new Vendedor[cantidadRegistros];
    FILE *pArchivo=nullptr;

    Vendedor vendedoraux;
    pArchivo = fopen(_nombreArchivo, "rb");

    if(pArchivo == nullptr) {
        return vendedor;
    }
    for(int i = 0; i < cantidadRegistros; i++) {

        fread(&vendedoraux, sizeof(Vendedor), 1, pArchivo);

        if(vendedoraux.getEstado()==true) {

            vendedor[i]=vendedoraux;
            //system("pause");
        }
    }
    fclose(pArchivo);
   // delete []clientes;
    return vendedor;
}



ArchivoVendedor::~ArchivoVendedor() {
    //dtor
}
