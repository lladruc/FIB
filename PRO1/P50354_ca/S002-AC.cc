#include <iostream>
#include <vector>
using namespace std;

bool coincideix(string a, string b){
  if(a.length() < b.length()) return false;
  else{
    for (int i = 0; i < b.length(); ++i){
      if(a[i] != b[i]) return false;
    }
    return true;
  }
  return true;
}

void search(const vector<string>& v, string word){
  cout << "Comencen amb " << word << ":" << endl;
  for(int i = v.size()-1; i >= 0; --i){
    if(coincideix(v[i],word)){
      cout << v[i] << endl;
    }
  }
}

int main(){
  int n;
  while(cin >> n){
    vector<string>v(n);
    while(n>0){
    --n;
      cin >> v[n];
    }
    cin >> n;
    string word;
    while(n>0){
      cin >> word;
      search(v,word);
      --n;
    }
  }
}