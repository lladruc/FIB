
/** @file Event.cc
	@brief Classe Event.cc*/
    //Constructora per defecte
    Event::Event(){
      titol = "";
      tags;
    }
    //Constructora custom
    Event::Event(string titol,stack<string> nTags){
      this->titol = titol;
      while(not nTags.empty()){
	tags.insert(nTags.top());
	nTags.pop();
      }
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
      string aux = "";
      return aux;
    }

    /** @brief Assigna un nou titol
    	\pre Cert
    	\post Titol pren per valor el rebut per parametre
    */
    void Event::setTitol(string titol){
      
    }

    /** @brief Assigna un nou tag a l'event
    	\pre Cert
    	\post Tags incloura el nou tag
    */
    void Event::setTags(stack<string> tags){
      
    }

    /** @brief busqueda d'una expresio regular de tags
        \pre Cert
        \post Retorna si l'event de l'agenda compleix la expresio regular
    */
    bool Event::sRe(string& s)const{
      return true;
    }

    /** @brief Metode d'esborrat de tags de l'event
    	\pre Cert
    	\post tags conte tots els tags menys els rebuts
    */
    void Event::delTag(stack<string> tags){
      
    }

    /** @brief esborra tots els tags [mes rapid que delTag [nomes per esborrar tots]]
    	\pre Cert
    	\post L'event no contindra cap tag
    */
    void Event::delAllTags(){
      
    }
