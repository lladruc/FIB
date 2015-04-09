#include <iostream>
using namespace std;

int main () {
  char a;
  cin >> a;
  if ((a>='A' and a<='Z') or (a>='a' and a<='z')) { // lletra [A-Z]||[a-z]
    cout << "lletra" << endl;
  }else if ( a >='0' and a<= '9' ) { // digit
    cout << "digit" << endl;
  }else { //res
    cout << "res" << endl;
  }
}