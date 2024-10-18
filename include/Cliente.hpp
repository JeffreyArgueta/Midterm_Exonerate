#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
    private:
        int idCliente;
        std::string nombre;
        std::string apellido;
    public:
        Cliente() { this->idCliente = 0; }
        Cliente(int id, std::string n, std::string a) {
            this->idCliente = id;
            this->nombre = n;
            this->apellido = a;
        }
        void setIdCliente(int sid) { this->idCliente = sid; }
        int getIdCliente() { return this->idCliente; }
        void setNombre(std::string sn) { this->nombre = sn; }
        std::string getNombre() { return this->nombre; }
        void setApellido(std::string sa) { this->apellido = sa; }
        std::string getApellido() { return this->apellido; }
};

#endif // !CLIENTE_H
