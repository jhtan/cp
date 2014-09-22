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

  string s;
  while(t--) {
    cin >> s;

    ll x = 1;

    for(int i=0; i<s.size(); i++) {
      if(i&1) {
	if(s[i] == 'l')
	  (x*=2)--;
	else if(s[i] == 'r')
	  (x*=2)++;
      } else {
	if(s[i] == 'l')
	  x*=2;
	else if(s[i] == 'r')
	  (x*=2)+=2;
      }

      x %= 1000000007;
    }

    printf("%lld\n", x);
  }

  return 0;
}
