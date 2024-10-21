#ifndef VENTA_H
#define VENTA_H

#include "Cliente.hpp"
#include "Producto.hpp"
#include "../LST/List.hpp"

class Venta {
    private:
        int noFactura;
        std::string fechaVenta;
        Cliente* cliente;
        List<Producto*> productosVendidos;
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
        void agregarProducto(Producto* ap) { this->productosVendidos.push_back(ap); }
        List<Producto*>& getProductosVendidos() { return this->productosVendidos; }
};

#endif // !VENTA_H
