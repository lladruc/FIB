#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  nota = -1;
}

Estudiant::Estudiant(const Estudiant& e){
  this->dni = e.dni;
  this->nota = e.nota;
}

Estudiant::~Estudiant(){
  cout << "Se ha eliminado el estudiante" << endl;
}

void Estudiant::afegir_nota(double nota)
{
  if (nota >= 0) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (nota < 0) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  if(nota == -1) return false;
  else return true;
}

double Estudiant::consultar_nota() const
{
  if (nota == -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

bool Estudiant::comp(const Estudiant& a, const Estudiant&	 b){
  return a.dni < b.dni;
}

void Estudiant::llegir()
{
  dni= readint();
  if (dni<0) throw PRO2Excepcio(ER4);
  double x = readdouble();
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
  else nota = -1;
}

void Estudiant::escriure() const
{
  if (nota >= 0)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
