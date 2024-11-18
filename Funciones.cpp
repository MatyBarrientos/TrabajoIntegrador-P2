#include "Funciones.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Producto.h"
#include <limits>


#include <iostream>
using namespace std;

///FUNCION DE CARGAR CADENA

void cargarCadena(char *pal, int tam) {
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++) {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

/*void definirVectorString(string* &v, int tam) {
    v=new string [tam];
    if (v==nullptr) {
        cout<<"Error de asignación de Memoria"<<endl;
        exit(-1);
    } else {
        cout<<"Vector creado correctamente."<<endl;
    }
}*/

void definirVectorEntero(int* &v, int tam) {
    v=new int [tam]();
    if (v==nullptr) {
        cout<<"Error de asignación de Memoria"<<endl;
        exit(-1);
    } else {
        cout<<"Vector creado correctamente."<<endl;
    }
}
void definirVectorBool(bool* &v, int tam) {
    v=new bool[tam]();
    if (v==nullptr) {
        cout<<"Error de asignación de Memoria"<<endl;
        exit(-1);
    } else {
        cout<<"Vector creado correctamente."<<endl;
    }
}

void definirVectorCliente(Cliente* &v, int tam) {
    v=new Cliente [tam]();
    if (v==nullptr) {
        cout<<"Error de asignación de Memoria"<<endl;
        exit(-1);
    } else {
        cout<<"Vector creado correctamente."<<endl;
    }
}


