#include "../include/Venta.hpp"
#include <iostream>
#include <iomanip>

#define WIDTH 12

char menu() {
    char op;
    
    std::cout << "MENU DE OPCIONES" << std::endl;
    std::cout << "1. Agregar cliente" << std::endl;
    std::cout << "2. Agregar producto" << std::endl;
    std::cout << "3. Hacer venta" << std::endl;
    std::cout << "4. Ver lista de clientes" << std::endl;
    std::cout << "5. Ver lista de productos" << std::endl;
    std::cout << "6. Ver lista de ventas" << std::endl;
    std::cout << "7. Ver detalles de la venta" << std::endl;
    std::cout << "8. Salir" << std::endl;
    std::cout << "Digitar opcion: "; std::cin >> op;

    return op;
}

Cliente* agregarCliente() {
    int id;
    std::string n, a;

    std::cout << "Digite el ID del cliente: "; std::cin >> id;
    std::cout << "Digite el nombre del cliente: "; std::cin >> n;
    std::cout << "Digite el apellido del cliente: "; std::cin >> a;

    return new Cliente(id, n, a);
}

Cliente* buscarCliente(List<Cliente*>& lst, int id) {
    List<Cliente*>::iterator pos;
    pos = lst.begin();

    while (pos != lst.end()) {
        Cliente* c = *pos;

        if (c->getIdCliente() == id) { return c; }
        else { pos++; }
    }

    return NULL;
}

Producto* agregarProducto() {
    int id;
    std::string d;
    Medida um(1, "Medida");
    float e;
    
    std::cout << "Digite el ID del producto: "; std::cin >> id;
    std::cout << "Digite la descripcion del producto: "; std::cin >> d;
    std::cout << "Digite la existencia del producto: "; std::cin >> e;

    return new Producto(id, d, um, e);
}

Producto* buscarProducto(List<Producto*>& lst, int id) {
    List<Producto*>::iterator pos;
    pos = lst.begin();

    while (pos != lst.end()) {
        Producto* p = *pos;

        if (p->getIdProducto() == id) { return p; }
        else { pos++; }
    }

    return NULL;
}

Venta* hacerVenta(List<Cliente*>& lstC, List<Producto*>& lstP) {
    int idCliente;
    Venta* v = nullptr;

    std::cout << "Digite el ID del cliente de la venta: "; std::cin >> idCliente;
    Cliente* c = buscarCliente(lstC, idCliente);

    if (c) {
        int nf, idProducto;
        std::string fv;
        char respuesta;

        std::cout << "Digite el numero de factura: "; std::cin >> nf;
        std::cout << "Digite la fecha de venta: "; std::cin >> fv;
        v = new Venta(nf, fv, c);

        do {
            std::cout << "Digite el ID del producto a agregar: "; std::cin >> idProducto; 
            Producto* p = buscarProducto(lstP, idProducto);

            if (p) {
                v->agregarProducto(p);
                std::cout << "Producto agregado con exito a la venta!" << std::endl;
            }
            else { std::cout << "Producto no existente." << std::endl; }

            std::cout << "Desea agregar otro producto? [SI = 1]: "; std::cin >> respuesta;
        } while (respuesta == '1');
    }
    else { std::cout << "Cliente no existente." << std::endl; }
    
    return v;
}

Venta* buscarVenta(List<Venta*>& lst, int nf) {
    List<Venta*>::iterator pos;
    pos = lst.begin();

    while (pos != lst.end()) {
        Venta* v = *pos;

        if (v->getNoFactura() == nf) { return v; }
        else { pos++; }
    }

    return nullptr;
}

