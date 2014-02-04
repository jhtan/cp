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
  int n, mn=101;
  scanf("%d", &n);

  int V[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &V[i]);
    mn = min(mn, V[i]);
  }

  int g = 1;
  for(int i=2; i<=mn; i++) {
    bool sw = true;
    for(int j=0; j<n; j++) {
      if(V[j] % i != 0) {
	sw = false;
	break;
      }
    }

    if(sw)
      g = i;
  }

  printf("%d\n", g*n);

  return 0;
}
