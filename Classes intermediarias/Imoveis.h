/*
 * Imoveis.h
 *
 *  Created on: 18 de jul de 2019
 *      Author: egidio
 */

#ifndef IMOVEIS_H_
#define IMOVEIS_H_

#include <iostream>

class Endereco{
private:
	std::string logradouro;
	int numero;
	std::string bairro;
	std::string cidade;
	std::string cep;
public:
	Endereco():logradouro("default"), numero(0), bairro("default"), cidade("default"), cep("default") {}

	std::string getBairro(){return bairro;}
	void setBairro(std::string bairro) {this->bairro = bairro;}
	std::string getCep() {return cep;}
	void setCep(std::string cep) {this->cep = cep;}
	std::string getCidade() {return cidade;}
	void setCidade(std::string cidade) {this->cidade = cidade;}
	std::string getLogradouro() const {return logradouro;}
	void setLogradouro(std::string logradouro) {this->logradouro = logradouro;}
	int getNumero() {return numero;}
	void setNumero(int numero) {this->numero = numero;}

	virtual ~Endereco();
};

class Imovel {
protected:
	double valor;
	bool venda;
	Endereco endereco;
	std::string descricao;
	int tipo;
public:
	Imovel();

	virtual double getValor();
	virtual bool getTipoOferta();
	virtual Endereco getEndereco();
	virtual std::string getDescricao();
	virtual void setDescricao(std::string descricao);
	virtual void setEndereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);
	virtual void setValor(double valor);

	virtual ~Imovel();
};

#endif /* IMOVEIS_H_ */
