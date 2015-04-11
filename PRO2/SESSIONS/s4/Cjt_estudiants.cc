#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}
  
Cjt_estudiants::~Cjt_estudiants(){}
 /*
void Cjt_estudiants::afegir_estudiant(const Estudiant& est)
{
  if (nest>=MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = 0;
  bool b = false;
  while (i<nest && !b) {
    if (est.consultar_DNI() < vest[i].consultar_DNI()) b = true;
    else ++i; 
  }	  
  // b indica que est ha d'anar abans del final i, per tant, cal desplaar
  // i es la posicio on ha d'anar est
  if(b) /* est.consultar_DNI() < vest[i].consultar_DNI() *//*
    {
      for (int j=nest; j>i; --j) vest[j] = vest[j-1];
    } 

  vest[i] = est;
  ++nest;
}
*/
void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b){
  /* PRE: El parametre implicit no esta ple
   * POST b indica si el parametre implicit original conté un estudiant amb dni d'est;
   *  - Si b= fals, s'ha afegit l'estudiant al parametre implicit
   */
  if (nest>=MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int dni = est.consultar_DNI();
  if(cerca_dicot(vest,0,nest-1,dni) != -1) b = true;
  else{
    int i;
    for(i = nest; i>=1 and vest[i-1].consultar_DNI() > dni; --i) vest[i] = vest[i-1];
    vest[i] = est;
    ++nest;
    b = false;
  }
  
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  int i;
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  if (found) return i; 
  else return -1;  
}  
/*
void Cjt_estudiants::modificar_estudiant(const Estudiant& est)
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  *//*
{
  int i = 0;
  int x = est.consultar_DNI();
  i=cerca_dicot(vest,0,nest-1,x);
  vest[i]= est;
} 
*/

void Cjt_estudiants::modificar_estudiant(const Estudiant& est, bool& b){
  if (nest>=MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest,0,nest-1,dni);
  if(pos != -1) b = true;
  else{
    vest[pos] = est;
    b=false;
  }  
}
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est)
{
  if (i<1 or i>nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i-1]= est;
}
  
int Cjt_estudiants::mida() const
{return nest;}
  
int Cjt_estudiants::mida_maxima()
{return MAX_NEST;}

bool Cjt_estudiants::existeix_estudiant(int dni) const
{
  int i = 0;
  i= cerca_dicot(vest,0,nest-1,dni);
  return (i!=-1);
}
/*
Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
{
  int i = 0;
  i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 */

void Cjt_estudiants::consultar_estudiant(Estudiant& est,int dni, bool& b) const{
  int i = 0;
  i=cerca_dicot(vest,0,nest-1,dni);
  est = consultar_iessim(i);
}


Estudiant Cjt_estudiants::consultar_iessim(int i) const
{
 if (i<1 or i>nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}
/*
bool comp(const Estudiant &e1, const Estudiant &e2){
  return (e1.consultar_DNI()<e2.consultar_DNI());
}
*/
void Cjt_estudiants::ordenar_cjt_estudiants (){
  //sort(vest.begin(),vest.begin()+nest,comp); //original file
  sort(vest.begin(),vest.begin()+nest,Estudiant::comp);
}

void Cjt_estudiants::esborrar_estudiant(int dni){
  /*PRE: Existeix un estudiant al parametre implicit amb DNI = dni
   * POST: el parametre implicit conté tots els estudiants menys el del DNI = dni;
   */
  Cjt_estudiants aux;
  int i = 0;
  bool noSirvoParaNada;
  while(vest[i].consultar_DNI() != dni)aux.afegir_estudiant(vest[i], noSirvoParaNada);
  ++i;
  for( ; i<= nest ;++i) aux.afegir_estudiant(vest[i], noSirvoParaNada);
}

void Cjt_estudiants::llegir(){
  cin >> nest;
  if (nest>MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i=0; i<nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
}


void Cjt_estudiants::escriure() const{
  for (int i=0; i<nest; ++i)
    vest[i].escriure();
}
