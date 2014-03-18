#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

//#define for(i, a, b) \
//  for(int i = int(a); i <= int(b); i++)
//#define Rvi(c, it) \
//  for(vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rvii(c, it) \
//  for(vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rmsi(c, it) \
//  for(msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  string s;
  getline(cin, s);
  getline(cin, s);

  while(s.compare("___________") != 0) {
    int n = 0;

    if(s[2] == 'o') n += 64;
    if(s[3] == 'o') n += 32;
    if(s[4] == 'o') n += 16;
    if(s[5] == 'o') n += 8;
    if(s[7] == 'o') n += 4;
    if(s[8] == 'o') n += 2;
    if(s[9] == 'o') n += 1;

    cout << char(n);

    getline(cin, s);
  }

  return 0;
}
