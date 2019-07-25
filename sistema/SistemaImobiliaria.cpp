#include <iostream>
#include "SistemaImobiliaria.h"

using namespace std;

SistemaImobiliaria::Sistema(){

};

void SistemaImobiliaria::cadastrarImovel(Imovel imovel){
  imoveis.push_back(imovel);
};

vector<Imovel> SistemaImobiliaria::getImoveis(){
  return imoveis;
};

vector<string> SistemaImobiliaria::getDescricaoImoveis(){
  vector<string> descricao;
  for(auto &i : imoveis){
    descricao.push_back(i.getDescricao());
  }
  return descricao;
};
