#include <bits/stdc++.h>

using namespace std;

vector<bool> V;
vector<vector<int> > G;

void dfs(int n) {
  V[n] = true;

  for(int i=0; i<G[n].size(); i++)
    if(!V[G[n][i]])
      dfs(G[n][i]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  G.assign(n, vector<int>());

  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
    
  int q; scanf("%d", &q);

  while(q--) {
    scanf("%d %d", &a, &b);
    V.assign(n, false);
    dfs(a);

    if(V[b]) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}
