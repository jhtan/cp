#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vector<vi> G;
int dp[1010][1010];

bool disjoint(int a, int b) {
  if(dp[a][b] != -1) return dp[a][b];

  if(a == b) {
    if(a == 1) return dp[a][b] = true;
    else return dp[a][b] = false;
  } else if(a < b) {
    for(int i=0; i<G[b].size(); i++)
      if(disjoint(a, G[b][i])) return dp[a][b] = true;
    return dp[a][b] = false;
  } else if(a > b) {
    for(int i=0; i<G[a].size(); i++)
      if(disjoint(G[a][i], b)) return dp[a][b] = true;
    return dp[a][b] = false;
  }
}

int main() {
  int n, m;
  
  while(scanf("%d %d", &n, &m) != EOF) {
    G.assign(n+1, vi());

    int a, b;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      G[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    int c = n-1;
    for(int i=2; i<=n; i++)
      for(int j=i+1; j<=n; j++)
	if(disjoint(i, j))
	  c++;

    printf("%d\n", c);
  }

  return 0;
}
