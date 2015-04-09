#include <iostream>
using namespace std;

int main(){
	int e,c;
	cin >> e >> c;
	cout << "Bitllets de 500 euros: " << e/500 << endl;
	e = e % 500;
	cout << "Bitllets de 200 euros: " << e/200 << endl;
	e = e % 200;
	cout << "Bitllets de 100 euros: " << e/100 << endl;
	e = e % 100;
	cout << "Bitllets de 50 euros: " << e/50 << endl;
	e = e % 50;
	cout << "Bitllets de 20 euros: " << e/20 << endl;
	e = e % 20;
	cout << "Bitllets de 10 euros: " << e/10 << endl;
	e = e % 10;
	cout << "Bitllets de 5 euros: " << e/5 << endl;
	e = e % 5;
	cout << "Monedes de 2 euros: " << e/2 << endl;
	e = e % 2;
	cout << "Monedes de 1 euro: " << e << endl;
	cout << "Monedes de 50 centims: " << c/50 << endl;
	c = c % 50;
	cout << "Monedes de 20 centims: " << c/20 << endl;
	c = c % 20;
	cout << "Monedes de 10 centims: " << c/10 << endl;
	c = c % 10;
	cout << "Monedes de 5 centims: " << c/5 << endl;
	c = c % 5;
	cout << "Monedes de 2 centims: " << c/2 << endl;
	c = c % 2;
	cout << "Monedes de 1 centim: " << c << endl;
	
}