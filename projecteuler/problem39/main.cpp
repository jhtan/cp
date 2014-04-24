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
  vi V(1000000, 0);

  for(int i=0; i<1000; i++) {
    for(int j=0; j<1000; j++) {
      int x = i*i + j*j;
      if(sqrt(x) * sqrt(x) == x) {
	V[i + j + sqrt(x)]++;
      }
    }
  }

  int mx = 0, n;
  for(int i=1; i<=1000; i++) {
    if(V[i] > mx) {
      mx = V[i];
      n = i;
    }
  }

  printf("%d\n", n);

  return 0;
}
