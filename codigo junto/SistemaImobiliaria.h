/*
 * SistemaImobiliaria.h
 *
 *  Created on: 19 de jul de 2019
 *      Author: egidio
 */

#ifndef SISTEMAIMOBILIARIA_H_
#define SISTEMAIMOBILIARIA_H_

#include <iostream>
#include <vector>
#include <fstream>

class Endereco{	//funcional
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
    std::string getLogradouro() {return logradouro;}
    void setLogradouro(std::string logradouro) {this->logradouro = logradouro;}
    int getNumero() {return numero;}
    void setNumero(int numero) {this->numero = numero;}
    void setAll(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade);

    virtual ~Endereco();
};

class Imovel {
protected:
    double valor;
    bool venda; //true = vendendo, false = alugando
    Endereco endereco = Endereco();
    std::string descricao;
    int tipo; //tipo do imovel 1-casa, 2-apê, 3-terreno
public:
    Imovel();

    virtual double getValor();
    virtual int getTipoOferta(); //getTipo
    virtual Endereco getEndereco();
    virtual std::string getDescricao();
    virtual bool getVenda();

    virtual void setDescricao(std::string descricao);
    virtual void setEndereco(std::string logradouro, int numero, std::string bairro,
                             std::string cidade, std::string cep);
    virtual void setValor(double valor);
    virtual void setTipo(int tipo);
    virtual void setVenda(bool venda);

    //metodos de endereco
    std::string getBairro();
    std::string getCep();
    std::string getCidade();
    std::string getLogradouro();
    int getNumero();

    std::string EnderecoToString();

    //metodos casa
    virtual int getNumPavimentos(){return 0;};
    virtual void setNumPavimentos(int numPavimentos){};
    virtual int getNumQuartos(){return 0;};
    virtual void setNumQuartos(int numQuartos){};
    virtual double getAreaTerreno(){return 0;};
    virtual void setAreaTerreno(double areaTerreno){};
    virtual double getAreaConstruida(){return 0;};
    virtual void setAreaConstruida(double areaConstruida){};

    //metodos apartamento
    virtual std::string getPosicao(){ return 0;};
    virtual void setPosicao(std::string posicao){};
    virtual double getValorCondominio(){return 0;};
    virtual void setValorCondominio(double valorCondominio){};
    virtual int getVagasGaragem(){return 0;};
    virtual void setVagasGaragem(int vagasGaragem){};
    virtual double getArea(){return 0;};
    virtual void setArea(double area){};

    virtual ~Imovel();
};

class Casa: public Imovel{
private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
public:

    Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida,
         bool venda, double valor, int tipo, std::string descricao, std::string logradouro,
         int numero, std::string bairro, std::string cidade, std::string cep);

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
    Apartamento(std::string posicao, int numQuartos, double valorCondominio,
                int vagasGaragem, double area, bool venda, double valor, int tipo,
                std::string descricao, std::string logradouro, int numero, std::string bairro,
                std::string cidade, std::string cep);

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
    Terreno(double area, bool venda, double valor, int tipo, std::string descricao,
            std::string logradouro, int numero, std::string bairro, std::string cidade,
            std::string cep);

    double getArea();
    void setArea(double area);

    virtual ~Terreno();
};

class SistemaImobiliaria {
private:
    std::vector<Imovel*> imoveis;
public:
    SistemaImobiliaria();

    void CadastraImovel(Imovel* imovel);
    std::vector<Imovel*> getImoveis();
    std::vector<std::string> getDescricao();
    std::vector<Imovel*> getImovelTipo(int tipo);
    std::vector<Imovel*> getImoveisAlugarBairro(std::string bairro);
    std::vector<Imovel*> getImoveisVenderBairro(std::string bairro);
    std::vector<Imovel*> getImoveisCidade(std::string cidade);


    virtual ~SistemaImobiliaria();
};

class GerenteDePersistencia{
public:
    GerenteDePersistencia();

    std::vector<Imovel*> RecuperaImoveis();
    void SalvaImoveis(std::vector <Imovel*> lista);

    virtual ~GerenteDePersistencia();
};

#endif /* SISTEMAIMOBILIARIA_H_ */
