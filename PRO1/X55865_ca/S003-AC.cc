#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Tauler;

struct Bola{
  int x_ant, y_ant;  // Posicio anterior de la bola
  int x_act, y_act;  // Posicio actual de la bola
  int x_seg, y_seg;  // Posicio seguent de la bola
};

Tauler crear_tauler(int n, int m, Bola& b){
  Tauler t(n, vector<char>(m,'.'));
  b.x_ant = b.y_ant = -1;
  
  cin >> b.x_act >> b.y_act;
  t[b.x_act][b.y_act] = 'B';
  
  if(b.x_act == 0) b.x_seg = b.x_act + 1;
  else b.x_seg = b.x_act -1;
  
  if(b.y_act == 0) b.y_seg = b.y_act + 1;
  else b.y_seg = b.y_act -1;
  
  int x,y;
  cin >> x >> y;
  t[x][y] = 'b';
  return t;
}

bool topa_banda(const Bola& b, int n, int m){
  return (b.x_act == 0 or b.x_act == n-1 or b.y_act == 0 or b.y_act == m-1);
}

bool topa_cantonada(const Bola& b, int n, int m){
  return ((b.x_act == 0 or b.x_act == n-1) and (b.y_act == 0 or b.y_act == m-1));
}

void escriu(const Tauler& t, const int& n, const int& m){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j) cout << t[i][j];
    cout << endl;
  }
  cout << endl;
}

void moure_fins_xocar(Tauler& t, Bola& b){ //desplacament
  int n = t.size();
  int m = t[0].size();
  int dx = b.x_seg - b.x_act;
  int dy = b.y_seg - b.y_act;
  
  bool banda = false;
  bool cantonada = false;
  bool bola = false;
  while(not banda and not cantonada and not bola){
    
    //avançar la bola
    b.x_ant = b.x_act;
    b.y_ant = b.y_act;
    b.x_act = b.x_seg;
    b.y_act = b.y_seg;
    
    //mirar on ha anat a parar
    
    banda = topa_banda(b,n,m);
    cantonada = topa_cantonada(b,n,m);
    bola = (t[b.x_act][b.y_act] == 'b');
    
    //calcular segunet posiciió;
    b.x_seg = b.x_act;
    b.y_seg = b.y_act;
    
    if(not banda){
      b.x_seg += dx;
      b.y_seg += dy;
    }else if(not cantonada){
      if(b.x_act == 0){
	++b.x_seg;
	if(b.y_ant < b.y_act) ++b.y_seg;
	else --b.y_seg;
      }
      else if(b.x_act == n-1){
	--b.x_seg;
	if(b.y_ant < b.y_act) ++b.y_seg;
	else --b.y_seg;
      }
      else if(b.y_act == 0){
	++b.y_seg;
	if(b.x_ant < b.x_act) ++b.x_seg;
	else --b.x_seg;
      }
      else{
	--b.y_seg;
	if(b.x_ant < b.x_act) ++b.x_seg;
	else --b.x_seg;
      }
    }
    t[b.x_ant][b.y_ant] = '=';
    t[b.x_act][b.y_act] = 'B';
  }
  
}


int main(){
  int n,m;
  while(cin >> n >> m){
    Bola b;
    Tauler t = crear_tauler(n,m,b);//(n, vector<char>(m,'.'));
    bool aturar = false;
    bool carambola = false;
    int xocs = 0;
    while(not aturar and not carambola){
      moure_fins_xocar(t, b);
      
      if(topa_cantonada(b,n,m)) aturar = true;
      
      else if (topa_banda(b,n,m)){
	cout << "(" << b.x_act << "," << b.y_act << ")";
	++xocs;
	if(xocs > 3) aturar = true;
      }else{ // xoc amb la vermella
	if(xocs < 3) aturar = true;
	else carambola = true;
      }
    }
    if(carambola) cout << ": si" << endl;
    else cout << ": no" << endl;
    escriu(t,n,m);
  }
}