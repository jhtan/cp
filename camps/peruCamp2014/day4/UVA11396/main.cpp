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

int main() {
  int v;
  scanf("%d", &v);

  while(v) {
    vector<vi> G(v+1);

    int a, b;
    scanf("%d %d", &a, &b);

    while(a+b > 0) {
      G[a].push_back(b);
      G[b].push_back(a);

      scanf("%d %d", &a, &b);
    }

    vector<int> V(v+1, -1);

    queue<int> q;
    q.push(1);
    V[1] = 0;
    bool sw = true;

    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(int i=0; i<G[u].size(); i++) {
	if(V[G[u][i]] == -1) {
	  V[G[u][i]] = 1 - V[u];
	  q.push(G[u][i]);
	} else if(V[G[u][i]] == V[u]) {
	  sw = false;
	  break;
	}
      }
    }

    if(sw)
      printf("YES\n");
    else
      printf("NO\n");

    scanf("%d", &v);
  }

  return 0;
}
