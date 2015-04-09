#include <iostream>
using namespace std;

int main(){
	int n; 
	cin >> n;
	cout << n/3600 << " ";
	n = n % 3600;
	cout << n/60 << " ";
	n = n % 60;
	cout << n << endl;
}