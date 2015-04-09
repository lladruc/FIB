
#include <iostream>
using namespace std;

int main(){
  bool principi = false;
  int cont=0;
  string n;
  while(cin >> n and n!="final"){
    if(n=="principi"){
      principi = true;
    }else if(principi){
      ++cont;
    }
  }
  if(n=="final" and principi){
    cout << cont << endl;
  }else{
    cout << "sequencia incorrecta" << endl;
  }
}