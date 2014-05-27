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

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vector<vi> G;

vi match, vis;

int aug(int l) {
  if(vis[l]) return 0;
  vis[l] = 1;
  for(int j=0; j<G[l].size(); j++) {
    int r = G[l][j];
    if(match[r] == -1 || aug(match[r])) {
      match[r] = l;
      return 1;
    }
  }

  return 0;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    int M[n][m], R[n][m], C[n][m], r, c;
    r = c = -1;

    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	scanf("%d", &M[i][j]);
	if(j == 0 || (M[i][j] != 2 && M[i][j-1] == 2)) {
	  r++;
	}

	if(M[i][j] == 2)
	  R[i][j] = -1;
	else
	  R[i][j] = r;
      }
    }

    G.assign(50000, vi());

    for(int j=0; j<m; j++) {
      for(int i=0; i<n; i++) {
	if(i == 0 || (M[i][j] != 2 && M[i-1][j] == 2)) {
	  c++;
	}

	if(M[i][j] == 2) {
	  R[i][j] = -1;
	} else {
	  C[i][j] = c;
	  if(M[i][j] == 0)
	    G[R[i][j]].push_back(c);
	}
      }
    }

    r++;
    c++;

    int mx = 0;
    match.assign(r+c, -1);
    for(int i=0; i<r; i++) {
      vis.assign(r, 0);
      mx += aug(i);
    }

    printf("%d\n", mx);
  }

  return 0;
}
