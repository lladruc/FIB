/** @file Tag.cc
 *  @brief Classe Tag
 */

 #include "tag.hh"

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
    string aux = "";
    itTag it = tags.begin();
    if(it != tags.end()) aux += (*it), ++it;
    while(it != tags.end()) aux += " " + (*it), ++it;
    return aux;
  }

  bool Tag::teTags()const{
    return (not tags.empty());
  }


  /**@brief 
    \pre
    \post
  */
  void Tag::iRs(const string & s, int & i, bool & ok, bool ev)const{ //const??
    if(s[i] == '#'){ //direct
        int j = i+2;
        while((s[i + j] != '.' and s[i + j] != ','
            and s[i + j] != ')' and i+j != s.size())) ++j;
        if(ev) ok = matchTag(s.substr(i, j)).first;
        i += j;
    }else{ // recursive
        ++i;
        //H.I. ok conte el resultat del primer element
        iRs(s, i, ok, ev);
        bool ok1 = ok;
        char op = s[i];
        ++i;
        bool ev1;
        if((ok and op == '.') or (not ok and op == ',')) ev1 = true;
        else ev1 = false;
        iRs(s, i, ok, ev1);
        if(op == '.') ok = ok and ok1;
        else if(op == ',') ok = ok or ok1;
        ++i;
     }
  }


  bool Tag::i_search(string& s)const{
    if(s[0]=='#') return matchTag(s).first;

    bool reg_expr = false;
    int par = 0;
    int i;
    for(i = s.length()-2; i > 2 and not reg_expr;--i){
      if(s[i]== ')') ++par;
      else if(s[i]== '(') --par;
      if((s[i]== '.' or s[i] == ',') and par == 0) reg_expr = true;
    }
    string s1, s2;
    char op = s[i+1];
    s1 = s.substr(1,i);
    s2 = s.substr(i+2,s.length()-i-3);
    bool b = i_search(s2);
    if(op == '.'){
      if(b) return i_search(s1);
      else return false;
     //return (i_search(s2) and i_search(s1));
    }else{
      if(b) return true;
      else return i_search(s1);
     //return (i_search(s2) or i_search(s1));
    }
  }

  pair<bool,itTag> Tag::matchTag(string tag)const {
  itTag r = tags.find(tag);
  return make_pair(r != tags.end(),r);
  }

  //OLD IMPLEMENTATION - DRU
  bool Tag::matchTags(stack<string>& tags)const{
    if(tags.empty()) return true;
    bool match = true;
    while(not tags.empty() and match){
      match = matchTag(tags.top()).first;
      tags.pop();
    }
    return match;
  }

  stack<string> Tag::hisTags()const {
    stack<string> aux;
    if(tags.empty()) return aux;
    set<string>::const_iterator it = tags.begin();
    while(it != tags.end()){
      aux.push((*it));
      ++it;
    }
    return aux;
  }


