#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  int n, m; scanf("%d %d", &n, &m);
  vector<vi> G(n, vi());

  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> Q; Q.push(0);
  vi D(n, -1); D[0] = 0;
  vi P(n); P[0] = -1;

  while(!Q.empty()) {
    int x = Q.front(); Q.pop();

    for(int i=0; i<G[x].size(); i++) {
      if(D[G[x][i]] == -1) {
	D[G[x][i]] = D[x] + 1;
	P[G[x][i]] = x;
	Q.push(G[x][i]);
      }
    }
  }

  for(int i=0; i<n; i++) printf("%d ", D[i]);
  printf("\n");
  for(int i=0; i<n; i++) printf("%d ", P[i]);
  printf("\n");
  
  return 0;
}
