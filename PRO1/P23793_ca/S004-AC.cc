#include <iostream>
#include <string>
using namespace std;
int compara(int d1, int m1, int a1, int d2, int m2, int a2){
  if(a1>a2){// any posterior
    return 1;
  }else if(a1==a2){ // any igual
    if(m1>m2){ 
      return 1;// mes posterior
    }else if(m1==m2){ // mes igual
      if(d1>d2){
	return 1;// dia posterior
      }else if(d1==d2){
	return 0;// dia igual
      }else{
	return -1;//dia anterior
      }
    }else{
      return -1; //mes anterior
    }
  }else{ // anyanterior
    return -1;
  }
}

int main(){
  int d1,d2,m1,m2,a1,a2,myReturn;
  char s;
  while(cin >> d1 >> s >> m1 >> s >> a1 >> d2 >> s >> m2 >> s >> a2){
    myReturn = compara(d1,m1,a1,d2,m2,a2);
    if(myReturn<0){
      cout << "anterior";
    }else if(myReturn==0){
      cout << "iguals";
    }else{
      cout << "posterior";
    }
    cout << endl;
  }
}