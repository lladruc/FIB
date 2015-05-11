#include <iostream>
#include "Arbre.hh"
 
inline int max (int a, int b)
{
        if (a > b) return a;
        return b;
}
 
int arbre_altura (Arbre<int> & alt, Arbre<int> & sortida)
{
        if (alt.es_buit()) return 0;
       
        Arbre<int> alt_fe, alt_fd, sortida_fe, sortida_fd;
        alt.fills(alt_fe, alt_fd);
        int e = arbre_altura(alt_fe, sortida_fe);
        int d = arbre_altura(alt_fd, sortida_fd);
 
        sortida.plantar(e - d, sortida_fe, sortida_fd);
       
        return max (e, d) + 1;;
}
 
void arbre_graus_desequilibri(Arbre<int> &a, Arbre<int> &agd)
{
        arbre_altura(a,agd);
}