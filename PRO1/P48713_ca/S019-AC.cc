#include <iostream>
using namespace std;

bool noEsPrimer(int n){
	if(n==1)return true;
	if(n==2)return false;
	if(n%2==0) return true;
	for(int i=3; i*i<=n;i+=2){
		if(n%i==0){
			return true; // n%i == 0, not prime( except %1, and max n/2 +1 )
		}
	}
	return false; // if no find n%i==0, is prime number.
}

int main(){
	int seq;
	cin >> seq;
	for(int n;seq>0;--seq){
		cin >> n;
		cout << n;
		if(noEsPrimer(n)){
			cout << " no";
		}
		cout << " es primer" << endl;
	}
}