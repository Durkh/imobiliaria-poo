/*
 * SIstemaImobiliaria.cpp
 *
 *  Created on: 19 de jul de 2019
 *      Author: egidio
 */

#include "SIstemaImobiliaria.h"

SIstemaImobiliaria::SIstemaImobiliaria() {
	// TODO Auto-generated constructor stub

}

SIstemaImobiliaria::~SIstemaImobiliaria() {
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

Imovel::Imovel():valor(0), venda(false), aluguel(false), descricao("none"), tipo(-1) {

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

}

Casa::Casa(int numPavimentos, int numQuartos, double areaTerreno,
		double areaConstruida, bool venda, bool aluguel, double valor, int tipo,
		std::string descricao, std::string logradouro, int numero,
		std::string bairro, std::string cidade, std::string cep) {

	this->numPavimentos = numPavimentos;
	this->numQuartos = numQuartos;
	this->areaTerreno = areaTerreno;
	this->areaConstruida = areaConstruida;
	this->venda = venda;
	this->aluguel = aluguel;
	this->valor = valor;
	this->tipo = tipo;
	this->endereco = endereco.setAll(logradouro, numero, bairro, cep, cidade);

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
	bool venda, bool aluguel, double valor, int tipo, std::string descricao, std::string logradouro, int numero,
	std::string bairro, std::string cidade, std::string cep){


    this->posicao = posicao;
    this->numQuartos = numQuartos;
    this->valorCondominio = valorCondominio;
    this->vagasGaragem = vagasGaragem;
    this->area = area;
    this->venda = venda;
    this->aluguel = aluguel;
    this->valor = valor;
    this->tipo = tipo;
    this->endereco = endereco.setAll(logradouro, numero, bairro, cep, cidade);
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

Terreno::Terreno(int area, bool venda, bool aluguel, double valor, int tipo, std::string descricao,
		std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep) {

	this->area = area;
	this->venda = venda;
	this->aluguel = aluguel;
    this->valor = valor;
    this->tipo = tipo;
    this->endereco = endereco.setAll(logradouro, numero, bairro, cep, cidade);
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

GerenteDePersistencia::~GerenteDePersistencia() {
}
