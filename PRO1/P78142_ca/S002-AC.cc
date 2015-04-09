#include <iostream>
using namespace std;

int main () {
  cout.setf(ios::fixed);
  cout.precision(2);
  double s, n, i;
  s=0;
  i=0;
  while ( cin >> n ) {
    s+=n;
    i++;
  }
  cout << s/i << endl;
}
