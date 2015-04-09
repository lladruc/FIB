#include <iostream>
using namespace std;

/*
int main {
	int entrada,r i=1,s=0; // r = repeticiones x suma.
	cin >> entrada;
	r= (10%entrada)+1;
	while (i<=r){
		s+=entrada%(10*i);
		i++;
	}
}
*/
int main () {
	char l;
	cin >> l;
	if(l<='Z'){ // es majuscula
		cout << "majuscula" << endl;
		if(l == 'A' or l == 'E' or l == 'I' or l == 'O' or l == 'U'){
			cout << "vocal" << endl;
		}else{
			cout << "consonant" << endl;
		}
		
	}else{ // es minuscula
		cout << "minuscula" << endl;
		if(l == 'a' or l == 'e' or l == 'i' or l == 'o' or l == 'u'){
			cout << "vocal" << endl;
		}else{
			cout << "consonant" << endl;
		}
	}
}