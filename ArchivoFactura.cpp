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

int ArchivoFactura::BuscarPorID(int IDfactura) {
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



ArchivoFactura::~ArchivoFactura(){}///DESTRUCTOR
