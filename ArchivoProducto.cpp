#include "ArchivoProducto.h"
#include "ArchivoMarca.h"
#include "ArchivoCategoria.h"
#include <cstring>
#include "Producto.h"
#include "Funciones.h"

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
bool ArchivoProducto::BuscarNombreProducto(const char* nombre) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL) {
        return false;
    }
    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)) {
        char cadena1[50],cadena2[50]; //dos variables auxiliares
        strcpy(cadena1,nombre);
        strcpy(cadena2,producto.getDetalle()); //en ambas voy a copiar el valor del producto[i] y del que recibo por parametro
        int repetido=strcmp(strlwr(cadena1),strlwr(cadena2)); //comparo y las vuelvo minusculas por las dudas
        if(repetido==0) {
            fclose(pArchivo);
            return false;
        }
    }
    fclose(pArchivo);
    return true;
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
///Problema planteado a Bruno.
int ArchivoProducto::autoIncrementalID() {
    int ID = 0;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        return 0; // Error al abrir el archivo
    }

    // Ir al final del archivo para calcular el tamaño
    fseek(pArchivo, 0, SEEK_END);
    int cantBytes = ftell(pArchivo);
    int variable= cantBytes-sizeof(Producto);

    if (cantBytes == 0) {
        fclose(pArchivo);
        return 1; // Si está vacío, el primer ID será 1
    }

    // Mover el puntero al inicio del último registro
    fseek(pArchivo,variable, SEEK_SET); ///-> lo menciono kloster en clase -sizeof(CLASE)
    Producto producto;                 ///se reemplazó por un warning, en su lugar vas desde el
    ///principio SEEK_SET hasta el inicio del ultimo registro

    if (fread(&producto, sizeof(Producto), 1, pArchivo) == 1) {
        ID = producto.getIdProducto() + 1;
    } else {
        ID = 1; // En caso de error de lectura, asumir el primer ID
    }

    fclose(pArchivo);
    return ID;
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

    cout << "Backup completado con exito." << endl;
    return true;
}
void ArchivoProducto::mostrarProductoPorMarca(int idMarca) {
    int cantidad = CantidadRegistros();
    Producto producto;
    ArchivoMarca archivoMarca;
    Marca marca;
    int pos = archivoMarca.Buscar(idMarca);
    marca=archivoMarca.Leer(pos);
    cout<<"Productos de la marca "<<marca.getNombre()<<": "<<endl;
    for (int i=0; i<cantidad; i++) {
        producto=Leer(i);
        if(producto.getIdMarca()==idMarca && producto.getEstado()) {
            cout<<"-----------------------------------"<<endl;
            producto.mostrarProducto();
        }
    }
    cout<<"-----------------------------------"<<endl;
}
void ArchivoProducto::mostrarProductoPorCategoria(int idCategoria) {
    int cantidad = CantidadRegistros();
    Producto producto;
    ArchivoCategoria archivoCategoria;
    Categoria categoria;
    int pos = archivoCategoria.Buscar(idCategoria);
    categoria=archivoCategoria.Leer(pos);
    cout<<"Productos de la categoria "<<categoria.getNombre()<<": "<<endl;
    for (int i=0; i<cantidad; i++) {
        producto=Leer(i);
        if(producto.getIdCategoria()==idCategoria && producto.getEstado()) {
            cout<<"----------------------------------------------"<<endl;
            producto.mostrarProducto();
        }
    }
    cout<<"----------------------------------------------"<<endl;
}
void ArchivoProducto::mostrarMarcasPorCategoria(int idCategoria) {
    int cantidad = CantidadRegistros(); ///CANTIDAD DE REGISTROS DE PRODUCTOS
    ArchivoMarca aMarca;
    int TAM = aMarca.CantidadRegistros(); ///CANTIDAD DE REGISTROS DE MARCA
    bool *vMarca;
    vMarca=nullptr;
    definirVectorBool(vMarca,TAM);//vector en 0 o false, sí hay match cambio el estado (true) para evitar mostrar repetidos

    Producto producto;

    bool encontrado=false;
    cout << "Marcas disponibles para la categoria seleccionada:" << endl;
    for (int i = 0; i < cantidad; i++) {
        producto = Leer(i);
        int IDmarca=producto.getIdMarca(); //va a ser el indice de mi vector de bools
        if(!(vMarca[IDmarca-1])) { //le restamos 1 porque nuestros ID arrancan en 1 y reviso el estado de ese elemento.
            if (producto.getEstado() && producto.getIdCategoria() == idCategoria) {
                cout<<"----------------------"<<endl;
                cout << "ID: " << producto.getIdMarca() << " -> " << aMarca.Leer(Buscar(producto.getIdMarca())).getNombre() << endl;
                vMarca[producto.getIdMarca()-1]=true; //cambio el estado del elemento de mi vector de bool
                encontrado=true;
            }
        }
    }
    cout<<"----------------------"<<endl;
    if (!encontrado) {
        cout << "No se encontraron marcas para esta categoria." << endl;
    }
    delete []vMarca;//devolver memoria
}
void ArchivoProducto::mostrarProductosPorMarcaYCategoria(int idCategoria, int idMarca) {
    int cantidad = CantidadRegistros();
    Producto producto;

    bool encontrado = false;
    cout << "Productos disponibles para la categoria y marca seleccionadas:" << endl;
    for (int i = 0; i < cantidad; i++) {
        producto = Leer(i);
        if (producto.getIdCategoria() == idCategoria && producto.getIdMarca() == idMarca && producto.getEstado()) {
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout << "ID Producto: " << producto.getIdProducto() << " -> " << producto.getDetalle()
                 << ", Precio: $" << producto.getPrecioVenta() <<" Stock-> "<<producto.getStock()<<endl;
            encontrado = true;
        }
    }
    cout<<"-------------------------------------------------------------------------"<<endl;
    if (!encontrado) {
        cout << "No se encontraron productos para esta marca en la categoria seleccionada." << endl;
    }
}

vector<string> ArchivoProducto::getEncabezados() {
    return {"ID Producto", "Detalle","Marca","Categoria", "precio", "stock"};
}

Producto* ArchivoProducto::listarEnVectorD() {
    Producto *productos=nullptr;
    int cantidadRegistros=CantidadRegistros();

    productos = new Producto[cantidadRegistros];
    FILE *pArchivo=nullptr;

    Producto productoaux;
    pArchivo = fopen(_nombreArchivo, "rb");

    if(pArchivo == nullptr) {
        return productos;
    }
    for(int i = 0; i < cantidadRegistros; i++) {

        fread(&productoaux, sizeof(Producto), 1, pArchivo);

        if(productoaux.getEstado()==true) {

            productos[i]=productoaux;
            //system("pause");
        }
    }
    fclose(pArchivo);
    return productos;
}




///DESTRUCTOR
ArchivoProducto::~ArchivoProducto() {}
