#include <iostream>
using namespace std;

int main(){
	int n,m,z1,z2;
	cin >> n;
	z1 = n%10;
	z2 = n%100;
	m = n/100;
	if(n%4 != 0 or (n%4==0 and (z1 ==0 and z2 == 0) and m%4 !=0)) cout << "NO";
	else cout << "YES";
	cout << endl;
}