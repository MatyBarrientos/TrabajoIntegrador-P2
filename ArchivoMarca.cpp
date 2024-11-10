#include "ArchivoMarca.h"
#include "Funciones.h"
#include <cstring>

ArchivoMarca::ArchivoMarca()
{
    strcpy(_nombreArchivo,"ArchivoCliente.dat");
}
ArchivoMarca::ArchivoMarca(const char *nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoMarca::~ArchivoMarca()
{
    strcpy(_nombreArchivo,"ArchivoMarcaBackUp.dat");
}
bool ArchivoMarca::Guardar(const Marca& marca) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&marca, sizeof(Marca), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoMarca::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }

    // Abrir archivo de respaldo en modo escritura (crea el archivo si no existe)
    pArchivoBackUp = fopen("ArchivoMarcaBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }

    Marca marca;
    // Leer registros y respaldar aquellos con estado activo
    while (fread(&marca, sizeof(Marca), 1, pArchivo) == 1) {
        if (marca.getEstado()) {  // Verificar si marca está activo
            fwrite(&marca, sizeof(Marca), 1, pArchivoBackUp);
        }
    }

    fclose(pArchivo);
    fclose(pArchivoBackUp);

    cout << "Backup completado con éxito." << endl;
    return true;
}

bool ArchivoMarca::ModificarRegistro(const Marca& marca, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Marca) * posicion, SEEK_SET);
    bool ok = fwrite(&marca, sizeof(Marca), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoMarca::CambiarEstadoRegistro() {
    int IDMarca,opc;
    bool resultado=false;
    Marca marca;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de ID de la Marca: ";
    cin>>IDMarca;
    int pos=Buscar(IDMarca);
    if(pos==-1||pos==-2) {
        cout<<"No hay Marca con esa ID."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    marca=Leer(pos);
    if (marca.getEstado()) {
        cout<<"La Marca está dada de alta."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            marca.setEstado(false);
            cout<<"Estado cambiado a Baja."<<endl;
        } else {
            cout<<"El estado permanece en Alta."<<endl;
        }
        resultado=ModificarRegistro(marca,pos);
    } else {
        cout<<"La Marca está dado de Baja."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            marca.setEstado(true);
            cout<<"Estado cambiado a Alta."<<endl;
            resultado=ModificarRegistro(marca,pos);
        } else {
            cout<<"El estado permanece en Baja."<<endl;
        }
    }
    fclose(pArchivo);
    if(!resultado) {
        cout << "Error al modificar el registro de la Marca." << endl;
        system("pause");
    }
    return resultado;
}
int ArchivoMarca::Buscar(int IDMarca) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Marca marca;
    int i = 0;
    while(fread(&marca, sizeof(Marca), 1, pArchivo)) {
        if(marca.getIdMarca() == IDMarca) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
Marca ArchivoMarca::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return Marca();
    }
    Marca marca;
    fseek(pArchivo, sizeof(Marca) * posicion, SEEK_SET);
    fread(&marca, sizeof(Marca), 1, pArchivo);
    fclose(pArchivo);
    return marca;
}
int ArchivoMarca::CantidadRegistros() {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Marca);
    fclose(pArchivo);
    return cantidadRegistros;
}
void ArchivoMarca::Listar() {
    int cantidadRegistros=CantidadRegistros();
    FILE *pArchivo=nullptr;
    Marca marca;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&marca, sizeof(Marca), 1, pArchivo);
        if(marca.getEstado()==true) {
            marca.mostrar();
            cout<<"----------------------------------------------"<<endl;
        }
    }
    fclose(pArchivo);
}
