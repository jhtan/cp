#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);
    int m = 0, x;
      ll c = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &x);
      c += abs(m);
      m += x;
    }
    printf("%lld\n", c);
  }

  return 0;
}
