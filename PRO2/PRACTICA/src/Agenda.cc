#include "agenda.hh"
using namespace std;

typedef map<Rellotge,Event>::iterator evIt;

//Constructora per defecte
Agenda::Agenda(){
	Rellotge rTime;
	map<Rellotge,Event> calendar;
}


//Destructora
//Agenda::~Agenda();


//deveria ser una función privada que dependa de otra función de la clse basada en el control y esta si deberia ser pública.
//Dada la cantidad de errores a gestionar, vale la pena una función pública o una clase con metodos públicos de gestión de errores? O.o¡
void Agenda::addEvent(string titol, string date, string hora, stack<string>& tags){
	Rellotge rAux(date,hora);
	if(not(rAux < rTime)){ //no estamos viajando al pasado
		Event eAux(titol,tags);
		evIt it = calendar.find(rAux);
		if(it == calendar.end()) calendar.insert(make_pair(rAux,eAux));
		else cout << "No s'ha realitzat" << endl;

	}else{
		cout << "No s'ha realitzat" << endl;
	}
}


void Agenda::modEvent(int i,Rellotge key,string titol, string date, string hora, stack<string>& tags){
	evIt it = calendar.find(key);
	Rellotge rAux(date,hora);
	evIt it2 = calendar.find(rAux);
	if(not (rAux < rTime) and (it == it2 or it2 == calendar.end())){ // o sobreescribimos el mismo, o lo movemos a un hueco libre
		Event evAux = (*it).second;
		if(titol != "") evAux.setTitol(titol);
		if(not tags.empty()) evAux.setTags(tags);
		pair<Rellotge,Event> calAux = make_pair(rAux,evAux);
		calendar.erase(it);
		calendar.insert(calAux);
		v[i-1].first = rAux;
	}else cout << "No s'ha realitzat" << endl;
}


void Agenda::delEvent(Rellotge key, int i){
	if(not(key < rTime)){
		if(calendar.erase(calendar.find(key)->first) == 0) cout << "No s'ha realitzat" << endl;
		else v[i-1].second = false;
	}else cout << "No s'ha realitzat" << endl;
}

string Agenda::escriure(const pair<Rellotge,Event>& e)const {
	string aux = e.second.getTitol() + " " + e.first.printDateAndTime();
	if(e.second.teTags())aux += " " + e.second.getTags();
	return aux;
}

/** @brief Funció de busqueda per expresió regular
	\pre Cert [Pre: Expresió correca definida per comanda]
	\post v[] conté
*/
void Agenda::listMatchEvents(string hashtags,Rellotge& ini, Rellotge& end){
	v = vector<pair<Rellotge,bool> >();
    map<Rellotge,Event>::const_iterator itIni = calendar.lower_bound(ini);
    map<Rellotge,Event>::const_iterator itEnd = calendar.upper_bound(end);
    int i = 1;
    while(itIni != itEnd){
      if(itIni->second.sRe(hashtags)){
		v.push_back(make_pair(itIni->first,(not (itIni->first < rTime))));
      	cout << i << " " << escriure((*itIni)) << endl;
      	++i;
      }
      ++itIni;
    }
  }

  void Agenda::pass_search(Rellotge ini, Rellotge& end,string& tag){
	v = vector<pair<Rellotge,bool> >();
	if(not(end < ini)){
		map<Rellotge,Event>::const_iterator it = calendar.lower_bound(ini);
		map<Rellotge,Event>::const_iterator itEnd = calendar.lower_bound(end); //per mirar al passat
		int i = 1;
		while(it != itEnd){
			if(it->second.findTag(tag)){
				v.push_back(make_pair(it->first,false));
				cout << i << " " << escriure((*it)) << endl;
				++i;
			}
			++it;
		}
	}
}
  
  
  
void Agenda::search(Rellotge ini, Rellotge& end,string& tag){
	v = vector<pair<Rellotge,bool> >();
	if(not(end < ini)){
		map<Rellotge,Event>::const_iterator it = calendar.lower_bound(ini);
		map<Rellotge,Event>::const_iterator itEnd = calendar.upper_bound(end);
		int i = 1;
		while(it != itEnd){
			if(it->second.findTag(tag)){
				v.push_back(make_pair(it->first,(not (it->first < rTime))));
				cout << i << " " << escriure((*it)) << endl;
				++i;
			}
			++it;
		}
	}
}
  
/** @brief borra un tag
	\pre Cert
	\post agenda en la posicio consultada conte tots els tags menys el borrat.
*/
void Agenda::delTag(Rellotge key, string tag){
	if(not(key < rTime)){
		evIt it = calendar.find(key);
		it->second.delTag(tag);
	}else cout << "No s'ha realitzat" << endl;
}

/** @brief
	\pre
	\post
*/
void Agenda::delTags(Rellotge key){
	evIt it = calendar.find(key);
	if(it->second.teTags() and (not(key < rTime))){
	it->second.delAllTags();
	}else{
		cout << "No s'ha realitzat" << endl;
	}
}


/** @brief
	\pre
	\post
*/
Rellotge Agenda::getClock() const{
	return rTime;
}

/** @brief
	\pre
	\post
*/
void Agenda::setClock(Rellotge& nuevo){
	if(not (nuevo < rTime)){
		rTime = nuevo;
		for(int i = 0; i < v.size(); ++i){
			if(v[i].first < rTime) v[i].second = false;
		}
	}
	else cout << "No s'ha realitzat" << endl;
}

/** @brief
	\pre
	\post
*/
Rellotge Agenda::vRi(int i){
	return v[i-1].first;
}

bool Agenda::vRe(int i){
	return v[i-1].second;
}

/** @brief
	\pre
	\post
*/
int Agenda::resultsSize(){
	return v.size();
}

/** @brief
	\pre
	\post
*/
bool Agenda::esBuit() const{
	return calendar.empty();
}