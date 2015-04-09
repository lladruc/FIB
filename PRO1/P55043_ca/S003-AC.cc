#include <iostream>
#include <vector>
using namespace std;

int suma_digit(int n){
	if(n < 10) return n;
	else return suma_digit(n/10) + n%10;
}

int trobada_de_rius(int n){
	int riun = n;
	int riu1 = 1;
	int riu3 = 3;
	int riu9 = 9;

	while(not (riun== riu1 or riun == riu3 or riun == riu9)){
		if(riu1 < riun) riu1 += suma_digit(riu1);
		if(riu3 < riun) riu3 += suma_digit(riu3);
		if(riu9 < riun) riu9 += suma_digit(riu9);

		if(riun < riu1 and riun < riu3 and riun < riu9) riun += suma_digit(riun);
	}

	return riun;
}