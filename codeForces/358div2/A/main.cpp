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

  vector<ll> A(6), B(6);

  for(int i=1; i<=5; i++) {
    A[i] = a / 5;
    if(a % 5 >= i) A[i]++;

    B[i] = b / 5;
    if(b % 5 >= i) B[i]++;
  }

  ll c = 0;
  for(int i=1; i<=4; i++)
    c += (A[i] * B[5 - i]);
  c += (A[5] * B[5]);

  cout << c << endl;

  return 0;
}
