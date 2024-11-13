#include "MenuVenta.h"
#include "Fecha.h"
#include "MenuProducto.h"
#include "Factura.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include "ArchivoFactura.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "ArchivoDetalleVenta.h"


MenuVenta::MenuVenta() {
    //ctor
}

Cliente MenuVenta::ObtenerCliente() {
    ArchivoCliente aCliente;
    Cliente cliente;
    int DNI,opc;
    bool bandera=true;
    while (bandera) {
        cout << "Ingrese el DNI del cliente: ";
        cin >> DNI;
        fflush(stdin);

        if (aCliente.Buscar(DNI) == -2) {
            cout << "Cliente no encontrado." << endl;
            cout << "Opciones:" << endl;
            cout << "1. Ingresar otro DNI" << endl;
            cout << "2. Mostrar listado de clientes" << endl;
            cout << "0. Salir al menú principal" << endl;
            cout << "Ingrese una opción: ";
            cin >> opc;
            fflush(stdin);

            switch (opc) {
            case 1:
                break;
            case 2:
                aCliente.listarIdNombreDNI();//modificar método para que solo muestre DNI y Apellido/nombre
                break;
            case 0:
                cout << "Saliendo al menú principal." << endl;
                bandera = false;
                return Cliente();
            default:
                cout << "Opción no válida, por favor intente nuevamente." << endl;
            }
        } else {
            // Cliente encontrado, se carga la información del cliente
            cliente = aCliente.Leer(aCliente.Buscar(DNI));
            cout << "Cliente encontrado: " << cliente.getNombre() << endl;
            bandera = false;  // Termina el bucle
        }
    }
    system("cls");
    //cout<<"IDCliente: "<<cliente.getIdCliente()<<"->"<<cliente.getApellido()<<" "<<cliente.getNombre()<<"."<<endl;
    return cliente;
}


void MenuVenta::realizarVenta(int IDVendedor) {
    ArchivoDetalleVenta aDetalleVenta;
    ArchivoVendedor archivoVendedor;
    MenuProducto mProducto;
    Fecha fechaCompra;
    fechaCompra.cargarFecha();
    ArchivoFactura aFactura;
    ArchivoProducto aProducto;
    Factura factura;
    DetalleVenta detalle;
    int IDProducto, cantidad;

    float precioUnitario;

    // Configuración inicial de la factura
    factura.setIdVendedor(IDVendedor);
    factura.setFechaCompra(fechaCompra);
    factura.setCantidadDetalles(0);
    factura.setTotal(0);
    factura.setNroFactura(factura.proxID()); //ID autoIncremental

    // Obtener y verificar el cliente
    Cliente cliente = ObtenerCliente();
    factura.setIdCliente(cliente.getIdCliente());

    // Registrar productos en la factura
    bool agregarMas = true;
    bool primerDetalle = true; // Bandera para registrar la posición del primer detalle
    while (agregarMas) {
        cout<<"Nro de Factura: "<<factura.getNroFactura()<<endl; //nro de factura
        archivoVendedor.BuscarIDvendedor(IDVendedor); //muestro vendedor
        cliente.mostrarDato(); //muestro cliente

        mProducto.filtroVenta();
        cout << "Ingrese el ID del producto (0 para terminar): ";
        cin >> IDProducto;
        fflush(stdin);
        if (IDProducto == 0) break;

        // Verificar y leer el producto
        int posicionProducto = aProducto.Buscar(IDProducto);
        if (posicionProducto == -2) {
            cout << "Producto no encontrado." << endl;
            continue;
        }

        Producto producto = aProducto.Leer(posicionProducto);
        precioUnitario = producto.getPrecioVenta();
        cout << "Ingrese la cantidad: ";
        cin >> cantidad;
        fflush(stdin);

        if (cantidad > producto.getStock()) {
            cout << "Stock insuficiente." << endl;
            continue;
        }

        // Configurar el detalle y guardarlo
        detalle.setIdFactura(factura.getNroFactura());
        detalle.setIdProducto(IDProducto);
        detalle.setCantidad(cantidad);
        detalle.setPrecioUnitario(precioUnitario);
        detalle.setSubTotal(detalle.calcularSubTotal());

        // Guardar el detalle en el archivo y obtener la posición de inicio si es el primer detalle
        int posicionDetalle = aDetalleVenta.Guardar(detalle);
        if (primerDetalle) {
            factura.setPosicionDetalleInicio(posicionDetalle);
            primerDetalle = false;
        }

        // Actualizar factura
        factura.setCantidadDetalles(factura.getCantidadDetalles() + 1);
        factura.setTotal((factura.getTotal() + detalle.getSubTotal()));

        // Actualizar stock
        producto.setStock(producto.getStock() - cantidad);
        aProducto.ModificarRegistro(producto, posicionProducto);

        cout << "Producto agregado a la venta." << endl;
        system("cls");
    }

    // Guardo
    aFactura.Guardar(factura);

    cout << "Venta completada. Total: $" << factura.getTotal() << endl;
}


