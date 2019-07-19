//
// Created by igor
//

#include "Terreno.h"

Terreno::Terreno() {}

Terreno::Terreno(double area, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco){
    this->area = area;
    this->IMOVEL_PARA_VENDER = IMOVEL_PARA_VENDER;
    this->IMOVEL_PARA_ALUGUEL = IMOVEL_PARA_ALUGUEL;
    this->valor = valor;
    this->tipoOferta = tipoOferta;
    this->endereco = endereco;
}

double Terreno::getArea() {
    return area;
}

void Terreno::setArea(double area) {
    this->area = area;
}


