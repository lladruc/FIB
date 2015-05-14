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
/** @brief: lIt es una lista de iteradores de los eventos de Agenda
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
  
  /** @brief Añade los tags del stack (ignora los que ya existen)
   * \pre Cert
   * \post tags ara conte els nous tags
   */
  void addTags(stack<string>& nTags);

  /** @brief
      \pre Cert
      \post Si el tag existeix, l'esborra.
  */
  void delTags(string& delTag);


  string getTags()const;

   /** @brief Funció de busqueda d'inmersió.
      \pre 
      \post
  */
  bool i_search(string& s)const;

  /** @brief
      \pre
      \post
  */
  pair<bool,itTag> matchTag(string& tag)const;
  
  /** @brief
      \pre
      \post
  */
  bool matchTags(stack<string>& tags)const;

};

#endif