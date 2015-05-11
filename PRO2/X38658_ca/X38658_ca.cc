#include <iostream>
#include <stack>
#include "Arbre.hh"
 
using namespace std;
 
void i_cami_preferent (Arbre<int> &a, stack<int> &c, int &n)
{
  if (a.es_buit())
  {
    n = 0;
  }
  else
  {
    int arrel = a.arrel();
   
    Arbre<int> a1, a2;
    a.fills(a1, a2);
    int n1;
    int n2;
    stack<int> c1;
    stack<int> c2;
   
    i_cami_preferent(a1, c1, n1);
    i_cami_preferent(a2, c2, n2);
 
    if (n1 >= n2) c = c1;
    else c = c2;
    n = n1 + n2 + 1;
    c.push(arrel);
  }
}
 
void cami_preferent (Arbre<int> &a, stack<int> &c)
{
    int n;
    i_cami_preferent(a, c, n);
}