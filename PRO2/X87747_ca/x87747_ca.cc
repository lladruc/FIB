#include <iostream>
#include <vector>
 
using namespace std;
 
int solitaris(const vector<int>& v)
{
        int s = 0;
        int l = v.size();
       
        if (l == 1) return 1;
        if (v[0] != v[1]) s ++;
        if (l > 1)
                if (v[l-2] != v[l-1]) s ++;
       
        for (int aux = 1; aux < l-1; ++ aux)
                if (v[aux-1] != v[aux] and v[aux] != v[aux+1]) s ++;
 
        return s;
}