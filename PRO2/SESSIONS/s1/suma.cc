#include "utils.PRO2"

int  main ()
{
  int n, aux;
  aux = 0;
  while(cin >> n and n != 0){
    aux += n;
  }
  cout << aux << endl;
}

