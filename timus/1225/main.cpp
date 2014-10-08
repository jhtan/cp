#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n;
  scanf("%d", &n);

  ll a = 1, b = 0, f;
  
  for(int i=0; i<n; i++) {
    f = a + b;
    a = b;
    b = f;
  }

  printf("%lld\n", f*2);

  return 0;
}
