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
    ll x;
    int n;
    scanf("%lld %d", &x, &n);

    vector<ll> V(n);
    for(int i=0; i<n; i++)
      scanf("%lld", &V[i]);

    bool sw = false;
    set<ll> S;
    S.insert(0);

    if(x == 0)
      sw = true;

    for(int i=0; i<n && !sw; i++) {
      set<ll>::iterator it;
      vector<ll> A;
      for(it=S.begin(); it!=S.end() && !sw; it++) {
	if((*it) + V[i] == x) {
	  sw = true;
	} else {
	  //if((*it) + V[i] < x)
	    A.push_back((*it) + V[i]);
	}
      }

      for(int j=0; j<A.size(); j++)
	S.insert(A[j]);
    }

    if(sw)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
