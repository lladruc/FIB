#include <iostream>
#include "utils.PRO2"
#include "Palabra.hh"

int max(const Palabra& a){
  int aux,cont,size;
  size = a.long_pal();
  aux = 0;
  bool mismaLetra = true;
  bool llega = true;
  char l = a.consultar_letra(1);
  for(int i = 1; i <= size and llega; ++i){
    mismaLetra=true;
    cont = 1;
    for(int j = i; j < size and mismaLetra and llega; ++j){
      if(l == a.consultar_letra(j+1)){
	++cont;
      }else{
	i=j;
	if(size - j < cont or size - j < aux) llega = not llega;
	mismaLetra = not mismaLetra;
	l = a.consultar_letra(j+1);
      }
    }
    if(cont >= aux){
	  aux = cont;
	}
  }
  return aux;
}

int main(){
  Palabra a;
  a.leer('.');
  cout << max(a) << endl;
}