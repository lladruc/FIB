#include "utils.PRO2"
#include <vector>
#include "Estudiant.hh"
void escriureMitjana(int materies, const vector<int>& sel);

/*Pre: Cert */
/*Post: cout << mitja notes seleccionades alumne */
void escriureMitjana(int materies, const vector<bool>& sel){
  int dni = readint(); // read DNI
  double aux, acum, nota;
  aux = acum = nota = 0;
  for(int i = 0; i < materies; ++i){
    nota = readdouble();
    if(sel[i]){
      acum += nota;
      ++aux;
    } 
  }
   cout << dni << " " << (acum/aux) << endl;
}

int main(){
  int size = readint(); // number of students
  int materies = readint(); // number of materies
  int selector = readint(); // selector or num. of valid notes v[$i]
  
  vector<bool> n(materies, false);
  for(int i = 0; i < selector; ++i) n[readint()-1] = true;
  
  for(int i = 0; i < size; ++i) escriureMitjana(materies, n);
}
