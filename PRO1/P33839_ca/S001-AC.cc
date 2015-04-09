#include <iostream>
using namespace std;

int main (){
  int n,aux;
  while(cin >> n){
    aux = 0;
    cout << "La suma dels digits de " << n << " es ";
    while(n>0){
      aux+=n%10;
      n=n/10;
    }
    cout << aux << "." << endl; 
  }
}