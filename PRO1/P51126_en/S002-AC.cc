#include <iostream>
using namespace std;

int main()
{
	int a1, a2, b1, b2, x, y; // Intervals d'entrada: [a1,b1], [a2,b2], sortida: [x,y]
	cin >> a1 >> b1 >> a2 >> b2;
	if(b1 < a2 || b2 < a1) // Intervals separats
		cout << "[]" << endl;
	else
	{
		if(a1 < a2)
			x = a2;
		else
			x = a1;
		if(b1 > b2)
			y = b2;
		else
			y = b1;
		cout << "[" << x << "," << y << "]" << endl;
	}
}