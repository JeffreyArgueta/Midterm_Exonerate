#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Medida.hpp"

class Producto {
    private:
        int idProducto;
        std::string descripcion;
        float precioUnitario;
        Medida unidadMedida;
        float existencia;
    public:
        Producto() {
            this->idProducto = 0;
            this->precioUnitario = 0;
            this->existencia = 0;
        }
        Producto(int id, std::string d, Medida um, float e) {
            this->idProducto = id;
            this->descripcion = d;
            this->unidadMedida = um;
            this->existencia = e;
        }
        void setIdProducto(int sid) { this->idProducto = sid; }
        int getIdProducto() { return this->idProducto; }
        void setDescripcion(std::string sd) { this->descripcion = sd; }
        std::string getDescripcion() { return this->descripcion; }
        void setPrecioUnitario(float spu) { this->precioUnitario = spu; }
        float getPrecioUnitario() { return this->precioUnitario; }
        void setUnidadMedida(Medida sum) { this->unidadMedida = sum; }
        Medida getUnidadMedida() { return this->unidadMedida; }
        void setExistencia(float se) { this->existencia = se; }
        float getExistencia() { return this->existencia; }
};

#endif // !PRODUCTO_H
