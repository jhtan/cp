#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;

vi taken;
priority_queue<ii> pq;
vector<vii> G;

void process(int vtx) {
  taken[vtx] = 1;
  for(int j=0; j<G[vtx].size(); j++) {
    ii v = G[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);
  G.assign(v, vii());

  int a, b, c;
  for(int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    G[a].push_back(ii(b, c));
    G[b].push_back(ii(a, c));
  }

  taken.assign(v, 0);
  process(0);
  int mst_cost = 0;
  while(!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int u = -front.second;
    int w = -front.first;
    if(!taken[u]) {
      mst_cost += w;
      process(u);
    }
  }

  printf("mst = %d\n", mst_cost);

  return 0;
}
