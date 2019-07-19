//
// Created by igor
//

#ifndef IMOVEIS_TERRENO_H
#define IMOVEIS_TERRENO_H


#include "Imovel.h"

class Terreno: public Imovel {
private:
    double area;

public:

    Terreno();

    Terreno(double area, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco);

    double getArea();

    void setArea(double area);

};


#endif //IMOVEIS_TERRENO_H
