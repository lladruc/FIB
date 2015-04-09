#include <iostream>
using namespace std;

int mcd(long int a, long int b){ 
	int aux; 
	while(b) { 
		aux = b; 
		b = a % b; 
		a = aux; 
	} 
	return a; 
} 
int mcm(long int a, long int b){ 
	return (a * b)/mcd(a, b); 
}

void calc(int n){
	long int a,b;
	cin >> a;
	for(int i=1;i<n;i++){
		cin >> b;
		a=mcm(a,b);
	}
	cout << a << endl;
}
int main(){
	int nums=1;
	bool durex = true;
	while(durex){
		cin >> nums;
		if(nums !=0){
			calc(nums);
		}else{
			durex = false;
		}
	}
}