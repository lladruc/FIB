#include <iostream>
#include <vector>
using namespace std;

struct Persona{
	string nom;
	bool dona;
	int edat;
};

int main(){
	int n,viejo=0;
	cin >> n;
	vector<Persona> p(n);
	while(n){
		string sexo;
		--n;
		cin >> p[n].nom;
		cin >> sexo;
		if(sexo == "home") p[n].dona = false;
		else p[n].dona = true;
		cin >> p[n].edat;
		if(not p[n].dona and p[n].edat > viejo) viejo = p[n].edat;
	}
	//n = p.size(); // @overload.
	for(int i = p.size()-1 ; i>=0; --i){
		if(p[i].dona and p[i].edat < viejo)
			cout << p[i].nom << " " << p[i].edat << endl;
	}
}