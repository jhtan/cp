#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  string s;
  cin >> s;
  int k; scanf("%d", &k);

  int mx = 0;

  vi alp(255, 0);
  for(int i='a'; i<='z'; i++) {
    scanf("%d", &alp[i]);
    mx = max(mx, alp[i]);
  }

  int v = 0;
  for(int i=1; i<=s.length(); i++) {
    v += (i * alp[s[i-1]]);
  }

  for(int j=s.length()+1; j<=s.length()+k; j++) {
    v += (j * mx);
  }

  printf("%d\n", v);

  return 0;
}
