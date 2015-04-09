#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int linea = 1;
    bool found = false;
    bool primero = true;
    while (not found and cin >> n) {
        string ahora, anterior;
        found = true;
        for (int i = 0; i < n; ++i) {
            cin >> ahora;
            if (primero) anterior = ahora;
            primero = false;
            if (ahora < anterior) found = false;
            anterior = ahora;
        }
        if (found) cout << "La primera linia ordenada creixentment es la " << linea << '.' << endl;
        ++linea;
    }
    if (not found) cout << "No hi ha cap linia ordenada creixentment." << endl;
}