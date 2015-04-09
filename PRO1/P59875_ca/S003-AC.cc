#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	if(n < m){
		int x = n;
		n = m;
		m = x;
	}
	for(int i = n; i >= m; --i) cout << i << endl;
}