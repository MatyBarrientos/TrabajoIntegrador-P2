#include "ArchivoProducto.h"
#include "ArchivoMarca.h"
#include "ArchivoCategoria.h"
#include <cstring>
#include "Producto.h"

///CONSTRUCTORES
ArchivoProducto::ArchivoProducto() {
    strcpy(_nombreArchivo,"ArchivoProducto.dat");
}
ArchivoProducto::ArchivoProducto(const char *nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoProducto::ArchivoProducto(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoProductoBackUp.dat");
}

///GUARDAR
bool ArchivoProducto::Guardar(Producto producto) {
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProducto::Guardar(Producto producto, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
///BUSCAR (ME DEVUELVE LA POS DEL PRODUCTO EN EL ARCH INGRESANDO EL ID)
int ArchivoProducto::Buscar(int IDProducto) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)) {
        if(producto.getIdProducto() == IDProducto) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoProducto::BuscarMarca(int IDMarca) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)) {
        if(producto.getIdMarca() == IDMarca) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
int ArchivoProducto::BuscarCategoria(int IDCategoria) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)) {
        if(producto.getIdCategoria() == IDCategoria) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
///LEER
Producto ArchivoProducto::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return Producto();
    }
    Producto producto;
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return producto;
}
///CONTAR REGISTROS
int ArchivoProducto::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidadRegistros;
}

///LISTADO
void ArchivoProducto::Listar() {
    ArchivoProducto archivo("ArchivoProducto.dat");
    Producto producto;
    int contador=0;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    system("pause");
    for(i = 0; i < cantidadRegistros; i++) {
        producto = archivo.Leer(i);
        if(producto.getEstado()) { ///SI EL ESTADO ES TRUE, LO MUESTRA
            cout<<"-------------------------------------------"<<endl;
            producto.mostrarProducto();
            contador++;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"Cantidad de registros TOTAL: "<<cantidadRegistros<<endl;
    cout<<"Cantidad de registros ACTIVOS: "<<contador<<endl;
    cout<<"Cantidad de registros DADOS DE BAJA: "<<(cantidadRegistros-contador)<<endl;
    cout<<"-------------------------------------------"<<endl;
    system("pause");
}
///MODIFICAR REGISTRO
bool ArchivoProducto::ModificarRegistro(const Producto& producto, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
////back up
bool ArchivoProducto::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }

    // Abrir archivo de respaldo en modo escritura (crea el archivo si no existe)
    pArchivoBackUp = fopen("ArchivoproductoBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }

    Producto producto;
    // Leer registros y respaldar aquellos con estado activo
    while (fread(&producto, sizeof(Producto), 1, pArchivo) == 1) {
        if (producto.getEstado()) {  // Verificar si el producto está activo
            fwrite(&producto, sizeof(Producto), 1, pArchivoBackUp);
        }
    }

    fclose(pArchivo);
    fclose(pArchivoBackUp);

    cout << "Backup completado con éxito." << endl;
    return true;
}

void ArchivoProducto::mostrarMarcasPorCategoria(int idCategoria) {
    int cantidad = CantidadRegistros();
    Marca marca;
    ArchivoMarca aMarca;
    Producto producto;

    cout << "Marcas disponibles para la categoría seleccionada:" << endl;
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        producto = Leer(i);
        if (producto.getEstado() && producto.getIdCategoria() == idCategoria) {
            cout << "ID: " << producto.getIdMarca() << " -> " << aMarca.Leer(Buscar(producto.getIdMarca())).getNombre() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron marcas para esta categoría." << endl;
    }
}
void ArchivoProducto::mostrarProductosPorMarcaYCategoria(int idCategoria, int idMarca) {
    int cantidad = CantidadRegistros();
    Producto producto;

    cout << "Productos disponibles para la categoría y marca seleccionadas:" << endl;
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        producto = Leer(i);
        if (producto.getIdCategoria() == idCategoria && producto.getIdMarca() == idMarca && producto.getEstado()) {
            cout << "ID Producto: " << producto.getIdProducto() << " -> " << producto.getDetalle()
                 << ", Precio: $" << producto.getPrecioVenta() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron productos para esta marca en la categoría seleccionada." << endl;
    }
}



///DESTRUCTOR
ArchivoProducto::~ArchivoProducto() {}
