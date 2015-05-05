/** @file x97464_ca.cc
	@brief Exercici del jutge.
*/
#include <iostream>
#include <list>
using namespace std;

/** @brief Selecciona els elemens majors que la mitja dels anteriors.
	\pre l not empty & sel is empty
	\post sel contains elements( l ): l[i] > sum{l[0...i-1]}/i
*/ 
void seleccio(const list<double>& l, list<double>& sel){
	double acum=0;
	list<double>::const_iterator it = l.begin();
	if(it != l.end()) acum = (*it) , sel.push_back(*it) , ++it; // obtains first element of mitjana
	while(it != l.end()){
		if((*it) >= acum) sel.push_back(*it);
		acum = (acum+(*it))/2;
		//cout << "M: " << acum << endl;
		++it;
	}
	//cout << " END DEBUG\n-----------" << endl;
}

int main(){
	list<double> l,r;
	double n;
	// - IN -
	/** @brief bucle de lectura.
		\pre Cert
		\post l contains all cin's except "-1" [exit condition]
	*/
	while(cin >> n and n != -1){
		//INV: l contiene todos los elementos leidos hasta el momento dif. de -1.
		l.push_back(n);
	}
	// aply algorithm ->
	seleccio(l,r);
	// - OUT -
	list<double>::iterator it = r.begin();
	if(it != r.end()) cout << (*it), ++it;
	//INV: it toma por valor los it elementos leidos de la lista.
	//INV: *it toma por valor el contenido del it(puntero) de la lista.
	while(it != r.end()){
		cout << " " << (*it);
		++it;
	}
	cout << endl;
}