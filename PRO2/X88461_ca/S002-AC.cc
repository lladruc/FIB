#include "utils.PRO2"
#include <iostream>
#include <vector>

struct parint{
  int prim, seg;
};

/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor m´aximo de v;
el segundo componente del resultado es el valor m´ınimo de v */
parint max_min (const vector<int> &v){
  parint a;
  a.prim=a.seg=v[0];
  for(int i = 0; i < v.size(); ++i){
    if(v[i]>a.prim) a.prim = v[i];
    else if(v[i]<a.seg) a.seg = v[i];
  }
  return a;
}

int main(){
  int n;
  n= readint();
  vector<int>v (n);
  while(n){
    --n;
    v[n] = readint();
  }
  parint a = max_min(v);
  cout << a.prim << " " << a.seg << endl;

}