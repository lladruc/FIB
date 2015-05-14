/** @file Tag.cc
 *  @brief Classe Tag
 */

 #include "Tag.hh"

//DEPRECATED
/** @brief: lIt es una lista de iteradores de los eventos de Agenda
*/
//typedef list<list<Events>::iterator> lIt;
//DEPRECATED

 typedef set<string>::const_iterator itTag;

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
    while(not nTags.empty()){
      string aux = nTags.top();
      if(not matchTag(aux).first) tags.insert(aux);
      nTags.pop();
    }
  }

  /** @brief
      \pre Cert
      \post Si el tag existeix, l'esborra.
  */
  void Tag::delTags(string& delTag){
    pair<bool,itTag> n = matchTag(delTag);
    if(n.first) tags.erase(n.second);
    else cout << "No s'ha realitzat" << endl;
  }

  string Tag::getTags()const{
    string aux;
    itTag it = tags.begin();
    if(it != tags.end()) aux += (*it);
    ++it;
    while(it != tags.end()) aux += " " + (*it);
    return aux;
  }

  bool Tag::i_search(string& s)const{
    //CODIGO OFUSCADO -- SE AÑADIRÁ PROXIMAMENTE
    return true;
  }

  pair<bool,itTag> Tag::matchTag(string& tag)const {
  itTag r = tags.find(tag);
  return make_pair(r != tags.end(),r);
  }


  bool Tag::matchTags(stack<string>& tags)const{
    if(tags.empty()) return false;
    bool match = true;
    while(not tags.empty() and match){
      string aux = tags.top();
      match = matchTag(aux).first;
    }
    return match;
  }



