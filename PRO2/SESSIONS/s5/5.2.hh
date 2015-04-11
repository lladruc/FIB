/**
 * @mainpage Ejemplo de diseño modular:  Ej 5.2.
 */

/** @file 5.2.cc
    @brief Programa principal para el ejercicio <em>Ej 5.2</em>.
*/

#include "Palabra.hh" // para que el diagrama modular quede bien
#include "ListaPalabras.hh"


/** \Pre 0 < word < Palabra(MAXLONG)
 * \Pre  0 < words < ListaPalabras(MAXNUMPAL)
 * \Post "lista" contains all words.
 */
void leer(ListaPalabras& l){
  Palabra p;
  p.leer('.');
  while(p.long_pal() != 0){
    l.anadir_palabra(p);
  }
}



/** @brief Programa principal para el ejercicio <em>Ej 5.2</em>.
*/
int main ()
{
  ListaPalabras lista;
  leer(lista);
  cout << lista.max_freq() << endl;
}
/*
Dado un texto terminado en ’.’, obtener la frecuencia de la palabra mas frecuente del 
mismo. El ´texto consta de una o mas palabras formadas por letras o n ´ umeros y 
separadas por cualquier otro ´caracter. 
El texto no contendra m´ as de ´ MAXNUMPAL palabras distintas, 
cada una de ellas no mayorde MAXLONG caracteres. 
El texto se introduce por el canal standard de entrada. Podeis hacer las ´2 SESION 5.
DISE ´ NO MODULAR EN C++ (I) ˜primeras pruebas escribiendolo por teclado,
pero resultar ´ a interesante que tambi ´ en lo prob ´ eis ´redireccionando la 
entrada a un ﬁchero como pro2 s52.txt.
De este enunciado podemos deducir dos claras abstracciones de datos:
necesitamos la clasePalabra para ir leyendo y procesando cada palabra del texto y 
necesitamos otra estructura paraalmacenar las diferentes palabras junto con sus 
frecuencias.
La clase Palabra esta preparada para usarse en este ejercicio ya que la longitud 
m ´ axima ´que permite coincide con el MAXLONG de las palabras del texto. 
Podeis ver un ejemplo de uso ´en el ﬁchero ejpalmarca.cc. 
Para representar la otra estructura de datos os ofrecemos la claseListaPalabras que 
tambien est ´ a preparada para usarse en este ejercicio ya que el n ´ umero de ´
palabras distintas que permite coincide con el MAXNUMPAL del texto.*/