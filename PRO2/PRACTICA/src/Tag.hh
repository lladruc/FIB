/** @file Tag.hh
 *  @brief Classe Tag

*/

#ifndef TAG_HH
#define TAG_HH

#include <iostream>
#include <string>
#include <set>
#include <stack>
using namespace std;

/** @class Tag
 *  @brief Conte el conjunt 
 */

//DEPRECATED
/** @brief: lIt es una lista de iteradors dels events de Agenda
*/
//typedef list<list<Events>::iterator> lIt;
//DEPRECATED
typedef set<string>::iterator itTag;

using namespace std;

class Tag{
private:
  set<string> tags;

public: 
  // Constructora
  Tag(); 
  
  Tag(stack<string>& nTags);
  // Destructora
  //~Tag();
  
  //Consultores
  
  /** @brief Metode per afegir els tags al stack (ignora els que ya existeixen)
   * \pre Cert
   * \post tags ara conte els nous tags
   */
  void addTags(stack<string>& nTags);

  /** @brief Metode per eliminar els tags del stack
      \pre Cert
      \post Si el tag existeix, l'esborra.
  */
  void delTags(string& delTag);
  
  /** @brief Funció de consulta de tags
      \pre true
      \post retorna una cadena amb tots els tags de la tasca
  */
  string getTags()const;
  
  /** @brief Funció per verificar que hi ha tags 
      \pre true
      \post retorna true si hi ha almenys 1 tag
  */
  bool teTags()const;
  
  /** @brief Metode de cerca per expressi� regular
      \pre true
      \post ok retorna true si es compleix la expressi�
  */
  void iRs(const string & s, int & i, bool & ok, bool ev)const;

   /** @brief Funció de recerca d'inmersió.
      \pre s != NULL
      \post retorna true si els tags del event 
	    compleixen les condicions de s
  */
  bool i_search(string& s)const;

  /** @brief  Funció trobar tag
      \pre    tag != NULL
      \post   Si es troba torna la posició del iterador on es troba
              Sino existeix retorna tags.end()
  */
  pair<bool,itTag> matchTag(string tag)const;
  
  /** @brief  Funció de recerca de tags
      \pre    tag != NULL
      \post   retorna true si es troba el tag en
              el set de tag de la tasca
  */
  bool matchTags(stack<string>& tags)const;
  
  /** @brief 
      \pre true
      \post 
  */
  stack<string> hisTags() const;

};

#endif