void MenuVenta::mostrarDetallesVenta() {
    int IDVenta;
    cout<<"Ingrese el Nro de Factura:";
    cin>>IDVenta;
    fflush(stdin);

    ArchivoFactura aFactura;
    ArchivoDetalleVenta aDetalleVenta;
    ArchivoCliente aCliente;
    ArchivoVendedor aVendedor;
    ArchivoProducto aProducto;

    // Buscar la factura en el archivo
    int posicionFactura = aFactura.BuscarPorID(IDVenta);
    if (posicionFactura == -1) {
        cout << "Factura no encontrada." << endl;
        return;
    }

   Factura factura = aFactura.Leer(posicionFactura);

    // Obtener datos del cliente
    int idCliente = factura.getIdCliente();
    Cliente cliente = aCliente.Leer(aCliente.Buscar(idCliente));

    // Obtener datos del vendedor
    int idVendedor = factura.getIdVendedor();
    Vendedor vendedor = aVendedor.Leer(aVendedor.Buscar(idVendedor));
    system("cls");

    // Mostrar datos de la factura, cliente y vendedor
    cout << "Factura Nro: " << factura.getNroFactura() << endl;
    cout << "Fecha de Venta: " << factura.getFechaCompra().getFechaCompleta() << endl;
    cout << "Cliente: " << cliente.getApellido()<<" "<< cliente.getNombre()  << " - DNI: " << cliente.getIdCliente() << endl;
    cout << "Vendedor: " << vendedor.getApellido()<<" "<< vendedor.getNombre() << " - ID: " << vendedor.getIdVendedor() << endl;
    cout << "Total: $" << factura.getTotal() << endl;
    cout << "Detalles de Venta:" << endl;

    // Leer y mostrar cada detalle de la venta
    /*int cantidadDetalles = factura.getCantidadDetalles();
    int posicionInicio = factura.getPosicionDetalleInicio();*/
    int cantidadDetalles = aDetalleVenta.CantidadRegistros();

    for (int i = 0; i < cantidadDetalles; i++) {
        DetalleVenta detalle = aDetalleVenta.Leer(i);


            if(detalle.getIdFactura()==IDVenta){
        cout <<"ID: "<<detalle.getIdProducto() <<"|| Producto: " << aProducto.Leer(aProducto.Buscar(detalle.getIdProducto())).getDetalle() << "||"<< "Cantidad: " << detalle.getCantidad() << "||"<< "Precio Unitario: $" << detalle.getPrecioUnitario() <<"||"<< "Subtotal: $" << detalle.getSubTotal() << endl;
        cout << endl;

            }
        /*DetalleVenta detalle = aDetalleVenta.Leer(posicionInicio + i);
        Producto producto = aProducto.Leer(aProducto.Buscar(detalle.getIdProducto()));*/

    }
     /* for (int i = 0; i < cantidadDetalles; i++) {
        DetalleVenta detalle = aDetalleVenta.Leer(posicionInicio + i);
        Producto producto = aProducto.Leer(aProducto.Buscar(detalle.getIdProducto()));

        cout << "Producto: " << producto.getDetalle() << endl;
        cout << "Cantidad: " << detalle.getCantidad() << endl;
        cout << "Precio Unitario: $" << detalle.getPrecioUnitario() << endl;
        cout << "Subtotal: $" << detalle.getSubTotal() << endl;
        cout << "----------------------------" << endl;
    }*/

}




MenuVenta::~MenuVenta() {
    //dtor
}
