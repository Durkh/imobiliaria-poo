//
// Created by igor
//

#include "Casa.h"

Casa::Casa() {}

Casa::Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco){
    this->numPavimentos = numPavimentos;
    this->numQuartos = numQuartos;
    this->areaTerreno = areaTerreno;
    this->areaConstruida = areaConstruida;
    this->IMOVEL_PARA_VENDER = IMOVEL_PARA_VENDER;
    this->IMOVEL_PARA_ALUGUEL = IMOVEL_PARA_ALUGUEL;
    this->valor = valor;
    this->tipoOferta = tipoOferta;
    this->endereco = endereco;
}

int Casa::getNumPavimentos() {
    return numPavimentos;
}

void Casa::setNumPavimentos(int numPavimentos) {
    this->numPavimentos = numPavimentos;
}

int Casa::getNumQuartos() {
    return numQuartos;
}

void Casa::setNumQuartos(int numQuartos) {
    this->numQuartos = numQuartos;
}

double Casa::getAreaTerreno() {
    return areaTerreno;
}

void Casa::setAreaTerreno(double areaTerreno) {
    this->areaTerreno = areaTerreno;
}

double Casa::getAreaConstruida() {
    return areaConstruida;
}

void Casa::setAreaConstruida(double areaConstruida) {
    this->areaConstruida = areaConstruida;
}


