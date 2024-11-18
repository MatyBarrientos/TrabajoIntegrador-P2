#include <iostream>
#include "MenuProducto.h"
#include "ArchivoCategoria.h"
#include "ArchivoMarca.h"
#include "Funciones.h"
#include <limits>

///(I.V)
MenuProducto::MenuProducto() {} ///ctor

///(OPC 1)AGREGAR NUEVO PRODUCTO AL ARCHIVO PRODUCTO
void MenuProducto::agregarProducto() {
    Producto producto;
    ArchivoProducto ArchP;
    producto.cargarProducto(ArchP.autoIncrementalID());
    ArchP.Guardar(producto);
    system("pause");
}
///(OPC2)CAMBIAR ESTADO DE PRODUCTO
void MenuProducto::cambiarEstadoProducto() {
    int inID, pos, opc;
    ArchivoProducto auxArch;
    Producto producto;
    cout<<"Ingresar el ID del producto al que desea cambiar el estado: "<<endl;
    cin>>inID;
    fflush(stdin);
    pos=auxArch.Buscar(inID); ///BUSCAMOS LA POSICION EN EL ARCHIVO
    if(pos==-1) { ///SI DEVUELVE -1 ES XQ NO ESTA EL ID EN EL ARCHIVO
        cout<<"ID no encontrado."<<endl;
        system("pause");
    } else { ///ACA SE TRABAJA UNA VEZ ENCONTRADO EL ID EN EL ARCHIVO
        producto=auxArch.Leer(pos); ///LEEMOS EL OBJ PRODUCTO
        ///ACA TRABAJAMOS SI ESTADO == TRUE
        if(producto.getEstado()) {
            cout<<"El producto esta dado de alta."<<endl;
            cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
            cin>>opc;
            fflush(stdin);
            if(opc==1) { /// PREG SI LE QUIERE CAMBIAR EL ESTADO A FALSE
                producto.setEstado(false); ///SETTEAMOS EL ESTADO
                //producto.mostrarProducto(); ///PARA VERIFICAR QUE EL CAMBIO SE HIZO
                bool ok1 = auxArch.ModificarRegistro(producto,pos); ///GUARDAMOS EL CAMBIO
                if(ok1) { ///VERIFICAMOS QUE EL CAMBIO SE HALLA REALIZADO
                    cout<<"Estado cambiado a Baja."<<endl;
                } else cout <<"El estado no se pudo modificar (error al abrir el archivo)."<<endl;
                system("pause");
            } else cout<<"El estado permanece en Alta."<<endl;
            system("pause");
            ///ACA TRABAJAMOS SI ESTADO == FALSE
        } else {
            cout<<"El Producto esta dado de Baja."<<endl;
            cout<<"Desea cambiar el estado? (1- Si || 2- NO) :";
            cin>>opc;
            fflush(stdin);
            if(opc==1) { /// PREG SI LE QUIERE CAMBIAR EL ESTADO A TRUE
                producto.setEstado(true); ///SETTEAMOS EL ESTADO
                //producto.mostrarProducto(); ///PARA VERIFICAR QUE EL CAMBIO SE HIZO
                bool ok2 = auxArch.ModificarRegistro(producto,pos); ///GUARDAMOS EL CAMBIO
                if(ok2) { ///VERIFICAMOS QUE EL CAMBIO SE HALLA REALIZADO
                    cout<<"Estado cambiado a Alta."<<endl;
                } else cout <<"El estado no se pudo modificar (error al abrir el archivo)."<<endl;
                system("pause");
            } else cout<<"El estado permanece en Baja."<<endl;
            system("pause");
        }
    }
}
///(OPC 3)BUSCAR PRODUCTO POR ID
void MenuProducto::buscarProducto() {
    int inID, pos;
    ArchivoProducto auxArch;
    cout<<"Ingresar el ID del producto que desea buscar: "<<endl;
    cin>>inID;
    fflush(stdin);
    pos=auxArch.Buscar(inID); ///BUSCAMOS LA POSICION EN EL ARCHIVO DEL ID
    if(pos==-1) { ///SI DEVUELVE -1 ES XQ NO ESTA EL ID EN EL ARCHIVO
        cout<<"ID no encontrado."<<endl;
    } else auxArch.Leer(pos).mostrarProducto(); ///SINO,LO MOSTRAMOS
    system("pause");
}
///(OPC 4)MODIFICAR PRODUCTO EN EL ARCHIVO
void MenuProducto::modificarProducto() {
    int inID, pos;
    Producto producto;
    ArchivoProducto archivo;
    cout<<"Ingresar el ID del producto al que desea modificar: "<<endl;
    cin>>inID;
    fflush(stdin);
    pos=archivo.Buscar(inID); ///BUSCAMOS LA POSICION EN EL ARCHIVO
    if(pos==-1) { ///SI DEVUELVE -1 ES XQ NO ESTA EL ID EN EL ARCHIVO
        cout<<"ID no encontrado."<<endl;
        system("pause");
    } else { ///ACA SE TRABAJA UNA VEZ ENCONTRADO EL ID EN EL ARCHIVO
        producto=archivo.Leer(pos); ///LEEMOS EL OBJ PRODUCTO
        producto.mostrarProducto(); ///MOSTRAMOS POR PANTALLA EL REGISTRO
        producto.modificarProducto(); ///MODIFICAMOS EL REGISTRO
        bool ok = archivo.ModificarRegistro(producto,pos); ///GUARDAMOS EL CAMBIO
        if(ok) { ///VERIFICAMOS QUE EL CAMBIO SE HALLA REALIZADO
            cout<<"Modificacion exitosa."<<endl;
        } else cout <<"El producto no se pudo modificar."<<endl;
        system("pause");
    }
}
void MenuProducto::listarProductos() {///LISTA TODOS LOS PRODUCTOS DEL ARCHIVO
    ArchivoProducto aux;
    aux.Listar();
    system("pause");
}
///(OPC 5)LISTAR PRODUCTOS
void MenuProducto::listarProductoActivo(){//OPC 1
    ArchivoProducto archivoP;
    Producto producto;
    int contador=0;
    int i, cantidadRegistros = archivoP.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++){
        producto = archivoP.Leer(i);
        if(producto.getEstado()){///SI EL ESTADO ES TRUE, LO MUESTRA
        cout<<"-------------------------------------------"<<endl;
        producto.mostrarProducto();
        contador++;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"Cantidad de registros ACTIVOS: "<<contador<<endl;
    system("pause");
}
void MenuProducto::listarProductoBaja(){//OPC 2
    ArchivoProducto archivoP;
    Producto producto;
    int contador=0;
    int i, cantidadRegistros = archivoP.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++){
        producto = archivoP.Leer(i);
        if(!producto.getEstado()){///SI EL ESTADO ES FALSE, LO MUESTRA
        cout<<"-------------------------------------------"<<endl;
        producto.mostrarProducto();
        contador++;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"Cantidad de registros DADOS DE BAJA: "<<contador<<endl;
    system("pause");
}
void MenuProducto::listarProductoMarca(){//OPC 3
    cout<<"FASTA HACER"<<endl;
    system("pause");
}
void MenuProducto::listarProductoCat(){//OPC 4
    cout<<"FASTA HACER"<<endl;
    system("pause");
}
/////Filtrar por Categoria Marca

void MenuProducto::filtroVenta() {
    int IDcat,IDmarca;
    ArchivoCategoria archivoCategoria;
    ArchivoMarca archivoMarca;
    ArchivoProducto archivoProducto;
    archivoCategoria.mostrarCategorias();
    cout<<endl;
    cout<<"Categoria:";
    cin>>IDcat;
    fflush(stdin);
    archivoProducto.mostrarMarcasPorCategoria(IDcat);
    cout<<endl;
    cout<<"Marca:";
    cin>>IDmarca;
    fflush(stdin);
    archivoProducto.mostrarProductosPorMarcaYCategoria(IDcat,IDmarca);
    system("pause");

}

MenuProducto::~MenuProducto() {} ///dtor
