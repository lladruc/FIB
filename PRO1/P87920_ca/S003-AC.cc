#include <iostream>
#include <vector>
using namespace std;

bool compleix(const vector<int>& v){
  int aux=0;
  for(int i=0;i<v.size();++i){ aux+=v[i]; }
  for(int i=0;i<v.size();++i){
    if(v[i] == aux-v[i]) return true;
  }
  return false;
}

int main(){
  int n;
  while(cin >> n){
    vector<int> v(n);
    while(n>0){
      --n;
      int aux;
      cin >> aux;
      v[n] = aux;
    }
    if(compleix(v)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}