#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoProducto.h"
#include "ArchivoCategoria.h"
#include "ArchivoCliente.h"
#include "ArchivosCSV.h"
#include "MenuOpciones.h"

using namespace std;

int main() {
    MenuOpciones mo;
    mo.ingresoSistema();
    /*ArchivoVendedores vendedor;
    ArchivosCSV muestra("Respaldos/Vendedores.csv",vendedores.getEncabezados());
    muestra.escribirFilaProdcuto();
    ArchivoCliente cliente;
    ArchivosCSV muestra("Respaldos/Cliente.csv",cliente.getEncabezados());
    muestra.escribirFilaProdcuto();
    ArchivoProducto producto;
    ArchivosCSV muestra("Respaldos/productos.csv",producto.getEncabezados());
    muestra.escribirFilaProdcuto();*/
    return 0;
}
