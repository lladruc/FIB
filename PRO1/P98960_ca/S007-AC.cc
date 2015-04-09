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
		cout << char(('a'-'A')+l) << endl;
	}else{ // es minuscula
		cout << char(l-('a'-'A')) << endl;
	}
}