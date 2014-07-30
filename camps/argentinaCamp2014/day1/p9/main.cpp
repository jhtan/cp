#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vi V(2000);
int dp[2000][2000];

int solve(int i, int j, int d) {
  if(dp[i][j] != -1) return dp[i][j];
  if(i == j) return dp[i][j] = V[i] * d;
  return dp[i][j] = max(V[i] * d + solve(i+1, j, d+1), solve(i, j-1, d+1) + V[j] * d);
}

int main() {
  int n; scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &V[i]);

  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0, n-1, 1));

  return 0;
}
