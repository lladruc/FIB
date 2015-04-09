#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int x,y;
	x=y=0;
	for(int i =0; i < s.length(); ++i){
		char aux = s[i];
		if(aux == 'n'){
			--y;
		}else if(aux == 's'){
			++y;
		}else if(aux == 'e'){
			++x;
		}else{ // aux == o
			--x;
		}
	}
	cout << "(" << x <<", " << y << ")" << endl;
}