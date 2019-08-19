/*
 * SIstemaImobiliaria.cpp
 *
 *  Created on: 19 de jul de 2019
 *      Author: egidio
 */

#include "SistemaImobiliaria.h"

SistemaImobiliaria::SistemaImobiliaria() {
	// TODO Auto-generated constructor stub

}

void SistemaImobiliaria::CadastraImovel(Imovel* imovel) {
	imoveis.push_back(imovel);
}

std::vector<Imovel*> SistemaImobiliaria::getImoveis() {

	std::vector<Imovel*> buffer = imoveis;

	return buffer;
}

std::vector<std::string> SistemaImobiliaria::getDescricao() {
	std::vector<std::string> buffer;

	for(auto i:imoveis){
		buffer.push_back(i->getDescricao());
	}

	return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImovelTipo(int tipo) {
	std::vector<Imovel*> buffer;

	for(auto i: imoveis){
		if(i->getTipoOferta() == tipo)
		buffer.push_back(i);
	}

	return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisAlugarBairro(
		std::string bairro) {

	std::vector<Imovel*> buffer;

	for(auto i: imoveis){
		if(i->getVenda() == false){
			if(i->getBairro() == bairro){
				buffer.push_back(i);
			}
		}

	}

	return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisVenderBairro(
		std::string bairro) {

	std::vector<Imovel*> buffer;

	for(auto i: imoveis){
		if(i->getVenda() == true){
			if(i->getBairro() == bairro){
				buffer.push_back(i);
			}
		}

	}

	return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisCidade(std::string cidade) {
	std::vector<Imovel*> buffer;

	for(auto i: imoveis){
		if(i->getCidade() == cidade){
			buffer.push_back(i);
		}
	}

	return buffer;
}

SistemaImobiliaria::~SistemaImobiliaria() {
	// TODO Auto-generated destructor stub
}

Endereco::~Endereco(){

}

void Endereco::setAll(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade){
	this->logradouro= logradouro;
	this->numero = numero;
	this->cidade = cidade;
	this->bairro = bairro;
	this->cep = cep;
}

Imovel::Imovel():valor(0), venda(false), descricao("none"), tipo(-1) {
}

std::string Imovel::getDescricao(){
	return this->descricao;
}

int Imovel::getTipoOferta(){
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

bool Imovel::getVenda() {
	return this->venda;
}

void Imovel::setTipo(int tipo) {
	this->tipo = tipo;
}

void Imovel::setVenda(bool venda) {
	this->venda = venda;
}

std::string Imovel::getBairro() {
	return endereco.getBairro();
}

std::string Imovel::getCep() {
	return endereco.getCep();
}

std::string Imovel::getCidade() {
	return endereco.getCidade();
}

std::string Imovel::getLogradouro() {
	return endereco.getLogradouro();
}

int Imovel::getNumero() {
	return endereco.getNumero();
}

std::string Imovel::EnderecoToString(){
	return " " + endereco.getLogradouro() + " " + endereco.getNumero() + " " + endereco.getCep() + " " +
			endereco.getBairro() + " " + endereco.getCidade();
}

Imovel::~Imovel() {

}

Casa::Casa(int numPavimentos, int numQuartos, double areaTerreno,
		double areaConstruida, bool venda, double valor, int tipo,
		std::string descricao, std::string logradouro, int numero,
		std::string bairro, std::string cidade, std::string cep) {

	this->numPavimentos = numPavimentos;
	this->numQuartos = numQuartos;
	this->areaTerreno = areaTerreno;
	this->areaConstruida = areaConstruida;
	this->venda = venda;
	this->valor = valor;
	this->tipo = tipo;
	endereco.setAll(logradouro, numero, bairro, cep, cidade);

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

Casa::~Casa() {
}

Apartamento::Apartamento(std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area,
	bool venda, double valor, int tipo, std::string descricao, std::string logradouro, int numero,
	std::string bairro, std::string cidade, std::string cep){


    this->posicao = posicao;
    this->numQuartos = numQuartos;
    this->valorCondominio = valorCondominio;
    this->vagasGaragem = vagasGaragem;
    this->area = area;
    this->venda = venda;
    this->valor = valor;
    this->tipo = tipo;
    endereco.setAll(logradouro, numero, bairro, cep, cidade);
}

std::string Apartamento::getPosicao() {
    return posicao;
}

void Apartamento::setPosicao( std::string posicao) {
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

Apartamento::~Apartamento() {
}

Terreno::Terreno(int area, bool venda, double valor, int tipo, std::string descricao,
		std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep) {

	this->area = area;
	this->venda = venda;
    this->valor = valor;
    this->tipo = tipo;
    endereco.setAll(logradouro, numero, bairro, cep, cidade);
}

double Terreno::getArea() {
    return area;
}

void Terreno::setArea(double area) {
    this->area = area;
}

Terreno::~Terreno() {
}

GerenteDePersistencia::GerenteDePersistencia() {
}

std::vector<Imovel*> GerenteDePersistencia::RecuperaImoveis() {
	std::ifstream buffer;
	std::vector<Imovel*> imoveis;
	Imovel* x;

	buffer.open("Imobiliaria.txt");

	if(!buffer.is_open() ){
		std::cout << "erro ao abrir arquivo" << std::endl;
		return imoveis;
	}

	int tipo;

	buffer >> tipo;

	switch(tipo){
		case 1:{
			x = new Casa;



			imoveis.push_back(x);
			delete x;
			}
			break;
		case 2:{
			x = new Apartamento;

			imoveis.push_back(x);
			delete x;
			}
			break;
		case 3:{
			x = new Terreno;

			imoveis.push_back(x);
			delete x;
		}
		break;
	}

	return imoveis;
}

void GerenteDePersistencia::SalvaImoveis(std::vector<Imovel*> lista) {
	std::ofstream buffer;

	buffer.open("Imobiliaria.txt");

	if(!buffer.is_open() ){
		std::cout << "erro ao abrir arquivo" << std::endl;
		return;
	}

	for (auto i: lista){
		buffer << i->getTipoOferta();
		buffer << i->getValor();
		buffer << i->EnderecoToString();
		buffer << i->getDescricao();
		buffer << i->getVenda();

		switch(i->getTipoOferta()){
			case 1:
				buffer << i->getNumPavimentos();
				buffer << i->getNumQuartos();
				buffer << i->getAreaTerreno();
				buffer << i->getAreaConstruida();
				break;
			case 2:
				buffer << i->getPosicao();
				buffer << i->getNumQuartos();
				buffer << i->getValorCondominio();
				buffer << i->getVagasGaragem();
				buffer << i->getArea();
				break;
			case 3:
				buffer << i->getArea();
		}
	}

	buffer.close();
}

GerenteDePersistencia::~GerenteDePersistencia() {
}
