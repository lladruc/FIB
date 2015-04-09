#include <iostream>
using namespace std;

int main () {
  int entrada, i;

  while (cin >> entrada){
    i=0;
    while(entrada > 1){
      if(entrada%2 != 0){
	entrada=entrada*3+1;
      }else{
	entrada=entrada/2;
      }
      ++i;
    }
    cout << i << endl;
  }
}