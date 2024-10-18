#ifndef VENTA_H
#define VENTA_H

// #include "../lib/list.hpp"
#include "Cliente.hpp"
#include "Producto.hpp"

class Venta {
    private:
        int noFactura;
        std::string fechaVenta;
        Cliente* cliente;
        // list<Producto*> productosVendidos;
    public:
        Venta() { this->noFactura = 0; }
        Venta(int nf, std::string fv, Cliente* c) {
            this->noFactura = nf;
            this->fechaVenta = fv;
            this->cliente = c;
        }
        void setNoFactura(int snf) { this->noFactura = snf; }
        int getNoFactura() { return this->noFactura; }
        void setFechaVenta(std::string sfv) { this->fechaVenta = sfv; }
        std::string getFechaVenta() { return this->fechaVenta; }
        void setCliente(Cliente* sc) { this->cliente = sc; }
        Cliente* getCliente() { return this->cliente; }
        // void setProductosVendidos(list<Producto*> spv) { this->productosVendidos = spv; }
        // list<Producto*> getProductosVendidos() { return this->productosVendidos; }
};

#endif // !VENTA_H
