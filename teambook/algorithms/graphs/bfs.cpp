#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

typedef vector<int> vi;
#define pb push_back

vector<vi> G;
int dist[10010];
int parent[10010];

void bfs(int n) {
  queue<int> q;
  q.push(n);
  memset(dist, -1, sizeof(dist));
  memset(dist, -1, sizeof(parent));
  dist[n] = 0;

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int i=0; i<G[u].size(); i++) {
      if(dist[G[u][i]] == -1) {
      	dist[G[u][i]] = dist[u] + 1;
      	parent[G[u][i]] = u;
      	q.push(G[u][i]);
      }
    }
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  G.assign(v, vi());

  int a, b;
  for(int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    G[a].pb(b);
  }

  bfs(0);

  printf("Distances\n");
  for(int i=0; i<v; i++)
    printf("%d ", dist[i]);
  printf("\n");

  printf("Parents\n");
  for(int i=0; i<v; i++)
    printf("%d ", parent[i]);
  printf("\n");

  return 0;
}
