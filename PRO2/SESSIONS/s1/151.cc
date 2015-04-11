#include <iostream>
#include <vector>
using namespace std;

/* Pre: 0 <= i, j < v.size() */
/* Post: v[i] y v[j] tienen sus valores intercambiados respecto a los iniciales */
void intercambiar_vect(vector<int> &v, int i, int j){
  int aux = v[i];
  v[i]=v[j];
  v[j] = aux;
}

int main(){
  int size, posA, posB;
  cin >> size;
  vector<int> v(size);
  for(int i = 0; i < size; ++i) cin >> v[i];
  
  cin >> posA >> posB;
  intercambiar_vect(v,posA,posB);
  //cout only for debug.
  cout << v[posA] << " " << v[posB] << endl;
}