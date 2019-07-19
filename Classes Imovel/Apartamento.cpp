//
// Created by igor
//

#include "Apartamento.h"

Apartamento::Apartamento() {}

Apartamento::Apartamento(string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, int IMOVEL_PARA_VENDER, int IMOVEL_PARA_ALUGUEL, double valor, int tipoOferta, Endereco endereco){
    this->posicao = posicao;
    this->numQuartos = numQuartos;
    this->valorCondominio = valorCondominio;
    this->vagasGaragem = vagasGaragem;
    this->area = area;
    this->IMOVEL_PARA_VENDER = IMOVEL_PARA_VENDER;
    this->IMOVEL_PARA_ALUGUEL = IMOVEL_PARA_ALUGUEL;
    this->valor = valor;
    this->tipoOferta = tipoOferta;
    this->endereco = endereco;
}

string Apartamento::getPosicao() {
    return posicao;
}

void Apartamento::setPosicao( string posicao) {
    this->posicao = posicao;
}

int Apartamento::getNumQuartos() {
    return numQuartos;
}

void Apartamento::setNumQuartos(int numQuartos) {
    this->numQuartos = numQuartos;
}

double Apartamento::getValorCondominio() {
    return valorCondominio;
}

void Apartamento::setValorCondominio(double valorCondominio) {
    this->valorCondominio = valorCondominio;
}

int Apartamento::getVagasGaragem() {
    return vagasGaragem;
}

void Apartamento::setVagasGaragem(int vagasGaragem) {
    this->vagasGaragem = vagasGaragem;
}

double Apartamento::getArea() {
    return area;
}

void Apartamento::setArea(double area) {
    this->area = area;
}




