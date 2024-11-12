#include "ArchivoDetalleVenta.h"
#include "Funciones.h"
#include <cstring>

ArchivoDetalleVenta::ArchivoDetalleVenta() {
    strcpy(_nombreArchivo,"ArchivoDetalleVenta.dat");
}
ArchivoDetalleVenta::ArchivoDetalleVenta(const char *nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoDetalleVenta::ArchivoDetalleVenta(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoDetalleVentaBackUp.dat");
}

bool ArchivoDetalleVenta::Guardar(const DetalleVenta& detalle) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoDetalleVenta::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }
    pArchivoBackUp = fopen("ArchivoDetalleVentaBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }
    DetalleVenta detalle;
    while (fread(&detalle, sizeof(DetalleVenta), 1, pArchivo) == 1) {

        fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivoBackUp);

    }
    fclose(pArchivo);
    fclose(pArchivoBackUp);
    cout << "Backup completado con éxito." << endl;
    return true;
}
bool ArchivoDetalleVenta::ModificarRegistro(const DetalleVenta& detalle, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(DetalleVenta) * posicion, SEEK_SET);
    bool ok = fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoDetalleVenta::Buscar(int IDVenta) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1; ///-1 no hay archivo
    }
    DetalleVenta detalle;
    int i = 0;
    while(fread(&detalle, sizeof(DetalleVenta), 1, pArchivo)) {
        if(detalle.getIdFactura() == IDVenta) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2; //-2 no hubo coincidencia
}

int ArchivoDetalleVenta::cantidadDetalles(int IDVenta) {
    FILE *pArchivo = nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        return -1; // No hay archivo
    }
    DetalleVenta detalle;
    int contador = 0;
    while (fread(&detalle, sizeof(DetalleVenta), 1, pArchivo) == 1) {
        if (detalle.getIdFactura() == IDVenta) {
            contador++;
        }
    }
    fclose(pArchivo);

    if (contador > 0) {
        return contador; // Devuelve el número de coincidencias encontradas
    } else {
        return -2; // No hubo coincidencias
    }

}


    bool agregarDetalle(DetalleVenta& detalle, Factura& factura) {
        FILE* pArchivo = fopen("DetalleVenta.dat", "ab");
        if (!pArchivo) return false;

        // Si es el primer detalle para esta factura, guardamos la posición de inicio
        if (factura.getCantidadDetalles() == 0) {
            int posicionInicio = ftell(pArchivo) / sizeof(DetalleVenta);
            factura.setPosicionDetalleInicio(posicionInicio);
        }

        // Escribir detalle y actualizar contador en factura
        fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivo);
        factura.setCantidadDetalles(factura.getCantidadDetalles() + 1);

        fclose(pArchivo);
        return true;
    }

    bool leerDetalles(const Factura& factura, std::vector<DetalleVenta>& detalles) {
        FILE* pArchivo = fopen("DetalleVenta.dat", "rb");
        if (!pArchivo) return false;

        // Saltar a la posición inicial de los detalles para esta factura
        fseek(pArchivo, factura.getPosicionDetalleInicio() * sizeof(DetalleVenta), SEEK_SET);

        DetalleVenta detalle;
        for (int i = 0; i < factura.getCantidadDetalles(); i++) {
            fread(&detalle, sizeof(DetalleVenta), 1, pArchivo);
            detalles.push_back(detalle);
        }

        fclose(pArchivo);
        return true;
    }
}

    ArchivoDetalleVenta::~ArchivoDetalleVenta() {
        //dtor
    }
