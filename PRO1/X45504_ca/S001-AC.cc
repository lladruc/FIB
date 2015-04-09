/*FIB - PRO2 - C1 T2 - C6S301 - Marcel Olsina Portell 48085329B*/
#include "ListaPalabras.hh"

void ListaPalabras::anadir_palabra(const Palabra &p)
/* Pre: el número de palabras en el parámetro implícito es menor que la 
     longitud máxima o p ya está en él; p no es la palabra vacía */
  /* Post: si p estaba en el parámetro implícito original, su frecuencia se ha
     incrementado en 1; si no, p pasa a estar en él, con frecuencia 1 */
{
    int i;
    bool trobada;
    buscar_palabra_posicion(p,trobada,i);
    if(trobada)
    {
        ++paraules[i].freq;
    }
    else
    {
        paraules[nparaules].par = p;
        paraules[nparaules].freq = 1;
        ++npar_long[p.long_pal()-1];
        ++nparaules;
    }
    //Exista o no +1
    ++suma_frec_long[p.long_pal()-1];
}

void ListaPalabras::borrar_palabra(const Palabra &p)
/* Pre: si p pertence al p.i., tiene frecuencia f */
  /* Post:
     si p no pertence al p.i, no cambia nada; 
     si f = 1, p ya no pertenece al p.i.; 
     si f > 1, la frecuencia de p se ha decrementado en 1  */
{
    bool trobada;
    int pos;
    buscar_palabra_posicion(p,trobada,pos);
    if(trobada){
        --suma_frec_long[p.long_pal()-1];
        if(paraules[pos].freq > 1) --paraules[pos].freq;
        else{ // hi es pro nomes 1 cop
            --npar_long[p.long_pal()-1];
            for(int i = pos+1; i < nparaules; ++i) paraules[i-1] = paraules[i];
            --nparaules;
        }
    }
}

void ListaPalabras::buscar_palabra_posicion(const Palabra &p, bool &b, int &i) const
/* Pre: cierto */
/* Post: b indica si p está en el parámetro implícito;
si b entonces i es la posición en la que está p; si no, i es la 
longitud del parámetro implícito */ 
{
    b = false;
    for(i = 0; i < nparaules and not b; ++i)
    {
        if(paraules[i].par.iguales(p)) b = true;
    }
    if(b) --i;
}