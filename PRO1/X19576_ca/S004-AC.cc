#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

bool readCamp(Matriu& camp){
  int n = camp.size();
  bool ok = true;
  for (int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> camp[i][j];
      if((j == 0 or j == n-1) and camp[i][j] != -1) ok = false;
    }
  }
  return ok;
}

int numMinas(const Matriu& c, int fil, int col){
  int n = c.size();
  int cont = 0;
  for (int i = -1; i <= 1; ++i){
    for(int j = -1; j <= 1; ++j){
      if( 0 <= fil+i and fil+i < n and 0 <= col+j and col+j < n){
	if(c[fil+i][col+j] == -1) ++cont;
      }
    }
  }
  return cont;
}

void calcularInfoMines(Matriu& c){
  int n = c.size();
  for (int i = 0; i < n; ++i){
    for(int j = 0; j < n-1; ++j){
      if(c[i][j] == 0) c[i][j] = numMinas(c,i,j);
    }
  }
}

void escriureInfoMines(const Matriu& camp){
  int n = camp.size();
  for (int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(camp[i][j] >= 0) cout << "+";
      cout << camp[i][j];
      if(j != n-1) cout << " ";
    }
    cout << endl;
  }
}

int main(){
  int n;
  cin >> n;
  while(n > 0){
    int z;
    cin >> z;
    Matriu camp(z, vector<int>(z));
    if(not readCamp(camp)) cout << "reject" << endl;
    else{
      calcularInfoMines(camp);
      escriureInfoMines(camp);
    }
    cout << endl;
    --n;
  }
}