/*
 * Author: Iogo Sadrack Souza Soares
 */

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

  std::cout << "Logradouro do imovel: ";
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Casa *casa = new Casa(numPavimentos, numQuartos, areaTerreno, areaConstruida, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(casa);
}

void MenuEditCasa(int indice, SistemaImobiliaria &sistema){
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Casa *casa = new Casa(numPavimentos, numQuartos, areaTerreno, areaConstruida, venda, valor, 1, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.editImovel(indice, casa);
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Apartamento *apartamento = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(apartamento);
}

void MenuEditApartamento(int indice, SistemaImobiliaria &sistema){
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Apartamento *apartamento = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, venda, valor, 2, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.editImovel(indice, apartamento);
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Terreno *terreno = new Terreno(area, venda, valor, escolha, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.CadastraImovel(terreno);
}

void MenuEditTerreno(int indice, SistemaImobiliaria &sistema){
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
  std::cout << "Descrição do imovel: ";
  getline(std::cin, descricao);
  MenuEndereco(logradouro, numero, bairro, cidade, cep);

  Terreno *terreno = new Terreno(area, venda, valor, 3, descricao, logradouro, numero, bairro, cidade, cep);

  sistema.editImovel(indice, terreno);
}

void Menu(int &escolha){

  std::cout << "Escolha uma opção:\n  1-Cadastrar imovel.\n  2-Mostrar.\n  3-Buscar.\n  4-Remover.\n";
  std::cout << "  5-Editar.\n  6-Sair.\n  0-Salvar & Sair.\n";
  std::cin >> escolha;
}

void MenuEscolheCadastro(int &escolha){
  system("clear");

  std::cout << "Escolha uma opção:\n  1-Casa.\n  2-Apartamento.\n  3-Terreno.\n";
  std::cin >> escolha;
}

void MenuMostrar(int &escolha){

  system("clear");
  std::cout << "Escolha uma opção:\n  1-Listagem simples.\n  2-Listagem por tipo";
  std::cout << "(casa, apartamento, terreno).\n  3-Listagem por categoria(venda, aluguel).\n";
  std::cin >> escolha;
}

void MenuMostrarPorTipo(int &escolha){
  system("clear");

  std::cout << "Escolha uma opção:\n  1-Listagem por casa.\n  2-Listagem por apartamento.\n  3-Listagem por terreno.\n";
  std::cin >> escolha;
}

void PrintImoveisPorTipo(SistemaImobiliaria &sistema, int &escolha){
  {
    system("clear");
    std::vector<Imovel*> myvector = sistema.getImoveis();
    for(auto &i: myvector){
      if(i->getTipoOferta() == escolha){
        std::cout << "=================================\n";
        std::cout << i->toString();
      }
    }
  }
}

void MenuMostrarPorOferta(int &escolha){
  system("clear");

  std::cout << "Escolha uma opção:\n  1-Venda.\n  0-Aluguel.\n";
  std::cin >> escolha;
}

void PrintImoveisPorOferta(SistemaImobiliaria &sistema, int &escolha){
  {
    system("clear");
    std::vector<Imovel*> myvector = sistema.getImoveis();
    for(auto &i: myvector){
      if(i->getVenda() == escolha){
        std::cout << "=================================\n";
        std::cout << i->toString();
      }
    }
  }
}

void PrintVector(std::vector<Imovel *> myVector){
  system("clear");

  for(auto &i: myVector){
    std::cout << "Índice: " << i->getIndice() << std::endl;
    std::cout << i->toString() << std::endl;
    std::cout << "===============================\n\n";
  }
}

void MenuBusca(int &escolha){

  system("clear");

  std::cout << "Escolha uma opção:\n  1-Cidade.\n  2-Bairro.\n  3-Por Titulo.\n";
  std::cout << "  4-Por valor maior que...\n  5-Por valor menor que...\n";
  std::cin >> escolha;
}

void MenuRemover(SistemaImobiliaria &sistema, std::string &strForSearch, int &escolha){
  std::cout << "Busque o imovel por titulo que deseja remover: ";
  getline(std::cin, strForSearch);
  PrintVector(sistema.getImoveisDescricao(strForSearch));
  std::cout << "Digite o índice que deseja remover: ";
  std::cin >> escolha;
}

void MenuEditar(SistemaImobiliaria &sistema, int &escolha){
  PrintVector(sistema.getImoveis());
  std::cout << "Digite o indice do imovel ao qual deseja editar: ";
  std::cin >> escolha;
}

int main(){

  SistemaImobiliaria sistema;
  GerenteDePersistencia gerente;

  int escolha;
  std::string strForSearch;
  double valor;

  system("clear");

  gerente.RecuperaImoveis(&sistema);

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
      MenuMostrar(escolha);
      switch(escolha){
        case 1:
        {
          system("clear");
          std::vector<Imovel*> myvector = sistema.getImoveis();

          std::cout << "=================================\n\n";
          for(auto &i: myvector){
            std::cout << i->basicToString() << std::endl;
            std::cout << "=================================\n\n";
          }
        }
        break;
        case 2:
        MenuMostrarPorTipo(escolha);
        PrintVector(sistema.getImovelTipo(escolha));
        break;
        case 3:
        MenuMostrarPorOferta(escolha);
        PrintVector(sistema.getImovelOferta(escolha));
        break;
        default:
        std::cout << "Digite uma opção válida.\n";
        }
      break;
      case 3:
      MenuBusca(escolha);
      switch(escolha){
        case 1:
        std::cout << "Digite a cidade que busca: ";
        std::cin >> strForSearch;
        PrintVector(sistema.getImoveisCidade(strForSearch));
        break;
        case 2:
        std::cout << "Digite o bairro que busca: ";
        std::cin >> strForSearch;
        PrintVector(sistema.getImoveisBairro(strForSearch));
        break;
        case 3:
        std::cout << "Digite o titulo que busca: ";
        std::cin >> strForSearch;
        PrintVector(sistema.getImoveisDescricao(strForSearch));
        break;
        case 4:
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        PrintVector(sistema.getImoveisValorMaior(valor));
        break;
        case 5:
        std::cout << "Digite o valor: ";
        std::cin >> valor;
        PrintVector(sistema.getImoveisValorMenor(valor));
        break;
        default:
        std::cout << "Digite uma opção válida.\n";
      }
      break;
      case 4:
      MenuRemover(sistema, strForSearch, escolha);
      sistema.eraseImovel(escolha);
      break;
      case 5:
      MenuEditar(sistema, escolha);
      switch(sistema.getTipoPorIndice(escolha)){
        case 1:
        MenuEditCasa(escolha, sistema);
        break;
        case 2:
        MenuEditApartamento(escolha, sistema);
        break;
        case 3:
        MenuEditTerreno(escolha, sistema);
        break;
        default:
        std::cout << "Indice não existe.\n";
        break;
      }
      break;
      case 0:
      gerente.SalvaImoveis(sistema.getImoveis());
      return 1;
      case 6:
      return 2;
      default:
      std::cout << "Digite uma opção válida.\n";
    }
  }

  return 0;
}
