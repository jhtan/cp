#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
#define pb push_back
#define INF 1000000000

vector<vii> G;
vi dist(10001, INF);
vi parent(10001, 0);

void dijkstra(int n) {
  dist[n] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, n));

  while(!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    int u = front.second, d = front.first;

    if(d > dist[u])
      continue;

    for(int i=0; i<G[u].size(); i++) {
      ii v = G[u][i];
      if(dist[u] + v.second < dist[v.first]) {
      	dist[v.first] = dist[u] + v.second;
	parent[v.first] = u;
      	pq.push(ii(dist[v.first], v.first));
      }
    }
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  G.assign(v, vii());
  int a, b, c;
  for(int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    G[a].pb(ii(b, c));
  }

  dijkstra(0);

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
