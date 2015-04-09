#include <iostream>
#include <vector>
using namespace std;

int avalua(const vector<int>& p, int x){
  int aux =0;
  for(int i=p.size()-1;i>0;--i){
    aux = ( aux + p[i] ) * x;
  }
  aux+=p[0];
  return aux;
}

int main(){
  vector<int> n(4);
  int b=0;
  n[0] = 1;
  n[1] = 2;
  n[2] = 3;
  n[3] = 4;
  
  b = avalua(n,3);
  cout << b << endl;
}