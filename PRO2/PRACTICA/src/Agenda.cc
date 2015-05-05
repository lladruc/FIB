#include <iostream>
#include <map>
#include <string>
#include <list>
#include "Rellotge.hh"
#include "tag.hh"
#include "event.hh"

using namespace std;

//Constructora per defecte
Agenda::Agenda(){
	Rellotge rTime();
	map<Rellotge,Event> calendar;
}

//Constructora personalitzada [posible delete.]
Agenda::Agenda(){
}

//Destructora
//Agenda::~Agenda();


//deveria ser una función privada que dependa de otra función de la clse basada en el control y esta si deberia ser pública.
//Dada la cantidad de errores a gestionar, vale la pena una función pública o una clase con metodos públicos de gestión de errores? O.o¡
void Agenda::addEvent(string titol, string date, string hora, stack<string>& tags){
	Rellotge rAux(date,hora);
	if(rTime < rAux){ //no estamos viajando al pasado
		Event eAux(titol,tags);
		a.insert(rAux,eAux);

	}else{
		cout << "No s'ha realitzat" << endl;
	}
	
	//a.insert(make_pair(,));

}

void Agenda::ModEvent(){}


void Agenda::delEvent(){}

string Agenda::print(){
	string aux = this.first.printDateAndTime() + " " +this.second.getTitol() + " " + this.second.getTags();
}

void Agenda::listMatchEvents(string& tags,vector<string>& v){
    Rellotge it = calendar.begin();
    int i = 1;
    while(it != calendar.end()){
      if((*it).tags.matchRegularExpresion(tags)) v.push_back(it);
      cout << i << this.print() << endl;
      ++i;
      ++it;
    }
  }

void Agenda::search(vector<string>& v, string ini, string end){
}
Rellotge Agenda::getClock() const{
	return rTime;
}
Rellotge Agenda::getLast() const{
	map<Rellotge,Event>::iterator it = a.end();
	--it;
	return (*it).first;
}
void Agenda::setRellotge(Rellotge& nuevo){
	rTime = nuevo;
}