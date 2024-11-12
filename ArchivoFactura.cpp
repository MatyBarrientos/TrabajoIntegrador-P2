#include <iostream>
#include "ArchivoFactura.h"
#include "Funciones.h"

/// CONSTRUCTORES
ArchivoFactura::ArchivoFactura(){
    strcpy(_nombreArchivo,"ArchivoFactura.dat");
}

ArchivoFactura::ArchivoFactura(const char *nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoFactura::ArchivoFactura(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoFacturaBackUp.dat");
}
///METODOS
bool ArchivoFactura::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }
    pArchivoBackUp = fopen("ArchivoCategoriaBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }
    Factura factura;
    while (fread(&factura, sizeof(Factura), 1, pArchivo) == 1) {
        if (factura.getEstado()) {
            fwrite(&factura, sizeof(Factura), 1, pArchivoBackUp);
        }
    }
    fclose(pArchivo);
    fclose(pArchivoBackUp);
    cout << "Backup completado con éxito." << endl;
    return true;
}
///METODOS
bool ArchivoFactura::Guardar(const Factura& factura) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoFactura::Buscar(int IDfactura) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Factura factura;
    int i = 0;
    while(fread(&factura, sizeof(Factura), 1, pArchivo)) {
        if(factura.getNroFactura() == IDfactura) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}

bool ArchivoFactura::ModificarRegistro(const Factura& factura, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    bool ok = fwrite(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoFactura::BajaRegistro() {
    int IDFactura;
    Factura factura;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el ID de la Factura: ";
    cin>>IDFactura;
    fflush(stdin);
    int pos=Buscar(IDFactura);
    if(pos==-1||pos==-2) {
        cout<<"No hay Factura con ese ID."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    factura=Leer(pos);
    factura.setEstado(false);
    bool resultado=ModificarRegistro(factura,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"La Factura fue dada de Baja"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro de la factura." << endl;
        system("pause");
    }
    return resultado;
}

bool ArchivoFactura::AltaRegistro() {
    int IDfactura;
    Factura factura;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el ID de la Factura: ";
    cin>>IDfactura;
    fflush(stdin);
    int pos=Buscar(IDfactura);
    if(pos==-1||pos==-2) {
        cout<<"No hay Factura con ese ID."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    factura=Leer(pos);
    factura.setEstado(true);
    bool resultado=ModificarRegistro(factura,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"La factura fue dado de Alta"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro de la factura." << endl;
        system("pause");
    }
    return resultado;
}

Factura ArchivoFactura::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return Factura();
    }
    Factura factura;
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    fread(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return factura;
}

int ArchivoFactura::CantidadRegistros() {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Factura);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoFactura::Listar() {
    int cantidadRegistros=CantidadRegistros();
    FILE *pArchivo=nullptr;
    Factura factura;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&factura, sizeof(Factura), 1, pArchivo);
        if(factura.getEstado()==true) {
            cout<<"----------------------------------------------"<<endl;
            factura.mostrar();
        }
    }
    cout<<"----------------------------------------------"<<endl;
    fclose(pArchivo);
}

ArchivoFactura::~ArchivoFactura(){}///DESTRUCTOR
