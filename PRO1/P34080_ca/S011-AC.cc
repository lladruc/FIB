#include <iostream>
using namespace std;


void quadrats(int n){ // in n out : 0123..n%10'\n'...5678...etc.
int i=0,j=0,aux=n*n;
	while(i<aux){
		cout << j;
		++j;
		++i;
		if(j>9){
			j=0;
		}
		if(i%n==0){
			cout << endl;
		}
	}
}

int main (){
	int n;
	bool first=false;
	while(cin >> n){
		if(first){
		  cout << endl;
		}
		quadrats(n);
		first=true;
	}
}