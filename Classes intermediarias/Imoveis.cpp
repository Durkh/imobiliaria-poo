/*
 * Imoveis.cpp
 *
 *  Created on: 18 de jul de 2019
 *      Author: egidio
 */

#include "Imoveis.h"

Endereco::~Endereco(){

}

Imovel::Imovel():valor(0), venda(false), descricao("none"), tipo(-1) {

	endereco = endereco.Endereco();

}

std::string Imovel::getDescricao(){
	return this->descricao;
}

bool Imovel::getTipoOferta(){
	return this->tipo;
}

Endereco Imovel::getEndereco(){
	return this->endereco;
}

double Imovel::getValor(){
	return this->valor;
}

void Imovel::setDescricao(std::string desc){
	this->descricao = desc;
}

void Imovel::setValor(double valor){
	this->valor = valor;
}

void Imovel::setEndereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep){
	endereco.setBairro(bairro);
	endereco.setCep(cep);
	endereco.setCidade(cidade);
	endereco.setLogradouro(logradouro);
	endereco.setNumero(numero);
}

Imovel::~Imovel() {
	// TODO Auto-generated destructor stub
}

