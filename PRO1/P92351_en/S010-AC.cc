#include <iostream> // P92351
using namespace std;

int main() {
	long int a, b, d, r;
	cin >> a >> b;
	if ( a < 0 && a % b != 0 ) {
		d = - 1 + ( a / b );
		r = -d * b + a;
	} else {
		d = a / b;
		r= a % b;
	}
	cout << d << " " << r << endl;
}

