#include <iostream>
using namespace std;

void Girar(int n){
	if(n>0){
		string s;
		cin >> s;
		Girar(n-1);
		cout << s << endl;
	}
}

int main(){
	int n;
	cin >> n;
	Girar(n);
}