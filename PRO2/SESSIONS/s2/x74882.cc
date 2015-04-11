#include "utils.PRO2"
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

/*Pre: rep dos estudiants amb o sense nota */
/*Post: retorna si la nota s'ha d'actualitzar o no */
bool notaMesAlta(const Estudiant& x, const Estudiant& y){ // note: x = NULL && y = note [0-10]
    // suposits: x no te nota
  if(not x.te_nota()){ // x NO TE NOTA
    if(y.te_nota()) return true;
    else return false;
  }else if(y.te_nota()){ // x TE NOTA & y TE NOTA
    if(x.consultar_nota() >= y.consultar_nota()) return false;
    else return true;
  }
  // NEVER USED
  return false;  
}


/*Pre: Rep Vector d'estudiants, amb repeticions.*/
/*Post: torna nota max. *Sense duplicats */
void mirarNotes(Cjt_estudiants& prim,const Cjt_estudiants& seg){
  int size = seg.mida();
  Estudiant first,second;
  for(int i = 1; i <= size; ++i){ //
    second = seg.consultar_iessim(i);
    if(not prim.existeix_estudiant(second.consultar_DNI())){
      if(prim.mida() < prim.mida_maxima())prim.afegir_estudiant(second); // prim[prim.mida()+1] <- a[$i]
    }else{ // estudiant seg existeix en prim!
     
      first = prim.consultar_estudiant(second.consultar_DNI());
      if(notaMesAlta(first,second)){
	if(first.te_nota()) first.modificar_nota(second.consultar_nota());
	else first.afegir_nota(second.consultar_nota());
	
	prim.modificar_estudiant(first);
      }      
    }
  } //endFor
}


int main(){
  Cjt_estudiants prim, seg;
  prim.llegir();
  seg.llegir();
  mirarNotes(prim,seg);
  prim.escriure();
}