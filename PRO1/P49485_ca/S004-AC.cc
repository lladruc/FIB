#include <iostream>
using namespace std;

bool es_equilibrat_de_tres_en_tres(int N) {
	int A = 0, B =0, C =0;
	while ( N > 0) {
		A = A + N%2;
		N = N/2;
		B = B + N%2;
		N = N/2;
		C = C + N%2;
		N = N/2;
	}
	return (A == B) and (B == C);
}