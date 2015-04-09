#include <iostream>
using namespace std;

int main(){
	double n;
	cin >> n;
	cout << int(n) << " ";
	if(n > int(n)) cout << int(n)+1;
	else cout << int(n);
	cout << " ";
	if((n - int(n)) >= 0.5) cout << int(n)+1;
	else cout << int(n);

	cout << endl;
}