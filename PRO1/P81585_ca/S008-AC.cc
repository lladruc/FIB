#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >>n){
		int aux=0,r,s=0;
		while(n>0){
			cin >> r;
			if(r>=aux){ //recibo > acumulado.
				s+=aux;
				aux=r;
			}else{ // recibo < acumulado
				s+=r;
			}
			--n;
		}
		if(aux==s){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}