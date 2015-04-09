#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Taula;

void LlegirCamp(Taula& taula){
  for(int i = 0 ; i < taula.size(); ++i){
    for(int j = 0 ; j < taula[0].size(); ++j){
      cin >> taula[i][j];
    }
  }
}

void avanzar(int& WF, int& WC, int IF, int IC, int& Deix, Taula& taula){
  while(taula[WF][WC] != 'X'){
    if(taula[WF][WC] != '.'){
      Deix += taula[WF][WC] - '0';
      taula[WF][WC] = '.';
    }
    WF += IF;
    WC += IC;
  }
  WF = WF - IF;
  WC = WC - IC;
}

void comptar_deixalles(int& WF, int& WC, int& Deix, Taula& taula){
  Deix = 0;
  string p;
  cin >> p;
  int IF, IC;
  for(int i = 0; i < p.length(); ++i){
    if(p[i] == 'N'){ // go to Nord < < Winter is coming > >
      IF = -1;
      IC = 0;
    }else if(p[i] == 'S'){ // go to South < < Dragons mother here > > 
      IF = +1;
      IC = 0;
    }else if(p[i] == 'E'){ // go to Est
      IF = 0;
      IC = +1;
    }else{ // go to West
      IF = 0;
      IC = -1;
    }
    avanzar(WF,WC,IF,IC,Deix,taula);
  }
}
int main(){
  int f,c;
  int cas = 0;
  while (cin >> f >> c){
    ++cas;
    Taula Camp(f,vector<char> (c));
    LlegirCamp(Camp);
    int wF,wC;
    cin >> wF >> wC;
    int D;
    comptar_deixalles(wF,wC,D,Camp);
    cout << "Cas " << cas << ": " << D << endl;
  }
}