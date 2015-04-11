#include "ListaPalabras.hh"

/* Constructoras */   
ListaPalabras::ListaPalabras (){
  paraules = vector<palfrec>(MAXNUMPAL);
  nparaules = 0;
  maxfrec = 0;
}

/* Destructora */
//~ListaPalabras();

/* Modificadoras  */
void ListaPalabras::anadir_palabra (const Palabra & p){
  bool trobada = false;
  for(int i = 0; i < nparaules and not trobada; ++i){
    if(paraules[i].par.iguales(p)){
      ++paraules[i].freq;
      trobada = true;
      if(paraules[i].freq > paraules[maxfrec].freq) maxfrec = i;
    }
  }
  if(not trobada){
    palfrec aux;
    aux.par = p;
    aux.freq = 1;
    paraules[nparaules] = aux;
    if(maxfrec == -1) maxfrec = nparaules;
    ++nparaules;
  }
}

/* Consultoras */
int ListaPalabras::longitud_maxima (){
  return MAXNUMPAL;
}
int ListaPalabras::longitud () const{
  return nparaules;
  
}

int ListaPalabras::max_frec () const{ 
/** \Pre: vector no buit;
  * \Post: return vector position of word maxfrec;
  */
if(nparaules>0) return paraules[maxfrec].freq;
else return 0;
}

/* Lectura y escritura */
/*
void ListaPalabras::leer (){
  Palabra p;
  p.leer('.');
  while(p.long_pal() != 0){
    this->anadir_palabra(p);
    p.leer('.');
  }
}

*/
void ListaPalabras::leer(){
  int op;
  bool fiwhile = false;
  while(cin >> op and not fiwhile){
    if(op == -1){
      Palabra p;
      p.leer('.');
    }else if(op == -2){
      paraules[maxfrec].par.escribir();
      cout << ": " << max_frec() << endl;
    }else if(op == -3){
      fiwhile = true;
    }else{
      cout << endl << "\rOPCION INCORRECTA !" << endl;
    } 
  }
}


void ListaPalabras::escribir () const{
  for(int i = 0; i < nparaules; ++i){
    cout << "La paraula: ";
    paraules[i].par.escribir();
    cout << " apareix " << paraules[i].freq << "vegada(es)." << endl;  
  }
}