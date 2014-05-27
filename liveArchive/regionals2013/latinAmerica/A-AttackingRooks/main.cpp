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
vi match, vis, vis2;

int aug(int l) {
  if (vis[l]) return 0;
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
  int n;

  while(scanf("%d", &n) != EOF) {
    int M[n][n], R[n][n], r, c;
    r = c = -1;

    for(int i=0; i<n; i++) {
      string aux;
      cin >> aux;
      for(int j=0; j<n; j++) {
	M[i][j] = aux[j];

	if(j == 0 || (M[i][j] == '.' && M[i][j-1] == 'X'))
	  r++;

	R[i][j] = r;
      }
    }

    G.assign(20000, vi());
    for(int j=0; j<n; j++) {
      for(int i=0; i<n; i++) {
	if(i == 0 || (M[i][j] == '.' && M[i-1][j] == 'X'))
	  c++;

	if(M[i][j] == '.')
	  G[R[i][j]].push_back(c);
      }
    }

    r++; c++;
    int mx = 0;
    match.assign(r+c, -1);
    
    vis2.assign(r, 0);
    for(int i=0; i<r; i++) {
      for(int j=0; j<G[i].size(); j++) {
	if(match[G[i][j]] == -1) {
	  match[G[i][j]] = i;
	  vis2[i] = 1;
	  mx++;
	  break;
	}
      }
    }

    for(int i=0; i<r; i++) {
      if(!vis2[i]) {
	vis.assign(r, 0);
	mx += aug(i);
      }
    }

    printf("%d\n", mx);
  }

  return 0;
}
