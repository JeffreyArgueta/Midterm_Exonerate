#ifndef MEDIDA_H
#define MEDIDA_H

#include <string>

class Medida {
    private:
        int idMedida;
        std::string unidadMed;
    public:
        Medida() { this->idMedida = 0; }
        Medida(int id, std::string um) {
            this->idMedida = id;
            this->unidadMed = um;
        }
        void setIdMedida(int sid) { this->idMedida = sid; }
        int getIdMedida() { return this->idMedida; }
        void setUnidadMed(std::string sum) { this->unidadMed = sum; }
        std::string getUnidadMed() { return this->unidadMed; }
};

#endif // !MEDIDA_H
