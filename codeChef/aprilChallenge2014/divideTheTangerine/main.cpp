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
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, k, p, a, b;
    scanf("%d %d %d", &n, &k, &p);

    vii V, W;
    for(int i=0; i<k; i++) {
      scanf("%d %d", &a, &b);
      V.push_back(ii(a, b));
    }

    for(int i=0; i<p; i++) {
      scanf("%d %d", &a, &b);
      W.push_back(ii(a, b));
    }

    sort(V.begin(), V.end());
    sort(W.begin(), W.end());
    V.push_back(ii(V[0].first, V[0].second));
    W.push_back(ii(W[0].first, W[0].second));

    bool sw = true;

    for(int i=0; i<W.size()-1 && sw; i++) {
      bool sw2 = true;
      for(int j=0; j<V.size()-1 && sw2; j++) {
	if(W[i].second == V[j].second && W[i+1].first == V[j+1].first) {
	  sw2 = false;
	  break;
	}
      }

      if(sw2) {
	sw = false;
	break;
      }
    }

    if(sw)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
