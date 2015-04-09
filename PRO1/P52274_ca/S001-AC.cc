#include <iostream>
#include <cmath>
using namespace std;
 
struct Punt {
    double x, y;
};
 
struct Cercle {
    Punt centre;
    double radi;
};
 
void llegeix(Punt& p) {
    cin >> p.x >> p.y;
}
 
void llegeix(Cercle& c) {
   cin >> c.centre.x >> c.centre.y >> c.radi;
}
 
void desplaca(Punt& p1, const Punt& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
   
}
 
void escala(Cercle& c, double esc) {
    c.radi *= esc;
 
}
 
double distancia(const Punt& a, const Punt& b) {
    double x1 = a.x - b.x;
    double y1 = a.y - b.y;
    double p = sqrt(x1*x1 + y1*y1);
    return p;
}
 
int relacio(const Cercle& c1, const Cercle& c2) {
    // Distancia entre centros menor que diferencia radios
    if (distancia(c1.centre, c2.centre) < c1.radi - c2.radi) return 2;
    else if (distancia(c1.centre, c2.centre) < c2.radi - c1.radi) return 1;
    // Distancia menor que suma de radios
    else if (distancia(c1.centre, c2.centre) < c2.radi + c1.radi) return 3;
    // Distancia mayor suma de radios
    else return 0;
}
 
void mostra_relacio(const Cercle& c1, const Cercle& c2) {
    if (relacio(c1, c2) == 1) cout << "el primer cercle es interior al segon";
    else if (relacio(c1, c2) == 2) cout << "el segon cercle es interior al primer";
    else if (relacio(c1, c2) == 3) cout << "els cercles intersecten";
    else cout << "els cercles no intersecten";
    cout << endl;
}
 
 
int main() {
    Cercle c1, c2;
    llegeix(c1);
    llegeix(c2);
    mostra_relacio(c1, c2);
    int c1c2;
    while (cin >> c1c2) {
        string s;
        cin >> s;
        if (s == "escala") {
            double d;
            cin >> d;
            if (c1c2 == 1) escala(c1, d);
            else escala(c2, d);
        }
        else  {
            Punt p;
            llegeix(p);
            if (c1c2 == 1) desplaca(c1.centre, p);
            else desplaca(c2.centre, p);
        }
        mostra_relacio(c1, c2);
    }
}