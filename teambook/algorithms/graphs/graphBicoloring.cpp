#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
#define pb push_back

int main() {
  int n, m;
  scanf("%d", &n);

  while(n) {
    scanf("%d", &m);

    vector<vi> G(n);

    int a, b;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    bool sw = true;

    // BFS
    queue<int> Q;
    vi color(n, -1);
    Q.push(0);
    color[0] = 0;
    while(!Q.empty()) {
      int u = Q.front();
      Q.pop();

      for(int i=0; i<G[u].size(); i++) {
      	if(color[G[u][i]] == -1) {
      	  color[G[u][i]] = (color[u]+1)%2;
      	  Q.push(G[u][i]);
      	} else {
	        if(color[G[u][i]] == color[u]) {
      	    sw = false;
    	      break;
      	  }
      	}
      }

      if(!sw)
      	break;
    }

    if(sw)
      printf("BICOLORABLE.\n");
    else
      printf("NOT BICOLORABLE.\n");

    scanf("%d", &n);
  }

  return 0;
}
