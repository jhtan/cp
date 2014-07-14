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
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    ll c = 0;
    for(int i=0; i<s.length(); i++)
      if(s[i] == '1')
	c++;

    printf("%lld\n", (c*(c+1)) / (ll)2);
  }

  return 0;
}
