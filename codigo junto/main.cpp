#include <iostream>

#include "SistemaImobiliaria.h"

void Venda(bool *p){
  int x;

  std::cout << "Está sendo vendido?\n  1-Sim\n  0-Não\n";
  std::cin >> x;

  if(x){
    *p = true;
  }else{
    *p =  false;
  }
}

void MenuEndereco(std::string &logradouro, int &numero, std::string &bairro, std::string &cidade, std::string &cep){
  std::string catchEndLine;

  std::cout << "Logradouro do imovel: \n";
  getline(std::cin, logradouro);
  std::cout << "Numero: ";
  std::cin >> numero;
  getline(std::cin, catchEndLine);
  std::cout << "Bairro: ";
  getline(std::cin, bairro);
  std::cout << "Cidade: ";
  getline(std::cin, cidade);
  std::cout << "CEP: ";
  getline(std::cin, cep);
}

void MenuCadastraCasa(SistemaImobiliaria &sistema, int escolha){
  int numPavimentos, numQuartos, numero;
  double areaTerreno, areaConstruida, valor;
  bool venda;
  std::string descricao, logradouro, bairro, cidade, cep;
  std::string catchEndLine;

  system("clear");

  std::cout << "Digite o numero de Pavimentos: ";
  std::cin >> numPavimentos;
  std::cout << "Numero de quartos: ";
  std::cin >> numQuartos;
  std::cout << "Área do terreno: ";
  std::cin >> areaTerreno;
  std::cout << "Área do construida: ";
  std::cin >> areaConstruida;
  Venda(&venda);
  std::cout << "Qual o valor do imovel: ";
  std::cin >> valor;
  getline(std::cin, catchEndLine);
  std::cout << "Descrição do imovel: \n";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Casa *casa = new Casa(numPavimentos, numQuartos, areaTerreno, areaConstruida, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(casa);
}

void MenuCadastraApartamento(SistemaImobiliaria &sistema, int escolha){
  int numQuartos, numero, vagasGaragem;
  double valorCondominio, valor, area;
  bool venda;
  std::string descricao, logradouro, bairro, cidade, cep;
  std::string catchEndLine, posicao;

  system("clear");

  getline(std::cin, catchEndLine);
  std::cout << "Digite a posição: ";
  getline(std::cin, posicao);
  std::cout << "Numero de quartos: ";
  std::cin >> numQuartos;
  std::cout << "Valor do condominio: ";
  std::cin >> valorCondominio;
  std::cout << "Vagas de garagem: ";
  std::cin >> vagasGaragem;
  std::cout << "Área do apartamento: ";
  std::cin >> area;
  Venda(&venda);
  std::cout << "Qual o valor do imovel: ";
  std::cin >> valor;
  getline(std::cin, catchEndLine);
  std::cout << "Descrição do imovel: \n";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Apartamento *apartamento = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(apartamento);
}

void MenuCadastraTerreno(SistemaImobiliaria &sistema, int escolha){
  int numero;
  double area, valor;
  bool venda;
  std::string descricao, logradouro, bairro, cidade, cep;
  std::string catchEndLine;

  system("clear");

  std::cout << "Digite a área do imovel: ";
  std::cin >> area;
  Venda(&venda);
  std::cout << "Qual o valor do imovel: ";
  std::cin >> valor;
  getline(std::cin, catchEndLine);
  std::cout << "Descrição do imovel: \n";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Terreno *terreno = new Terreno(area, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(terreno);
}

void Menu(int &escolha){

  std::cout << "Escolha uma opção:\n  1-Cadastrar imovel.\n  2-Mostrar.\n  0-Sair.\n";
  std::cin >> escolha;
}

void MenuEscolheCadastro(int &escolha){
  system("clear");
  
  std::cout << "Escolha uma opção:\n  1-Casa.\n  2-Apartamento.\n  3-Terreno.\n";
  std::cin >> escolha;
}

int main(void){

  SistemaImobiliaria sistema;

  int escolha;

  while(1){
    Menu(escolha);

    switch(escolha){
      case 1:
      MenuEscolheCadastro(escolha);
      switch(escolha){
        case 1:
        MenuCadastraCasa(sistema, escolha);
        break;
        case 2:
        MenuCadastraApartamento(sistema, escolha);
        break;
        case 3:
        MenuCadastraTerreno(sistema, escolha);
        break;
        default:
        std::cout << "Digite uma opção válida.\n";
        }
        break;
        case 2:
        {
          system("clear");
          std::vector<Imovel*> myvector = sistema.getImoveis();
          for(auto &i: myvector){
            std::cout << i->getTipoOferta() << std::endl;
          }
        }
        break;
        case 0:
        return 1;
        default:
        std::cout << "Digite uma opção válida.\n";
      }
  }

  return 0;
}
