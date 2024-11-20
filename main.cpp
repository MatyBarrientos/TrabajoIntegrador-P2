#include <iostream>
#include <locale>
#include "MenuOpciones.h"
#include "ArchivoCategoria.h"
#include "MenuProducto.h"

using namespace std;

int main() {

    setlocale(LC_ALL,"");
    MenuOpciones mo;
    mo.ingresoSistema();
    return 0;
}
