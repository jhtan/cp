#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, e;
vector<vi> G;
vi V;

void dfs(int n) {
  cout << n+1 << ", ";
  V[n] = 1;

  for(int i=0; i<G[n].size(); i++)
    if(!V[G[n][i]])
      dfs(G[n][i]);

}

int main() {
  scanf("%d %d", &n, &e);
  G.assign(n, vi());
  V.assign(n, 0);

  int a, b;
  for(int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  // Mostrando truchamente...
  for(int i=0; i<G.size(); i++) {
    cout << "(" << i+1 << ") -> ";
    
    for(int j=0; j < G[i].size(); j++) {
      cout << G[i][j] + 1 << ", ";
    }
    cout << endl;
  }

  dfs(0);
  cout << endl;

  return 0;
}
