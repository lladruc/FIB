#include <iostream>
#include <vector>
using namespace std;


struct Punt{
	double x,y;	
};

bool baricentre(const vector<Punt>& v, Punt& b){
	double auxX = 0, auxY = 0;  
	for(int i = 0; i < v.size(); ++i) {
	    auxX += v[i].x;
	    auxY += v[i].y;
	}
	b.x = auxX / v.size();
	b.y = auxY / v.size();
	for(int i = 0; i < v.size(); ++i) {
	  if(b.x == v[i].x and b.y == v[i].y) return true;
	}
	return false;
}

bool minimdos(const vector<Punt>& v){
	for(int p = v.size(); p > 0; --p) {
	  for(int q = 0; q < p-1; ++q) {
	    if(v[p-1].x != v[q].x or v[p-1].y != v[q].y) return true;
	  }
	}
	return false;
}

bool xey(const vector<Punt>& v){
	double auxX, auxY;
	auxY=auxX=0;
	for(int i = 0; i < v.size(); ++i){
		auxX += v[i].x;
		auxY += v[i].y;
	}
	return auxX == auxY;	
}

int main(){ 
cout.setf(ios::fixed);
cout.precision(2);
	int n;
	while(cin >> n){
		vector<Punt>v(n);
		while(n>0){
			--n;
			cin >> v[n].x >> v[n].y;
		}
		Punt b;
		bool hote = baricentre(v,b);
		cout << "baricentre: (" << b.x << "," << b.y << ")" << endl;
		if(not minimdos(v)){ // no cumple propiedad 1
			cout << "el vector no compleix la propietat 1" << endl;
		}else if(not xey(v)){ // no cumple la propiedad 2
			cout << "el vector no compleix la propietat 2" << endl;
		}else if(hote){ // no cumple la propiedad 3
			cout << "el vector no compleix la propietat 3" << endl;
		}else{ // hazte con todos, Pokec++
			cout << "vector normalitzat" << endl;
		}
	}
}