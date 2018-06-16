#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define MINF -2000000000

int n, k;
vi P(10000);

int dp(int n) {
  if(n == 0) return 0;
  int q = -1000000;

  for(int i=1; i<=n; i++)
    q = max(q, P[i] + dp(n-i));

  return q;
}

int main() {
  while(scanf("%d %d", &n, &k) != EOF) {
    for(int i=1; i<=k; i++) scanf("%d", &P[i]);
    printf("%d\n", dp(n));
  }

  return 0;
}
