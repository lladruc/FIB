#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

struct Veces{
	string s;
	int cont;
};

bool sorter(const Veces& a, const Veces& b){
	if (a.cont == b.cont ) return a.s < b.s;
	return a.cont > b.cont;
}
void orderby(vector<Veces>& mx){
	int max,j;
	max = mx.size();
	j=1;
	for(int i=1; i < max; ++i ){
		if ( mx[i-1].s == mx[i].s ){
			++j;
		}else{
			mx[i-1].cont = j;
			j=1;
		}
	}
	mx[mx.size()-1].cont = j;
}

int main(){
	int x,y;
	while(cin >> x >> y){
		vector<Veces>mx(x);
		while(x>0){
			--x;
			cin >> mx[x].s;
			mx[x].cont = 0;
			
		} // save words -> vector;
		// alphabetic order.
		sort(mx.begin(),mx.end(),sorter);
		// recount words.
		orderby(mx);
		// order vector 1r cont 2n alphabetic
		sort(mx.begin(),mx.end(),sorter);
		// print words;
		for(int i = 0; i < y;++i){
			cout << mx[i].s << endl;
		}
		cout << "----------" << endl;
	}
}