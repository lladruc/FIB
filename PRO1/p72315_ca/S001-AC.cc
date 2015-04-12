#include <iostream>
using namespace std;

int intercalacio(int x, int y){
	int aux;
	if(x<10){
		return x*10+y;
	}else{
		int a = x%10;
		int b = y%10;
		aux = a*10+b;
		x /= 10;
		y /= 10;
		return (intercalacio(x,y)*100+aux);
	}
}

int main(){
	int a,b;
	bool first = true;
	while(cin >> a >> b){
		cout << intercalacio(a,b) << endl;
	}
}