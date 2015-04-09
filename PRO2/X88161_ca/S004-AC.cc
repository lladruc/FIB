#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct par {
    int x, y;
};
 
typedef vector< vector<par> > Matriz;
 
struct team {
  int ind, puntos, favor, contra;
};
 
void leer_matriz(Matriz& m) {
    int n;
    cin >> n;
    m =  Matriz(n, vector<par>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          cin >> m[i][j].x >> m[i][j].y;
      }
    }
}
 
 
void inicializar_equipos(vector<team>& c) {
  for (int i = 0; i < c.size(); ++i) {
    c[i].ind = i + 1;
    c[i].puntos = c[i].favor = c[i].contra = 0;
  }
}
 
void liga(vector<team>& v, const Matriz& m) {
    int n = m.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          //procesar goles a favor/contra
          v[i].favor += m[i][j].x;
          v[i].contra += m[i][j].y;
          v[j].favor += m[i][j].y;
          v[j].contra += m[i][j].x;
          //procesar puntos
          if (m[i][j].x > m[i][j].y) v[i].puntos += 3;
          else if (m[i][j].x < m[i][j].y) v[j].puntos += 3;
          else {
            ++v[i].puntos;
            ++v[j].puntos;
          }
        }
      }
    }
}
 
bool cmp(const team& a, const team& b) {
  if (a.puntos == b.puntos) {
    if ((a.favor - a.contra) == (b.favor - b.contra))  return a.ind < b.ind;
    else return (a.favor - a.contra) > (b.favor - b.contra);
  }
  else return a.puntos > b.puntos;
}
 
void escribir_clas(vector<team>& c) {
  for (int i = 0; i < c.size(); ++i) {
    cout << c[i].ind << " " << c[i].puntos << " " << c[i].favor << " " << c[i].contra << endl;
  }
}
 
int main() {
  Matriz m;
  leer_matriz(m);
  vector<team> c(m.size());
  inicializar_equipos(c);
  liga(c, m);
  sort(c.begin(), c.end(), cmp);
  escribir_clas(c);
 
}