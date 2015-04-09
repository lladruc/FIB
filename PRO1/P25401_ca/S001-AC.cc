#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int diferents(vector<int>& v) {
  sort(v.begin(), v.end());
  int cont = 1;
  for ( int i = 1; i < v.size(); ++i ) {
    if ( v[i] != v[i - 1] ) ++cont;
  }
  return cont;
}

int main () {
  int n;
  while ( cin >> n ) {
    vector<int> v( n );
    for ( int i = 0; i < n; ++i ) {
      cin >> v[i];
    }
    cout << diferents(v) << endl;
  }
}