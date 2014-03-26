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

#define INF 2000000000

int main() {
  vector<vi> G;
  vi D;

  int n, tc = 1;
  scanf("%d", &n);

  while(n > 0) {
    G.assign(30, vi());
    int v = 0, a, b;
    map<int, int> M;

    for(int i=0; i<n; i++) {
      scanf("%d %d", &a, &b);

      if(M.count(a) == 0)
	M[a] = v, v++;
      if(M.count(b) == 0)
	M[b] = v, v++;

      G[M[a]].push_back(M[b]);
      G[M[b]].push_back(M[a]);
    }

    scanf("%d %d", &a, &b);
    while(a + b > 0) {
      D.assign(v, INF);
      queue<int> Q;
      Q.push(M[a]);
      D[M[a]] = 0;
      int s = 0;

      while(!Q.empty()) {
	int p = Q.front();
	Q.pop();

	for(int i=0; i<G[p].size(); i++) {
	  if(D[G[p][i]] == INF) {
	    Q.push(G[p][i]);
	    D[G[p][i]] = D[p] + 1;
	  }
	}
      }

      for(int i=0; i<D.size(); i++) {
	// cout << D[i] << "  ";

	if(D[i] <= b)
	  s++;
      }
      // cout << endl;

      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", tc, v-s, a, b);
      tc++;

      scanf("%d %d", &a, &b);
    }

    scanf("%d", &n);
  }

  return 0;
}
