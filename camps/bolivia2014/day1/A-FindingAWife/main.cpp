#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis, vis2;

int Aug(int l) {
  if (vis[l]) return 0;
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;
  } }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  while(n && m) {
    int V = n+m+1, Vleft = n+1;
    AdjList.assign(V, vi());

    for(int i=0; i<n; i++) {
      int q, x;
      scanf("%d", &q);
      for(int j=0; j<q; j++) {
	scanf("%d", &x);
	AdjList[i+1].push_back(x+1);
      }
    }

    int MCBM = 0;
    match.assign(V, -1);
    vis2.assign(Vleft, 0);

    for(int i=0; i<=n; i++) {
      for(int j=0; j<AdjList[i].size(); j++) {
	int r = AdjList[i][j];
	if(match[r] == -1) {
	  vis2[i] = 1;
	  match[r] = i;
	  MCBM++;
	  break;
	}
      }
    }

    for (int l = 0; l < Vleft; l++) {
      if(!vis2[l]) {
	vis.assign(Vleft, 0);
	MCBM += Aug(l);
      }
    }

    printf("%d\n", MCBM);
    scanf("%d %d", &n, &m);
  }

  return 0;
}
