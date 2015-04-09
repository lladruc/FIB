#include <iostream>
using namespace std;

int main () {
 int d; // d = decimal
 cin >> d;
  while(d>1){
      cout << d%2;
	//cout << "parte: " << d << ",da: " << d/2 << ",mod: " << d%2 << endl;
	d=d/2;
  }
  cout << d << endl;
}
