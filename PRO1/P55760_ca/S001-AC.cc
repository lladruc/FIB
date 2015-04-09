#include <iostream>
#include <vector>
 
using namespace std;
 
void paso(vector <char>& v, int n);
 
int main(){
    int n, p;   
    while (cin >> n >> p) {
        vector <char> v(n,'.');
        int bd;     // Boles cap a la dreta
        cin >> bd;
        // Colocacio de boles cap a la dreta
        if (bd > 0) for (int k = 0; k < bd; ++k) {
            int pos;
            cin >> pos;
            v[pos - 1] = '>';
        }
        int be;     // Boles cap a la esquerra
        cin >> be;
        // Colocacio de boles cap a la esquerra
        if (be > 0) for (int k = 0; k < be; ++k) {
            int pos;
            cin >> pos;
            v[pos - 1] = '<';
        }
        for (int h = 0; h < n; ++h) cout << v[h];
        cout << endl;
        for (int i = 0; i < p - 1; ++i) {
            paso(v, n);
            for (int l = 0; l < n; ++l) {
                cout << v[l];
            }
            cout << endl;
        }
        cout << endl;
    }
}
 
void paso(vector <char>& v, int n) {
    vector <char> p;
    p = v;
    for (int i = 0; i < n; ++i) {
        if (p[i] == '<' and (p[i - 1] == '>' or i == 0)) {
            v[i] = '.';
            v[i + 1] = '>';
        }
        else if (p[i] == '>' and (p[i + 1] == '<' or i == n - 1)) {
            v[i] = '.';
            v[i - 1] = '<';
        }
        else if (p[i] == '<' and p[i - 1] == '.') {
            v[i] = '.';
            v[i - 1] = '<';
        }
        else if (p[i] == '>' and p[i + 1] == '.') {
            v[i] = '.';
            v[i + 1] = '>';
        }
    }
}