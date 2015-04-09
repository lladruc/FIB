#include <iostream>
using namespace std;

int main(){
  int sumatori=0, f, c, i, j;
  cin >> f >> c;
  for(i=0;i<f;++i){
    char l;
    for(j=0;j<c;++j){
      cin >> l; 
      sumatori+= l - '0' ;
    }
  }
  cout << sumatori << endl;
}