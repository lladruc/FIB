#include "event.hh"
/** @file Event.cc
	@brief Classe Event.cc*/
    //Constructora per defecte
    Event::Event(){
      titol = "";
      tagList = Tag();
    }
    //Constructora custom
    Event::Event(string titol,stack<string> nTags){
      this->titol = titol;
      tagList.addTags(nTags);
    }


    bool Event::operator==(const Event& e)const {
        bool eq = this->titol == e.titol;
        stack<string> aux1 = this->tagList.hisTags();
        stack<string> aux2 = e.tagList.hisTags();
        if(not (aux1.empty() and aux2.empty())){
            while(not aux1.empty() and aux2.empty() and eq){
                eq = aux1.top() == aux2.top();
                aux1.pop();
                aux2.pop();
            }
        }
        if(not aux1.empty() or not aux2.empty()) eq = false;
        return eq;

    }
    //Destructora
    //~Event();

    /** @brief retorna el titol de l'event.
    	\pre Cert
    	\post retorna el titol de l'event.
    */	
    string Event::getTitol() const{
      return titol;
    }
    
    /** @brief Retorna un string amb tots els tags de l'event separats per espais.
		\pre Cert
		\post Retorna un string amb tots els tags separats per espais "#tag1 #tag2 #tagN"
    */
    string Event::getTags() const{
        return tagList.getTags();
    }

    /** @brief Assigna un nou titol
    	\pre Cert
    	\post Titol pren per valor el rebut per parametre
    */
    void Event::setTitol(string titol){
      if(titol != "") this->titol = titol;
    }

    /** @brief Assigna un nou tag a l'event
    	\pre Cert
    	\post Tags incloura el nou tag
    */
    void Event::setTags(stack<string>& tags){
      tagList.addTags(tags);
    }

    /** @brief busqueda d'una expresio regular de tags
        \pre Cert
        \post Retorna si l'event de l'agenda compleix la expresio regular
    */
    bool Event::sRe(string s)const{
      return tagList.i_search(s);
    /*   bool ok = false;
        int i = 0;
        tagList.iRs(s,i,ok);
        return ok; */
    }

    bool Event::teTags()const{
        return tagList.teTags();
    }

    bool Event::findTag(string& tag)const{
        if(tag.length() < 1) return true;
        return tagList.matchTag(tag).first;
    }

    /** @brief Metode d'esborrat de tags de l'event
    	\pre Cert
    	\post tags conte tots els tags menys els rebuts
    */
    void Event::delTag(string& tags){
      tagList.delTags(tags);
    }

    /** @brief esborra tots els tags [mes rapid que delTag [nomes per esborrar tots]]
    	\pre Cert
    	\post L'event no contindra cap tag
    */
    void Event::delAllTags(){
        tagList = Tag();
    }
