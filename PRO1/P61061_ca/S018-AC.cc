#include <iostream>
using namespace std;

int productos(int n){ // in abcde, return a*b*c*d*e;
  int aux = 1;
  while (n > 0 and aux != 0){
    aux = aux*(n%10);
    n = n/10;
  }
  return aux;
}

void number(int n){ // in Numnber abcde -> abcd -> abc -> ab
  if(n>=10){
    while(n>=10){
      cout << "El producte dels digits de " << n << " es ";
      n= productos(n);
      cout << n << "." << endl;
    }
  }else{
    cout << "El producte dels digits de " << n << " es ";
    cout << n << "." << endl;
  }
}

int main() {
  int n;
  while (cin >> n) {
    if(n<0){
      n=n*(-1);
    }
  number(n);
  cout << "----------" << endl;
  } // close cin >> n;
} // close main;