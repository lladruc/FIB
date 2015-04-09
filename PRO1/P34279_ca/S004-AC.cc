#include <iostream>
using namespace std;

int main(){
	int h,m,s;
	cin >> h >> m >> s;
	++s;
	if(s>59){
		++m;
		s=0;
		if(m>59){
			++h;
			m=0;
			if(h>23){
				h=0;
			}
		}
	}
	if(h<10) cout << "0" << h << ":";
	else cout << h << ":";
	if(m<10) cout << "0" << m << ":";
	else cout << m << ":";
	if(s<10) cout << "0"<< s << endl;
	else cout << s << endl;
}