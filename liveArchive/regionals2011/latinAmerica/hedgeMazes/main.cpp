#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define INF 2000000000
 
vector<vi> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
set<ii> B;
 
int pp[100010];
void initSet(int n) {
  for (int i = 0; i < n ; i++) pp[i] = i;
}
int findSet(int i) {
  return pp[i] == i?i:pp[i] = findSet(pp[i]);
}
void unionSet(int i, int j) {
  pp[findSet(i)] = findSet(j);
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
 
void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(int j=0; j<G[u].size(); j++) {
    int v = G[u][j];
    if(dfs_num[v] == DFS_WHITE) {
      dfs_parent[v] = u;
      if(u == dfsRoot)
	rootChildren++;
 
      articulationPointAndBridge(v);
 
      if(dfs_low[v] >= dfs_num[u])
	articulation_vertex[u] = true;
      if(dfs_low[v] > dfs_num[u])
	unionSet(u, v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if(v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}
 
int main()
{
  int v, e, q;
  scanf("%d %d %d", &v, &e, &q);
 
  while(v+e+q > 0) {
    G.assign(v, vi());
    B.clear();
    initSet(v);
 
    int a, b;
    for(int i=0; i<e; i++) {
      scanf("%d %d", &a, &b);
      G[a-1].push_back(b-1);
      G[b-1].push_back(a-1);
    }
 
    // Bridges
    dfsNumberCounter = 0;
    dfs_num.assign(v, DFS_WHITE);
    dfs_low.assign(v, 0);
    dfs_parent.assign(v, 0);
    articulation_vertex.assign(v, 0);
    for(int i=0; i<v; i++) {
      if(dfs_num[i] == DFS_WHITE) {
	dfsRoot = i;
	rootChildren = 0;
	articulationPointAndBridge(i);
	articulation_vertex[dfsRoot] = (rootChildren > 1);
      }
    }
 
    for(int i=0; i<q; i++) {
      scanf("%d %d", &a, &b);
      a--, b--;
 
      if(isSameSet(a, b))
	printf("Y\n");
      else
	printf("N\n");
    }
 
    printf("-\n");
    scanf("%d %d %d", &v, &e, &q);
  }
 
  return 0;
}
