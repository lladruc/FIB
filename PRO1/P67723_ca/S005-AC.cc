#include <iostream>
using namespace std;

int main () {
    int a, b, r, t1, t2;
    cin >> a >> b;
    t1 = a;
    t2 = b;
    r=a%b;
    while ( r > 0 ) {
        a=b;
        b=r;
        r=a%b;
    }
    
    cout << "El mcd de " << t1 << " i " << t2 << " es " << b << "." <<  endl;
}