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
  V.assign(n, false);

  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
    
  int c = 0;
  for(int i=0; i<n; i++) {
    if(!V[i]) {
      dfs(i);
      c++;
    }
  }

  printf("%d\n", c);

  return 0;
}
