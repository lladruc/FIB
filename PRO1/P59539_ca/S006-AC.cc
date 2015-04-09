#include <iostream> /* by Lladruc */
using namespace std;

int main (){
	cout.setf(ios::fixed);
	cout.precision(4);
	double number, i=1,res; // result
	cin >> number;

	while(i<=number){
		res+= 1/i;
		++i; // or i++ -.-¡
	}
	cout << res << endl;
}