/** @file Tag.cc
 *  @brief Classe Tag
 */

 #include <iostream>
 #include <string>
 #include <set>
 #include <stack>
 #include "Tag.hh"
 using namespace std;

//DEPRECATED
/** @brief: lIt es una lista de iteradores de los eventos de Agenda
*/
//typedef list<list<Events>::iterator> lIt;
//DEPRECATED

 typedef set<string>::iterator itTag;

  // Constructora
  Tag::Tag(){
    set<string> tags;
  }

  Tag::Tag(stack<string>& nTags){
    set<string> tags;
    while(not nTags.empty()){
      tags.insert(nTags.top());
      nTags.pop();
    }
  }
  
  // Destructora
  //Tag::~Tag();
  
  //Consultores
  
  /** @brief 
   * \pre Cert
   * \post agrega els tags nous (ignora els que ja hi son)
   */
  void Tag::addTags(stack<string>& nTags){
    itTag p;
    while(not nTags.empty()){
      string aux = nTags.top();
      if(not matchTag(aux,p)) tags.insert(aux);
      nTags.pop();
    }
  }

  /** @brief
      \pre Cert
      \post Si el tag existeix, l'esborra.
  */
  void Tag::delTags(stack<string>& delTags){
    while(not delTags.empty()){
      itTag p;
      string aux = delTags.top();
      if(matchTag(aux,p)) tags.erase(p);
      delTags.pop();
    }
  }

  bool Tag::matchRegularExpresion(string re){
   return true; 
  }

  bool Tag::matchTag(string tag,itTag& r){
  r = tags.find(tag);
  return (r != tags.end());
  }


  bool Tag::matchTags(stack<string>& tags){
    bool match = true;
    while(not tags.empty() and match){
      itTag p;
      string aux = tags.top();
      match = matchTag(aux,p);
    }
    return match;
  }



