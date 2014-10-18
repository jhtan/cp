#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

ll sum(ll n) {return (n*(n+(ll)1))/(ll)2;}

int main() {
  ll n, m;
  cin >> n >> m;

  ll mn = 0, mx = 0;
  if(n % m == 0) {
    mn += m * (sum((n/m)-1));
  } else {
    mn += ((n%m) * (sum(n/m)));
    mn += (m-(n%m)) * (sum((n/m) - 1));
  }

  mx = sum(n-m);
  cout << mn << " " << mx << endl;

  return 0;
}
