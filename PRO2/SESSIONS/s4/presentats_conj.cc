#include "Cjt_estudiants.hh"

double presentats (const Cjt_estudiants  &c)
/* Pre: c cont� almenys un element */
/* Post: el resultat �s el percentatge de presentats de vest */
 {
 int numEst = c.mida();
 int n = 0;
 for (int i=1; i<=numEst; ++i) if(c.consultar_iessim(i).te_nota()) ++n;
 /* n �s el nombre d'estudiants de c amb nota */
 double p = n*100./numEst;
 return p;
}

int main()
{
  Cjt_estudiants c; 
  c.llegir();  
  cout << "Estudiants del conjunt: " << endl;
  c.escriure();
  double x =presentats(c);
  cout << "Presentats del conjunt: " << x << "%" << endl;
}
