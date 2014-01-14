#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define UNVISITED -1
#define VISITED 1

vector<vi> G;
vi S, visited, dfs_num, dfs_low;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  
  for(int j=0; j<G[u].size(); j++) {
    int v = G[u][j];
    if(dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if(visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  
  if(dfs_low[u] == dfs_num[u]) {
    numSCC++;
    printf("SCC %d:", numSCC);
    
    while(1) {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      printf(" %d", v);
      if(u == v)
	break;
    }
    printf("\n");
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  G.assign(v, vi());

  int a, b;
  for(int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
  }

  dfs_num.assign(v, UNVISITED);
  dfs_low.assign(v, 0);
  visited.assign(v, 0);
  dfsNumberCounter = numSCC = 0;

  for(int i=0; i<v; i++) {
    if(dfs_num[i] == UNVISITED)
      tarjanSCC(i);
  }

  return 0;
}
