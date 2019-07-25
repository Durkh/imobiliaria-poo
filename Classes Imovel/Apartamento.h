//
// Created by igor
//

#ifndef IMOVEIS_APARTAMENTO_H
#define IMOVEIS_APARTAMENTO_H

#include <iostream>
#include "Imovel.h"

using namespace std;

class Apartamento: public Imovel {
private:
    string posicao;
    int numQuartos;
    double valorCondominio;
    int vagasGaragem;
    double area;

public:
    Apartamento();

    Apartamento(string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco);

    string getPosicao();

    void setPosicao(string posicao);

    int getNumQuartos();

    void setNumQuartos(int numQuartos);

    double getValorCondominio();

    void setValorCondominio(double valorCondominio);

    int getVagasGaragem();

    void setVagasGaragem(int vagasGaragem);

    double getArea();

    void setArea(double area);

};


#endif //IMOVEIS_APARTAMENTO_H
