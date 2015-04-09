#include "utils.PRO2"
#include <vector>
#include "Estudiant.hh"

typedef vector<Estudiant> llistaEst;

llistaEst llegirEstudiants();
bool notaMesAlta(const Estudiant& x, const Estudiant& y);
llistaEst mirarNotes(const llistaEst& v);
void escriureResultats(const llistaEst& v);

  

/*Pre: Entren DNI's i Notes, les repetición de DNI son consecutius*/
/*Post: retorna llistat d'estudiants amb les notes.*/
llistaEst llegirEstudiants(){
  int n;
  cin >> n; //read next imputs;
  llistaEst aux(n);
  while(n){ //ad inverse order ->
    --n;
    aux[n].llegir(); // read DNI + NOTA (security dependence on class Estudiant
  }
  return mirarNotes(aux);
}

/*Pre: rep dos estudiants amb o sense nota */
/*Post: retorna si la nota s'ha d'actualitzar o no */
bool notaMesAlta(const Estudiant& x, const Estudiant& y){ // note: x = actual note. y = posible note
  if(not x.te_nota()) return true; // encara no te nota.
  else if(not y.te_nota()) return false; // el que ve no te nota
  else{ //ambos tenen nota
    if(x.consultar_nota() >= y.consultar_nota()) return false; // >= implica MENYS cambis + eficient
    else return true;
  }
}


/*Pre: Rep Vector d'estudiants, amb repeticions.*/
/*Post: torna nota max. *Sense duplicats */
llistaEst mirarNotes(const llistaEst& v){
  llistaEst aux;
  int size = v.size(), numDnis=0, thisDNI=-1;
  for(int i = 0 ; i < size; ++i){
    if(v[i].consultar_DNI() != thisDNI){
      ++numDnis;
      thisDNI = v[i].consultar_DNI();
      aux.push_back(v[i]);
    }else{
	if(notaMesAlta(aux[aux.size()-1], v[i])){
	  aux[aux.size()-1] = v[i];
	}
    }
  }
  return aux; // return llistaEstudiants  
}


/*Pre: Rep el vector*/
/*Post: cout << vector[$i].dni << " " << vector[$i].nota << endl */
void escriureResultats(const llistaEst& v){ //remember; for v.size --i ... 0;
  for(int i = v.size()-1; i >= 0; --i){
    cout << v[i].consultar_DNI() << " ";
    if(v[i].te_nota()) cout << v[i].consultar_nota() << endl;
    else cout << "NP" << endl;
  }
  
}

int main(){
  llistaEst v = llegirEstudiants();
  escriureResultats(v);
}