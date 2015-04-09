#include <iostream>
 
using namespace std;
 
bool primer(int N) {
    int divisor = 2;
    bool is_prime = (N != 1);
    while (is_prime and divisor*divisor <= N) {
    is_prime = N%divisor != 0;
    divisor = divisor + 1;
    }
    if (is_prime) return true;
    else return false;
}
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (primer(k) and k != 0) cout << k << " es primer" << endl;
        else cout << k << " no es primer" << endl;
    }
 
}