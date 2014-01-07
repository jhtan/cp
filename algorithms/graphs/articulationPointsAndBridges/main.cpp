#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(int j=0; j<G[u].size(); j++) {
    ii v = G[u][j];
    if(dfs_num[v.first] == DFS_WHITE) {
      dfs_parent[v.first] = u;
      if(u == dfsRoot)
	rootChildren++;

      articulationPointAndBridge(v.first);

      if(dfs_low[v.first] >= dfs_num[u])
	articulation_vertex[u] = true;
      if(dfs_low[v.first] > dfs_num[u])
	printf(" Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    } else if(v.first != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  G.assign(v, vii());
  int a, b;
  for(int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(ii(b, 1));
    G[b].push_back(ii(a, 1));
  }

  dfsNumberCounter = 0;
  dfs_num.assign(v, DFS_WHITE);
  dfs_low.assign(v, 0);
  dfs_parent.assign(v, 0);
  articulation_vertex.assign(v, 0);
  printf("Bridges\n");
  for(int i=0; i<v; i++) {
    if(dfs_num[i] == DFS_WHITE) {
      dfsRoot = i;
      rootChildren = 0;
      articulationPointAndBridge(i);
      articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
  }    

  printf("Articulation Points:\n");
  for(int i=0; i<v; i++) {
    if(articulation_vertex[i])
      printf(" Vertex %d\n", i);
  }
  
  return 0;
}
