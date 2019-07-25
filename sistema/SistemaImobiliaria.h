/* Author: Iogo Sadrack Souza Soares
*  Code: Esse código serve para controlar o sistema da imobiliaria, atualizando, deletando e criando elementos no sistema.
*/

#ifndef SISTEMAIMOBILIARIA_SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_SISTEMAIMOBILIARIA_H

#include <vector>
#include "Imovel.h"

class SistemaImobiliaria{
private:
  vector<Imovel> imoveis;
public:
  Sistema();
  void cadastrarImovel(Imovel);
  vector<Imovel> getImoveis();
  vector<string> getDescricaoImoveis();
  vector<Imovel> getImoveisPorTipo(int);
  vector<Imovel> getImoveisParaAlugarPorBairro(string);
  vector<Imovel> getImoveisParaVenderPorBairro(string);
  vector<Imovel> getImoveisPorCidade(string);
};

#endif
