//
// Created by igor
//

#ifndef IMOVEIS_CASA_H
#define IMOVEIS_CASA_H


#include "Imovel.h"

class Casa: public Imovel{
private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;

public:

    Casa();

    Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco);

    int getNumPavimentos();

    void setNumPavimentos(int numPavimentos);

    int getNumQuartos();

    void setNumQuartos(int numQuartos);

    double getAreaTerreno();

    void setAreaTerreno(double areaTerreno);

    double getAreaConstruida();

    void setAreaConstruida(double areaConstruida);

};


#endif //IMOVEIS_CASA_H
