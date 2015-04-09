#include <iostream>
#include <vector>
using namespace std;
 
struct Info {
  string nom, hora;  
};
 
string dicotomica (string x, const vector <Info>& v, int esq, int dre) {
  if (esq > dre) return "ABANDONA";
  int pos = (esq + dre)/2;
  if (v[pos].nom > x) return dicotomica(x,v,esq,pos-1);
  if (v[pos].nom < x) return dicotomica(x,v,pos+1,dre);
  if ((pos > 0 and v[pos - 1].nom == x) or (pos < v.size() - 1 and v[pos + 1].nom == x)) return "???";
  return v[pos].hora;
}
 
string busca(string nom, const vector<Info>& v) {
  return dicotomica(nom,v,0,v.size()-1);
}
 
 
 
int main() {
  int n;
  cin >> n;
  vector <Info> v(n);
  for (int i = 0; i < v.size(); ++i) {
    cin >> v[i].nom >> v[i].hora;
  }
  string num,part;
  while (cin >> num >> part) {
    cout << num << " " << busca(part,v) << endl;
  }
}