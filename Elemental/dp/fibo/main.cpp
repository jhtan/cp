#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[200];

ll fibo(ll n) {
  if(dp[n] != -1) return dp[n];
  return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
  ll n; cin >> n;

  memset(dp, -1, sizeof(dp));
  dp[1] = 1;
  dp[2] = 1;

  for(ll i=1; i<=n; i++)
    cout << fibo(i) << endl;

  return 0;
}
