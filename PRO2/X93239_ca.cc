#include <iostream>
#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int>& v){
/** @brief 
\pre Cert
\Post el resultat es el nombre d'elements frontissa de v */
	int frontissa, pre, post;
	frontissa = pre = post = 0;
	if(not v.size()) frontissa = 1;

	for(int i = 0; i < v.size(); ++i) post += v[i];
	for(int i = 0; i < v.size();++i){
		post -= v[i];
		if(post-pre == v[i]) ++frontissa;
		pre += v[i];
	}
	return frontissa;
}
/* DEBUG 
int main(){
	vector<int> v;
	int n;
	while(cin >> n){
		v.push_back(n);
	}
	n = comptatge_frontisses(v);
	cout << "Resultat: " << n << endl;
} */