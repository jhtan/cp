#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

ll M[1010][1010];
ll dp[1010][1010];

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
      for(int j=0; j<=i; j++)
	scanf("%lld", &M[i][j]);

    dp[0][0] = M[0][0];
    for(int i=1; i<n; i++) {
      for(int j=0; j<=i; j++) {
	dp[i][j] = M[i][j];
	if(j > 0 && j < i)
	  dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
	else if(j > 0) dp[i][j] += dp[i-1][j-1];
	else if(j < i) dp[i][j] += dp[i-1][j];
      }
    }

    ll mx = 0;
    for(int i=0; i<n; i++)
      mx = max(mx, dp[n-1][i]);

    printf("%lld\n", mx);
  }

  return 0;
}
