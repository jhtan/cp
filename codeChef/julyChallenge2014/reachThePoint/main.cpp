#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    ll x, y, s;
    scanf("%lld %lld", &x, &y);

    x = abs(x);
    y = abs(y);

    s = min(x, y) * 2;

    if(x < y) {
      y -= x;
      s += ((y/2) * 3);
      s += (y/2 + y%2);
    } else {
      x -= y;
      s += (x/2);
      s += ((x/2 + x%2) * 3);
    }

    printf("%lld\n", s);
  }

  return 0;
}
