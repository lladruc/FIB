#include <iostream>
#include <vector>

using namespace std;

int main() {
int n;
while (cin >> n) {
typedef vector<int> Row;
typedef vector<Row> Matrix;
Matrix matriu(n,Row(n));

int n2 = n * n;
vector<int> numeros(n2, false);

//Guardem les dades entrades dins de la matriu
for (int x = 0; x < n; ++x) {
for (int y = 0; y < n; ++y) {
int valor;
cin >> valor;
numeros[valor-1] = true;
matriu[x][y] = valor;
}
}

//Comprovem que hi siguin tots els nombres
bool todos_numeros = true;
for (int i = 0; i < n2 and todos_numeros; ++i) {
if (!numeros[i]) todos_numeros = false;
}



//Calculem la suma de la primera fila
int suma = 0;
for (int i = 0; i < n; ++i) {
suma += matriu[0][i];
}

//Comprovem les sumes horitzontals verticals i diagonals
bool esmagico = true;
int temp = 0;
int temp2 = 0;
int temp3 = 0;
int temp4 = 0;
int n1 = n - 1;
for (int x = 0; x < n and esmagico; ++x) {
for (int y = 0; y < n; ++y) {
temp += matriu[x][y];
temp2 += matriu[y][x];
temp3 += matriu[y][y];
temp4 += matriu[y][n1-y];
}
if (temp != suma) esmagico = false;
if (temp2 != suma) esmagico = false;
if (temp3 != suma) esmagico = false;
if (temp4 != suma) esmagico = false;
temp = 0;
temp2 = 0;
temp3= 0;
temp4= 0;

}

//Imprimim el resultat
if (esmagico and todos_numeros) cout << "yes" << endl;
else cout << "no" << endl;
}
}