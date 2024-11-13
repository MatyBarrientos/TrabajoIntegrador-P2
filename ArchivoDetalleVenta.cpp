#include "ArchivoDetalleVenta.h"
#include "Factura.h"
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
int ArchivoDetalleVenta::Guardar(const DetalleVenta& detalle) {
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if (pArchivo == nullptr) {
        return -1; // Indicador de error
    }

    // Obtener posición antes de escribir
    int posicion = ftell(pArchivo) / sizeof(DetalleVenta);

    // Escribir el detalle en el archivo
    if (fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivo) != 1) {
        fclose(pArchivo);
        return -1;
    }

    fclose(pArchivo);
    return posicion; // Devuelve la posición del primer detalle guardado
}
DetalleVenta ArchivoDetalleVenta::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return DetalleVenta();
    }
    DetalleVenta detalle;;
    fseek(pArchivo, sizeof(DetalleVenta) * posicion, SEEK_SET);
    fread(&detalle, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return detalle;
}

/*bool ArchivoDetalleVenta::Guardar(const DetalleVenta& detalle) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&detalle, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}*/
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
int ArchivoDetalleVenta::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(DetalleVenta);
    fclose(pArchivo);
    return cantidadRegistros;
}

    ArchivoDetalleVenta::~ArchivoDetalleVenta() {
        //dtor
    }
