#include <iostream>
#include <vector>
using namespace std;

void calcular_primeros_mil_primeros(vector<bool>& v){
	v[0] = v[1] = false; //0 y 1 no son primos

	for(int i = 2; i*i <= 7919; ++i){
		if(v[i]){
			for(int j = 2*i; j<= 7919; j+=i){
				if(v[j]) v[j] = false;
			}
		}
	}
}

int main(){
	vector<bool>v(7929,true);
	calcular_primeros_mil_primeros(v);
	int n;
	while(cin >> n){
		int i = 1;
		bool primer = true;
		for(int j = 0; j < n; ++j){
			++i;
			while(i < v.size() and not v[i]) ++ i;
			if(primer){
				cout << i;
				primer = false;
			}else cout << "," << i;
		}
		cout << endl;
	}
}