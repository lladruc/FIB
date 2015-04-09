
#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
	if(esq > dre) return -1;
	int pos = ( esq + dre ) / 2; // p central de v[esq+dre]
	if(x < v[pos]) return posicio(x,v,esq,pos-1);
	if(x > v[pos])return posicio(x,v,pos+1,dre);

	return pos;
}