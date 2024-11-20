#include "ArchivoCategoria.h"
#include "Funciones.h"
#include <limits>
#include <cstring>

ArchivoCategoria::ArchivoCategoria() {
    strcpy(_nombreArchivo,"ArchivoCategoria.dat");
}
ArchivoCategoria::ArchivoCategoria(const char *nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoCategoria::ArchivoCategoria(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoCategoriaBackUp.dat");
}
bool ArchivoCategoria::Guardar(const Categoria& categoria) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCategoria::BackUp() {
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
    Categoria categoria;
    while (fread(&categoria, sizeof(Categoria), 1, pArchivo) == 1) {
        if (categoria.getEstado()) {
            fwrite(&categoria, sizeof(Categoria), 1, pArchivoBackUp);
        }
    }
    fclose(pArchivo);
    fclose(pArchivoBackUp);
    cout << "Backup completado con éxito." << endl;
    return true;
}
bool ArchivoCategoria::ModificarRegistro(const Categoria& categoria, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoCategoria::BajaRegistro() {
    int IDCategoria;
    Categoria categoria;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el ID de la Categoria: ";
    cin>>IDCategoria;
    fflush(stdin);
    int pos=Buscar(IDCategoria);
    if(pos==-1||pos==-2) {
        cout<<"No hay Categoria con es IDMarca."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    categoria=Leer(pos);
    categoria.setEstado(false);
    bool resultado=ModificarRegistro(categoria,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"La categoria fue dada de Baja"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro de la categoria." << endl;
        system("pause");
    }
    return resultado;
}
bool ArchivoCategoria::AltaRegistro() {
    int IDCategoria;
    Categoria categoria;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el ID de la Categoria: ";
    cin>>IDCategoria;
    fflush(stdin);
    int pos=Buscar(IDCategoria);
    if(pos==-1||pos==-2) {
        cout<<"No hay Categoria con es IDMarca."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    categoria=Leer(pos);
    categoria.setEstado(true);
    bool resultado=ModificarRegistro(categoria,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"La categoria fue dado de Alta"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro de la categoria." << endl;
        system("pause");
    }
    return resultado;
}
bool ArchivoCategoria::CambiarEstadoRegistro() {
    int IDcategoria,opc;
    bool resultado=false;
    Categoria categoria;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de ID de la categoria: ";
    cin>>IDcategoria;
    fflush(stdin);
    int pos=Buscar(IDcategoria);
    if(pos==-1||pos==-2) {
        cout<<"No hay categoria con esa ID."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    categoria=Leer(pos);
    if (categoria.getEstado()) {
        cout<<"La categoria está dado de alta."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        fflush(stdin);
        if(opc==1) {
            categoria.setEstado(false);
            cout<<"Estado cambiado a Baja."<<endl;
        } else {
            cout<<"El estado permanece en Alta."<<endl;
        }
        resultado=ModificarRegistro(categoria,pos);
    } else {
        cout<<"La categoria está dada de Baja."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        fflush(stdin);
        if(opc==1) {
            categoria.setEstado(true);
            cout<<"Estado cambiado a Alta."<<endl;
            resultado=ModificarRegistro(categoria,pos);
        } else {
            cout<<"El estado permanece en Baja."<<endl;
        }
    }
    fclose(pArchivo);
    if(!resultado) {
        cout << "Error al modificar el registro de la Categoria." << endl;
        system("pause");
    }
    return resultado;
}
int ArchivoCategoria::Buscar(int IDCategoria) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Categoria categoria;
    int i = 0;
    while(fread(&categoria, sizeof(Categoria), 1, pArchivo)) {
        if(categoria.getID() == IDCategoria) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
Categoria ArchivoCategoria::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return Categoria();
    }
    Categoria categoria;
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    fread(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return categoria;
}
int ArchivoCategoria::CantidadRegistros() {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Categoria);
    fclose(pArchivo);
    return cantidadRegistros;
}
void ArchivoCategoria::Listar() {
    int cantidadRegistros=CantidadRegistros();
    FILE *pArchivo=nullptr;
    Categoria categoria;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&categoria, sizeof(Categoria), 1, pArchivo);
        if(categoria.getEstado()==true) {
            cout<<"----------------------------------------------"<<endl;
            categoria.mostrar();
        }
    }
    cout<<"----------------------------------------------"<<endl;
    fclose(pArchivo);
}
void ArchivoCategoria::mostrarListaCategorias(){
    int ID, cantidad;
    char nombre[20];
    Categoria categoria;

    cantidad = CantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay categorias aún ingresadas" << endl;
        return;
    }else{
        for (int i = 0; i < cantidad; i++) {
            categoria = Leer(i);
            if (categoria.getEstado()) {
                ID = categoria.getID();
                strcpy(nombre, categoria.getNombre());
                cout<<"------------------------------"<<endl;
                cout<<"ID "<<ID<<" -> "<<nombre<<endl;
            }
        }
        cout<<"------------------------------"<<endl;
    }
}
void ArchivoCategoria::mostrarCargaCategoria() {
    int contador = 0, ID, cantidad;
    char nombre[20];
    Categoria categoria;

    cantidad = CantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay categorias aún ingresadas" << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        categoria = Leer(i);
        if (categoria.getEstado()) {
            ID = categoria.getID();
            strcpy(nombre, categoria.getNombre());
            if (contador > 0) cout << " || ";
            cout << "ID " << ID << " -> " << nombre;
            contador++;
        }
    }
    cout << endl; // Añadir un salto de línea al final de la lista.
}

int ArchivoCategoria::CargaCategoriaID() {
    int opc, cantidad;
    Categoria categoria;

    cantidad = CantidadRegistros();

    if (cantidad == 0) {
        cout << "Desea ingresar una nueva Categoria o seleccionar una ID existente? (1-SI || 2-NO): ";
        cin >> opc;
        fflush(stdin);
        if (opc == 1) {
            categoria.cargar();
            this->Guardar(categoria);
            return categoria.getID();
        } else {
            ingresoCategoria();
        }
    } else {
        return ingresoCategoria();
    }
    return -1; // En caso de que no se encuentre o el usuario salga.
}
///(M.B)
int ArchivoCategoria::ingresoCategoria() {
    int ID, opc;
    Categoria categoria;

    while (true) {
        cout << "Ingrese el ID de la Categoria: ";
        cin >> ID;
        fflush(stdin);
        int pos = Buscar(ID);

        if (pos != -1 && pos != -2) {
            return ID;
        } else {
            cout << "ID no encontrado. ¿Desea registrar una nueva Categoria en su lugar? (1-SI || 0-NO): ";
            cin >> opc;
            fflush(stdin);
            if (opc == 1) {
                categoria.cargar();
                this->Guardar(categoria);
                return categoria.getID();
            } else if (opc == 0) {
                return -1;  // valor que indique que el usuario no desea registrar una nueva categoría.
            } else {
                cout << "Opción no válida. Por favor, ingrese 1 para registrar o 0 para salir." << endl;
            }
        }
    }
}
void ArchivoCategoria::mostrarCategorias() {
    char nombre[20];
    int ID,cantidad = CantidadRegistros();
    int contador=0;
    Categoria categoria;
    if (cantidad == 0) {
        cout << "No hay marcas aún ingresadas" << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        categoria = Leer(i);
        if (categoria.getEstado()) {
            ID = categoria.getID();
            strcpy(nombre, categoria.getNombre());
            if (contador > 0) cout << " || ";
            cout << "ID " << ID << " -> " << nombre;
            contador++;
        }
    }
}


ArchivoCategoria::~ArchivoCategoria() {
    //dtor
}
