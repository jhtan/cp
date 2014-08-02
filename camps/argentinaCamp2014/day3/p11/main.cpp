#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vector<vi> G;
vi V;

void dfs(int v) {
  for(int i=0; i<G[v].size(); i++) {
    if(V[G[v][i]] == -1) {
      V[G[v][i]] = v;
      dfs(G[v][i]);
    }
  }
}

int main() {
  int n, x, y, z; scanf("%d %d %d", &n, &x, &y);

  G.assign(n+1, vi());
  for(int i=1; i<=n; i++) {
    if(i == x) continue;
    scanf("%d", &z);
    G[i].push_back(z);
    G[z].push_back(i);
  }

  V.assign(n+1, -1);
  dfs(y);

  vi W;
  for(int i=1; i<=n; i++) {
    if(i != y) W.push_back(V[i]);
  }

  for(int i=0; i<W.size(); i++) {
    printf("%d", W[i]);
    if(i != W.size()-1)
      printf(" ");
    else
      printf("\n");
  }

  return 0;
}
