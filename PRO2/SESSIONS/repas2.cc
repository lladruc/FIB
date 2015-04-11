#include "utils.PRO2"
#include <iostream>
#include <algorithm>
#include <vector>

struct equip{
  int num;
  int punts;
  int marcats;
  int rebuts;
};


typedef vector<equip> lliga;

void inicialitzar(lliga& v){
  for(int i = 0; i < v.size(); ++i){
     v[i].num = i+1;
     v[i].punts = v[i].marcats = v[i].rebuts = 0;
  }
}
void llegirLliga(lliga& v){
  int fa, rep, tamany;
  tamany = v.size();
  for(int i = 0; i < tamany; ++i){
    for(int j = 0; j < tamany; ++j){
	if(i != j){
	  fa = readint();
	  rep = readint();
	  
	  // MIREM ELS PUNTS QUE CORRESPON
	  if(fa < rep){ // a < b
	    v[i].punts += 3;
	    // v[j].punts += 0 // no rep punts! 4debug.
	  }else if(fa > rep){ // a > b
	    //v[i].punts += 0 // no rep punts! 4debug.
	    v[j].punts +=3;
	  }else{ // a == b // tots dos equips reben 1 punt.
	    ++v[i].punts;
	    ++v[j].punts;
	   }
	  // TRACTEM ELS GOLS aFavor i enContra
	  v[i].marcats += fa;
	  v[i].rebuts += rep;
	  v[j].marcats += rep;
	  v[j].rebuts += fa;
	}else{
	   fa = readint();
	  rep = readint();
	}
    }
  }
}
bool sorter(const equip& a, const equip& b){
  bool resultat = false;
  if(a.punts == b.punts){
    if((a.marcats - a.rebuts) == (b.marcats - b.rebuts)){
      resultat = a.num < b.num;
    }else{
      resultat = (((a.marcats - a.rebuts) > (b.marcats - b.rebuts)));
    }
  }else{
    resultat = a.punts > b.punts;
  }
  return resultat;
}

void calcul_i_printa( lliga& r){
  //SORT PUNTS > GOLSMARCATS - REBUTS > NUM_EQUIP_ASC
  sort(r.begin(),r.end(),sorter);
  int tamany = r.size();
  for(int i = 0; i < tamany; ++i){
    cout << r[i].num << " " << r[i].punts << " " << r[i].marcats << " " << r[i].rebuts << endl;
  }
}

int main(){
  int tamany = readint();
  lliga r(tamany);
  inicialitzar(r);
  llegirLliga(r);
  calcul_i_printa(r);
  
}