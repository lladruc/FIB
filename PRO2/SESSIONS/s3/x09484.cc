#include <iostream>
#include "utils.PRO2"
#include "Palabra.hh"
bool permutan(const Palabra& a,const Palabra& b);
bool retornar(const Palabra& a,const Palabra& b);


bool permutan(const Palabra& a,const Palabra& b){
  int size = a.long_pal();
  vector<bool>v (size,true);
  bool match;
  char c;
  for(int i = 1; i <= size; i++){
    c = a.consultar_letra(i);
    match = false;
    for(int j = 1; j <= size and not match; ++j){
      if(c == b.consultar_letra(j) and v[j-1]) match = true, v[j-1] = false;
    }
    if(not match) return false;
  }
  return true;
}

bool retornar(const Palabra& a,const Palabra& b){
  if(a.long_pal() != b.long_pal()) return false;
  return (permutan(a,b));
}

int main(){
  Palabra a,b; // 1a palabra, 2a palabra.
  a.leer('.');
  b.leer('.');
  if(retornar(a,b)) cout << "SI";
  else cout << "NO";
  cout << endl;  
}