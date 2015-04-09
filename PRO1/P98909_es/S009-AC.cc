
#include <iostream>
using namespace std;

int main() {
  int e, i, p, g, s; // e = euros. i = contador. p = paga. g = gastos. s = semana con deudas
  e = 0; //inicializamos e=0
  s = 0;
  cin >> p >> g; // cojemos paga y ahorros (usamos GASTOS para reciclar variable)
  e+=g; // usamos GASTOS para añadir los ahorros iniciales sin gastar una variable mas.
  for ( i = 0; i < 5; i++ ){
    e+=p;
    cin >> g;
    e-=g;
    if ( e < 0 ) { // si los gastos superan los ahorros, damos la semana con perdida
      s++;
    }
  }
  cout << e << endl << s << endl;
 }