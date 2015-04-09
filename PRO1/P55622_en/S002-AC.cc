#include <iostream>
using namespace std;

int main () {
  int n, d, t;
  cin >> n;
  d=1;
  t=n;
  while(t>9){
    t=t/10;
    d++;
  }
  cout << "The number of digits of " << n << " is " << d << "." << endl;
}
