#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, m;
vector<vi> G;
vector<bool> D;

void dfs(int x) {
  printf("-> %d\n", x);
  D[x] = true;

  for(int i=0; i<G[x].size(); i++)
    if(!D[G[x][i]])
      dfs(G[x][i]);
}

int main() {
  scanf("%d %d", &n, &m);
  G.assign(n, vi());
  D.assign(n, false);

  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  //dfs(0);
  for(i->n)
    !marcado
      dfs(i)
      c++;
  
  // for(int i=0; i<n; i++) {
  //   printf("%d -> ", i);
  //   for(int j=0; j<G[i].size(); j++) {
  //     printf("%d, ", G[i][j]);
  //   }
  //   printf("\n");
  // }

  return 0;
}
