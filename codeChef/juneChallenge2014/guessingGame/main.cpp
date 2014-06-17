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
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll a = n/2 + n%2;
    ll b = m/2 + m%2;
    ll x = (n-a)*b + a*(m-b);
    ll y = n * m;
    ll g = __gcd(x, y);
    x /= g;
    y /= g;

    printf("%lld/%lld\n", x, y);
  }

  return 0;
}
