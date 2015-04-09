#include <iostream>
#include "utils.PRO2"
#include "Palabra.hh"

Palabra retornar(const Palabra& a,const Palabra& b){
  int size = a.long_pal()+b.long_pal();
  Palabra aux;
  char l;
  for(int i = 1; i <= size; ++i){
   if(i <= a.long_pal()) l = a.consultar_letra(i);
   else l = b.consultar_letra(i-a.long_pal());
   
   if(not a.es_separador(l)) aux.anadir_letra(l);
  }
  return aux;
}

int main(){
  Palabra a,b; // 1a palabra, 2a palabra, resultado
  a.leer('.');
  b.leer('.');
  a = retornar(a,b);
  a.escribir();
  cout << endl;
}