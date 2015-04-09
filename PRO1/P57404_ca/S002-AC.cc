#include <iostream>
using namespace std;

bool es_poderos(int n) {
    int div = 2;
    while (n != 1) {
        if ((n % div == 0) and (n % (div*div) != 0)) return false;
        if ((n % div == 0) and (n % (div*div) == 0)) {
            n = n/(div*div);
            while (n % div == 0) {
                n = n/div;
            }
        }
        ++div;
    }
    if (n == 1) return true;
    else return false;
}

int main() {
    int n;
    while (cin >> n) {
        cout << 1;
        for(int i=2; i <= n; ++i) {
            if (es_poderos(i)) cout << "," << i;
        }
        cout << endl;
    }
}
