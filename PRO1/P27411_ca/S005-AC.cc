#include <iostream>
using namespace std;

int main(){
	int i,r;
	bool esCorrecte=false;
	cin >> i;
	if(i>=0){
		for(int n=0,j=1;cin >> n and n!=-1 and !esCorrecte;++j){
			if(j==i){
				r=n;
				esCorrecte=true;
			}
		}
	}
	if(esCorrecte){
		cout << "A la posicio " << i << " hi ha un " << r << "." << endl;
	}else{
		cout << "Posicio incorrecta." << endl;
	}
}