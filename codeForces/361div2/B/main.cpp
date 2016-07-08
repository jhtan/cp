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

int main() {
  int n; scanf("%d", &n);
  
  G.assign(n+1, vi());
  for(int i=1; i<n; i++) {
    G[i].push_back(i+1);
    G[i+1].push_back(i);
  }

  for(int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);
    G[i+1].push_back(x);
  }

  V.assign(n+1, -1);

  queue<int> Q;
  Q.push(1);
  V[1] = 0;

  while(!Q.empty()) {
    int x = Q.front(); Q.pop();

    for(int i=0; i<G[x].size(); i++) {
      if(V[G[x][i]] == -1) {
	V[G[x][i]] = V[x] + 1;
	Q.push(G[x][i]);
      }
    }
  }
  

  for(int i=1; i<=n; i++) {
    printf("%d", V[i]);
    if(i < n) printf(" ");
    else printf("\n");
  }
  
  return 0;
}
