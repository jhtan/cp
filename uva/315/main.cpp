#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;
#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vi> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

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
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if(v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }    
}

int main() {
  int v;
  scanf("%d", &v);

  while(v) {
    G.assign(v+1, vi());
    string s;
    getline(cin, s);
    getline(cin, s);

    while(s.compare("0") != 0) {
      stringstream stream(s);
      bool sw = true;
      int n, x;

      while(stream >> x) {
	if(sw) {
	  n = x;
	  sw = false;
	} else {
	  G[n].push_back(x);
	  G[x].push_back(n);
	}
      }

      getline(cin, s);
    }

    dfsNumberCounter = 0;
    dfs_num.assign(v+1, DFS_WHITE);
    dfs_low.assign(v+1, 0);
    dfs_parent.assign(v+1, 0);
    articulation_vertex.assign(v+1, 0);
    for(int i=1; i<=v; i++) {
      if(dfs_num[i] == DFS_WHITE) {
	dfsRoot = i;
	rootChildren = 0;
	articulationPointAndBridge(i);
	articulation_vertex[dfsRoot] = (rootChildren > 1);
      }
    }

    int ap = 0;
    for(int i=1; i<=v; i++) {
      if(articulation_vertex[i])
	ap++;
    }

    printf("%d\n", ap);
    scanf("%d", &v);
  }

  return 0;
}
