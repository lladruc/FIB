#ifndef LISTAPALABRAS_HH
#define LISTAPALABRAS_HH

#include "Palabra.hh"
#include <vector>

/*
* Clase ListaPalabras
*/

struct palfrec; 

class ListaPalabras
{

private:
  struct palfrec{
    Palabra par;
    int freq;
  };
  int nparaules;
  int maxfrec;
  vector<palfrec> paraules;
  static const int MAXNUMPAL = 20;
/* MAXNUMPAL se podria incluir como campo normal, para poder manejar
     distintos maximos segun la situacion */
 
public:
  /* Constructoras */   
  ListaPalabras ();

  /* Destructora */
  //  ~ListaPalabras();
  /* Modificadoras  */
  void anadir_palabra (const Palabra & p);

  /* Consultoras */
  static int longitud_maxima ();
  int longitud () const;
  int max_frec () const;

  /* Lectura y escritura */
  void leer ();
  void escribir () const;

};

#endif
