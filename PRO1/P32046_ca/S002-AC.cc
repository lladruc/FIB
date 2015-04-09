 #include <iostream>
using namespace std;

int main () {
    int base, altre, i = 0;
    cin >> base;
    cout << "nombres que acaben igual que " << base << ":" << endl;
    while ( cin >> altre ) {
        if( ( base % 1000 ) == ( altre % 1000 ) ){
            ++i;
            cout << altre << endl;
        }
    }
    cout << "total: " << i << endl;
}
