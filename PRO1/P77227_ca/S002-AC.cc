#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sortida(int p, vector<int>&v){
	bool indexOutOfBounds = false;
	int ant = p, size = v.size();

	while(not indexOutOfBounds and v[p]!= 0){
		ant = p;
		p = p + v[p];
		v[ant] = 0;
		indexOutOfBounds = p < 0 or p >= size;
	}
	if(indexOutOfBounds){
		if(p<0) return "esquerra";
		return "dreta";
	}
	return "mai";
}