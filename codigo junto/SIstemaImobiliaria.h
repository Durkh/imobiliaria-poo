/*
 * SIstemaImobiliaria.h
 *
 *  Created on: 19 de jul de 2019
 *      Author: egidio
 */

#ifndef SISTEMAIMOBILIARIA_H_
#define SISTEMAIMOBILIARIA_H_

#include <iostream>
#include <vector>

class GerenteDePersistencia{
	GerenteDePersistencia();
	virtual ~GerenteDePersistencia();
};

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
	void setAll(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade);

	virtual ~Endereco();
};

class Imovel {
protected:
	double valor;
	bool venda;
	bool aluguel;
	Endereco endereco = Endereco();
	std::string descricao;
	int tipo;
public:
	Imovel();
	Imovel(bool venda, bool aluguel, double valor, int tipo, Endereco endereco, std::string descricao);

	virtual double getValor();
	virtual bool getTipoOferta();
	virtual Endereco getEndereco();
	virtual std::string getDescricao();
	virtual void setDescricao(std::string descricao);
	virtual void setEndereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);
	virtual void setValor(double valor);

	virtual ~Imovel();
};

class Casa: public Imovel{
private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
public:

    Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida, bool venda, bool aluguel, double valor, int tipo, std::string descricao, std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);

	int getNumPavimentos();
	void setNumPavimentos(int numPavimentos);
	int getNumQuartos();
	void setNumQuartos(int numQuartos);
	double getAreaTerreno();
	void setAreaTerreno(double areaTerreno);
	double getAreaConstruida();
	void setAreaConstruida(double areaConstruida);

	virtual ~Casa();
};

class Apartamento: public Imovel{
private:
	std::string posicao;
	int numQuartos;
	double valorCondominio;
	int vagasGaragem;
	double area;
public:
	Apartamento(std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, bool venda, bool aluguel, double valor, int tipo, std::string descricao, std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);

	std::string getPosicao();
	void setPosicao(std::string posicao);
	int getNumQuartos();
	void setNumQuartos(int numQuartos);
	double getValorCondominio();
	void setValorCondominio(double valorCondominio);
	int getVagasGaragem();
	void setVagasGaragem(int vagasGaragem);
	double getArea();
	void setArea(double area);

	virtual ~Apartamento();
};

class Terreno: public Imovel{
private:
    double area;
public:
	Terreno(int area, bool venda, bool aluguel, double valor, int tipo, std::string descricao, std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);
	virtual ~Terreno();

	double getArea();
	void setArea(double area);
};

class SIstemaImobiliaria {
private:
	std::vector<Imovel> imoveis;
public:
	SIstemaImobiliaria();
	virtual ~SIstemaImobiliaria();
};

#endif /* SISTEMAIMOBILIARIA_H_ */
