#include <iostream>
#include <vector>
 
using namespace std;
 
struct Provincia {
    string nom;
    string capital;
    int habitants;
    int area;
    double pib;
};
 
struct Pais {
    string nom;
    string capital;
    vector<Provincia> provs;
};
 
typedef vector<Pais> Paisos;
 
double pib(const Paisos& p, char c, double d) {
    double pib = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i].nom[0] == c) {
            for (int k = 0; k < p[i].provs.size(); ++k) {
                double densidad = double(p[i].provs[k].habitants)/p[i].provs[k].area;
                if (densidad > d) {
                    pib += p[i].provs[k].pib;
                }
            }
        }
    }
    return pib;
}