#include <iostream>
using namespace std;

bool es_guai(int n, int b){
	if(n<b){
		if(n%2==0)return true;
		else return false;
	}else{	
		if((n%b)%2==0) return es_guai(n/b,b);
		else return false;
	}
}