void mostrarClientes(List<Cliente*>& lst) {
    if (!lst.empty()) {
        std::cout << std::left;
        std::cout << "------------------------------" << std::endl;
        std::cout << std::setw(WIDTH/2) << "ID";
        std::cout << std::setw(WIDTH) << "Nombre";
        std::cout << std::setw(WIDTH) << "Apellido" << std::endl;
        std::cout << "------------------------------" << std::endl;

        List<Cliente*>::iterator pos = lst.begin();
        while (pos != lst.end()) {
            Cliente* c = *pos;
            std::cout << std::setw(WIDTH/2) << c->getIdCliente();
            std::cout << std::setw(WIDTH) << c->getNombre();
            std::cout << std::setw(WIDTH) << c->getApellido() << std::endl;
            pos++;
        }

        std::cout << "------------------------------" << std::endl;
    }
    else {
        std::cout << "------------------------------" << std::endl;
        std::cout << "          LISTA VACIA         " << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

void mostrarProductos(List<Producto*>& lst) {
    if (!lst.empty()) {
        std::cout << std::left;
        std::cout << "------------------------------" << std::endl;
        std::cout << std::setw(WIDTH/2) << "ID";
        std::cout << std::setw(WIDTH) << "Descripcion";
        std::cout << std::setw(WIDTH) << "Existencia" << std::endl;
        std::cout << "------------------------------" << std::endl;
        
        List<Producto*>::iterator pos = lst.begin();
        while (pos != lst.end()) {
            Producto* p = *pos;
            std::cout << std::setw(WIDTH/2) << p->getIdProducto();
            std::cout << std::setw(WIDTH) << p->getDescripcion();
            std::cout << std::setw(WIDTH) << p->getExistencia() << std::endl;
            pos++;
        }

        std::cout << "------------------------------" << std::endl;
    }
    else {
        std::cout << "------------------------------" << std::endl;
        std::cout << "          LISTA VACIA         " << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

void mostrarVentas(List<Venta*>& lst) {
    if (!lst.empty()) {
        std::cout << std::left;
        std::cout << "----------------------------" << std::endl;
        std::cout << std::setw(WIDTH/2) << "No.";
        std::cout << std::setw(WIDTH) << "Cliente";
        std::cout << std::setw(WIDTH-2) << "Fecha" << std::endl;
        std::cout << "----------------------------" << std::endl;

        List<Venta*>::iterator pos = lst.begin();
        while (pos != lst.end()) {
            Venta* v = *pos;
            std::cout << std::setw(WIDTH/2) << v->getNoFactura();
            std::cout << std::setw(WIDTH) << v->getCliente()->getNombre();
            std::cout << std::setw(WIDTH) << v->getFechaVenta() << std::endl;
            pos++;
        }

        std::cout << "----------------------------" << std::endl;
    }
    else {
        std::cout << "------------------------------" << std::endl;
        std::cout << "          LISTA VACIA         " << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

void verDetallesVenta(List<Venta*>& lst) {
    if (!lst.empty()) {
        int nf;

        std::cout << "Digite el No. de factura: "; std::cin >> nf;
        Venta* venta = buscarVenta(lst, nf);

        if (venta) {
            system("cls");
            std::cout << "No. factura: " << venta->getNoFactura() << std::endl;
            std::cout << "Cliente: " << venta->getCliente()->getNombre() << " " << venta->getCliente()->getApellido() << std::endl;
            std::cout << "Fecha: " << venta->getFechaVenta() << std::endl;

            mostrarProductos(venta->getProductosVendidos());
        }
        else { std::cout << "Venta no existente." << std::endl; }
    }
    else {
        std::cout << "------------------------------" << std::endl;
        std::cout << "          LISTA VACIA         " << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

int main (int argc, char *argv[]) {
    char op;
    List<Cliente*> lstCliente;
    List<Producto*> lstProducto;
    List<Venta*> lstVenta;

    do {
        system("cls");
        op = menu();
        system("cls");

        switch (op) {
            case '1':
                {
                    // AGREGAR CLIENTE
                    lstCliente.push_back(agregarCliente());
                    std::cout << "Cliente agregado con exito!" << std::endl;
                }
                break;
            case '2':
                {
                    // AGREGAR PRODUCTO
                    lstProducto.push_back(agregarProducto());
                    std::cout << "Producto agregado con exito!" << std::endl;
                }
                break;
            case '3':
                {
                    // HACER VENTA
                    lstVenta.push_back(hacerVenta(lstCliente, lstProducto));
                    std::cout << "La venta se realizo con exito!" << std::endl;
                }
                break;
            case '4':
                {
                    // MOSTRAR CLIENTES
                    mostrarClientes(lstCliente);
                }
                break;
            case '5':
                {
                    // MOSTRAR PRODUCTOS
                    mostrarProductos(lstProducto);
                }
                break;
            case '6':
                {
                    // MOSTRAR VENTAS
                    mostrarVentas(lstVenta);
                }
                break;
            case '7':
                {
                    // VER DETALLES VENTA
                    verDetallesVenta(lstVenta);
                }
                break;
            case '8':
                { std::cout << "Saliendo del programa..." << std::endl; }
                break;
            default:
                { std::cout << "Error, opcion no definida." << std::endl; }
                break;
        }

        system("pause"); 
    } while (op != '8');

    return 0;
}
