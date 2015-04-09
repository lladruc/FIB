#include <iostream>
#include <vector>
using namespace std;

void ordena_per_bombolla(vector<double>& v){

	int i = 1;
	int n = v.size();
	bool ordenado = false;

	while( i < n and not ordenado){
		++i;
		ordenado = true;
		for(int j = 0; j <= n - i; ++j){
			if(v[j] > v[j+1]){
				ordenado = false;
				double aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}