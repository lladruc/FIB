#include <iostream>
#include "utils.PRO2"
#include "Palabra.hh"

bool permutan(const Palabra& a,const Palabra& b){
  if(a.long_pal() != b.long_pal()) return false;
  int size = a.long_pal();
  
  vector<int> v(128, 0);

  for(int i = 1; i <= size; ++i) ++v[a.consultar_letra(i)], --v[b.consultar_letra(i)];
  //for(int i = 1; i <= size; ++i) --v[b.consultar_letra(i)];

  for(int i = 0; i < v.size(); ++i){
    if(v[i] != 0) return false;
  }
  return true;
}


int main(){
  Palabra a,b; // 1a palabra, 2a palabra.
  a.leer('.');
  b.leer('.');
  if(permutan(a,b)) cout << "SI";
  else cout << "NO";
  cout << endl;  
}