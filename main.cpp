#include <iostream>
#include <locale>
#include "MenuOpciones.h"

using namespace std;

int main() {
     setlocale(LC_ALL,"");
    MenuOpciones mo;
    mo.ingresoSistema();
    return 0;
}
