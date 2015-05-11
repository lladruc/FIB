#include <iostream>
#include <list>
 
using namespace std;
 
void seleccio (const list<double> & l, list<double> & sel){
        list<double>::const_iterator i = l.begin();
        double valor = *i;
        double suma = valor;
        sel.insert(sel.end(), valor);
        int count = 1;
       
        ++i;
       
        while (i != l.end()){
                valor = *i;
                if (valor >= (suma/count)) sel.insert(sel.end(), valor);
                ++ i;
                ++ count;
                suma += valor;
        }
}