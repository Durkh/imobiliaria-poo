#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class testeAbstrato{
protected:
public:
  virtual void setTestet(string) = 0;
  virtual string getString() = 0;
};

class testePolimorfismo2 : public testeAbstrato{
private:
  string a1;
  int i;
public:
  testePolimorfismo2(){};
  void setTestet(string testet){
    a1 = testet;
  };
  string getString(){
    return a1;
  };
};

class testePolimorfismo1 : public testeAbstrato{
private:
  string a1;
  int i;
public:
  testePolimorfismo1(){};
  void setTestet(string testet){
    a1 = testet;
  };
  string getString(){
    return a1;
  };
};

class teste{
private:
  vector<testeAbstrato *> a;
  bool tipo;
public:
  teste(){};
  void setString(testeAbstrato *teste){
    a.push_back(teste);
  };
  vector<string> getString(){
    vector<string> teste;
    for(auto &i : a){
      teste.push_back(i->getString());
    }
    return teste;
  };
};

int main(){
  teste t1 = teste();
  int o = 1, escolha;
  string teste;

  testePolimorfismo1 testep1 = testePolimorfismo1();
  testePolimorfismo2 testep2 = testePolimorfismo2();

  while(o){

    cout << "Escolha o tipo de teste, polimorfismo 1 ou polimorfismo 2: ";
    cin >> escolha;

    switch(escolha){
      case 1:
      cout << "String: ";
      cin >> teste;

      testep1.setTestet(teste);

      t1.setString(&testep1);
      cout << "Continuar? ";
      cin >> o;
      break;
      case 2:
      cout << "String: ";
      cin >> teste;

      testep2.setTestet(teste);

      t1.setString(&testep2);
      cout << "Continuar? ";
      cin >> o;
      break;
    }

  }

  vector<string> teste1 = t1.getString();

  for(int i = 0; i < teste1.size(); i++){
    cout << teste1[i] << endl;
  }

  return 1;
  return 0;

}
