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

int v, e, c;
vector<vi> G;
vector<bool> B;
vector<bool> S;
bool sw;

void dfs(int x) {
  B[x] = true;

  if(sw) {
    printf("%d", x);
    sw = false;
  } else {
    printf(" %d", x);
  }

  for(int i=0; i<G[x].size(); i++) {
    if(!B[G[x][i]]) {
      dfs(G[x][i]);
    }
  }
}

int main() {
  scanf("%d %d", &v, &e);

  while(v+e > 0) {
    G.assign(v+1, vi());
    int a, b;
    
    S.assign(v+1, false);
    for(int i=0; i<e; i++) {
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      S[b] = true;
    }

    B.assign(v+1, false);
    c = 0;
    sw = true;
    for(int i=1; i<=v; i++) {
      if(!B[i] && !S[i]) {
	dfs(i);
      }
    }
    
    printf("\n");
    scanf("%d %d", &v, &e);
  }

  return 0;
}
