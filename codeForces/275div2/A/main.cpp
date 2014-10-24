#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  ll a, b;
  cin >> a >> b;

  if(a & 1) a++;

  if(b - a < 2) cout << "-1" << endl;
  else cout << a << " " << a+1 << " " << a+2 << endl;

  return 0;
}
