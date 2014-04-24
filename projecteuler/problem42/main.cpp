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
  vector<bool> T(1000000, false);

  for(int i=1; i<=1000; i++)
    T[(i*(i+1))/2] = true;
  
  bool sw = true;
  int s = 0, n = 0;
  char c;
  while(true) {
    c = getchar();
    if(c == '\377')
      break;

    if(c == '\"') {
      if(sw) {
	sw = false;
      } else {
	if(T[s])
	  n++;
	s = 0;
	sw = false;
      }
    } else {
      if(c != ',')
	s += (c-'@');
    }
  }

  printf("%d\n", n);

  return 0;
}
