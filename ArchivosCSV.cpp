#include "ArchivosCSV.h"
#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Persona.h"
#include "Vendedor.h"
#include "Producto.h"
#include "ArchivoCliente.h"
#include "ArchivoMarca.h"
#include "ArchivoCategoria.h"
#include "ArchivoVendedor.h"
#include "ArchivoProducto.h"
using namespace std;

using vectorString = vector<string>;
ArchivosCSV::ArchivosCSV(string nombreArchivo, vectorString encabezados)
    : _nombreArchivo(nombreArchivo), _encabezados(encabezados) {

    ofstream file(_nombreArchivo,ios_base::app);///ABRIMOS EL ARCHIVO EN ESCRITURA Y USAMOS IOS_BASE APP COMO APPEND, DONDE NO VAMOS A SOBREESCRIBIR
    if(file.is_open()) { ///PREGUNTAR SI ESTA ABIERTO CORRECTAMENTE
        for (size_t i=0; i < _encabezados.size(); i++) { ///RECORRE CADA ELEMENTO DEL VECTOR DE STRING Y USA SIZE_T PARA REPRESENTAR EL TAMANIO
            file << _encabezados[i]; ///ESCRIBE EL ELEMENTO ACTUAL DEL VECTOR "_ENCABEZADOS" AL ARCHIVO
            if (i < _encabezados.size() - 1) { ///ASEGURA QUE SE COLOQUE UNA "," LUEGO DE CADA PALABRA, EXCEPTUANDO EL ULTIMO
                file << ",";
            }
        }
        file << endl;///AGREGAMOS UN SALTO DE LINEA AL ARCHIVO
        file.close();///CERRAMOS EL ARCHIVO
    } else {
        ///CUANDO NO SE PUEDA ABRIR, QUE NOS AVISE
        cout << "No se pudo abrir el archivo para escribir Encabezados." << endl;
    }
}


bool ArchivosCSV::escribirFilaCliente() {
    ArchivoCliente archivo;
    int cantidadRegistros = archivo.CantidadRegistros();

    // Asegúrate de que listarEnVectorD devuelve un puntero o usa un contenedor como vector.
    Cliente* vClientes = archivo.listarEnVectorD();

    if (vClientes == nullptr) {
        cout << "Error al obtener los clientes." << endl;
        return false;
    }

    ofstream file(_nombreArchivo, ios_base::app); ///ABRIMOS EL ARCHIVO EN MODO ESCRITURA, CON APP NO SOBREESCRIBIMOS EL ARCHIVO

    if (!file.is_open()) { ///COMPROBAMOS SI EL ARCHIVO SE ABRE CORRECTAMENTE, SI NO QUE NOS RETORNE CON UN MENSAJE
        cout << "Error: No se pudo abrir el archivo" << endl;
        delete[] vClientes;
        return false;
    }

    for (int j = 0; j < cantidadRegistros; j++) {
        file << vClientes[j].getNombre() << ","
             << vClientes[j].getApellido() << ","
             << vClientes[j].getIdCliente() << ","
             << vClientes[j].getFecha() <<","
             << vClientes[j].getTelefono() << ","
             << vClientes[j].getEmail() << ","
             << vClientes[j].getDomicilio()
             << endl; ///NUEVA LINEA PARA CADA REGISTRO
    }

    file.close(); ///CERRAMOS EL ARCHIVO
    delete[] vClientes; ///LIBERA LA MEMORIA DEL VECTOR DINAMICO
    return true;
}
bool ArchivosCSV::escribirFilaVendedor() {
    ArchivoVendedor archivo;
    int cantidadRegistros = archivo.CantidadRegistros();

    // Asegúrate de que listarEnVectorD devuelve un puntero o usa un contenedor como vector.
    Vendedor* vVendedores = archivo.listarEnVectorD();

    if (vVendedores == nullptr) {
        cout << "Error al obtener los vendedores." << endl;
        return false;
    }

    ofstream file(_nombreArchivo, ios_base::app); ///ABRIMOS EL ARCHIVO EN MODO ESCRITURA, CON APP NO SOBREESCRIBIMOS EL ARCHIVO

    if (!file.is_open()) { ///COMPROBAMOS SI EL ARCHIVO SE ABRE CORRECTAMENTE, SI NO QUE NOS RETORNE CON UN MENSAJE
        cout << "Error: No se pudo abrir el archivo" << endl;
        delete[] vVendedores;
        return false;
    }

    for (int j = 0; j < cantidadRegistros; j++) {
        file << vVendedores[j].getIdVendedor() << ","
             << vVendedores[j].getNombre() << ","
             << vVendedores[j].getApellido() << ","
             << vVendedores[j].getIdUsuario() << ","
             << vVendedores[j].getFecha() <<","
             << vVendedores[j].getNivelUsuario()<<","
             << vVendedores[j].getPassword()
             << endl; ///NUEVA LINEA PARA CADA REGISTRO
    }

    file.close(); ///CERRAMOS EL ARCHIVO
    delete[] vVendedores; ///LIBERA LA MEMORIA DEL VECTOR DINAMICO
    return true;
}

bool ArchivosCSV::escribirFilaProducto() {
    ArchivoProducto archivo;
    ArchivoMarca marca;
    ArchivoCategoria categoria;
    int cantidadRegistros = archivo.CantidadRegistros();

    // Asegúrate de que listarEnVectorD devuelve un puntero o usa un contenedor como vector.
    Producto* vProductos = archivo.listarEnVectorD();

    if (vProductos == nullptr) {
        cout << "Error al obtener los productos." << endl;
        return false;
    }

    ofstream file(_nombreArchivo, ios_base::app); ///ABRIMOS EL ARCHIVO EN MODO ESCRITURA, CON APP NO SOBREESCRIBIMOS EL ARCHIVO

    if (!file.is_open()) { ///COMPROBAMOS SI EL ARCHIVO SE ABRE CORRECTAMENTE, SI NO QUE NOS RETORNE CON UN MENSAJE
        cout << "Error: No se pudo abrir el archivo" << endl;
        delete[] vProductos;
        return false;
    }

    for (int j = 0; j < cantidadRegistros; j++) {
        file << vProductos[j].getIdProducto() << ","
             << vProductos[j].getDetalle() << ","
             << marca.Leer(marca.Buscar(vProductos[j].getIdMarca())).getNombre() << ","
             << categoria.Leer(categoria.Buscar(vProductos[j].getIdCategoria())).getNombre() << ",$ "
             << vProductos[j].getPrecioVenta() << ",unidades: "
             << vProductos[j].getStock()
             << endl; ///NUEVA LINEA PARA CADA REGISTRO
    }

    file.close(); ///CERRAMOS EL ARCHIVO
    delete[] vProductos; ///LIBERA LA MEMORIA DEL VECTOR DINAMICO
    return true;
}
ArchivosCSV::~ArchivosCSV() {
    //dtor
}
