#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Representa un conjunt ordenat per DNI d'estudiants.  
  // Es poden consultar i modificar els seus elements  
  // (de tipus Estudiant) donat un DNI o per posició en l'ordre.
  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 60; //before: max 20, after: max 60 // DRU.
  int imax;//int pointer -> est max note.
  void ordenar_cjt_estudiants ();
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);

public:

  //Constructores

  Cjt_estudiants();

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadores

  //void afegir_estudiant(const Estudiant& est);
  void afegir_estudiant(const Estudiant& est, bool& b);

  //void modificar_estudiant(const Estudiant& est);
  void modificar_estudiant(const Estudiant& est, bool& b);
    
  void modificar_iessim(int i, const Estudiant& est);
  
  void esborrar_estudiant(int dni);

  //Consultores
	
  int mida() const;

  static int mida_maxima();

  bool existeix_estudiant(int dni) const;

  //Estudiant consultar_estudiant(int dni) const;
  void consultar_estudiant(Estudiant& est,int dni, bool& b) const;

  Estudiant consultar_iessim(int i) const;
		
  // Lectura i escriptura
	
  void llegir();

  void escriure() const;

};
#endif
