#include "ArchivoCliente.h"
#include "Funciones.h"
#include <cstring>


ArchivoCliente::ArchivoCliente() {
    strcpy(_nombreArchivo,"ArchivoCliente.dat");
}
ArchivoCliente::ArchivoCliente(const char *nombreArchivo) {
    strcpy(_nombreArchivo,nombreArchivo);
}
ArchivoCliente::ArchivoCliente(bool backUp) {
    strcpy(_nombreArchivo,"ArchivoClienteBackUp.dat");
}

bool ArchivoCliente::Guardar(const Cliente& cliente) {
    FILE *pArchivo=nullptr;
    pArchivo= fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCliente::BackUp() {
    FILE *pArchivo = nullptr;
    FILE *pArchivoBackUp = nullptr;

    // Abrir archivo principal en modo lectura
    pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo principal." << endl;
        return false;
    }

    // Abrir archivo de respaldo en modo escritura (crea el archivo si no existe)
    pArchivoBackUp = fopen("ArchivoClienteBackUp.dat", "wb");
    if (pArchivoBackUp == nullptr) {
        cout << "Error al crear el archivo de respaldo." << endl;
        fclose(pArchivo);
        return false;
    }

    Cliente cliente;
    // Leer registros y respaldar aquellos con estado activo
    while (fread(&cliente, sizeof(Cliente), 1, pArchivo) == 1) {
        if (cliente.getEstado()) {  // Verificar si el cliente está activo
            fwrite(&cliente, sizeof(Cliente), 1, pArchivoBackUp);
        }
    }

    fclose(pArchivo);
    fclose(pArchivoBackUp);

    cout << "Backup completado con éxito." << endl;
    return true;
}

bool ArchivoCliente::ModificarRegistro(const Cliente& cliente, int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        fclose(pArchivo);
        return false;
    }
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCliente::BajaRegistro() {
    int DNI;
    Cliente cliente;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de DNI del Cliente: ";
    cin>>DNI;
    int pos=Buscar(DNI);
    if(pos==-1||pos==-2) {
        cout<<"No hay Cliente con es DNI."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    cliente=Leer(pos);
    cliente.setEstado(false);
    bool resultado=ModificarRegistro(cliente,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"El cliente fue dado de Baja"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro del cliente." << endl;
        system("pause");
    }
    return resultado;
}

bool ArchivoCliente::AltaRegistro() {
    int DNI;
    Cliente cliente;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de DNI del Cliente: ";
    cin>>DNI;
    int pos=Buscar(DNI);
    if(pos==-1||pos==-2) {
        cout<<"No hay Cliente con es DNI."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    cliente=Leer(pos);
    cliente.setEstado(true);
    bool resultado=ModificarRegistro(cliente,pos);
    fclose(pArchivo);
    if(resultado) {
        cout<<"El cliente fue dado de Alta"<<endl;
        system("pause");
    } else {
        cout << "Error al modificar el registro del cliente." << endl;
        system("pause");
    }
    return resultado;
}
bool ArchivoCliente::CambiarEstadoRegistro() {
    int DNI,opc;
    bool resultado=false;
    Cliente cliente;
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr) {
        return false;
    }
    cout<<"Ingrese el número de DNI del Cliente: ";
    cin>>DNI;
    int pos=Buscar(DNI);
    if(pos==-1||pos==-2) {
        cout<<"No hay Cliente con es DNI."<<endl;
        system("pause");
        fclose(pArchivo);
        return false;
    }
    cliente=Leer(pos);
    if (cliente.getEstado()) {
        cout<<"El cliente está dado de alta."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            cliente.setEstado(false);
            cout<<"Estado cambiado a Baja."<<endl;
        } else {
            cout<<"El estado permanece en Alta."<<endl;
        }
        resultado=ModificarRegistro(cliente,pos);
    } else {
        cout<<"El cliente está dado de Baja."<<endl;
        cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
        cin>>opc;
        if(opc==1) {
            cliente.setEstado(true);
            cout<<"Estado cambiado a Alta."<<endl;
            resultado=ModificarRegistro(cliente,pos);
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

int ArchivoCliente::Buscar(int IDCliente) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, pArchivo)) {
        if(cliente.getIdCliente() == IDCliente) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -2;
}
Cliente ArchivoCliente::Leer(int posicion) {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return Cliente();
    }
    Cliente cliente;
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return cliente;
}

int ArchivoCliente::CantidadRegistros() {
    FILE *pArchivo=nullptr;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCliente::Listar() {
    int cantidadRegistros=CantidadRegistros();
    FILE *pArchivo=nullptr;
    Cliente cliente;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&cliente, sizeof(Cliente), 1, pArchivo);
        if(cliente.getEstado()==true) {
            cliente.mostrar();
            cout<<"----------------------------------------------"<<endl;
        }
    }
    fclose(pArchivo);
}

ArchivoCliente::~ArchivoCliente() {
    //dtor
}



