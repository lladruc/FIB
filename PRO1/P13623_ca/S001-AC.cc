#include <iostream>
using namespace std;

int main (){
  int f,c,suma=0;
  cin >> f >> c;
  for(int i=0;i<f;++i){
    for(int j=0;j<c;j++){
      char n;
      cin >> n;
      if((i+j)%2==0){
	suma+=(n-'0');
      }
    }
  }
  cout << suma << endl;
}