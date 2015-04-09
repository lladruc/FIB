#include <iostream>
#include <vector>
 
using namespace std;
 
double producte_escalar(const vector<double>& u, const vector<double>& v);
 
int main() {
    vector <double> v (50,5);
    vector <double> u (50,8);
    cout << producte_escalar(u, v) << endl;
}
 
double producte_escalar(const vector<double>& u, const vector<double>& v) {
    double producto = 0;
    for (int i = 0; i < u.size(); ++i){
    	producto += u[i]*v[i];
    }
    return producto;
}