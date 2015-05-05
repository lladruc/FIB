#include <iostream>
using namespace std;

int main(){
	int target, n, cont, position;
	cont = 1;
	tarjet = -1;
	cin >> position;
	while(cin >> n and n != -1){
		if(position == cont) tarjet = n;
		++cont;
	}
	if(tarjet != -1) cout << "A la posicio " << position << " hi ha un " << tarjet << "." << endl;
	else "Posicio incorrecta." << endl;
}