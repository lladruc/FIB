#include <iostream>
#include <vector>
using namespace std;

int ndiferents(const vector<int>& v){
  int r=0;
  for(int i=0;i<v.size();++i){
    bool unic = true;
    int j=i-1;
    while( j >= 0 and unic){
      if(v[i] == v[j]) unic = false;
      --j;
    }
    if(unic) ++r;
  }
  return r;
}

int main(){
  int n;
  while(cin >> n){
    vector<int> v(n);
    while(n>0){
      --n;
      cin >> v[n];
    }
    cout << ndiferents(v) << endl;
  }
}