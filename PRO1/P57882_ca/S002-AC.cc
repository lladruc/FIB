#include <iostream>
using namespace std;
 
int suma_divisors(int n) {
  int suma = 0;
  for (int i = 1; i <= n/2; ++i) {
    if (n%i == 0) suma += i;
  }
        return suma;
}
 
int main() {
  int x;
  while (cin >> x) {
  int sumadiv = suma_divisors(x) + suma_divisors(x - 2) + suma_divisors(x + 2);
    cout << x << ": ";
    if (sumadiv%x == 0 and sumadiv/x == 1) cout << "popiropis";
    else if (sumadiv%x == 0) cout << sumadiv/x << "-popiropis";
    else cout << "res";
    cout << endl;
  }
}