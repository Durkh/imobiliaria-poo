/*
 * SIstemaImobiliaria.cpp
 *
 *  Created on: 19 de jul de 2019
 *      Author: egidio
 */

#include "SistemaImobiliaria.h"

#include <sstream>
#include <boost/algorithm/string.hpp>
#include <string>

SistemaImobiliaria::SistemaImobiliaria() {
    // TODO Auto-generated constructor stub

}

void SistemaImobiliaria::CadastraImovel(Imovel* imovel) {
    imoveis.push_back(imovel);
}

std::vector<Imovel*> SistemaImobiliaria::getImoveis() {

  int indice = 0;

    for(auto &i: imoveis){
      i->setIndice(indice);
      indice++;
    }

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
    int indice =0;

    for(auto i: imoveis){
        if(i->getTipoOferta() == tipo){
            i->setIndice(indice);
            buffer.push_back(i);
          }
        indice++;
    }

    return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImovelOferta(int oferta){
  std::vector<Imovel*> myVector;
  int indice = 0;

  for(auto &i: imoveis){
    if(i->getVenda() == oferta){
      i->setIndice(indice);
      myVector.push_back(i);
    }
    indice++;
  }

  return myVector;
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
    std::string temp;
    int indice = 0;

    boost::algorithm::to_lower(cidade);

    for(auto i: imoveis){
      temp = i->getCidade();
      boost::algorithm::to_lower(temp);
        if(temp.find(cidade) != std::string::npos){
            i->setIndice(indice);
            buffer.push_back(i);
        }
      indice++;
    }

    return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisBairro(std::string bairro) {
    std::vector<Imovel*> buffer;
    std::string temp;
    int indice = 0;

    boost::algorithm::to_lower(bairro);

    for(auto i: imoveis){
      temp = i->getBairro();
      boost::algorithm::to_lower(temp);
        if(temp.find(bairro) != std::string::npos){
          i->setIndice(indice);
          buffer.push_back(i);
        }
      indice++;
    }

    return buffer;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisDescricao(std::string descricao) {
    std::vector<Imovel*> buffer;
    std::string temp;
    int indice = 0;

    boost::algorithm::to_lower(descricao);

    for(auto i: imoveis){
      temp = i->getDescricao();
      boost::algorithm::to_lower(temp);
        if(temp.find(descricao) != std::string::npos){
          i->setIndice(indice);
          buffer.push_back(i);
        }
      indice++;
    }

    return buffer;
}

std::vector<Imovel *> SistemaImobiliaria::getImoveisValorMaior(double valor){
  std::vector<Imovel *> myVector;
  int indice = 0;

  for(auto &i: imoveis){
    if(i->getValor() > valor){
      i->setIndice(indice);
      myVector.push_back(i);
    }
    indice++;
  }

  return myVector;
}

std::vector<Imovel *> SistemaImobiliaria::getImoveisValorMenor(double valor){
  std::vector<Imovel *> myVector;
  int indice = 0;

  for(auto &i: imoveis){
    if(i->getValor() < valor){
      i->setIndice(indice);
      myVector.push_back(i);
    }
    indice++;
  }

  return myVector;
}

void SistemaImobiliaria::eraseImovel(int indice){
  imoveis.erase(imoveis.begin() + indice - 1);
}

void SistemaImobiliaria::setStartup(std::vector<Imovel*> myVector){
  imoveis = myVector;
}

int SistemaImobiliaria::getTipoPorIndice(int indice){
  if(indice < imoveis.size() && indice >= 0)
  return imoveis[indice]->getTipoOferta();
  else
  return 0;
}

void SistemaImobiliaria::editImovel(int indice, Imovel* imovel){
  imoveis[indice] = imovel;
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

void Imovel::setIndice(int indice){
  this->indice = indice;
}

int Imovel::getIndice(){
  return indice;
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
    std::stringstream buffer;

    buffer << endereco.getLogradouro() << std::endl;
    buffer << endereco.getNumero() << std::endl;
    buffer << endereco.getCep() << std::endl;
    buffer << endereco.getBairro() << std::endl;
    buffer << endereco.getCidade() << std::endl;


    return buffer.str();
}

std::string Imovel::basicToString(){
  std::stringstream sstr;

  sstr << "Titulo: " << descricao << std::endl << "Bairro: " << endereco.getBairro()
  << std::endl << "Cidade: " << endereco.getCidade() << std::endl << "Valor: " << valor
  << std::endl;

  return sstr.str();
}

std::string Imovel::overallToString(){
  std::stringstream sstr;

  sstr << "Titulo: " << descricao << std::endl << "Valor: " << valor << "\nEndereço:\n" << EnderecoToString();

  return sstr.str();
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
    this->descricao = descricao;
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

std::string Casa::toString(){
  std::stringstream sstr;

  sstr << overallToString() << "Numero de pavimentos: " << numPavimentos << std::endl
  << "Numero de quartos: " << numQuartos << std::endl << "Área do terreno: " << areaTerreno
  << std::endl << "Área construida: " << areaConstruida << std::endl;

  return sstr.str();
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
    this->descricao = descricao;
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

std::string Apartamento::toString(){
  std::stringstream sstr;

  sstr << overallToString() << "Posição: " << posicao << std::endl
  << "Numero de quartos: " << numQuartos << std::endl << "Valor do condominio: "
  << valorCondominio << std::endl << "Vagas na garagem: " << vagasGaragem << std::endl
  << "Área: " << area << std::endl;

  return sstr.str();
}

Apartamento::~Apartamento() {
}

Terreno::Terreno(double area, bool venda, double valor, int tipo, std::string descricao,
                 std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep) {

    this->area = area;
    this->venda = venda;
    this->valor = valor;
    this->tipo = tipo;
    this->descricao = descricao;
    endereco.setAll(logradouro, numero, bairro, cep, cidade);
}

double Terreno::getArea() {
    return area;
}

void Terreno::setArea(double area) {
    this->area = area;
}

std::string Terreno::toString(){
  std::stringstream sstr;

  sstr << overallToString() << "Área do terreno: " << area << std::endl;

  return sstr.str();
}

Terreno::~Terreno() {
}

GerenteDePersistencia::GerenteDePersistencia() {
}

std::vector<Imovel*> GerenteDePersistencia::RecuperaImoveis() {
    std::ifstream buffer;
    std::vector<Imovel*> imoveis;
    Imovel* x;
    int tipo, numero;
    double valor;
    bool venda;
    std::string descricao, logradouro, bairro, cidade, cep;

    buffer.open("Imobiliaria.txt");

    if(!buffer.is_open() ){
        std::cout << "erro ao abrir arquivo" << std::endl;
        return imoveis;
    }
    while(buffer){

        if(buffer.bad() || buffer.eof() || buffer.fail()) break;
        {

          char tempRua[100], tempCep[10], tempBairro[100], tempCida[100], tempDesc[100];

          buffer >> tipo;
          buffer.ignore();
          buffer >> valor;
          buffer.ignore();
          buffer.getline(tempRua, 100);
          logradouro = tempRua;
          buffer >> numero;
          buffer.ignore();
          buffer.getline(tempCep, 10);
          cep = tempCep;
          buffer.getline(tempBairro, 100);
          bairro = tempBairro;
          buffer.getline(tempCida, 100);
          cidade = tempCida;
          buffer.getline(tempDesc, 100);
          descricao = tempDesc;
          buffer >> venda;
          buffer.ignore();
        }
        switch(tipo){
            case 1:{

                int numPavimentos, numQuartos;
                double areaTerreno, areaConstruida;

                buffer >> numPavimentos;
                buffer.ignore();
                buffer >> numQuartos;
                buffer.ignore();
                buffer >> areaTerreno;
                buffer.ignore();
                buffer >> areaConstruida;

                x = new Casa(numPavimentos, numQuartos, areaTerreno, areaConstruida, venda, valor, tipo,
                             descricao, logradouro, numero, bairro, cidade, cep);
                imoveis.push_back(x);
                delete x;
            }
                break;
            case 2:{

                std::string posicao;
                int numQuartos, vagasGaragem;
                double valorCondominio, area;
                char tempPos[20];

                  buffer.getline(tempPos, 20);
                  posicao = tempPos;
                  buffer >> numQuartos;
                  buffer.ignore();
                  buffer >> valorCondominio;
                  buffer.ignore();
                  buffer >> vagasGaragem;
                  buffer.ignore();
                  buffer >> area;

                  std::cout << "Debug: " << std::endl << std:: endl;
                std::cout << tipo << std::endl << valor << std::endl << logradouro << std::endl << numero << std::endl << cep <<
                std::endl << bairro << std::endl << cidade << std::endl << descricao << std::endl << venda << std::endl << posicao << std::endl <<
                numQuartos << std::endl << valorCondominio << std::endl << vagasGaragem << std::endl << area << std::endl << std::endl;

                x = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, venda,
                                    valor, tipo, descricao, logradouro, numero, bairro, cidade, cep);

                imoveis.push_back(x);

                delete x;
            }
                break;
            case 3:{

                double area;

                buffer >> area;

                x = new Terreno(area, venda, valor, tipo, descricao, logradouro, numero, bairro, cidade, cep);
                imoveis.push_back(x);
                delete x;
            }
                break;

        } // switch end

    }// while end

    std::cout << "tamanho do array lido: " << imoveis.size() << std::endl << "fim do Debug;" << std:: endl << std::endl;
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
        buffer << i->getTipoOferta() << std::endl;
        buffer << i->getValor() << std::endl;
        buffer << i->EnderecoToString();
        buffer << i->getDescricao() << std::endl;
        buffer << i->getVenda() << std::endl;

        switch(i->getTipoOferta()){
            case 1:
                buffer << i->getNumPavimentos() << std::endl;
                buffer << i->getNumQuartos() << std::endl;
                buffer << i->getAreaTerreno() << std::endl;
                buffer << i->getAreaConstruida();
                break;
            case 2:
                buffer << i->getPosicao() << std::endl;
                buffer << i->getNumQuartos() << std::endl;
                buffer << i->getValorCondominio() << std::endl;
                buffer << i->getVagasGaragem() << std::endl;
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
