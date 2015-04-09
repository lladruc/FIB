
#include <iostream>
using namespace std;

int main() {
  int y, d, h, m, s;
  cin >> y >> d >> h >> m >> s;
  s+= m * 60;
  s+= h * 3600; // seconds per hour
  s+= d * 86400; // seconds per day
  s+= y * 31536000; // seconds x year
  cout << s << endl;
}