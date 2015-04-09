#include <iostream>
using namespace std;

int main () {
  cout.setf(ios::fixed);  // fix output
  cout.precision(3);	// set precision 3 ditits x = x.000
  int a,b;
  double c;
  cin >> a >> b;
  if(b!=0){
  c = double(a)/b;
  cout << c << " " << a/b << " " << a%b << endl;
  }else{
    cout << "divisio per zero" << endl;
  }
}